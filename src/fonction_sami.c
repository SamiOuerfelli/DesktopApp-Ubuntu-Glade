#include<stdio.h>
#include "fonction_sami.h"
#include <gtk/gtk.h>
#include<string.h>




int ajouter_liste(listelec L )
{
    FILE * f=fopen("liste.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,L.d.j,L.d.m,L.d.a,L.nbV) ;
        fclose(f);
        return 1;
    }
    else return 0;
}

//***************************************************
int supprimer_liste( char nomliste[])
{
    int tr=0;
listelec L;
    FILE * f=fopen("liste.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    
    if(f!=NULL && f2!=NULL )
    {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
        {
            if( strcmp(nomliste,L.nomListe)==0 )
                tr=1;
            else
			 fprintf(f2,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,L.d.j,L.d.m,L.d.a,L.nbV) ;
        } }    
    fclose(f);
    fclose(f2);
  

    remove("liste.txt");
    rename("nouv.txt", "liste.txt");
	

return tr;
}
//**************************************

int det_numliste (listelec L)
{

  FILE *f;

  int nbline=0;

  f= fopen("liste.txt","r");

  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {
        nbline=nbline+1;

      }
      fclose(f);
    }
return nbline ;
}

//**********************************
int verifier_existant_IdL(char idenliste[])
{
  int verif =-1;
  listelec tableau[100];
listelec L;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");

  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {
        nbline ++;
        tableau[i]=L;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(idenliste, tableau[i].idenListe) == 0)
        {
          verif = 0; 
          break;
        }
      else
      {
        verif =1; 
      }
    }
  return verif;
}
//**********************************
int verifier_existant_NL(char nomliste[])
{
  int verif =-1;
  listelec tableau[100];
listelec L;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");

  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {
        nbline ++;
        tableau[i]=L;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(nomliste, tableau[i].nomListe) == 0)
        {
          verif = 0;
          break;
        }
      else
      {
        verif =1;
      }
    }
  return verif;
}
//***************************************
int verifier_existant_IdTL(char identetetiste[])
{
  int verif =-1;
  listelec tableau[100];
listelec L;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");

  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {
        nbline ++;
        tableau[i]=L;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(identetetiste, tableau[i].idenTeteliste) == 0)
        {
          verif = 0; 
          break;
        }
      else
      {
        verif =1; 
      }
    }
  return verif;
}
//******************************************
int verifier_existant_id1(char Candidat1[])
{
  int verif =-1;
  listelec tableau[100];
listelec L;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");

  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {
        nbline ++;
        tableau[i]=L;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(Candidat1, tableau[i].candidat1) == 0)
        {
          verif = 0; 
          break;
        }
      else
      {
        verif =1; 
      }
    }
  return verif;
}
//**************************************
int verifier_existant_id2(char Candidat2[])
{
  int verif =-1;
  listelec tableau[100];
listelec L;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");

  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {
        nbline ++;
        tableau[i]=L;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(Candidat2, tableau[i].candidat2) == 0)
        {
          verif = 0; 
          break;
        }
      else
      {
        verif =1; 
      }
    }
  return verif;
}
//*******************************************
int verifier_existant_id3(char Candidat3[])
{
  int verif =-1;
  listelec tableau[100];
listelec L;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");

  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {
        nbline ++;
        tableau[i]=L;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(Candidat3, tableau[i].candidat3) == 0)
        {
          verif = 0; 
          break;
        }
      else
      {
        verif =1; 
      }
    }
  return verif;
}

//*****************************************

void afficher_liste (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


char municipalite [20];
char nom_liste [20];
char num_liste [20];
char id_liste[20];
char id_tete_liste[20] ;
char candidat1 [20];
char candidat2 [20];
char candidat3 [20];
int jour , mois , annee , nbr_vote ;
store = NULL;
FILE *f ;
store = gtk_tree_view_get_model(liste) ;
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("MUNICIPALITÉ",renderer,"text",MUNICIPALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("NOM LISTE",renderer,"text",NOM_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("NUMÉRO LISTE",renderer,"text",NUM_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID LISTE",renderer,"text",ID_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID TÊTE LISTE",renderer,"text",IDTTLISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 1",renderer,"text",CANDIDAT1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 2",renderer,"text",CANDIDAT2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 3",renderer,"text",CANDIDAT3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Jour d'ajout ",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Mois d'ajout ",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Année d'ajout ",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("N°vote ",renderer,"text",NBR_VOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);



store = gtk_list_store_new(COLUMNS, G_TYPE_STRING , G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);

f=fopen("liste.txt","r");

if (f!=NULL)
{
f=fopen("liste.txt","a+");

while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d",municipalite,nom_liste,num_liste,id_liste,id_tete_liste,candidat1,candidat2,candidat3,&jour,&mois,&annee,&nbr_vote)!=EOF)
	{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set (store,&iter,MUNICIPALITE,municipalite,NOM_LISTE,nom_liste,NUM_LISTE,num_liste,ID_LISTE,id_liste,IDTTLISTE,id_tete_liste,CANDIDAT1,candidat1,CANDIDAT2,candidat2,CANDIDAT3,candidat3,JOUR,jour,MOIS,mois,ANNEE,annee,NBR_VOTE,nbr_vote,-1);

	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste) , GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}

//**************************************************
int modifier_liste( listelec nouv , char numliste[] )
{
    int tr=0;
    listelec L;
    FILE * f=fopen("liste.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    
    if(f!=NULL && f2!=NULL )
    {

        while(fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
        {
            if (strcmp(numliste,L.numListe)==0)
            {
               fprintf(f2,"%s %s %s %s %s %s %s %s %d %d %d %d \n",nouv.municipalite,nouv.nomListe,L.numListe,L.idenListe,L.idenTeteliste,nouv.candidat1,nouv.candidat2,nouv.candidat3,nouv.d.j,nouv.d.m,nouv.d.a,L.nbV) ; ;

                tr=1;
            }
            else
              fprintf(f2,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,L.d.j,L.d.m,L.d.a,L.nbV) ;
		

        }
    }
    fclose(f);
    fclose(f2);
   

    remove("liste.txt");
    rename("nouv.txt", "liste.txt");

    return tr;}
//****************************************************
listelec chercher_liste(char NomListe[])
{
    listelec E,L;
    FILE * f=fopen("liste.txt", "r");
    if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
        {

            if(strcmp(L.nomListe,NomListe)==0)
   	 return L;
        }
     fclose(f);
}
       strcpy(E.nomListe,"");
    return E;

}
//****************************************************
void treeview_sami_rechercher_municip(GtkWidget *liste,char municipalite[])
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


listelec L;
store = NULL;
FILE *f ;
store = gtk_tree_view_get_model(liste) ;


if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("MUNICIPALITÉ",renderer,"text",MUNICIPALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("NOM LISTE",renderer,"text",NOM_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("NUMÉRO LISTE",renderer,"text",NUM_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID LISTE",renderer,"text",ID_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID TÊTE LISTE",renderer,"text",IDTTLISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 1",renderer,"text",CANDIDAT1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 2",renderer,"text",CANDIDAT2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 3",renderer,"text",CANDIDAT3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Jour d'ajout ",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Mois d'ajout ",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Année d'ajout ",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("N°vote ",renderer,"text",NBR_VOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}

store = gtk_list_store_new(COLUMNS, G_TYPE_STRING , G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);


f=fopen("liste.txt","r");


if (f!=NULL)
{

while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF) 
{
if (sami_recherche_adv(municipalite, L.municipalite))
{
gtk_list_store_append(store, &iter);

gtk_list_store_set (store,&iter,MUNICIPALITE,L.municipalite,NOM_LISTE,L.nomListe,NUM_LISTE,L.numListe,ID_LISTE,L.idenListe,IDTTLISTE,L.idenTeteliste,CANDIDAT1,L.candidat1,CANDIDAT2,L.candidat2,CANDIDAT3,L.candidat3,JOUR,L.d.j,MOIS,L.d.m,ANNEE,L.d.a,NBR_VOTE,L.nbV,-1);
}
}

fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}



}



//****************************************************

int sami_recherche_adv(char cherch[], char champliste[]){
	int c1,c2,i,cmp = 0;
	c1 = strlen(cherch);
	c2= strlen(champliste);
	if (c1<=c2){
	for (i=0;i<c1;i++){
		if (cherch[i] == champliste[i]){
			cmp +=1;			
}
	}
	if (cmp == c1){
		return 1;
	}else{
		return 0;
	}
}else{
	return 0;
}
}


//****************************************
void treeview_sami_rechercher_nl (GtkWidget *liste,char nomliste[])

{GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


listelec L;
store = NULL;
FILE *f ;
store = gtk_tree_view_get_model(liste) ;


if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("MUNICIPALITÉ",renderer,"text",MUNICIPALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("NOM LISTE",renderer,"text",NOM_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("NUMÉRO LISTE",renderer,"text",NUM_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID LISTE",renderer,"text",ID_LISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID TÊTE LISTE",renderer,"text",IDTTLISTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 1",renderer,"text",CANDIDAT1,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 2",renderer,"text",CANDIDAT2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("ID CANDIDAT 3",renderer,"text",CANDIDAT3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Jour d'ajout ",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Mois d'ajout ",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("Année d'ajout ",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column =gtk_tree_view_column_new_with_attributes ("N°vote ",renderer,"text",NBR_VOTE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}

store = gtk_list_store_new(COLUMNS, G_TYPE_STRING , G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);


f=fopen("liste.txt","r");


if (f!=NULL)
{

while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF) 
{
if (sami_recherche_adv(nomliste, L.nomListe))
{
gtk_list_store_append(store, &iter);

gtk_list_store_set (store,&iter,MUNICIPALITE,L.municipalite,NOM_LISTE,L.nomListe,NUM_LISTE,L.numListe,ID_LISTE,L.idenListe,IDTTLISTE,L.idenTeteliste,CANDIDAT1,L.candidat1,CANDIDAT2,L.candidat2,CANDIDAT3,L.candidat3,JOUR,L.d.j,MOIS,L.d.m,ANNEE,L.d.a,NBR_VOTE,L.nbV,-1);
}
}

fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}



}


//***************************
	

int vote (char liste_vote[])
{ 
int tr=0;

listelec L ,nouv; 
 FILE * f=fopen("liste.txt", "r");
 FILE * f2=fopen("nouv.txt", "w");
 if(f!=NULL && f2!=NULL ){
 while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
	{
		if (strcmp(liste_vote,L.numListe)==0 )
		{ L.nbV++;
		   nouv.nbV = L.nbV ;
		   fprintf(f2,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,L.d.j,L.d.m,L.d.a,L.nbV) ;
			tr = 1 ;
		}

          
            else
              fprintf(f2,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,L.d.j,L.d.m,L.d.a,L.nbV) ;
		
	}}


    fclose(f);
    fclose(f2);
    remove("liste.txt");
    rename("nouv.txt", "liste.txt");

return tr;}

//*******************************************************
int verifierModNL(char nomliste[] , char NomListe[] )
{
  int verif =-1;
  listelec tableau[100];
listelec L,E;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");
E=chercher_liste(NomListe);
  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {

	if (strcmp(L.nomListe,E.nomListe)!=0)
        {nbline ++;
	tableau[i]=L;
        i++;}
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(nomliste, tableau[i].nomListe) == 0)
        {
          verif = 0; //Existant
          break;
        }
      else
      {
        verif =1; //inÃ©xistant
      }
    }
  return verif;
}







int verifierModC(char candidat[],char NomListe[]  )
{
  int verif =-1;
  listelec tableau[100];
listelec L,E;
  FILE *f;

  int nbline=0, i=0;

  f= fopen("liste.txt","r");
E=chercher_liste(NomListe);
  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF)
      {

	if (strcmp(L.candidat1,E.candidat1)!=0||strcmp(L.candidat2,E.candidat2)!=0||strcmp(L.candidat3,E.candidat3)!=0)
        {nbline ++;
        tableau[i]=L;
        i++;}
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if ((strcmp(candidat, tableau[i].candidat1) == 0)||(strcmp(candidat, tableau[i].candidat2) == 0)||(strcmp(candidat, tableau[i].candidat3) == 0))
        {
          verif = 0; //Existant
          break;
        }
      else
      {
        verif =1; //inÃ©xistant
      }
    }
  return verif;
}
//*********************************************

void trier_decroissant(char *liste )
{
   
    FILE *f=fopen("liste_aff.txt","r");
     listelec tab[50],L, aux;
     int i,j,k,max,p;
      i=0;
    
    if (f!=NULL)
    {

        while (fscanf(f,"%s %s  %d \n",L.nomListe,L.numListe,&L.nbV)!=EOF)
             {
            tab[i]=L;
	    i++; 
	     }
   }
 

// tri tableau
     for (j=0;j<i-1;j++)
     {
     	max=j;
     	 for (k=j+1;k<i;k++) // Recherche du maximum en commençant à partir de l'indice i+1
		{
         if( ((tab[j]).nbV) < (tab[k].nbV))
         	max=k;
		}

           aux=tab[j];
           tab[j]=tab[max];
           tab[max]=aux;
           p=1;

         }

    
	FILE * f1=fopen("nouv.txt", "w");
	if( f1!=NULL)
	{
     for (j=0;j<i;j++)
	{
    fprintf(f1,"\n %s %s  %d \n",tab[j].nomListe,tab[j].numListe,tab[j].nbV);}}
   
fclose(f);
fclose(f1);
remove("liste_aff.txt");
rename("nouv.txt", "liste_aff.txt");
 //return p; 
}
//*****************************************


void trier_croissant(char *liste )
{
    
    FILE *f=fopen("liste_aff.txt","r");
     listelec tab[50],L, aux;
     int i,j,k,max,p;
      i=0;
    
    if (f!=NULL)
    {

        while (fscanf(f,"%s %s  %d \n",L.nomListe,L.numListe,&L.nbV)!=EOF)
             {
            tab[i]=L;
	    i++; 
	     }
   }
 

// tri tableau
     for (j=0;j<i-1;j++)
     {
     	max=j;
     	 for (k=j+1;k<i;k++) // Recherche du maximum en commençant à partir de l'indice i+1
		{
         if( ((tab[j]).nbV) > (tab[k].nbV))
         	max=k;
		}

           aux=tab[j];
           tab[j]=tab[max];
           tab[max]=aux;
           p=1;

         }

    
	FILE * f1=fopen("nouv.txt", "w");
	if( f1!=NULL)
	{
     for (j=0;j<i;j++)
	{
    fprintf(f1,"\n %s %s  %d \n",tab[j].nomListe,tab[j].numListe,tab[j].nbV);}}
   
fclose(f);
fclose(f1);
remove("liste_aff.txt");
rename("nouv.txt", "liste_aff.txt");
 //return p; 
}

//*****************************************

void afficher_liste_trier (GtkWidget *liste)
{
GtkCellRenderer *renderer2 ;
GtkTreeViewColumn *column2 ;
GtkTreeIter iter ;
GtkListStore *store2 ;



char nom_liste2 [20];
char num_liste2 [20];
int nbr_vote2 ;
store2 = NULL;
FILE *f ;
store2 = gtk_tree_view_get_model(liste) ;
if (store2==NULL)
{


renderer2 = gtk_cell_renderer_text_new();
column2 =gtk_tree_view_column_new_with_attributes ("NOM LISTE",renderer2,"text",NOM_LISTE2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column2);


renderer2 = gtk_cell_renderer_text_new();
column2 =gtk_tree_view_column_new_with_attributes ("NUMÉRO LISTE",renderer2,"text",NUM_LISTE2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column2);


renderer2 = gtk_cell_renderer_text_new();
column2 =gtk_tree_view_column_new_with_attributes ("N°vote ",renderer2,"text",NBR_VOTE2,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column2);



store2 = gtk_list_store_new(COLUMNS2, G_TYPE_STRING , G_TYPE_STRING ,G_TYPE_INT);

f=fopen("liste_aff.txt","r");

if (f!=NULL)
{
f=fopen("liste_aff.txt","a+");

while (fscanf(f,"%s %s %d %d",nom_liste2,num_liste2,&nbr_vote2)!=EOF)
	{
		gtk_list_store_append(store2,&iter);
		gtk_list_store_set (store2,&iter,NOM_LISTE2,nom_liste2,NUM_LISTE2,num_liste2,NBR_VOTE2,nbr_vote2,-1);

	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste) , GTK_TREE_MODEL (store2));
g_object_unref (store2);
}
}
}

//*************************
void create_fichier_aff ( char *liste)
{
listelec L ;

    FILE * f=fopen("liste.txt", "r");
    FILE * f1 = fopen("liste_aff.txt","w");
    if(f!=NULL && f1!=NULL)
    {
        while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF) 
       		{ fprintf(f1,"%s %s %d \n",L.nomListe,L.numListe,L.nbV) ;  }      
	




	fclose(f);
	fclose(f1);
       
    }

}






































