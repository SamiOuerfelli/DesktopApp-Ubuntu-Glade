#ifndef RECLAMATION_H_INCLUDED
#define RECLAMATION_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
#include<string.h>

enum{
IDL,
NUM_B,
NOM_L,
TYPE,
OBJET,
TEXT,
COLUMNS_R
};

enum{
	EIDLIST,
	ENBVOTESS,
	ECOLUMNSS,
};



typedef struct
{ 
  char type[20];
  char nom_list[20];
char num_bur[20];
char id_list[20];
  char objet[20];
  char text[1000];
} reclamation ;

typedef struct 
{
	char id[20];
	int nombre ;
}ReclamationListe;



void ajouter_rec(reclamation rec);
void afficher_reclamation(GtkWidget *liste);
int supprimer_reclamation( char IDENT_LIST[]);
int Chercher_reclamation(GtkWidget *liste,char*r,char*ident);
void modifier_reclamation(reclamation nouv);

void nombreReclListe(GtkWidget *liste);
int nbTotal(char *filename);





#endif // RECLAMATION_H_INCLUDED
