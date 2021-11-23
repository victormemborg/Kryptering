#include <gtk/gtk.h>
#include <stdio.h>

GtkWidget *window1_, *overskrift_, *tekst_krypt_, *tekst_dinkrypt_, *ec_input_, *tekst_dekrypt_, *ec_output_, *dc_input_, *tekst_dindekrypt_, *dc_output_, *start_, *gtk_box_;

char *ec_input_text;
char *dc_input_text;

static void check (void)
{
  ec_input_text = gtk_entry_get_text (GTK_ENTRY (ec_input_));
  dc_input_text = gtk_entry_get_text (GTK_ENTRY (dc_input_));

  if(ec_input_text != NULL)
  {
    encrypt();
  }
  if(dc_input_text != NULL)
  {
    decrypt();
  }

}

void encrypt()
{
  ec_input_text = gtk_entry_get_text (GTK_ENTRY (ec_input_));
  char ch;
  int i, key;
  key = 8;

  for(i = 0; ec_input_text[i] != '\0'; ++i)
  {
    ch = ec_input_text[i];
    if(ch >= 'a' && ch <= 'z')
    {
      ch = ch + key;
      if(ch > 'z')
      {
        ch = ch - 'z' + 'a' - 1;
      }
      ec_input_text[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z')
    {
      ch = ch + key;
      if(ch > 'Z')
      {
        ch = ch - 'Z' + 'A' - 1;
      }
      ec_input_text[i] = ch;
    }
  }
  gtk_label_set_text(GTK_LABEL(ec_output_), ec_input_text);
}

void decrypt()
{
  dc_input_text = gtk_entry_get_text (GTK_ENTRY (dc_input_));
  int i, key;
  char ch;
  key = 8;
  for(i = 0; dc_input_text[i] != '\0'; ++i)
  {
    ch = dc_input_text[i];
    if(ch >= 'a' && ch <= 'z')
    {
      ch = ch - key;
      if(ch < 'a')
      {
        ch = ch + 'z' - 'a' + 1;
      }
      dc_input_text[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z')
    {
      ch = ch - key;
      if(ch < 'A')
      {
        ch = ch + 'Z' - 'A' + 1;
      }
      dc_input_text[i] = ch;
    }
  }
  gtk_label_set_text(GTK_LABEL(dc_output_), dc_input_text);
}

void end_program(GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit();
}

void main(int argc, char *argv[])
{
	GtkBuilder *gtkBuilder;
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
  g_signal_connect(start_, "clicked", G_CALLBACK(check), NULL);
	gtk_widget_show(window1_);
	gtk_main();
	
	
}


