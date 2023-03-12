#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
typedef struct{
int jour ; 
int mois ; 
int annee;
}Date;
typedef struct {
char id[50];
Date date;
char Municipalite[50];
char NbrH[30];
char NbrC[30];
}election;



enum
{
ID,
MUNICIPALITE2,
NOMBRE_HABITANT,
NOMBRE_CONSEILLER,
JOUR2,
MOIS2,
ANNEE2,
COLUMNS3
};


void ajouter(election e );
void Afficher_ele(GtkWidget *liste);
void supprimer_election(char*id);
election chercher_id(char id0[]);
int chercher_Avance(char cherch[], char champliste[]);
void treeview_chercher(GtkWidget *liste,char iden[]);

#endif
