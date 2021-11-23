#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder *gtkBuilder;
    GtkWidget *window1, *overskrift, *tekst_krypt, *tekst_dinkrypt, *ec_input, *tekst_dekrypt, *ec_output, *dc_input, *tekst_dindekrypt, *dc_output, *start;
    gtk_init(&argc, &argv);
    
    gtkBuilder = gtk_builder_new();
    gtk_builder_add_from_file(gtkBuilder, "UI_kryptering.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "window1"));
    overskrift = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "overskrift"));
    tekst_krypt = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_krypt"));
    ec_input = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "ec_input"));
    tekst_dekrypt = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_dekrypt"));
    ec_output = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "ec_output"));
    dc_input = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "dc_input"));
    tekst_dinkrypt = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_dinkrypt"));
    tekst_dindekrypt = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "tekst_dindekrypt"));
    dc_output = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "dc_output"));
    start = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "start"));

    
    g_object_unref(G_OBJECT(gtkBuilder));
    gtk_widget_show(window);
    gtk_main();
    
    return 0;
}