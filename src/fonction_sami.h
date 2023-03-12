#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>

enum
{
MUNICIPALITE,
NOM_LISTE, 
NUM_LISTE, 
ID_LISTE,
IDTTLISTE,
CANDIDAT1, 
CANDIDAT2, 
CANDIDAT3,
JOUR,
MOIS,
ANNEE,
NBR_VOTE,
COLUMNS 
};
enum
{NOM_LISTE2, 
NUM_LISTE2, 
NBR_VOTE2,
COLUMNS2
};




typedef struct Date
{
int j;
int m;
int a;
}date;

typedef struct listElec
{

char municipalite [50];
char nomListe[50] ;
char numListe[50] ;
char idenListe [50] ;
char idenTeteliste [50];
char candidat1 [50];
char candidat2 [50];
char candidat3 [50];
date d;
int nbV;
} listelec;


int ajouter_liste(listelec L );
int det_numliste (listelec L) ;
int modifier_liste( listelec nouv , char numliste[] );
int supprimer_liste( char nomliste[]);
void afficher_liste (GtkWidget *liste);
listelec chercher_liste(char Nomliste[]);
void treeview_sami_rechercher_municip(GtkWidget *liste,char municipalite[]);
void treeview_sami_rechercher_nl (GtkWidget *liste,char nomliste[]);
int sami_recherche_adv(char cherch[], char champliste[]);
int verifier_existant_NL (char nomliste[]);
int verifier_existant_IdL (char idenliste[]);
int verifier_existant_IdTL (char identeteliste[]);
int verifier_existant_id1 (char Candidat1[]);
int verifier_existant_id2 (char Candidat2[]);
int verifier_existant_id3 (char Candidat3[]);
int vote (char liste_vote[]) ;
int verifierModC(char candidat[],char NomListe[]  );
int verifierModNL(char nomliste[] , char NomListe[] );
void trier_decroissant(char *liste );
void trier_croissant(char *liste );
void afficher_liste_trier (GtkWidget *liste);
void create_fichier_aff ( char *liste);




#endif // FONCTION_H_INCLUDED

