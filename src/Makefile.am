dist_bin_SCRIPTS = gnome-photos

libexec_PROGRAMS = gnome-photos-service

gnome_photos_service_built_sources = \
	gegl-gtk-enums.c \
	gegl-gtk-marshal.c \
	gegl-gtk-marshal.h \
	photos-about-data.c \
	photos-about-data.h \
	photos-enums.c \
	photos-enums.h \
	photos-dleyna-renderer-device.c \
	photos-dleyna-renderer-device.h \
	photos-dleyna-renderer-manager.c \
	photos-dleyna-renderer-manager.h \
	photos-dleyna-renderer-push-host.c \
	photos-dleyna-renderer-push-host.h \
	photos-gom-miner.c \
	photos-gom-miner.h \
	photos-marshalers.c \
	photos-marshalers.h \
	photos-mpris-player.c \
	photos-mpris-player.h \
	photos-resources.c \
	photos-resources.h \
	photos-shell-search-provider2.c \
	photos-shell-search-provider2.h \
	photos-tracker-resources.c \
	photos-tracker-resources.h \
	$(NULL)

nodist_gnome_photos_service_SOURCES = \
	$(gnome_photos_service_built_sources) \
	$(NULL)

gnome_photos_service_SOURCES = \
	eog-debug.c \
	eog-debug.h \
	eog-enums.h \
	eog-exif-util.c \
	eog-exif-util.h \
	eog-image.c \
	eog-image.h \
	eog-image-private.h \
	eog-image-save-info.c \
	eog-image-save-info.h \
	eog-job-queue.c \
	eog-job-queue.h \
	eog-jobs.c \
	eog-jobs.h \
	eog-metadata-reader.c \
	eog-metadata-reader.h \
	eog-metadata-reader-jpg.c \
	eog-metadata-reader-jpg.h \
	eog-metadata-reader-png.c \
	eog-metadata-reader-png.h \
	eog-transform.c \
	eog-transform.h \
	eog-uri-converter.c \
	eog-uri-converter.h \
	eog-util.c \
	eog-util.h \
	gegl-gtk-enums.h \
	gegl-gtk-view.c \
	gegl-gtk-view.h \
	gegl-gtk-view-helper.c \
	gegl-gtk-view-helper.h \
	photos-application.c \
	photos-application.h \
	photos-base-manager.c \
	photos-base-manager.h \
	photos-base-model.c \
	photos-base-model.h \
	photos-base-item.c \
	photos-base-item.h \
	photos-base-view.c \
	photos-base-view.h \
	photos-camera-cache.c \
	photos-camera-cache.h \
	photos-collection-icon-watcher.c \
	photos-collection-icon-watcher.h \
	photos-collection-manager.c \
	photos-collection-manager.h \
	photos-create-collection-icon-job.c \
	photos-create-collection-icon-job.h \
	photos-create-collection-job.c \
	photos-create-collection-job.h \
	photos-delete-item-job.c \
	photos-delete-item-job.h \
	photos-dlna-renderer.c \
	photos-dlna-renderer.h \
	photos-dlna-renderers-dialog.c \
	photos-dlna-renderers-dialog.h \
	photos-dlna-renderers-manager.c \
	photos-dlna-renderers-manager.h \
	photos-dropdown.c \
	photos-dropdown.h \
	photos-embed.c \
	photos-embed.h \
	photos-empty-results-box.c \
	photos-empty-results-box.h \
	photos-error-box.c \
	photos-error-box.h \
	photos-facebook-item.c \
	photos-facebook-item.h \
	photos-fetch-collection-state-job.c \
	photos-fetch-collection-state-job.h \
	photos-fetch-collections-job.c \
	photos-fetch-collections-job.h \
	photos-fetch-ids-job.c \
	photos-fetch-ids-job.h \
	photos-fetch-metas-job.c \
	photos-fetch-metas-job.h \
	photos-filterable.c \
	photos-filterable.h \
	photos-flickr-item.c \
	photos-flickr-item.h \
	photos-header-bar.c \
	photos-header-bar.h \
	photos-icons.h \
	photos-indexing-notification.c \
	photos-indexing-notification.h \
	photos-item-manager.c \
	photos-item-manager.h \
	photos-load-more-button.c \
	photos-load-more-button.h \
	photos-local-item.c \
	photos-local-item.h \
	photos-main-toolbar.c \
	photos-main-toolbar.h \
	photos-main-window.c \
	photos-main-window.h \
	photos-mode-controller.c \
	photos-mode-controller.h \
	photos-notification-manager.c \
	photos-notification-manager.h \
	photos-offset-collections-controller.c \
	photos-offset-collections-controller.h \
	photos-offset-controller.c \
	photos-offset-controller.h \
	photos-offset-favorites-controller.c \
	photos-offset-favorites-controller.h \
	photos-offset-overview-controller.c \
	photos-offset-overview-controller.h \
	photos-offset-search-controller.c \
	photos-offset-search-controller.h \
	photos-organize-collection-dialog.c \
	photos-organize-collection-dialog.h \
	photos-organize-collection-model.c \
	photos-organize-collection-model.h \
	photos-organize-collection-view.c \
	photos-organize-collection-view.h \
	photos-overview-searchbar.c \
	photos-overview-searchbar.h \
	photos-preview-model.c \
	photos-preview-model.h \
	photos-preview-nav-buttons.c \
	photos-preview-nav-buttons.h \
	photos-preview-view.c \
	photos-preview-view.h \
	photos-print-operation.c \
	photos-print-operation.h \
	photos-print-preview.c \
	photos-print-preview.h \
	photos-print-setup.c \
	photos-print-setup.h \
	photos-properties-dialog.c \
	photos-properties-dialog.h \
	photos-query.c \
	photos-query.h \
	photos-query-builder.h \
	photos-query-builder.c \
	photos-remote-display-manager.c \
	photos-remote-display-manager.h \
	photos-search-context.c \
	photos-search-context.h \
	photos-search-controller.c \
	photos-search-controller.h \
	photos-search-match.c \
	photos-search-match.h \
	photos-search-match-manager.c \
	photos-search-match-manager.h \
	photos-search-provider.c \
	photos-search-provider.h \
	photos-search-type.c \
	photos-search-type.h \
	photos-search-type-manager.c \
	photos-search-type-manager.h \
	photos-searchbar.c \
	photos-searchbar.h \
	photos-selection-controller.c \
	photos-selection-controller.h \
	photos-selection-toolbar.c \
	photos-selection-toolbar.h \
	photos-set-collection-job.c \
	photos-set-collection-job.h \
	photos-settings.c \
	photos-settings.h \
	photos-single-item-job.c \
	photos-single-item-job.h \
	photos-source.c \
	photos-source.h \
	photos-source-manager.c \
	photos-source-manager.h \
	photos-spinner-box.c \
	photos-spinner-box.h \
	photos-tracker-change-event.c \
	photos-tracker-change-event.h \
	photos-tracker-change-monitor.c \
	photos-tracker-change-monitor.h \
	photos-tracker-collections-controller.c \
	photos-tracker-collections-controller.h \
	photos-tracker-controller.c \
	photos-tracker-controller.h \
	photos-tracker-favorites-controller.c \
	photos-tracker-favorites-controller.h \
	photos-tracker-overview-controller.c \
	photos-tracker-overview-controller.h \
	photos-tracker-search-controller.c \
	photos-tracker-search-controller.h \
	photos-tracker-queue.c \
	photos-tracker-queue.h \
	photos-update-mtime-job.c \
	photos-update-mtime-job.h \
	photos-utils.c \
	photos-utils.h \
	photos-view-container.c \
	photos-view-container.h \
	photos-view-model.c \
	photos-view-model.h \
	photos-main.c \
	$(NULL)

BUILT_SOURCES = \
	$(gnome_photos_service_built_sources) \
	$(NULL)

EXTRA_DIST = \
	gegl-gtk-marshal.list \
	org.gnome.ShellSearchProvider2.xml \
	photos-enums.c.template \
	photos-enums.h.template \
	photos-generate-about \
	photos.gresource.xml \
	photos-app-menu.ui \
	photos-dlna-renderers-dialog.ui \
	photos-marshalers.list \
	photos-preview-menu.ui \
	photos-selection-menu.ui \
	photos-gom-miner.xml \
	photos-tracker-resources.xml \
	photos-dleyna-renderer-device.xml \
	photos-dleyna-renderer-manager.xml \
	photos-dleyna-renderer-push-host.xml \
	photos-mpris-player.xml \
	$(NULL)

AM_CPPFLAGS = \
	-DPACKAGE_ICONS_DIR=\""${pkgdatadir}/icons"\" \
	-DPACKAGE_LOCALE_DIR=\""${datadir}/locale"\" \
	$(BABL_CFLAGS) \
	$(CAIRO_CFLAGS) \
	$(EXEMPI_CFLAGS) \
	$(GDK_PIXBUF_CFLAGS) \
	$(GFBGRAPH_CFLAGS) \
	$(GEGL_CFLAGS) \
	$(GIO_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(GNOME_DESKTOP_CFLAGS) \
	$(GOA_CFLAGS) \
	$(GRILO_CFLAGS) \
	$(GTK_CFLAGS) \
	$(GTK_UNIX_PRINT_CFLAGS) \
	$(LCMS_CFLAGS) \
	$(LIBEXIF_CFLAGS) \
	$(LIBRSVG_CFLAGS) \
	$(TRACKER_CFLAGS) \
	$(WARN_CFLAGS) \
	-I$(top_srcdir)/libgd \
	$(NULL)

gnome_photos_service_LDFLAGS = 

gnome_photos_service_LDADD = \
	$(BABL_LIBS) \
	$(CAIRO_LIBS) \
	$(EXEMPI_LIBS) \
	$(GDK_PIXBUF_LIBS) \
	$(GFBGRAPH_LIBS) \
	$(GEGL_LIBS) \
	$(GIO_LIBS) \
	$(GLIB_LIBS) \
	$(GNOME_DESKTOP_LIBS) \
	$(GOA_LIBS) \
	$(GRILO_LIBS) \
	$(GTK_LIBS) \
	$(GTK_UNIX_PRINT_LIBS) \
	$(LCMS_LIBS) \
	$(LIBEXIF_LIBS) \
	$(LIBRSVG_LIBS) \
	$(TRACKER_LIBS) \
	$(LIBM) \
	$(top_builddir)/libgd/libgd.la \
	$(NULL)

CLEANFILES = \
	$(BUILT_SOURCES) \
	stamp-gegl-gtk-marshal.h \
	stamp-photos-about-data.h \
	stamp-photos-enums.h \
	stamp-photos-marshalers.h \
	xgen-ac \
	xgen-ah \
	xgen-etbc \
	xgen-etbh \
	xgen-gmc \
	xgen-gmh \
	xgen-tmc \
	xgen-tmh \
	$(NULL)

gegl-gtk-enums.c: $(srcdir)/gegl-gtk-enums.h
	$(AM_V_GEN) ( \
		glib-mkenums \
			--fhead "/* This is a generated file, do not edit directly */\n\n#include \"config.h\"\n#include <glib-object.h>\n#include \"gegl-gtk-enums.h\"" \
			--fprod "\n/* enumerations from \"@filename@\" */" \
			--vhead "GType\n@enum_name@_get_type (void)\n{\n  static GType etype = 0;\n  if (etype == 0) {\n	static const G@Type@Value values[] = {" \
			--vprod "	  { @VALUENAME@, \"@valuenick@\", \"@valuenick@\" }," \
			--vtail "	  { 0, NULL, NULL }\n	};\n	etype = g_@type@_register_static (\"@EnumName@\", values);\n  }\n  return etype;\n}\n\n" \
			$(srcdir)/gegl-gtk-enums.h > gegl-gtk-enums.c \
	)

gegl-gtk-marshal.h: stamp-gegl-gtk-marshal.h
	@true

stamp-gegl-gtk-marshal.h: gegl-gtk-marshal.list Makefile
	$(AM_V_GEN) ( \
		( glib-genmarshal \
			--prefix=gegl_gtk_marshal \
			--header $(srcdir)/gegl-gtk-marshal.list \
		) >> xgen-gmh \
		&& ( cmp -s xgen-gmh gegl-gtk-marshal.h || cp xgen-gmh gegl-gtk-marshal.h ) \
		&& rm -f xgen-gmh \
		&& echo timestamp > $(@F) \
	)

gegl-gtk-marshal.c: gegl-gtk-marshal.list gegl-gtk-marshal.h Makefile
	$(AM_V_GEN) ( \
		echo "#include \"gegl-gtk-marshal.h\"" > xgen-gmc \
		&& ( glib-genmarshal \
			--prefix=gegl_gtk_marshal \
			--body $(srcdir)/gegl-gtk-marshal.list \
		   ) >> xgen-gmc \
		&& cp xgen-gmc gegl-gtk-marshal.c \
		&& rm -f xgen-gmc \
	)

photos-about-data.h: stamp-photos-about-data.h
	@true

stamp-photos-about-data.h: $(top_srcdir)/ARTISTS $(top_builddir)/AUTHORS
	$(AM_V_GEN) ( \
		( $(srcdir)/photos-generate-about \
			--header $(top_builddir) $(top_srcdir) \
                ) >> xgen-ah \
		&& ( cmp -s xgen-ah photos-about-data.h || cp xgen-ah photos-about-data.h ) \
		&& rm -f xgen-ah \
		&& echo timestamp > $(@F) \
	)

photos-about-data.c: $(top_srcdir)/ARTISTS $(top_builddir)/AUTHORS
	$(AM_V_GEN) ( \
		echo "#include \"photos-about-data.h\"" > xgen-ac \
		&& ( $(srcdir)/photos-generate-about \
			--body $(top_builddir) $(top_srcdir) \
                   ) >> xgen-ac \
		&& ( cmp -s xgen-ac photos-about-data.c || cp xgen-ac photos-about-data.c ) \
		&& rm -f xgen-ac \
	)

photos-enums.h: stamp-photos-enums.h
	@true

stamp-photos-enums.h: photos-enums.h.template
	$(AM_V_GEN) ( \
		( glib-mkenums \
			--template $(srcdir)/photos-enums.h.template \
                        $(srcdir)/photos-mode-controller.h \
                ) >> xgen-etbh \
		&& ( cmp -s xgen-etbh photos-enums.h || cp xgen-etbh photos-enums.h ) \
		&& rm -f xgen-etbh \
		&& echo timestamp > $(@F) \
	)

photos-enums.c: photos-enums.c.template
	$(AM_V_GEN) ( \
		( glib-mkenums \
			--template $(srcdir)/photos-enums.c.template \
                        $(srcdir)/photos-mode-controller.h \
                ) >> xgen-etbc \
		&& ( cmp -s xgen-etbc photos-enums.c || cp xgen-etbc photos-enums.c ) \
		&& rm -f xgen-etbc \
	)

photos-marshalers.h: stamp-photos-marshalers.h
	@true

stamp-photos-marshalers.h: photos-marshalers.list Makefile
	$(AM_V_GEN) ( \
		( glib-genmarshal \
			--prefix=_photos_marshal \
			--header $(srcdir)/photos-marshalers.list \
		) >> xgen-tmh \
		&& ( cmp -s xgen-tmh photos-marshalers.h || cp xgen-tmh photos-marshalers.h ) \
		&& rm -f xgen-tmh \
		&& echo timestamp > $(@F) \
	)

photos-marshalers.c: photos-marshalers.list photos-marshalers.h Makefile
	$(AM_V_GEN) ( \
		echo "#include \"photos-marshalers.h\"" > xgen-tmc \
		&& ( glib-genmarshal \
			--prefix=_photos_marshal \
			--body $(srcdir)/photos-marshalers.list \
		   ) >> xgen-tmc \
		&& cp xgen-tmc photos-marshalers.c \
		&& rm -f xgen-tmc \
	)

photos-resources.c: photos.gresource.xml $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(srcdir)/photos.gresource.xml)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --target=$@ \
		--c-name photos \
		--sourcedir=$(srcdir) \
		--generate-source \
		$<

photos-resources.h: photos.gresource.xml $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(srcdir)/photos.gresource.xml)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --target=$@ \
		--c-name photos \
		--sourcedir=$(srcdir) \
		--generate-header \
		$<

photos-dleyna-renderer-device.h photos-dleyna-renderer-device.c: photos-dleyna-renderer-device.xml
	$(AM_V_GEN)gdbus-codegen \
		--c-namespace Dleyna \
		--generate-c-code photos-dleyna-renderer-device \
		--interface-prefix com.intel.dLeynaRenderer. \
		--annotate 'com.intel.dLeynaRenderer.RendererDevice.GetIcon()[Bytes]' org.gtk.GDBus.C.ForceGVariant true \
		$<

photos-dleyna-renderer-manager.h photos-dleyna-renderer-manager.c: photos-dleyna-renderer-manager.xml
	$(AM_V_GEN)gdbus-codegen \
		--c-namespace Dleyna \
		--generate-c-code photos-dleyna-renderer-manager \
		--interface-prefix com.intel.dLeynaRenderer. \
		$<

photos-dleyna-renderer-push-host.h photos-dleyna-renderer-push-host.c: photos-dleyna-renderer-push-host.xml
	$(AM_V_GEN)gdbus-codegen \
		--c-namespace Dleyna \
		--generate-c-code photos-dleyna-renderer-push-host \
		--interface-prefix com.intel.dLeynaRenderer. \
		$<

photos-gom-miner.h photos-gom-miner.c: photos-gom-miner.xml
	$(AM_V_GEN)gdbus-codegen \
		--c-namespace Gom \
		--generate-c-code photos-gom-miner \
		--interface-prefix org.gnome.OnlineMiners. \
		$<

photos-mpris-player.h photos-mpris-player.c: photos-mpris-player.xml
	$(AM_V_GEN)gdbus-codegen \
		--c-namespace Mpris \
		--generate-c-code photos-mpris-player \
		--interface-prefix org.mpris.MediaPlayer2. \
		$<

photos-shell-search-provider2.h photos-shell-search-provider2.c: org.gnome.ShellSearchProvider2.xml Makefile
	$(AM_V_GEN)gdbus-codegen \
		--c-namespace Shell \
		--generate-c-code photos-shell-search-provider2 \
		--interface-prefix org.gnome.Shell. \
		$<

photos-tracker-resources.h photos-tracker-resources.c: photos-tracker-resources.xml
	$(AM_V_GEN)gdbus-codegen \
		--c-namespace Tracker \
		--generate-c-code photos-tracker-resources \
		--interface-prefix org.freedesktop.Tracker1. \
		$(srcdir)/photos-tracker-resources.xml

-include $(top_srcdir)/git.mk
