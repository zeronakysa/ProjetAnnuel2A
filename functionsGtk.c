#include "protoGtk.h"

// -----------------  Fonctions -----------------

void windowsDeletion(){
    gtk_main_quit();
}

void closeWindows(){
    gtk_main_quit();
}

void buttonClick(GtkButton * button1, employee * rawData){
    // On a récupéré le type de données, on récupère le contenu maintenant
    // On met en constante car pas amené à être modifié, et code plus sécurisé

    const char * name = gtk_entry_get_text(GTK_ENTRY(rawData->name));
    const char * surname = gtk_entry_get_text(GTK_ENTRY(rawData->surname));
    const char * birthday = gtk_entry_get_text(GTK_ENTRY(rawData->birthday));
    const char * birthplace = gtk_entry_get_text(GTK_ENTRY(rawData->birthplace));
    const char * residency = gtk_entry_get_text(GTK_ENTRY(rawData->residency));
    const char * emailAdress = gtk_entry_get_text(GTK_ENTRY(rawData->emailAdress));
    const char * phoneNumber = gtk_entry_get_text(GTK_ENTRY(rawData->phoneNumber));
    const char * workInfo = gtk_entry_get_text(GTK_ENTRY(rawData->workInfo));
    const char * iban = gtk_entry_get_text(GTK_ENTRY(rawData->iban));
    const char * workplace = gtk_entry_get_text(GTK_ENTRY(rawData->workplace));

    printf("%s\n", name);
    printf("%s\n", surname);
    printf("%s\n", birthday);
    printf("%s\n", birthplace);
    printf("%s\n", residency);
    printf("%s\n", emailAdress);
    printf("%s\n", phoneNumber);
    printf("%s\n", workInfo);
    printf("%s\n", workplace);
}
