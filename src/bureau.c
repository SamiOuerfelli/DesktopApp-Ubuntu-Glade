#ifndef HAVE_CONFIG_H_
#include <config.h>
#endif
#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bureau.h"
#include "function.h"
#include <gtk/gtk.h>
enum{
IDB,
CAPELEC,
CAPOBS,
BADR,
SALLE,
IDAGENTB,
COLUMNS
};

void ajouter_bureau(bureau p)
{
    FILE * f=fopen("bureau.txt", "a+");
    if(f!=NULL)
    { fprintf(f,"%s %s %s %s %s %s\n",p.id_b,p.cap_elec,p.cap_obs,p.b_adr,p.salle,p.id_agentb);
        fclose(f);
    }
    
}
int exist_bureau(char*id)
{
FILE*f=NULL;
 bureau p;
f=fopen("bureau.txt","r");// ouverture du fichier equipement en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %s\n",p.id_b,p.cap_elec,p.cap_obs,p.b_adr,p.salle,p.id_agentb)!=EOF){
if(strcmp(p.id_b,id)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

void modifier_bureau(bureau p)
{
FILE*f=NULL;
FILE*f1=NULL;
bureau b;
f=fopen("bureau.txt","r");
f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s\n",b.id_b,b.cap_elec,b.cap_obs,b.b_adr,b.salle,b.id_agentb)!=EOF)
{
if(strcmp(p.id_b,b.id_b)==0)
{
fprintf(f1,"%s %s %s %s %s %s\n",p.id_b,p.cap_elec,p.cap_obs,p.b_adr,p.salle,p.id_agentb);
}
else
{
fprintf(f1,"%s %s %s %s %s %s\n",b.id_b,b.cap_elec,b.cap_obs,b.b_adr,b.salle,b.id_agentb);
}

}
fclose(f);
fclose(f1);
remove("bureau.txt");
rename("ancien.txt","bureau.txt");
}

int modif_bureau_exist(bureau p)
{
FILE*f=NULL;
 bureau b;
f=fopen("bureau.txt","r");// ouverture du fichier equipement en  mode lecture 
while(fscanf(f,"%s %s %s %s %s %s",b.id_b,b.cap_elec,b.cap_obs,b.b_adr,b.salle,b.id_agentb)!=EOF){
if(strcmp(b.id_b,p.id_b)==0 && strcmp(b.cap_elec,p.cap_elec)==0 && strcmp(b.cap_obs,p.cap_obs)==0 && strcmp(b.b_adr,p.b_adr)==0 && strcmp(b.salle,p.salle)==0 && strcmp(b.id_agentb,p.id_agentb)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}
void supprimer_bureau(char*id)
{
FILE*f=NULL;
FILE*f1=NULL;
bureau p;
f=fopen("bureau.txt","r");
f1=fopen("ancien.txt","w+");//mode lecture et ecriture
while(fscanf(f,"%s %s %s %s %s %s\n",p.id_b,p.cap_elec,p.cap_obs,p.salle,p.b_adr,p.id_agentb)!=EOF){
if(strcmp(id,p.id_b)!=0)fprintf(f1,"%s %s %s %s %s %s\n",p.id_b,p.cap_elec,p.cap_obs,p.salle,p.b_adr,p.id_agentb);
}
fclose(f);
fclose(f1);
remove("bureau.txt");
rename("ancien.txt","bureau.txt");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_bureau(GtkWidget *liste)
{
bureau p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id_b[20];
char cap_elec[20];
char cap_obs[20];
char b_adr[20];
char salle[20];
char id_agentb[20];
store = NULL;
FILE *f;
store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_b",renderer,"text",IDB,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cap_elec",renderer,"text",CAPELEC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cap_obs",renderer,"text",CAPOBS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("b_adr",renderer,"text",BADR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("salle",renderer,"text",SALLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_agentb",renderer,"text",IDAGENTB,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("bureau.txt", "r");

	if(f==NULL)
	{
	return;
	}

	else
	{	
          while(fscanf(f,"%s %s %s %s %s %s \n",p.id_b,p.cap_elec,p.cap_obs,p.b_adr,p.salle,p.id_agentb)!=EOF)
		{
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, IDB, p.id_b, CAPELEC, p.cap_elec,CAPOBS, p.cap_obs, BADR, p.b_adr,  SALLE, p.salle, IDAGENTB, p.id_agentb,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

////////////////////////////////////////////////////////////////////////////////////////////

int Chercherbureau(GtkWidget *liste,char*l,char*id)
{
bureau p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id_b[20];
char cap_elec[20];
char cap_obs[20];
char b_adr[20];
char salle[20];
char id_agentb[20];
store = NULL;
FILE *f;
int nb;
store = gtk_tree_view_get_model(liste);
	    if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_b",renderer,"text",IDB,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cap_elec",renderer,"text",CAPELEC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cap_obs",renderer,"text",CAPOBS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("b_adr",renderer,"text",BADR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("salle",renderer,"text",SALLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_agentb",renderer,"text",IDAGENTB,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	    f=fopen(l,"r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			f=fopen(l,"a+");
			while(fscanf(f,"%s %s %s %s %s %s\n",p.id_b,p.cap_elec,p.cap_obs,p.b_adr,p.salle,p.id_agentb)!=EOF)
			{ if (strcmp(id,p.id_b)==0){ nb++;
				gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, IDB, p.id_b, CAPELEC, p.cap_elec,CAPOBS, p.cap_obs, BADR, p.b_adr,  SALLE, p.salle, IDAGENTB, p.id_agentb,-1);
			}}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
return nb;
}

int taux_obsertn(char *filename)
{ 
coord P;
int tn=0;
FILE *f=fopen(filename, "r");
if(f!=NULL)
{
        while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!=EOF)
	{
        if(strcmp(P.role,"Observateur")==0) 
        {
	if(strcmp(P.nationalite,"Tunisienne")==0)
		{tn++;}
	}
        }
	
}
return tn;
}



int taux_obser(char *filename)
{ 
coord P;
int nbt=0;
FILE *f=fopen(filename, "r");
if(f!=NULL)
{
        while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!=EOF)
	{
        if(strcmp(P.role,"Observateur")==0) 
        { nbt++;}
        }
	
}
return nbt;
}

