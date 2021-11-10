#include <gtk/gtk.h>

void end_program(GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit();
}

void main(int argc, char *argv[])
{
	GtkBuilder *gtkBuilder;
	GtkWidget *window, *btn1;
	gtk_init(&argc, &argv);
	GError *err = NULL;
	
	gtkBuilder = gtk_builder_new();
	if(0 == gtk_builder_add_from_file (gtkBuilder, "UI_kryptering.glade", &err))
	{
		/* Printer fejlen ud i konsollen */
		fprintf(stderr, "Fejl i indlæsning af layout-fil. Fejl: %s\n", err->message);
		/* Evt håndtering af fejl her */
	}
	
	window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "window1"));
	
	btn1 = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "start"));
	g_signal_connect(btn1, "clicked", G_CALLBACK(end_program), NULL);
	g_object_unref(G_OBJECT(gtkBuilder));
	gtk_widget_show(window);
	gtk_main();
	
	
}
