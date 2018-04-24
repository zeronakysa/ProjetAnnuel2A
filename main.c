#include <stdio.h>
#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>
#include "protolib.h"
#include "functions.c"



int main (int argc, char *argv[]) {
    GtkBuilder * builder;
    GtkWidget  * window1;
    employee * rawData;

    // A COMPRENDRE
    rawData = g_slice_new(employee);

    // Initialisation de GTK
    gtk_init(&argc, &argv);

    // Creation des widgets de l'interface a partir du fichier XML de Glade, grace au builder GTK
    builder = gtk_builder_new();

    if(gtk_builder_add_from_file(builder, "../uiPersonnel.glade", NULL) == 0){
        fprintf(stderr, "Erreur: ouverture du fichier GLADE\n");
        exit(EXIT_FAILURE);
    }

    // Connection des fonctions de rappel avec les signaux de l'interface
    gtk_builder_connect_signals(builder, rawData);

    // Recuperation du widget de la fenetre principale
    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

    // Récupération du type des donneés champs
    rawData->name = GTK_WIDGET(gtk_builder_get_object(builder, "nameEntry"));
    rawData->surname = GTK_WIDGET(gtk_builder_get_object(builder, "surnameEntry"));
    rawData->birthday = GTK_WIDGET(gtk_builder_get_object(builder, "birthdayEntry"));
    rawData->birthplace = GTK_WIDGET(gtk_builder_get_object(builder, "birthplaceEntry"));
    rawData->residency = GTK_WIDGET(gtk_builder_get_object(builder, "cityEntry"));
    rawData->emailAdress = GTK_WIDGET(gtk_builder_get_object(builder, "emailEntry"));
    rawData->phoneNumber = GTK_WIDGET(gtk_builder_get_object(builder, "phoneEntry"));
    rawData->workInfo = GTK_WIDGET(gtk_builder_get_object(builder, "workInfoEntry"));
    rawData->iban = GTK_WIDGET(gtk_builder_get_object(builder, "ibanEntry"));
    rawData->workplace = GTK_WIDGET(gtk_builder_get_object(builder, "workplaceEntry"));



    // Changement de la fenetre principale a l'etat visible
    gtk_widget_show(window1);

    // Lancement de l'execution de la boucle GTK et suppression du builder (déjà enregistré dans GTK)
    gtk_main();
    g_object_unref(G_OBJECT(builder));

    // Fin du programme
    return EXIT_SUCCESS;

}
