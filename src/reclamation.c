
#include  <stdio.h>
#include "reclamation.h"
#include "fonction_sami.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>




void ajouter_rec(reclamation rec)
{
    FILE *f=fopen("reclamation.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s\n",rec.id_list,rec.nom_list,rec.num_bur ,rec.type ,rec.objet ,rec.text);
        fclose(f);    
    }
    

}
///////////////////////////////////////////////////////////////////////////////
void afficher_reclamation(GtkWidget *liste)
{
reclamation rec;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id_list[20];
char nom_list[20];
char num_bur[20];
char type[20];
char objet[20];
char text[1000];

store = NULL;
FILE *f;
store = gtk_tree_view_get_model(liste);


if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_list",renderer,"text",IDL ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom_list",renderer,"text",NOM_L,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("num_bur",renderer,"text",NUM_B,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("objet",renderer,"text",OBJET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("text",renderer,"text",TEXT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
}
	store = gtk_list_store_new(COLUMNS_R, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f = fopen("reclamation.txt", "r");

	if(f==NULL)
	{
	return;
	}

	else
	{	
          while(fscanf(f,"%s %s %s %s %s %s \n",rec.id_list,rec.nom_list,rec.num_bur,rec.type,rec.objet,rec.text)!=EOF)
		{
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, IDL, rec.id_list ,NOM_L, rec.nom_list,NUM_B, rec.num_bur, TYPE, rec.type,  OBJET, rec.objet, TEXT, rec.text,-1);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}
///////////////

int supprimer_reclamation( char IDENT_LIST[])

{
    
    int tr=0;
    reclamation rec;
    FILE *f=fopen("reclamation.txt", "r");
    FILE *f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    
    {
      while (fscanf(f,"%s %s %s %s %s %s\n",rec.id_list, rec.nom_list ,rec.num_bur ,rec.type ,rec.objet ,rec.text)!=EOF)
        {
            if( strcmp(IDENT_LIST,rec.id_list)==0 )
                tr=1;
            else
			 fprintf(f2,"%s %s %s %s %s %s\n",rec.id_list , rec.nom_list ,rec.num_bur , rec.type ,rec.objet ,rec.text);

 }
    }
    fclose(f);
    fclose(f2);
  

    remove("reclamation.txt");
    rename("nouv.txt", "reclamation.txt");
	

return tr;
}

/////
int Chercher_reclamation(GtkWidget *liste,char*r,char*ident)
{
reclamation rec;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id_list[20];
char nom_list[20];
char num_bur[20];
char type[20];
char objet[20];
char text[1000];
store = NULL;
FILE *f;
int nb;
store = gtk_tree_view_get_model(liste);
	if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_list",renderer,"text",IDL ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom_list",renderer,"text",NOM_L,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("num_bur",renderer,"text",NUM_B,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("objet",renderer,"text",OBJET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("text",renderer,"text",TEXT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
}
	store = gtk_list_store_new(COLUMNS_R, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	    f=fopen(r,"r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			f=fopen(r,"a+");
			while(fscanf(f,"%s %s %s %s %s %s\n",rec.id_list, rec.nom_list ,rec.num_bur ,rec.type ,rec.objet ,rec.text)!=EOF)
			{ if (strcmp(ident,rec.id_list)==0){ nb++;
				gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, IDL, rec.id_list ,NOM_L, rec.nom_list,NUM_B, rec.num_bur, TYPE, rec.type,  OBJET, rec.objet, TEXT, rec.text,-1);
			}}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }
return nb;
}

//////////////////////////////
void modifier_reclamation(reclamation nouv)
{
FILE*f=NULL;
FILE*f1=NULL;
reclamation rec;
f=fopen("reclamation.txt","r");
f1=fopen("nouv.txt","w+");
while (fscanf(f,"%s %s %s %s %s %s\n",rec.id_list, rec.nom_list ,rec.num_bur ,rec.type ,rec.objet ,rec.text)!=EOF)
if( strcmp(nouv.nom_list,rec.id_list)==0 )
{

fprintf(f1,"%s %s %s %s %s %s\n",nouv.id_list,nouv.nom_list,nouv.num_bur,nouv.type ,nouv.objet ,nouv.text);
}
else
{fprintf(f,"%s %s %s %s %s %s\n",rec.id_list , rec.nom_list ,rec.num_bur , rec.type ,rec.objet ,rec.text);

}
fclose(f);
fclose(f1);
remove("reclamation.txt");
rename("nouv.txt","reclamation.txt");
}

////////

/* -------------------------------------------------------------------------------------- */


void nombreReclListe(GtkWidget *liste){
	reclamation r; 
	listelec L; 	
	ReclamationListe rl;
	ReclamationListe data[100];
	int index = 0 ,count = 0;
	FILE *f , *g ;
	f = fopen("liste.txt","r"); 
	
	while(fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d %d \n",L.municipalite,L.nomListe,L.numListe,L.idenListe,L.idenTeteliste,L.candidat1,L.candidat2,L.candidat3,&L.d.j,&L.d.m,&L.d.a,&L.nbV)!=EOF){
		strcpy(rl.id,L.idenListe);
     		g = fopen("reclamation.txt","r");
		count = 0 ; 
		while(fscanf(g,"%s %s %s %s %s %s\n",r.id_list,r.num_bur,r.nom_list,r.type,r.objet,r.text) != EOF){
			if(strcmp(L.idenListe,r.id_list) == 0 ) {
				count ++ ;
			}
		} 
		rl.nombre = count ; 
		
		fclose(g);
		data[index] = rl ; 
		index ++ ;
	}
	fclose(f);


	 GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
 
    char nb[20];
    store = NULL;
    store = gtk_tree_view_get_model(liste);


    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID Liste",renderer,"text",EIDLIST,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nombre de Réclamations",renderer,"text",ENBVOTESS,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



    }
	store = gtk_list_store_new(ECOLUMNSS,G_TYPE_STRING,G_TYPE_STRING);
    
    	int k = 0;
	while(k < index){	
		sprintf(nb,"%d",data[k].nombre);
		          		
		gtk_list_store_append(store,&iter);
    		gtk_list_store_set(store,&iter,EIDLIST,data[k].id,ENBVOTESS,nb,-1);
		k++;

	}

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
        	

}
////
int nbTotal(char *filename){
	FILE *f ; 
	reclamation r; 
	int count = 0 ; 
	f = fopen("reclamation.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",r.id_list,(r.num_bur),r.nom_list,r.type,r.objet,r.text) != EOF){
		count ++ ; 
	
	}

	fclose(f);
	return count ; 
}

