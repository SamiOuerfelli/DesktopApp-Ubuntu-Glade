#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <stdio.h>
#include <gtk/gtk.h>




typedef struct
{  int jour;
    int mois;
    int annee;
}d_d;


typedef struct
{   char id_CIN[10];
    char nom[20];
    char prenom[20];
    char nationalite[20];
    d_d d_d_n;
    char sexe[6];
    char num_tel[10];
    char adresse_mail[50];
    char role[30];
    char num_bureau[3];
    char profession[20];
    char vote[3];
}coord;


typedef struct
{
    char login[10];
    char mdp[5];
}lg;



void salma_ajouter (coord P);
void salma_supprimer ( char *id);
void salma_modifier ( char *id,coord nouv);
int salma_chercher (GtkWidget *liste, char *l,char *id);

void salma_afficher (GtkWidget *liste);
void salma_afficher_util (GtkWidget *liste);
void salma_afficher_obv (GtkWidget *liste);

int nbr_tot_obv();
void trier_obv ();
void trier_util ();


void generation_acces(coord P);
void choix_vote (int choix, char vote[]);

#endif // FUNCTION_H_INCLUDED


