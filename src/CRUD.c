#include "CRUD.h"
#include <string.h>


int i;
void modifier(char *ident, election e1)
{
FILE*f=NULL;
FILE*f1=NULL;
election e;
f=fopen("election.txt","r");
f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF){
if(strcmp(ident,e.id)!=0)
fprintf(f1,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,e.date.jour,e.date.mois,e.date.annee);
else
fprintf(f1,"%s %s %s %s %d %d %d \n",e1.id,e1.Municipalite,e1.NbrH,e1.NbrC,e1.date.jour,e1.date.mois,e1.date.annee);

}
fclose(f);
fclose(f1);
remove("election.txt");
rename("ancien.txt","election.txt");    

}




election chercher_id(char id0[])
{
election e,l;
FILE *f=fopen("election.txt","r");
    if(f!=NULL)
{
 while(fscanf(f,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF)
        {

            if(strcmp(e.id,id0)==0)
   	 return e;
        }
     fclose(f);
}
       strcpy(l.id,"");
    return l;

}


void ajouter(election e )
{FILE*f=NULL;
     f=fopen("election.txt", "a");
        fprintf(f,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,e.date.jour,e.date.mois,e.date.annee);
        fclose(f);
}
void supprimer_election(char*id){
FILE*f=NULL;
FILE*f1=NULL;
election e;
f=fopen("election.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF){
if(strcmp(id,e.id)!=0)
fprintf(f1,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,e.date.jour,e.date.mois,e.date.annee);
}
fclose(f);
fclose(f1);
remove("election.txt");
rename("ancien.txt","election.txt");
}
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

void Afficher_ele(GtkWidget* liste)
{

election e;
char id[50];
int jour;
int mois;
int annee;
char Municipalite[50];
char NbrH[30];
char NbrC[30];

	GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column3;
 	    GtkTreeIter iter;
	    GtkListStore *store;

	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)
            {
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("id",renderer,"text", ID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);

		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("Municipalite",renderer,"text", MUNICIPALITE2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("NbrH",renderer,"text", NOMBRE_HABITANT,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);

		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("NbrC",renderer,"text", NOMBRE_CONSEILLER,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("jour",renderer,"text", JOUR2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("mois",renderer,"text", MOIS2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("annee",renderer,"text", ANNEE2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);


        /* Creation du modele */
        store = gtk_list_store_new(COLUMNS3,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
        /* Insertion des elements */
        f=fopen("election.txt","r");
	if (f==NULL)
          {
		return ;
          }
	else
 	  {
		f=fopen("election.txt","r");
	while(fscanf(f,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF)
        {
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(store, &iter);
         /* Mise a jour des donnees */
         gtk_list_store_set(store,&iter,ID,e.id,MUNICIPALITE2,e.Municipalite,NOMBRE_HABITANT,e.NbrH,NOMBRE_CONSEILLER,e.NbrC,JOUR2,e.date.jour,MOIS2,e.date.mois,ANNEE2,e.date.annee, -1);
                            }
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }

}
}



	
int chercher_Avance(char ch[], char champ[])
{
	int c1,c2,i,cmp = 0;
	c1 = strlen(ch);
	c2= strlen(champ);
	if (c1<=c2){
	for (i=0;i<c1;i++){
		if (ch[i] == champ[i]){
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





void treeview_chercher(GtkWidget *liste,char iden[]){


	election e;
	GtkCellRenderer *renderer;
	    GtkTreeViewColumn *column3;
 	    GtkTreeIter iter;
	    GtkListStore *store;

	    store==NULL;
 	    
	    FILE *f;
	    
	    store=gtk_tree_view_get_model(liste);
	    if(store==NULL)

{renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("id",renderer,"text", ID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);

		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("Municipalite",renderer,"text", MUNICIPALITE2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("NbrH",renderer,"text", NOMBRE_HABITANT,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);

		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("NbrC",renderer,"text", NOMBRE_CONSEILLER,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("jour",renderer,"text", JOUR2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("mois",renderer,"text", MOIS2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
		
		renderer = gtk_cell_renderer_text_new();
        	column3 = gtk_tree_view_column_new_with_attributes("annee",renderer,"text", ANNEE2,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column3);
}

store = gtk_list_store_new(COLUMNS3,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);


        f=fopen("election.txt","r");
if (f==NULL)
          {
		return ;
          }
	else
 	  {
		f=fopen("election.txt","r");
	while(fscanf(f,"%s %s %s %s %d %d %d \n",e.id,e.Municipalite,e.NbrH,e.NbrC,&e.date.jour,&e.date.mois,&e.date.annee)!=EOF)
        {
if (chercher_Avance(iden,e.id))
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,ID,e.id,MUNICIPALITE2,e.Municipalite,NOMBRE_HABITANT,e.NbrH,NOMBRE_CONSEILLER,e.NbrC,JOUR2,e.date.jour,MOIS2,e.date.mois,ANNEE2,e.date.annee, -1);
}
}
fclose(f);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
}}











