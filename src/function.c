#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include <gtk/gtk.h>


enum 
{
CIN,
NOM,
PRENOM,
JOUR,
MOIS,
ANNEE,
NATIONALITE,
SEXE,
NUMERO_DE_TELEPHONE,
ADRESSE_MAIL,
ROLE,
NUMERO_DE_BUREAU,
PROFESSION,
VOTE,
COLUMNS,
};

    void salma_ajouter (coord P)
    {
       FILE *f=fopen("coord.txt","a+");
       if (f!=NULL)
          {fprintf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,P.d_d_n.jour,P.d_d_n.mois,P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote);
                fclose(f);
               }

     }  
       
    


void  salma_modifier ( char *id,coord nouv)
{ int i=0;  coord P;

FILE *f1=fopen("coord.txt","r");
FILE *f2=fopen("nouv.txt","w");

if(f1!=NULL && f2!=NULL)
{
    while (i<sizeof(f1)&&fscanf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!= EOF)
    {
        if (strcmp(P.id_CIN,id)==0)
          {
            fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",nouv.id_CIN,nouv.nom,nouv.prenom,nouv.d_d_n.jour,nouv.d_d_n.mois,nouv.d_d_n.annee,nouv.nationalite,nouv.sexe,nouv.num_tel,nouv.adresse_mail,nouv.role,nouv.num_bureau,nouv.profession,nouv.vote);
             i++;
           }
        else
                {fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,P.d_d_n.jour,P.d_d_n.mois,P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote);
                    i++;}
    }
}
fclose(f1);
fclose(f2);
remove("coord.txt");
rename("nouv.txt","coord.txt");

}

void salma_supprimer (char *id)
{ int i=0;
    coord P;
    FILE *f1=fopen("coord.txt","r");
    FILE *f2=fopen("nouv.txt","w");

    if (f1!= NULL && f2!=NULL)
    {
        while (i<sizeof(f1) && fscanf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!= EOF )
        {
            if (strcmp(P.id_CIN,id)==0)
               {i++;}
             else
                {fprintf(f2,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,P.d_d_n.jour,P.d_d_n.mois,P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote);
                 i++;}
        }
    }
    fclose(f1);
    fclose(f2);
    remove("coord.txt");
    rename("nouv.txt","coord.txt");
}

int salma_chercher (GtkWidget *liste, char *l,char *id)
{ 
coord P ; int tr=0;

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
GtkWidget *labelrecherche;
GtkWidget *objet;

    char cin[9];
    char nom[20];
    char prenom[20];
    int jour, mois, annee;
    char nationalite[20];
    char sexe[6];
    char num_tel[9];
    char adresse_mail[50];
    char role[30];
    char num_bureau[5];
    char profession[20];
    char vote[3];

FILE *f;
int nb;
store=gtk_tree_view_get_model(liste);
if (store==NULL)

{

 renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("cin", renderer,"text",CIN , NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nom", renderer,"text",NOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("prenom", renderer,"text",PRENOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("jour", renderer,"text",JOUR ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("mois", renderer,"text",MOIS ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("annee", renderer,"text",ANNEE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nationalite", renderer,"text",NATIONALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("sexe", renderer,"text",SEXE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_tel", renderer,"text",NUMERO_DE_TELEPHONE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("adresse_mail", renderer,"text",ADRESSE_MAIL ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("role", renderer,"text",ROLE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_bureau", renderer,"text",NUMERO_DE_BUREAU ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("profession", renderer,"text",PROFESSION ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("vote", renderer,"text",VOTE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,
           G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
             G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen(l,"r");
if (f==NULL)
{return;}
else 
{

f=fopen(l,"a+");

 while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!= EOF)
            { if(strcmp(id,P.id_CIN)==0)
               {nb++;  
    gtk_list_store_append(store, &iter);

   gtk_list_store_set (store , &iter , CIN, P.id_CIN, NOM, P.nom, PRENOM, P.prenom, JOUR , P.d_d_n.jour , MOIS ,P.d_d_n.mois, ANNEE ,P.d_d_n.annee, NATIONALITE, P.nationalite, SEXE , P.sexe,NUMERO_DE_TELEPHONE ,P.num_tel, ADRESSE_MAIL , P.adresse_mail, ROLE , P.role, NUMERO_DE_BUREAU , P.num_bureau , PROFESSION  , P.profession , VOTE ,P.vote,-1);
                }
            }


fclose (f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) , GTK_TREE_MODEL (store));
g_object_unref (store);
}
   return nb;
 }


void salma_afficher (GtkWidget *liste)
{
coord p;

GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore  *store;

    char cin[9];
    char nom[20];
    char prenom[20];
    int jour, mois, annee;
    char nationalite[20];
    char sexe[6];
    char num_tel[9];
    char adresse_mail[50];
    char role[30];
    char num_bureau[5];
    char profession[20];
    char vote[3];

store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);
if (store==NULL)
{
      renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("cin", renderer,"text",CIN , NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nom", renderer,"text",NOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("prenom", renderer,"text",PRENOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("jour", renderer,"text",JOUR ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("mois", renderer,"text",MOIS ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("annee", renderer,"text",ANNEE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nationalite", renderer,"text",NATIONALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("sexe", renderer,"text",SEXE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_tel", renderer,"text",NUMERO_DE_TELEPHONE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("adresse_mail", renderer,"text",ADRESSE_MAIL ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("role", renderer,"text",ROLE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_bureau", renderer,"text",NUMERO_DE_BUREAU ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("profession", renderer,"text",PROFESSION ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("vote", renderer,"text",VOTE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store = gtk_list_store_new(COLUMNS , G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,
           G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
             G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("coord.txt","r");

if (f==NULL)
{return;}

else 

{ f = fopen("coord.txt" , "a+" );
     while (fscanf(f, "%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",p.id_CIN, p.nom, p.prenom, &p.d_d_n.jour, &p.d_d_n.mois, &p.d_d_n.annee,p.nationalite,p.sexe, p.num_tel, p.adresse_mail, p.role, p.num_bureau, p.profession,p.vote)!=EOF)
   { 

gtk_list_store_append (store , &iter);

gtk_list_store_set (store , &iter , CIN, p.id_CIN, NOM, p.nom, PRENOM, p.prenom, JOUR , p.d_d_n.jour , MOIS ,p.d_d_n.mois, ANNEE ,p.d_d_n.annee, NATIONALITE, p.nationalite, SEXE , p.sexe, NUMERO_DE_TELEPHONE ,p.num_tel, ADRESSE_MAIL , p.adresse_mail, ROLE , p.role, NUMERO_DE_BUREAU , p.num_bureau , PROFESSION  , p.profession , VOTE ,p.vote,-1);
   }

fclose (f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) , GTK_TREE_MODEL (store));
g_object_unref (store);
}

}




void salma_afficher_util (GtkWidget *liste)
{
coord p;

GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore  *store;

    char cin[9];
    char nom[20];
    char prenom[20];
    int jour, mois, annee;
    char nationalite[20];
    char sexe[6];
    char num_tel[9];
    char adresse_mail[50];
    char role[30];
    char num_bureau[5];
    char profession[20];
    char vote[3];

store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);
if (store==NULL)
{
      renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("cin", renderer,"text",CIN , NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nom", renderer,"text",NOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("prenom", renderer,"text",PRENOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("jour", renderer,"text",JOUR ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("mois", renderer,"text",MOIS ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("annee", renderer,"text",ANNEE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nationalite", renderer,"text",NATIONALITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("sexe", renderer,"text",SEXE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_tel", renderer,"text",NUMERO_DE_TELEPHONE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("adresse_mail", renderer,"text",ADRESSE_MAIL ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("role", renderer,"text",ROLE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_bureau", renderer,"text",NUMERO_DE_BUREAU ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("profession", renderer,"text",PROFESSION ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("vote", renderer,"text",VOTE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store = gtk_list_store_new(COLUMNS , G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,
           G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
             G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

trier_util();

f=fopen("util.txt","r");

if (f==NULL)
{return;}

else 

{ f = fopen("util.txt" , "a+" );
     while (fscanf(f, "%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",p.id_CIN, p.nom, p.prenom, &p.d_d_n.jour, &p.d_d_n.mois, &p.d_d_n.annee,p.nationalite,p.sexe, p.num_tel, p.adresse_mail, p.role, p.num_bureau, p.profession,p.vote)!=EOF)
   

  {gtk_list_store_append (store , &iter);

  gtk_list_store_set (store , &iter , CIN, p.id_CIN, NOM, p.nom, PRENOM, p.prenom, JOUR , p.d_d_n.jour , MOIS ,p.d_d_n.mois, ANNEE ,p.d_d_n.annee, NATIONALITE, p.nationalite, SEXE , p.sexe, NUMERO_DE_TELEPHONE ,p.num_tel, ADRESSE_MAIL , p.adresse_mail, ROLE , p.role, NUMERO_DE_BUREAU , p.num_bureau , PROFESSION  , p.profession , VOTE ,p.vote,-1);
   }
  
fclose (f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) , GTK_TREE_MODEL (store));
g_object_unref (store);
}

}

void salma_afficher_obv (GtkWidget *liste)
{
coord p;

GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter  iter;

GtkListStore  *store;

    char cin[9];
    char nom[20];
    char prenom[20];
    int jour, mois, annee;
    char nationalite[20];
    char sexe[6];
    char num_tel[9];
    char adresse_mail[50];
    char role[30];
    char num_bureau[5];
    char profession[20];
    char vote[3];

store=NULL;

FILE *f;

store = gtk_tree_view_get_model(liste);
if (store==NULL)
{
      renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("cin", renderer,"text",CIN , NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nom", renderer,"text",NOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("prenom", renderer,"text",PRENOM ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("jour", renderer,"text",JOUR ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("mois", renderer,"text",MOIS ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("annee", renderer,"text",ANNEE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("nationalite", renderer,"text",NATIONALITE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("sexe", renderer,"text",SEXE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_tel", renderer,"text",NUMERO_DE_TELEPHONE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("adresse_mail", renderer,"text",ADRESSE_MAIL ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("role", renderer,"text",ROLE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("num_bureau", renderer,"text",NUMERO_DE_BUREAU ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("profession", renderer,"text",PROFESSION ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

   renderer=gtk_cell_renderer_text_new();
 column=gtk_tree_view_column_new_with_attributes ("vote", renderer,"text",VOTE ,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}

store = gtk_list_store_new(COLUMNS , G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,
           G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,
             G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

trier_obv();

f=fopen("obv.txt","r");

if (f==NULL)
{return;}

else 

{ f = fopen("obv.txt" , "a+" );
     while (fscanf(f, "%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",p.id_CIN, p.nom, p.prenom, &p.d_d_n.jour, &p.d_d_n.mois, &p.d_d_n.annee, p.nationalite, p.sexe, p.num_tel, p.adresse_mail, p.role, p.num_bureau, p.profession,p.vote)!=EOF)
    

{

gtk_list_store_append (store , &iter);

gtk_list_store_set (store , &iter , CIN, p.id_CIN, NOM, p.nom, PRENOM, p.prenom, JOUR , p.d_d_n.jour , MOIS ,p.d_d_n.mois, ANNEE ,p.d_d_n.annee, NATIONALITE, p.nationalite, SEXE , p.sexe, NUMERO_DE_TELEPHONE ,p.num_tel, ADRESSE_MAIL , p.adresse_mail, ROLE , p.role, NUMERO_DE_BUREAU , p.num_bureau , PROFESSION  , p.profession , VOTE ,p.vote,-1);
   }


fclose (f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste) , GTK_TREE_MODEL (store));
g_object_unref (store);
}

}


int nbr_tot_obv()
{
    int occ; coord P;
    FILE *f=fopen("coord.txt","r");
    if (f!=NULL)
    {occ=0;
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!= EOF)
        {
            if (strcmp(P.role,"Observateur")==0)
            occ++;

        }
    }
fclose(f);
return occ;
}

void  trier_obv ()
{ coord *tab,P,aux; int i,j,n,premier=0,p=0;
    FILE *f=fopen("coord.txt","r");
    FILE *f1=fopen("obv.txt","a");

    tab=(coord*)malloc(sizeof(coord));
    if (f!=NULL)
    { i=0;
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!= EOF)
             {if (strcmp(P.role,"Observateur")==0)
                     {*(tab+i)=P; i++;} }
    }
     for (j=0;j<i-1;j++)
     {  premier=j;
        for (n=j+1;n<i;n++)
           {if ((*(tab+premier)).nom > (*(tab+n)).nom)
               premier =n;
           }

             aux=*(tab+j);
             *(tab+j)= *(tab+premier);
             *(tab+premier)=aux;
             p=1;
    }
    for (j=0;j<i;j++)
        fprintf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",(*(tab+j)).id_CIN,(*(tab+j)).nom,(*(tab+j)).prenom,(*(tab+j)).d_d_n.jour,(*(tab+j)).d_d_n.mois,(*(tab+j)).d_d_n.annee,(*(tab+j)).nationalite,(*(tab+j)).sexe,(*(tab+j)).num_tel,(*(tab+j)).adresse_mail,(*(tab+j)).role,(*(tab+j)).num_bureau,(*(tab+j)).profession,(*(tab+j)).vote);



}

void trier_util ()
{ coord *tab1,P,aux1; int i,j,n,premier=0,p=0;
    FILE *f=fopen("coord.txt","r");
    FILE *f1=fopen("util.txt","a");

    tab1=(coord*)malloc(sizeof(coord));
    if (f!=NULL)
    { i=0;
        while (fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",P.id_CIN,P.nom,P.prenom,&P.d_d_n.jour,&P.d_d_n.mois,&P.d_d_n.annee,P.nationalite,P.sexe,P.num_tel,P.adresse_mail,P.role,P.num_bureau,P.profession,P.vote)!= EOF)
             {if (strcmp(P.role,"Electeur")==0 || strcmp(P.role,"Agent")==0)
                     {*(tab1+i)=P; i++;} }
    }

     for (j=0;j<i-1;j++)
     {  premier=j;
        for (n=j+1;n<i;n++)
           {if ((*(tab1+premier)).nom < (*(tab1+n)).nom)
               premier =n;
           }

             aux1=*(tab1+j);
             *(tab1+j)= *(tab1+premier);
             *(tab1+premier)=aux1;
             p=1;
    }
     for (j=0;j<i;j++)
        fprintf(f1,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",(*(tab1+j)).id_CIN,(*(tab1+j)).nom,(*(tab1+j)).prenom,(*(tab1+j)).d_d_n.jour,(*(tab1+j)).d_d_n.mois,(*(tab1+j)).d_d_n.annee,(*(tab1+j)).nationalite,(*(tab1+j)).sexe,(*(tab1+j)).num_tel,(*(tab1+j)).adresse_mail,(*(tab1+j)).role,(*(tab1+j)).num_bureau,(*(tab1+j)).profession,(*(tab1+j)).vote);
    
}



void generation_acces(coord P)
{  lg Q;  
   int n=0;
 
    FILE *f=fopen("log.txt","a");
    if (f!=NULL)
    
           { 
          strcpy(Q.login,P.id_CIN);

            do {
              n=rand();} while (n<1000 || n>9999);

             char chaine1[5]; 
             sprintf(chaine1,"%d",n);

              strcpy(Q.mdp,chaine1);
              fprintf(f,"%s %s\n",Q.login,Q.mdp);
            }
    fclose(f);   
    }


void choix_vote (int choix, char vote[])
{
if (choix==1) 
strcpy(vote,"-1");
}


