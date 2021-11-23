#include <gtk/gtk.h>

/*gcc -o nytest2.exe gtk_glade.c -mms-bitfields -IC:/gtk3/include/gtk-3.0 -IC:/gtk3/include/cairo -IC:/gtk3/include/pango-1.0 -IC:/gtk3/include/atk-1.0 -IC:/gtk3/include/cairo -IC:/gtk3/include/pixman-1 -IC:/gtk3/include -IC:/gtk3/include/freetype2 -IC:/gtk3/include -IC:/gtk3/include/libpng15 -IC:/gtk3/include/gdk-pixbuf-2.0 -IC:/gtk3/include/libpng15 -IC:/gtk3/include/glib-2.0 -IC:/gtk3/lib/glib-2.0/include -LC:/gtk3/lib -lgtk-3 -lgdk-3 -lgdi32 -limm32 -lshell32 -lole32 -Wl,-luuid -lpangocairo-1.0 -lpangoft2-1.0 -lfreetype -lfontconfig -lpangowin32-1.0 -lgdi32 -lpango-1.0 -lm -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0 */
void end_program(GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit();
}

void main(int argc, char *argv[])
{
	GtkBuilder *gtkBuilder;
	GtkWidget *window1_, *overskrift_, *tekst_krypt_, *tekst_dinkrypt_, *ec_input_, *tekst_dekrypt_, *ec_output_, *dc_input_, *tekst_dindekrypt_, *dc_output_, *start_, *gtk_box_;
	gtk_init(&argc, &argv);
	GError *err = NULL;
	
	gtkBuilder = gtk_builder_new();
	if(0 == gtk_builder_add_from_file (gtkBuilder, "UI_kryptering.glade", &err))
	{
		/* Printer fejlen ud i konsollen */
		fprintf(stderr, "Fejl i indlæsning af layout-fil. Fejl: %s\n", err->message);
		/* Evt håndtering af fejl her */
	}
	
    window1_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "window1"));
    overskrift_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "overskrift"));
    tekst_krypt_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_krypt"));
    ec_input_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "ec_input"));
    tekst_dekrypt_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_dekrypt"));
    ec_output_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "ec_output"));
    dc_input_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "dc_input"));
    tekst_dinkrypt_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_dinkrypt"));
    tekst_dindekrypt_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_dindekrypt"));
    dc_output_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "dc_output"));
    start_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "start"));
    gtk_box_ = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "gtk_box"));

	g_object_unref(G_OBJECT(gtkBuilder));
	gtk_widget_show(window1_);
	gtk_main();
	
	
}
