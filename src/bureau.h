#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <gtk/gtk.h>

typedef struct 
{
char id_b[20];
char cap_elec[20];
char cap_obs[20];
char b_adr[20];
char salle[20];
char id_agentb[20];
} bureau ;


void ajouter_bureau(bureau);
void modifier_bureau(bureau);
void supprimer_bureau(char *);
void afficher_bureau(GtkWidget *liste);
int exist_bureau(char*id);
int Chercherbureau(GtkWidget *,char *,char *id);
int modif_bureau_exist(bureau p);
int taux_obsertn(char *filename);
int taux_obser(char *filename);
#endif

