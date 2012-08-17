/*
 * Photos - access, organize and share your photos on GNOME
 * Copyright © 2012 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */


#include "config.h"

#include <clutter/clutter.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gtk/gtk.h>

#include "photos-embed.h"
#include "photos-error-box.h"
#include "photos-item-manager.h"
#include "photos-main-toolbar.h"
#include "photos-mode-controller.h"
#include "photos-selection-toolbar.h"
#include "photos-spinner-box.h"
#include "photos-tracker-controller.h"
#include "photos-view-container.h"


struct _PhotosEmbedPrivate
{
  ClutterActor *background;
  ClutterActor *contents_actor;
  ClutterActor *error_box;
  ClutterActor *image_actor;
  ClutterActor *overview_actor;
  ClutterActor *spinner_box;
  ClutterActor *view_actor;
  ClutterLayoutManager *contents_layout;
  ClutterLayoutManager *view_layout;
  GCancellable *loader_cancellable;
  GtkWidget *overview;
  PhotosBaseManager *item_mngr;
  PhotosMainToolbar *toolbar;
  PhotosSelectionToolbar *selection_toolbar;
  PhotosModeController *mode_cntrlr;
  PhotosTrackerController *trk_cntrlr;
  gint preview_page;
  gint view_page;
};


G_DEFINE_TYPE (PhotosEmbed, photos_embed, GTK_CLUTTER_TYPE_EMBED);


static void
photos_embed_item_load (GObject *source_object, GAsyncResult *res, gpointer user_data)
{
  PhotosEmbed *self = PHOTOS_EMBED (user_data);
  PhotosEmbedPrivate *priv = self->priv;
  ClutterContent *image;
  CoglPixelFormat pixel_format;
  GdkPixbuf *pixbuf;
  PhotosBaseItem *item = PHOTOS_BASE_ITEM (source_object);
  gboolean has_alpha;
  gint height;
  gint row_stride;
  gint width;
  guchar *pixels;

  g_clear_object (&priv->loader_cancellable);
  pixbuf = photos_base_item_load_finish (item, res, NULL);
  if (pixbuf == NULL)
    return;

  pixels = gdk_pixbuf_get_pixels (pixbuf);
  has_alpha = gdk_pixbuf_get_has_alpha (pixbuf);
  pixel_format = (has_alpha) ? COGL_PIXEL_FORMAT_RGBA_8888 : COGL_PIXEL_FORMAT_RGB_888;

  width = gdk_pixbuf_get_width (pixbuf);
  height = gdk_pixbuf_get_height (pixbuf);
  row_stride = gdk_pixbuf_get_rowstride (pixbuf);

  image = clutter_image_new ();
  clutter_image_set_data (CLUTTER_IMAGE (image), pixels, pixel_format, width, height, row_stride, NULL);
  g_object_unref (pixbuf);

  clutter_actor_save_easing_state (priv->image_actor);
  clutter_actor_set_content_gravity (priv->image_actor, CLUTTER_CONTENT_GRAVITY_RESIZE_ASPECT);
  clutter_actor_restore_easing_state (priv->image_actor);
  clutter_actor_set_content (priv->image_actor, image);
  g_object_unref (image);

  /* TODO: set toolbar model */

  photos_spinner_box_move_out (PHOTOS_SPINNER_BOX (priv->spinner_box));
  photos_mode_controller_set_can_fullscreen (priv->mode_cntrlr, TRUE);
}


static void
photos_embed_active_changed (PhotosBaseManager *manager, GObject *object, gpointer user_data)
{
  PhotosEmbed *self = PHOTOS_EMBED (user_data);
  PhotosEmbedPrivate *priv = self->priv;

  if (object == NULL)
    return;

  /* TODO: CollectionManager */

  photos_mode_controller_set_window_mode (priv->mode_cntrlr, PHOTOS_WINDOW_MODE_PREVIEW);
  photos_spinner_box_move_in_delayed (PHOTOS_SPINNER_BOX (priv->spinner_box), 400);

  priv->loader_cancellable = g_cancellable_new ();
  photos_base_item_load_async (PHOTOS_BASE_ITEM (object),
                               priv->loader_cancellable,
                               photos_embed_item_load,
                               self);
}


static void
photos_embed_fullscreen_changed (PhotosModeController *mode_cntrlr, gboolean fullscreen, gpointer user_data)
{
}


static void
photos_embed_prepare_for_overview (PhotosEmbed *self)
{
  PhotosEmbedPrivate *priv = self->priv;

  photos_base_manager_set_active_object (priv->item_mngr, NULL);

  if (priv->loader_cancellable != NULL)
    {
      g_cancellable_cancel (priv->loader_cancellable);
      g_clear_object (&priv->loader_cancellable);
    }

  photos_spinner_box_move_out (PHOTOS_SPINNER_BOX (priv->spinner_box));
  photos_error_box_move_out (PHOTOS_ERROR_BOX (priv->error_box));

  clutter_actor_set_child_above_sibling (priv->view_actor, priv->overview_actor, NULL);
}


static void
photos_embed_prepare_for_preview (PhotosEmbed *self)
{
  PhotosEmbedPrivate *priv = self->priv;

  /* TODO: SearchController,
   *       ErrorHandler
   */

  clutter_actor_set_child_above_sibling (priv->view_actor, priv->image_actor, NULL);
}


void
photos_embed_query_status_changed (PhotosTrackerController *trk_cntrlr, gboolean querying, gpointer user_data)
{
  PhotosEmbed *self = PHOTOS_EMBED (user_data);
  PhotosEmbedPrivate *priv = self->priv;

  if (querying)
    {
      photos_error_box_move_out (PHOTOS_ERROR_BOX (priv->error_box));
      photos_spinner_box_move_in (PHOTOS_SPINNER_BOX (priv->spinner_box));
    }
  else
    photos_spinner_box_move_out (PHOTOS_SPINNER_BOX (priv->spinner_box));
}


void
photos_embed_set_error (PhotosEmbed *self, const gchar *primary, const gchar *secondary)
{
  PhotosEmbedPrivate *priv = self->priv;

  photos_error_box_update (PHOTOS_ERROR_BOX (priv->error_box), primary, secondary);
  photos_error_box_move_in (PHOTOS_ERROR_BOX (priv->error_box));
}


static void
photos_embed_window_mode_change_flash_completed (PhotosEmbed *self)
{
  PhotosEmbedPrivate *priv = self->priv;
  clutter_actor_set_child_below_sibling (priv->view_actor, priv->background, NULL);
}


static void
photos_embed_window_mode_change_flash (PhotosEmbed *self)
{
  PhotosEmbedPrivate *priv = self->priv;
  ClutterAnimation *animation;

  clutter_actor_set_child_above_sibling (priv->view_actor, priv->background, NULL);
  clutter_actor_set_opacity (priv->background, 255);

  animation = clutter_actor_animate (priv->background, CLUTTER_EASE_IN_QUAD, 200, "opacity", 0, NULL);
  g_signal_connect_swapped (animation,
                            "completed",
                            G_CALLBACK (photos_embed_window_mode_change_flash_completed),
                            self);
}


static void
photos_embed_window_mode_changed (PhotosModeController *mode_cntrlr,
                                  PhotosWindowMode mode,
                                  PhotosWindowMode old_mode,
                                  gpointer user_data)
{
  PhotosEmbed *self = PHOTOS_EMBED (user_data);

  if (mode == PHOTOS_WINDOW_MODE_OVERVIEW)
    photos_embed_prepare_for_overview (self);
  else
    photos_embed_prepare_for_preview (self);

  if (old_mode != PHOTOS_WINDOW_MODE_NONE)
    photos_embed_window_mode_change_flash (self);
}


static void
photos_embed_dispose (GObject *object)
{
  PhotosEmbed *self = PHOTOS_EMBED (object);
  PhotosEmbedPrivate *priv = self->priv;

  g_clear_object (&priv->loader_cancellable);
  g_clear_object (&priv->item_mngr);

  if (priv->mode_cntrlr != NULL)
    {
      g_object_unref (priv->mode_cntrlr);
      priv->mode_cntrlr = NULL;
    }

  g_clear_object (&priv->trk_cntrlr);

  G_OBJECT_CLASS (photos_embed_parent_class)->dispose (object);
}


static void
photos_embed_init (PhotosEmbed *self)
{
  PhotosEmbedPrivate *priv;
  ClutterActor *actor;
  ClutterActor *stage;
  ClutterActor *toolbar_actor;
  ClutterLayoutManager *overlay_layout;
  ClutterConstraint *constraint;
  gboolean querying;

  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, PHOTOS_TYPE_EMBED, PhotosEmbedPrivate);
  priv = self->priv;

  gtk_clutter_embed_set_use_layout_size (GTK_CLUTTER_EMBED (self), TRUE);

  overlay_layout = clutter_bin_layout_new (CLUTTER_BIN_ALIGNMENT_CENTER, CLUTTER_BIN_ALIGNMENT_CENTER);
  actor = clutter_actor_new ();
  clutter_actor_set_layout_manager (actor, overlay_layout);

  stage = gtk_clutter_embed_get_stage (GTK_CLUTTER_EMBED (self));
  constraint = clutter_bind_constraint_new (stage, CLUTTER_BIND_SIZE, 0.0);
  clutter_actor_add_constraint (actor, constraint);
  clutter_actor_add_child (stage, actor);

  priv->contents_layout = clutter_box_layout_new ();
  clutter_box_layout_set_orientation (CLUTTER_BOX_LAYOUT (priv->contents_layout), CLUTTER_ORIENTATION_VERTICAL);
  priv->contents_actor = clutter_actor_new ();
  clutter_actor_set_layout_manager (priv->contents_actor, priv->contents_layout);
  clutter_actor_set_x_expand (priv->contents_actor, TRUE);
  clutter_actor_set_y_expand (priv->contents_actor, TRUE);
  clutter_actor_add_child (actor, priv->contents_actor);

  priv->toolbar = photos_main_toolbar_new ();
  toolbar_actor = photos_main_toolbar_get_actor (priv->toolbar);
  clutter_actor_set_x_expand (toolbar_actor, TRUE);
  clutter_actor_add_child (priv->contents_actor, toolbar_actor);

  priv->view_layout = clutter_bin_layout_new (CLUTTER_BIN_ALIGNMENT_CENTER, CLUTTER_BIN_ALIGNMENT_CENTER);
  priv->view_actor = clutter_actor_new ();
  clutter_actor_set_layout_manager (priv->view_actor, priv->view_layout);
  clutter_actor_set_x_expand (priv->view_actor, TRUE);
  clutter_actor_set_y_expand (priv->view_actor, TRUE);
  clutter_actor_add_child (priv->contents_actor, priv->view_actor);

  priv->overview = photos_view_container_new ();
  priv->overview_actor = gtk_clutter_actor_new_with_contents (priv->overview);
  clutter_actor_set_x_expand (priv->overview_actor, TRUE);
  clutter_actor_set_y_expand (priv->overview_actor, TRUE);
  clutter_actor_add_child (priv->view_actor, priv->overview_actor);

  priv->image_actor = clutter_actor_new ();
  clutter_actor_set_background_color (priv->image_actor, CLUTTER_COLOR_Black);
  clutter_actor_set_content_scaling_filters (priv->image_actor,
                                             CLUTTER_SCALING_FILTER_TRILINEAR,
                                             CLUTTER_SCALING_FILTER_TRILINEAR);
  clutter_actor_set_x_expand (priv->image_actor, TRUE);
  clutter_actor_set_y_expand (priv->image_actor, TRUE);
  clutter_actor_insert_child_below (priv->view_actor, priv->image_actor, NULL);

  priv->spinner_box = photos_spinner_box_new ();
  clutter_actor_insert_child_below (priv->view_actor, priv->spinner_box, NULL);

  priv->error_box = photos_error_box_new ();
  clutter_actor_insert_child_below (priv->view_actor, priv->error_box, NULL);

  priv->background = clutter_actor_new ();
  clutter_actor_set_background_color (priv->background, CLUTTER_COLOR_White);
  clutter_actor_set_x_expand (priv->background, TRUE);
  clutter_actor_set_y_expand (priv->background, TRUE);
  clutter_actor_insert_child_below (priv->view_actor, priv->background, NULL);

  /* TODO: SearchBar.Dropdown,
   *       ...
   */

  priv->selection_toolbar = photos_selection_toolbar_new (priv->contents_actor);
  toolbar_actor = photos_selection_toolbar_get_actor (priv->selection_toolbar);
  clutter_actor_add_child (actor, toolbar_actor);

  priv->mode_cntrlr = photos_mode_controller_new ();
  g_signal_connect (priv->mode_cntrlr,
                    "window-mode-changed",
                    G_CALLBACK (photos_embed_window_mode_changed),
                    self);
  g_signal_connect (priv->mode_cntrlr,
                    "fullscreen-changed",
                    G_CALLBACK (photos_embed_fullscreen_changed),
                    self);

  priv->trk_cntrlr = photos_tracker_controller_new ();
  g_signal_connect (priv->trk_cntrlr,
                    "query-status-changed",
                    G_CALLBACK (photos_embed_query_status_changed),
                    self);

  priv->item_mngr = photos_item_manager_new ();
  g_signal_connect (priv->item_mngr, "active-changed", G_CALLBACK (photos_embed_active_changed), self);

  querying = photos_tracker_controller_get_query_status (priv->trk_cntrlr);
  photos_embed_query_status_changed (priv->trk_cntrlr, querying, self);

  gtk_widget_show (GTK_WIDGET (self));
}


static void
photos_embed_class_init (PhotosEmbedClass *class)
{
  GObjectClass *object_class = G_OBJECT_CLASS (class);

  object_class->dispose = photos_embed_dispose;

  g_type_class_add_private (class, sizeof (PhotosEmbedPrivate));
}


GtkWidget *
photos_embed_new (void)
{
  return g_object_new (PHOTOS_TYPE_EMBED, NULL);
}