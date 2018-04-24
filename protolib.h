#include <gtk-3.0/gtk/gtk.h>


// -----------------  Initialisations -----------------


typedef struct{
    GtkWidget * name;
    GtkWidget * surname;
    GtkWidget * birthday;
    GtkWidget * birthplace;
    GtkWidget * residency;
    GtkWidget * emailAdress;
    GtkWidget * phoneNumber;
    GtkWidget * workInfo;
    GtkWidget * iban;
    GtkWidget * workplace;
}employee;


// -----------------  Prototypes de fonctions -----------------

void windowDeletion();

void closeWindow();

void buttonClick(GtkButton * button1, employee * rawData);

