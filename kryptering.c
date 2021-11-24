//Importere relavante libraries
#include <gtk/gtk.h>
#include <stdio.h>

//Vi spærrer plads i hukommelsen til vores gtk widgets
GtkWidget *window1_, *overskrift_, *tekst_krypt_, *tekst_dinkrypt_, *ec_input_, *tekst_dekrypt_, *ec_output_, *dc_input_, *tekst_dindekrypt_, *dc_output_, *start_, *gtk_box_;

//Deklarere vores input variabler som characters
char *ec_input_text;
char *dc_input_text;

//Definerer check-funktionen som skal køre hver gang startknappen bliver aktiveret
static void check (void)
{
  //Her tager vi brugerens input fra tekstfelterne og lægger det i variablerne
  ec_input_text = gtk_entry_get_text (GTK_ENTRY (ec_input_));
  dc_input_text = gtk_entry_get_text (GTK_ENTRY (dc_input_));

  //Tjekker om der skal krypteres eller dekrypteres
  if(ec_input_text != NULL)
  {
    encrypt();
  }
  if(dc_input_text != NULL)
  {
    decrypt();
  }

}

//krypterings-funktion (Caesar)
void encrypt()
{
  //Tager input fra tekstfelt og indsætter i variabel
  ec_input_text = gtk_entry_get_text (GTK_ENTRY (ec_input_));
  //Definerer variabler
  char ch;
  int i, key;
  //Vi definerer key'en, som bestemmer hvor mange bogstaver der skal rykkes frem
  key = 8;

  //Starter et for-loop
  for(i = 0; ec_input_text[i] != '\0'; ++i)
  {
    //Sætter brugerinput lig "ch"
    ch = ec_input_text[i];
    //Tjekker om input er indenfor alfabetet
    if(ch >= 'a' && ch <= 'z')
    {
      //Lægger key's værdi til ch's talværdi
      ch = ch + key;
      //Tjekker om den nye ch er indenfor alfabetet
      if(ch > 'z')
      {
        //Hvis ch er ude for alfabetet, trækkes 25 fra ch, dermed er ch sat tilbage til "a"
        ch = ch - 'z' + 'a';
      }
      //Redifinerer vores input til den nye krypterede tekst
      ec_input_text[i] = ch;
    }
    //Samme som nævnt ovenover, bare med store tal
    else if(ch >= 'A' && ch <= 'Z')
    {
      ch = ch + key;
      if(ch > 'Z')
      {
        ch = ch - 'Z' + 'A';
      }
      ec_input_text[i] = ch;
    }
  }
  //sætter label til den krypterede tekst
  gtk_label_set_text(GTK_LABEL(ec_output_), ec_input_text);
}

//Dekrypterings-funktion
void decrypt()
{
  //Tager input fra tekstfelt og indsætter i variabel
  dc_input_text = gtk_entry_get_text (GTK_ENTRY (dc_input_));
  //Definerer variabler
  int i, key;
  char ch;
  //Vi definerer key'en, som bestemmer hvor mange bogstaver der skal rykkes tilbage
  key = 8;

  //Starter et for-loop
  for(i = 0; dc_input_text[i] != '\0'; ++i)
  {
    //Sætter brugerinput lig "ch"
    ch = dc_input_text[i];
    //Tjekker om input er indenfor alfabetet
    if(ch >= 'a' && ch <= 'z')
    {
      //trækker key's værdi fra ch's talværdi
      ch = ch - key;
        //Tjekker om den nye ch er indenfor alfabetet
      if(ch < 'a')
      {
        //Hvis ch er ude for alfabetet, lægges 25 til ch, dermed er ch sat tilbage til "z"
        ch = ch + 'z' - 'a';
      }
      //Redifinerer vores input til den nye dekrypterede tekst
      dc_input_text[i] = ch;
    }
    //Samme som nævnt ovenover, bare med store tal
    else if(ch >= 'A' && ch <= 'Z')
    {
      ch = ch - key;
      if(ch < 'A')
      {
        ch = ch + 'Z' - 'A';
      }
      dc_input_text[i] = ch;
    }
  }
  //sætter label til den dekrypterede tekst
  gtk_label_set_text(GTK_LABEL(dc_output_), dc_input_text);
}

//definere funktion til at afslutte programmet
void end_program(GtkWidget *wid, gpointer ptr)
{
	gtk_main_quit();
}

//Main
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

  //Initialiserer vores widgets 
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
  //Får aktivering af knappen til at kalde check-funktionen
  g_signal_connect(start_, "clicked", G_CALLBACK(check), NULL);
  //Åbner vinduet
	gtk_widget_show(window1_);
  //Main kalder sig selv
	gtk_main();
}


