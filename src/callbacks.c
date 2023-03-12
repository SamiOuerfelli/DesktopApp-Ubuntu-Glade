#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"
#include "bureau.h"
#include "function.h"
#include "CRUD.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int k=0;
int btnradioajout=0;
int bureau_valid=0;
int modif_valid=0;
int btnradiointer=0;
GtkTreeSelection *selection1;
int affichage_gl_flag=0 ;
char NomListe[50]="";
char NumListe[50]="";
int radio_oui_non ;
char liste_vote [20] ="";
int vote_blanc = 0 ;
char liste [20]="";
char IDENT_LIST[20]="";
int oui_non ;

int elec_valid;
char MUNICIP[]="";
char IDEN[50]="";


int Munic=-1;

/*
void
on_refreshNRLE_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewRLE");
	nombreReclListe(treeview);
}

void
on_ValiderNR_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *output ;

	output = lookup_widget(objet,"outputReclNb");

	int x = nbTotal("reclamtion.txt");
	char message[10] ; 

	sprintf(message,"%d",x);
	gtk_label_set_text(GTK_LABEL(output),message);	
}*/



void
on_admin_connexion_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

lg q; lg t; int tr=0;
coord p;

GtkWidget *input1, *input2;
GtkWidget *fenetre1,*fenetre2;
GtkWidget *label1 , *label2;

fenetre2=lookup_widget(objet,"admin_authentification");

input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");

label1=lookup_widget(objet,"Veuillez saisir tous les données");
label2=lookup_widget(objet,"donnée(s) erronée(s)");

strcpy(q.login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(q.mdp,gtk_entry_get_text(GTK_ENTRY(input2)));

   
FILE *f=fopen("log.txt","r");
if (f!=NULL)
{ while (fscanf(f,"%s %s\n",t.login,t.mdp)!=EOF)
  { if ((strcmp(q.login,"")==0) || (strcmp(q.mdp,"")==0) )
       gtk_widget_show(label1);
     
   else if (strcmp(q.login,t.login)==0)
            {tr=1;
               if (strcmp (q.mdp,t.mdp)==0)
                 tr=1;
               else gtk_widget_show(label2);
           }
   }
}


if (tr==0)
gtk_widget_show(label2);
else if (tr==1)
{ FILE *f=fopen("coord.txt","r");
if (f!=NULL)
{ while (fscanf(f, "%s %s %s %d %d %d %s %s %s %s %s %s %s %s\n",p.id_CIN, p.nom, p.prenom, &p.d_d_n.jour, &p.d_d_n.mois, &p.d_d_n.annee,p.nationalite,p.sexe, p.num_tel, p.adresse_mail, p.role, p.num_bureau, p.profession,p.vote)!=EOF)
  { if (strcmp(q.login,p.id_CIN)==0)
      { if (strcmp(p.role,"Administrateur")==0)
           {
            
		fenetre1 = create_admin_page_accueil ();
                 gtk_widget_show(fenetre1);
		 gtk_widget_destroy(fenetre2);
            }
         else if (strcmp(p.role,"Electeur")==0)
           {
		GtkWidget *sami_gl_window_acceuil;
		sami_gl_window_acceuil = create_sami_gl_window_acceuil ();
  		gtk_widget_show (sami_gl_window_acceuil);
		gtk_widget_destroy(fenetre2);
		
           }
         else if (strcmp(p.role,"Observateur")==0)
           {
fenetre1 = create_admin_page_accueil ();
                 gtk_widget_show(fenetre1);
		 gtk_widget_destroy(fenetre2);
            }
         else if (strcmp(p.role,"Agent de bureau")==0)
            {
		fenetre1 = create_admin_page_accueil ();
                 gtk_widget_show(fenetre1);
		 gtk_widget_destroy(fenetre2);
            }
      }
  }
}
}


}


void
on_admin_mdp_oublie_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1, *fenetre2; 

fenetre1=lookup_widget(objet,"admin_authentification");

gtk_widget_destroy(fenetre1); 
fenetre2=create_mdp_oublie();
gtk_widget_show(fenetre2);
}


void
on_Retour1_CRUD_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1, *fenetre2;
GtkWidget *saisie_coordonnee, *CRUD_admin;
GtkWidget *treeview5;

fenetre1=lookup_widget(objet,"saisie_coordonnee");

gtk_widget_destroy(fenetre1);
fenetre2=create_CRUD_admin();
gtk_widget_show(fenetre2);

treeview5=lookup_widget(fenetre2,"treeview5");
salma_afficher(treeview5);
}


void
on_admin_valider_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
coord p; coord q; int test=0; int n=1;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7,
          *input8, *input9, *input10 , *input11, *input12 , *input13, *input14;

GtkWidget *fenetre1,  *fenetre2;
GtkWidget *saisie_coordonnee, *CRUD_admin;
GtkWidget *treeview5;

GtkWidget *labelvalid, *labelexistant, *labelvide;

fenetre1=lookup_widget(objet_graphique,"saisie_coordonnee");
//fenetre2=lookup_widget (objet_graphique,"CRUD_admin");

//labelvalid=lookup_widget(objet_graphique,"label190");
//labelexistant=lookup_widget(objet_graphique,"label189");
//labelvide=lookup_widget(objet_graphique,"message-erreur");

input1=lookup_widget(objet_graphique,"admin_CIN");
input2=lookup_widget(objet_graphique,"admin_nom");
input3=lookup_widget(objet_graphique,"admin_prenom");
input4=lookup_widget(objet_graphique,"adm_date_j");
input5=lookup_widget(objet_graphique,"adm_date_m");
input6=lookup_widget(objet_graphique,"adm_date_a");
input7=lookup_widget(objet_graphique,"admin_nationalite");
input8=lookup_widget(objet_graphique,"admin_sexe");
input9=lookup_widget(objet_graphique,"admin_tel");
input10=lookup_widget(objet_graphique,"admin_mail");
input11=lookup_widget(objet_graphique,"admin_role");
input12=lookup_widget(objet_graphique,"admin_num_bureau");
input13=lookup_widget(objet_graphique,"admin_profession");
input14=lookup_widget(objet_graphique,"vote1");


strcpy(p.id_CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.nationalite,gtk_entry_get_text(GTK_ENTRY(input7)));

p.d_d_n.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
p.d_d_n.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
p.d_d_n.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(p.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));
 
strcpy(p.num_tel,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(p.adresse_mail,gtk_entry_get_text(GTK_ENTRY(input10)));

strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input11)));
 

strcpy(p.num_bureau,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(p.profession,gtk_entry_get_text(GTK_ENTRY(input13)));

int input15=1;
choix_vote(input15,p.vote);

/*if ( (strcmp(p.id_CIN,"")==0) || (strcmp(p.nom,"")==0) ||(strcmp(p.prenom,"")==0) ||(strcmp(p.sexe,"")==0) ||(strcmp(p.nationalite,"")==0) ||(strcmp(p.adresse_mail,"")==0) ||(strcmp(p.num_tel,"")==0) ||(strcmp(p.num_bureau,"")==0) ||(strcmp(p.vote,"")==0) ||(strcmp(p.profession,"")==0) ||(strcmp(p.role,"")==0) )
{ n=0;
//gtk_widget_show (labelvide); 
}

if (n==1)
  {  FILE *f=fopen("coord.txt","a+");

if (strlen(p.id_CIN)==8) 
 { while (test==0&& fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s",q.id_CIN, q.nom, q.prenom, &q.d_d_n.jour,&q.d_d_n.mois,&q.d_d_n.annee,q.sexe,q.nationalite, q.num_tel, q.adresse_mail, q.role, q.num_bureau, q.profession, q.vote)!=EOF)
  if (strcmp(p.id_CIN, q.id_CIN)==0) 
    test=1;
  }
else test=1;

if (test==0)*/
//{gtk_widget_show(labelvalid);
salma_ajouter(p);
generation_acces(p);
gtk_widget_destroy(fenetre1);
fenetre2=create_CRUD_admin();

gtk_widget_show(fenetre2);
treeview5=lookup_widget(fenetre2,"treeview5");
salma_afficher(treeview5);
//}
/*else 
 gtk_widget_show(labelexistant);
}*/

}


void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *cin; 
gchar *nom;
gchar *prenom;
gint *jour;
gint *mois;
gint *annee;
gchar *nationalite;
gchar *sexe;
gchar *num_tel;
gchar *adresse_mail;
gchar *role;
gchar *num_bureau;
gchar *profession;
gchar *vote;

coord p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter , path))  {

gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom , 2 , &prenom, 3 ,&jour, 4 ,&mois, 5 , &annee, 6, &nationalite , 7 , &sexe, 8, &num_tel, 9, &adresse_mail, 10 , &role, 11, &num_bureau, 12 , &profession, 13 ,&vote ,-1);

strcpy(p.id_CIN,cin);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
p.d_d_n.jour=jour;
p.d_d_n.mois=mois;
p.d_d_n.annee=annee;
strcpy(p.nationalite, nationalite);
strcpy(p.sexe, sexe);
strcpy(p.num_tel,num_tel);
strcpy(p.adresse_mail,adresse_mail);
strcpy(p.role,role);
strcpy(p.num_bureau,num_bureau);
strcpy(p.profession, profession);
strcpy(p.vote,vote);


salma_afficher(treeview);
}

}


void
on_admin_recherche_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry , *treeview;
char chaine1[9];
char id[100];
int b=0;
int res;

entry=lookup_widget(objet,"admin_CIN_chercher");
treeview=lookup_widget(objet,"treeview5");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));
if (strcmp(id,"")==0) {
b=0;}
else {b=1;}

if (b==0) {return;}
else {

res=salma_chercher(treeview,"coord.txt",id);
//salma_afficher(treeview);
}
}


void
on_admin_ajoutp1_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *saisie_coordonnee, *CRUD_admin;
GtkWidget *fenetre1, *fenetre2;

fenetre1=lookup_widget(objet,"CRUD_admin");

gtk_widget_destroy(fenetre1);
fenetre2=create_saisie_coordonnee();
gtk_widget_show(fenetre2);
}


void
on_admin_modif_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data)
{
char cin[10];
    char nom[20];
    char prenom[20];
    int jour, mois, annee ;
    char nationalite[20];
    char sexe[6];
    char num_tel[10];
    char adresse_mail[50];
    char role[30];
    char num_bureau[3];
    char profession[20];
    char vote[3];

GtkWidget *affiche, *modifier, *tree;
GtkTreeModel *model ; 
GtkTreeSelection *selection1;
GtkTreeIter iter;

affiche=lookup_widget(objet,"CRUD_admin");

tree=lookup_widget(objet,"treeview5");

selection1=gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
if (gtk_tree_selection_get_selected(selection1, &model , &iter))
{ 
  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom , 2 , &prenom, 3 ,&jour, 4 ,&mois, 5 , &annee, 6, &nationalite , 7 , &sexe, 8, &num_tel, 9, &adresse_mail, 10 , &role, 11, &num_bureau, 12 , &profession, 13 ,&vote ,-1);



modifier=create_saisie_coordonnee_modif();
gtk_widget_destroy(affiche);
gtk_widget_show(modifier);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_cin_modif")),cin);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_nom_modif")),nom);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_prenom_modif")),prenom);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"adm_date_j_modif")),jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"adm_date_m_modif")),mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"adm_date_a_modif")),annee);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_nationalite_modif")),nationalite);

gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier,"admin_sexe_modif")),sexe);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_tel_modif")),num_tel);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_mail_modif")),adresse_mail);

gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier,"admin_role_modif")),role);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_num_bureau_modif")),num_bureau);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_profession_modif")),profession);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"admin_vote_modif")),vote);

}

}


void
on_admin_suppression_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
GtkTreeIter iter;
GtkTreeModel *model;
GtkWidget *label; 
GtkWidget *tree;

gchar *cin; 
gchar *nom;
gchar *prenom;
gint *jour;
gint *mois;
gint *annee;
gchar *nationalite;
gchar *sexe;
gchar *num_tel;
gchar *adresse_mail;
gchar *role;
gchar *num_bureau;
gchar *profession;
gchar *vote;

coord p;

tree=lookup_widget(objet,"treeview5");

selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));

(gtk_tree_selection_get_selected(selection, &model, &iter ));
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom , 2 , &prenom, 3 ,&jour, 4 ,&mois, 5 , &annee, 6, &nationalite , 7 , &sexe, 8, &num_tel, 9, &adresse_mail, 10 , &role, 11, &num_bureau, 12 , &profession, 13 , &vote ,-1);

gtk_list_store_remove (GTK_LIST_STORE(model),&iter);
salma_supprimer (cin);
}


void
on_retour_accueil_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1 ,*fenetre2; 
GtkWidget *CRUD_admin, *admin_page_accueil;

fenetre1=lookup_widget(objet,"CRUD_admin");

gtk_widget_destroy(fenetre1);
fenetre2=create_admin_page_accueil();
gtk_widget_show(fenetre2);
}


void
on_admin_liste_elec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *admin_page_accueil,*sami_gl_window_gestion,*w3;
sami_gl_window_gestion=create_sami_gl_window_gestion();
w3 = lookup_widget(objet,"admin_page_accueil");

gtk_widget_show(sami_gl_window_gestion);
gtk_widget_destroy (w3);

}


void
on_admin_liste_utilisateur_clicked     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *admin_page_accueil, *aff_listes;
GtkTreeView *treeview7;
GtkWidget *fenetre1, *fenetre2;

fenetre1=lookup_widget(objet,"admin_page_accueil");

gtk_widget_destroy(fenetre1);
fenetre2=lookup_widget(objet,"aff_listes");
fenetre2=create_aff_listes();

gtk_widget_show(fenetre2);

treeview7=lookup_widget(fenetre2,"treeview7");

salma_afficher_util(treeview7);
}


void
on_admin_liste_obv_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *admin_page_accueil, *aff_listes;
GtkTreeView *treeview7;
GtkWidget *fenetre1, *fenetre2;

fenetre1=lookup_widget(objet,"admin_page_accueil");

gtk_widget_destroy(fenetre1);
fenetre2=lookup_widget(objet,"aff_listes");
fenetre2=create_aff_listes();

gtk_widget_show(fenetre2);

treeview7=lookup_widget(fenetre2,"treeview7");

salma_afficher_obv(treeview7);
}


void
on_admin_reclamation_clicked           (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *ibtihel_reclamation , *admin_page_accueil;
admin_page_accueil = lookup_widget(objet,"admin_page_accueil");
ibtihel_reclamation=create_ibtihel_reclamation();
gtk_widget_show(ibtihel_reclamation);
gtk_widget_destroy (admin_page_accueil);

}


void
on_admin_deconnexion_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1, *fenetre2;
GtkWidget *CRUD_admin, *admin_authentification;

fenetre1=lookup_widget(objet,"CRUD_admin");

gtk_widget_destroy(fenetre1);
fenetre2=create_admin_authentification();
gtk_widget_show(fenetre2);
}


void
on_admin_gest_bv_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *acceuil, *treeview, *window;
window=lookup_widget(objet,"admin_page_accueil");
gtk_widget_destroy(window);
acceuil=create_Bv_affinterface ();
gtk_widget_show(acceuil);

}


void
on_admin_gest_elec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *admin_page_accueil,*gestionsdeselections,*w3;
gestionsdeselections=create_gestionsdeselections();
w3 = lookup_widget(objet,"admin_page_accueil");

gtk_widget_show(gestionsdeselections);
gtk_widget_destroy (w3);


}


void
on_admin_gestion_util_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1, *fenetre2, *treeview5;
GtkWidget *admin_page_accueil,CRUD_admin;

fenetre1=lookup_widget(objet,"admin_page_accueil");

gtk_widget_destroy(fenetre1);
fenetre2=create_CRUD_admin();
gtk_widget_show(fenetre2);
treeview5=lookup_widget(fenetre2,"treeview5");
salma_afficher(treeview5);
}


void
on_admin_stat_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *msg1,*msg2,*msg3,*fenetre1,*fenetre2;
fenetre1=lookup_widget(objet,"admin_page_accueil");
gtk_widget_destroy(fenetre1);
fenetre2=create_window_statistique ();
gtk_widget_show(fenetre2);
msg1=lookup_widget(objet,"bv_stat_blanc");
msg2=lookup_widget(objet,"label_stat_obs2");
msg3=lookup_widget(objet,"label_statobs1");
gtk_widget_show(msg1);
gtk_widget_show(msg2);
gtk_widget_show(msg3);
}


void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *cin; 
gchar *nom;
gchar *prenom;
gint *jour;
gint *mois;
gint *annee;
gchar *nationalite;
gchar *sexe;
gchar *num_tel;
gchar *adresse_mail;
gchar *role;
gchar *num_bureau;
gchar *profession;
gchar *vote;

coord p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter , path))  {

gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom , 2 , &prenom, 3 ,&jour, 4 ,&mois, 5 , &annee, 6, &nationalite , 7 , &sexe, 8, &num_tel, 9, &adresse_mail, 10 , &role, 11, &num_bureau, 12 , &profession, 13 ,&vote ,-1);

strcpy(p.id_CIN,cin);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
p.d_d_n.jour=jour;
p.d_d_n.mois=mois;
p.d_d_n.annee=annee;
strcpy(p.nationalite, nationalite);
strcpy(p.sexe, sexe);
strcpy(p.num_tel,num_tel);
strcpy(p.adresse_mail,adresse_mail);
strcpy(p.role,role);
strcpy(p.num_bureau,num_bureau);
strcpy(p.profession, profession);
strcpy(p.vote,vote);

salma_afficher(treeview);
}
}


void
on_Retour_liste_accueil_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1, *fenetre2;
GtkWidget *aff_listes, *CRUD_admin;

fenetre1=lookup_widget(objet,"aff_listes");

gtk_widget_destroy(fenetre1);
fenetre2=create_admin_page_accueil();
gtk_widget_show(fenetre2);
}


void
on_renvoi_mdp_mail_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_renvoi_num_tel_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeview_aff_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;

	gchar *id_list;
	GtkTreeModel *model ;
	model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,IDL,&id_list,-1);
	strcpy(IDENT_LIST,id_list);
}
}


void
on_ibti_retour_acceuil_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ibtihel_reclamation , *admin_page_accueil;
ibtihel_reclamation = lookup_widget(button,"ibtihel_reclamation");
admin_page_accueil=create_admin_page_accueil();
gtk_widget_show(admin_page_accueil);
gtk_widget_destroy (ibtihel_reclamation);

}


void
on_ibti_chercher_rec_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *r1;
GtkWidget *entry;
GtkWidget *labelnom; 

	labelnom=lookup_widget(objet,"ibti_msg_cher");

char ident[20];
char chnb[20];
int b=0,nb; //b=0  entry  cherche vide 
entry=lookup_widget(objet,"entry31");

r1=lookup_widget(objet,"treeview_aff");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(ident,"")==0){
  b=0;



}else{
b=1;
     
}

if(b==0)
    {return;
    }
    else
    {

nb=Chercher_reclamation(r1,"reclamation.txt",ident);

       char message[100];
	sprintf(message,"le resultat est : ");
	gtk_label_set_text(GTK_LABEL(labelnom),message);;




}


}


void
on_ibti_modifier_rec_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char type[20];
  char nom_list[20];
  char num_bur[20];
  char id_list[20];
  char objet[20];
  char text[1000];
reclamation rec;

	int id_r;
	GtkWidget *affiche, *modifier,*tree;
        GtkTreeModel     *model;
		GtkTreeSelection *selection1;
        GtkTreeIter iter;
tree=lookup_widget(objet_graphique,"treeview_aff");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

      
                gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&type,1,&nom_list,2,&num_bur,3,&id_list,4,&objet,5,&text, -1);

affiche=lookup_widget(objet_graphique,"ibtihel_reclamation");
gtk_widget_destroy(affiche);

modifier = create_ibtihel_modif_rec ();
  gtk_widget_show (modifier);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"ibti_modif_type_rec1")),type);
gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(modifier,"ibti_modif_noml")),nom_list);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"ibti_modif_num_bv")),num_bur);


//gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier))id_list);

//ident=atoi(id_list);
sprintf(rec.id_list,"%d",id_r);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"spinbutton_modif")),id_r);


//input4=lookup_widget(objet_graphique,"spinbutton9");

gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"ibti_modif_objet")),objet);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"ibti_text")),text);

}


}


void
on_ibti_supprimer_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_aff ;
GtkWidget *ibtihel_reclamation,*ibti_msg_supp;
treeview_aff= lookup_widget(GTK_WIDGET(button),"treeview_aff");
ibti_msg_supp = create_ibti_msg_supp();
gtk_widget_show(ibti_msg_supp);
ibtihel_reclamation = lookup_widget(button,"ibtihel_reclamation");
gtk_widget_destroy (ibtihel_reclamation);

}


void
on_ibti_ajouter_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ibtihel_ajou_rec;
GtkWidget *ibtihel_reclamation;
ibtihel_ajou_rec=create_ibtihel_ajou_rec();
gtk_widget_show (ibtihel_ajou_rec);
ibtihel_reclamation = lookup_widget(button,"ibtihel_reclamation");
gtk_widget_destroy (ibtihel_reclamation);

}


void
on_ibti_actualiser_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_ibti ;
GtkWidget *ibtihel_reclamation,*w1;
treeview_ibti= lookup_widget(GTK_WIDGET(button),"treeview_aff");
w1 = lookup_widget(button,"ibtihel_reclamation");
ibtihel_reclamation=create_ibtihel_reclamation();
gtk_widget_show(ibtihel_reclamation);
gtk_widget_hide(w1);
treeview_ibti= lookup_widget(GTK_WIDGET(ibtihel_reclamation),"treeview_aff");
afficher_reclamation(treeview_ibti);

}


void
on_ibti_retour_ajout_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ibtihel_reclamation , *ibtihel_ajou_rec;
ibtihel_ajou_rec = lookup_widget(button,"ibtihel_ajou_rec");
ibtihel_reclamation=create_ibtihel_reclamation();
gtk_widget_show(ibtihel_reclamation);
gtk_widget_destroy (ibtihel_ajou_rec);

}


void
on_ibti_confirmer_ajout_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
int ident ;
reclamation rec;
GtkWidget *ajout_r,*affiche_r,*treeview_r;
GtkWidget *ibtihel_ajou_rec ;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
input1=lookup_widget(objet_graphique,"ibti_type1");
input2=lookup_widget(objet_graphique,"ibti_nom_liste");
input3=lookup_widget(objet_graphique,"ibti_num_bur1");

input4=lookup_widget(objet_graphique,"spinbutton9");
input5=lookup_widget(objet_graphique,"ibti_obj1");
input6=lookup_widget(objet_graphique,"ibti_text1");


strcpy(rec.type,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(rec.nom_list,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(rec.num_bur,gtk_entry_get_text(GTK_ENTRY(input3)));
ident=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
sprintf(rec.id_list,"%d",ident);

strcpy(rec.objet,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(rec.text,gtk_entry_get_text(GTK_ENTRY(input6)));
ajouter_rec(rec);


gtk_widget_destroy(ajout_r);
affiche_r=create_ibtihel_reclamation();
gtk_widget_show(affiche_r);
treeview_r=lookup_widget(affiche_r,"treeview_aff");
afficher_reclamation(treeview_r);


ibtihel_ajou_rec=create_ibtihel_ajou_rec();
ibtihel_ajou_rec = lookup_widget(objet_graphique,"ibtihel_ajou_rec");
gtk_widget_destroy (ibtihel_ajou_rec);

}


void
on_MAAjouter_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *gestionsdeselections;
GtkWidget *ajout_election, *w3 ;
w3=lookup_widget(button,"gestionsdeselections");

ajout_election=create_ajout_election();
gtk_widget_show (ajout_election);
gtk_widget_destroy (w3);



}


void
on_MAAjouterA_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
election e;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6, *input7;
GtkWidget *MAtree;
GtkWidget *fenetre, *msg, *msg1;
int x;
msg1=lookup_widget(objet,"AE");
gtk_widget_show(msg1);
fenetre=lookup_widget(objet,"ajout_election");
input1=lookup_widget(objet,"MAIdA");
input2=lookup_widget(objet,"MANbrHabitantA");
input3=lookup_widget(objet,"MAJourA");
input4=lookup_widget(objet,"MAMoisA");
input5=lookup_widget(objet,"MAAnneeA");
input6=lookup_widget(objet,"MANbreconseillersA");
input7=lookup_widget(objet,"MAMunicipA");
msg=lookup_widget(objet,"succesA");
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(input1) ) );
e.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3)); 
e.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
e.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5)); 
strcpy(e.NbrH,gtk_entry_get_text(GTK_ENTRY(input2) ) );
strcpy(e.NbrC,gtk_label_get_text(GTK_LABEL(input6) ) );
strcpy(e.Municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));

if (elec_valid==1)
{
ajouter(e);
gtk_widget_show(msg);
}
//Afficherproduit(MAtree,"election.txt");

}


void
on_MAAffichA_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1, *fenetre2, *treeview, *msg ;

msg=lookup_widget(objet,"AffE");
fenetre1=lookup_widget(objet,"gestionsdeselections");

gtk_widget_destroy(fenetre1);
fenetre2=create_affichage_election();

gtk_widget_show (fenetre2);
gtk_widget_show(msg);
treeview=lookup_widget(fenetre2,"MAtree");
Afficher_ele(treeview);
}


void
on_MARetour_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_authentification,*gestionsdeselections,*w3;
admin_authentification=create_admin_authentification();
w3 = lookup_widget(button,"gestionsdeselections");

gtk_widget_show(admin_authentification);
gtk_widget_destroy (w3);


}


void
on_MAtree_row_activated                (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *id;
gchar *Municipalite;

GtkTreeModel *model;
model=gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter (model, &iter, path)) 
   {

    gtk_tree_model_get(GTK_LIST_STORE(model), &iter,ID,&id,MUNICIPALITE2,&Municipalite,-1);
     strcpy(IDEN,id);
     strcpy(MUNICIP,Municipalite);
   //Afficher_ele(treeview);
   }
}


void
on_MAIdentAff_changed                  (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *MAIdentAff;
char id[50]= "";

GtkWidget *tree;
tree =  lookup_widget(editable,"MAtree");

MAIdentAff = lookup_widget(GTK_WIDGET(editable),"MAIdentAff");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(MAIdentAff)));

treeview_chercher(tree,id); 
}


void
on_MAModifierAff_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *affichage_election;
GtkWidget *modif_election, *label ;
label=lookup_widget(objet,"ME");

modif_election=create_modif_election();
gtk_widget_show (modif_election);
gtk_widget_show (label);

affichage_election=lookup_widget(objet,"affichage_election");
gtk_widget_destroy(affichage_election);

}


void
on_MASuppAff_clicked                   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
int x;
GtkTreeModel     *model,*msg;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* MAtree;
        GtkWidget *label;
	msg=lookup_widget(objet_graphique,"Suppression");
        gchar* id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        MAtree=lookup_widget(objet_graphique, "MAtree") ;

        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(MAtree));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView
 		

           supprimer_election(id);
	gtk_widget_show(msg);
}// supprimer la ligne du fichier

}


void
on_MARetourAff_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affichage_election;
GtkWidget *gestionsdeselections ;


gestionsdeselections=create_gestionsdeselections();
gtk_widget_show (gestionsdeselections);

affichage_election=lookup_widget(button,"affichage_election");
gtk_widget_destroy(affichage_election);
}


void
on_MAOkA_clicked                       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
election e;
GtkWidget* input5 ;
GtkWidget* input6;
input5=lookup_widget(objet_graphique, "MANbrHabitantA") ;
input6=lookup_widget(objet_graphique, "MANbreconseillersA") ;
strcpy(e.NbrH,gtk_entry_get_text(GTK_ENTRY(input5) ));
int x;
x=atoi(e.NbrH);
if (x==0)
gtk_label_set_text(GTK_LABEL(input6),"-1");
else
if(x<5001)
gtk_label_set_text(GTK_LABEL(input6),"10");
else if(x<10001)
gtk_label_set_text(GTK_LABEL(input6),"12");
else if(x<25001)
gtk_label_set_text(GTK_LABEL(input6),"16");
else if(x<50001)
gtk_label_set_text(GTK_LABEL(input6),"22");
else if(x<100001)
gtk_label_set_text(GTK_LABEL(input6),"30");
else if(x<500001)
gtk_label_set_text(GTK_LABEL(input6),"40");
else if(x>500001)
gtk_label_set_text(GTK_LABEL(input6),"50");
}


void
on_MAaccepter_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{elec_valid=1;}
else
{elec_valid=0;}
}


void
on_MARetourA_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_election;
GtkWidget *gestionsdeselections ;


gestionsdeselections=create_gestionsdeselections();
gtk_widget_show (gestionsdeselections);

ajout_election=lookup_widget(button,"ajout_election");
gtk_widget_destroy(ajout_election);

}


void
on_MAOkM_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
election e;

GtkWidget *MAIdM;	
GtkWidget* input5 ;
GtkWidget* input6;
input5=lookup_widget(objet_graphique, "MANbrHabitantsM") ;
input6=lookup_widget(objet_graphique, "MANbrconseillerM") ;
	MAIdM=lookup_widget(objet_graphique, "MAIdM") ;
	gtk_label_set_text(GTK_LABEL(MAIdM),"qqqqqqqqqqq");
strcpy(e.NbrH,gtk_entry_get_text(GTK_ENTRY(input5) ));
int x;
x=atoi(e.NbrH);
if (x==0)
gtk_label_set_text(GTK_LABEL(input6),"-1");
else
if(x<5001)
gtk_label_set_text(GTK_LABEL(input6),"10");
else if(x<10001)
gtk_label_set_text(GTK_LABEL(input6),"12");
else if(x<25001)
gtk_label_set_text(GTK_LABEL(input6),"16");
else if(x<50001)
gtk_label_set_text(GTK_LABEL(input6),"22");
else if(x<100001)
gtk_label_set_text(GTK_LABEL(input6),"30");
else if(x<500001)
gtk_label_set_text(GTK_LABEL(input6),"40");
else if(x>500001)
gtk_label_set_text(GTK_LABEL(input6),"50");

}


void
on_MAConfirmM_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestionsdeselections;
		GtkWidget *modif_election ;


		gestionsdeselections=create_gestionsdeselections();
		gtk_widget_show (modif_election);

		modif_election=lookup_widget(objet_graphique,"modif_election");
		gtk_widget_destroy(modif_election);

}


void
on_liste_bureaux_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *id_b;
	gchar *cap_elec;
	gchar *cap_obs;
	gchar *b_adr;
	gchar *salle;
	gchar *id_agentb;
	bureau p;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model, &iter, path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id_b,1,&cap_elec,2,&cap_obs,3,&b_adr,4,&salle,5,&id_agentb, -1);
	strcpy(p.id_b,id_b);
	strcpy(p.cap_elec,cap_elec);
	strcpy(p.cap_obs,cap_obs);
	strcpy(p.b_adr,b_adr);
	strcpy(p.salle,salle);	
	strcpy(p.id_agentb,id_agentb);		
	afficher_bureau(treeview);
	}	
}


void
on_bv_retour1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout,*affiche,*inter,*treeview, *nbResultat;
affiche=lookup_widget(objet,"Bv_page_d_acceuil");
gtk_widget_destroy(affiche);
inter=create_Bv_affinterface();
gtk_widget_show(inter);
}


void
on_bv_Ajouter1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *bv_ajoutunbureau;
GtkWidget *Bv_page_d_acceuil,*acceuil;

acceuil=lookup_widget(objet,"Bv_page_d_acceuil");
bv_ajoutunbureau=create_bv_ajoutunbureau();
gtk_widget_show (bv_ajoutunbureau);
gtk_widget_destroy(acceuil);
}


void
on_bv_Modifier1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char *id_b;
    	char *cap_elec;
    	char *cap_obs;
   	char *b_adr;
   	char *salle;
   	char *id_agentb;
	int a,b,c;
	GtkWidget *affiche, *modifier,*tree;
	GtkWidget *nbResultat;
	nbResultat=lookup_widget(objet,"bv_titrerecherche2");
	gtk_widget_hide(nbResultat);
        GtkTreeModel     *model;
		GtkTreeSelection *selection1;
        GtkTreeIter iter;
tree=lookup_widget(objet,"liste_bureaux");
        selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
selection1 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
        if (gtk_tree_selection_get_selected(selection1, &model, &iter))
        {

      
                gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id_b,1,&cap_elec,2,&cap_obs,3,&b_adr,4,&salle,5,&id_agentb, -1);

affiche=lookup_widget(objet,"Bv_page_d_acceuil");
gtk_widget_destroy(affiche);

modifier = create_bv_modifierunbureau ();
  gtk_widget_show (modifier);
gtk_label_set_text(GTK_ENTRY(lookup_widget(modifier,"bv_spindid2")),id_b);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entry_cap_elec2")),cap_elec);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entry_cap_obs2")),cap_obs);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifier,"entry_bv_adr2")),b_adr);
a=atoi(salle);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(modifier,"bv_spinsalle2")),a);
if (strcmp(id_agentb,"5")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(modifier,"bv_comboagentid2")),5 );
}
else if (strcmp(id_agentb,"4")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(modifier,"bv_comboagentid2")),4 );}
else if (strcmp(id_agentb,"3")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(modifier,"bv_comboagentid2")),3 );}
else if (strcmp(id_agentb,"2")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(modifier,"bv_comboagentid2")),2 );}
else if (strcmp(id_agentb,"1")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(modifier,"bv_comboagentid2")),1 );}
else if (strcmp(id_agentb,"....")==0){
gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(modifier,"bv_comboagentid2")),0 );}
}
}


void
on_bv_Supprimer1_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{

	GtkTreeSelection *selection;
        GtkTreeIter iter;
	GtkTreeModel *model;
        GtkWidget *label, *nbResultat;
        GtkWidget* tree;
   	gchar *id_b;
	gchar *cap_elec;
	gchar *cap_obs;
	gchar *b_adr;
	gchar *salle;
	gchar *id_agentb;
	label=lookup_widget(objet,"bv_labelsupp");
        tree=lookup_widget(objet,"liste_bureaux");
	nbResultat=lookup_widget(objet,"bv_titrerecherche2");
	gtk_widget_hide(nbResultat);
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));
        (gtk_tree_selection_get_selected(selection, &model, &iter)) ;
        gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id_b,1,&cap_elec,2,&cap_obs,3,&b_adr,4,&salle,5,&id_agentb, -1);
        gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
	supprimer_bureau(id_b);
	gtk_widget_show(label);
}


void
on_bv_chercher_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *p1;
GtkWidget *entry, *labelnom;
GtkWidget *nbResultat;
GtkWidget *message;
char id[30];
int b,nb;
entry=lookup_widget(objet,"entry_bv_chercher");
labelnom=lookup_widget(objet,"bv_titrerecherche");
nbResultat=lookup_widget(objet,"bv_titrerecherche2");
gtk_widget_hide(nbResultat);
p1=lookup_widget(objet,"liste_bureaux");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(id,"")==0){
  b=0;
}else{
b=1;
}

if(b==0)
    {return;
    }
    else
    {

nb=Chercherbureau(p1,"bureau.txt",id);
gtk_widget_show (nbResultat);

}
}



void
on_bv_retour2_clicked                  (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout,*affiche,*inter,*treeview, *nbResultat;
ajout=lookup_widget(objet,"bv_ajoutunbureau");
gtk_widget_destroy(ajout);
inter=create_Bv_affinterface();
gtk_widget_show(inter);
}


void
on_bv_check1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{bureau_valid=1;}
else
{bureau_valid=0;}
}


void
on_bv_valider1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
int idb,salle;
bureau p;
GtkWidget *ajout,*affiche,*treeview;
int b=1;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
GtkWidget *labelid, *labelcape, *labelcapobs, *labelbadr, *labelsalle, *labelidagent, *labelvalid, *labelexist, *labeltitre, *labelcoche;

ajout=lookup_widget(objet,"bv_ajoutunbureau");

input1=lookup_widget(objet,"bv_spinid1");
input2=lookup_widget(objet,"entry_cap_elec1");
input3=lookup_widget(objet,"entry_cap_obs1");
input4=lookup_widget(objet,"bv_spinsalle");
input5=lookup_widget(objet,"entry_bv_adr1");
input6=lookup_widget(objet,"bv_comboagentid");

labelid=lookup_widget(objet,"bv_titreid1");
labelcape=lookup_widget(objet,"bv_titrecapelec1");
labelcapobs=lookup_widget(objet,"bv_titrecapobs1");
labelbadr=lookup_widget(objet,"bv_titreadr1");
labelsalle=lookup_widget(objet,"bv_titresalle1");
labelidagent=lookup_widget(objet,"bv_idagentb");
labelvalid=lookup_widget(objet,"bv_titresuccess1");
labelexist=lookup_widget(objet,"bv_titreexiste1");
labeltitre=lookup_widget(objet,"bv_titre1");
labelcoche=lookup_widget(objet,"bv_titrecoche1");

gtk_widget_show(labeltitre);

strcpy(p.id_b,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.cap_elec,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cap_obs,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.b_adr,gtk_entry_get_text(GTK_ENTRY(input5)));
salle=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
sprintf(p.salle,"%d",salle);
strcpy(p.id_agentb,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));

if(strcmp(p.id_b,"")==0){
		  gtk_widget_show (labelid);
b=0;
}
else {
		  gtk_widget_hide(labelid);
}

if(strcmp(p.cap_elec,"")==0){
		  gtk_widget_show (labelcape);
b=0;
}
else {
		  gtk_widget_hide(labelcape);
}
if(strcmp(p.cap_obs,"")==0){
		  gtk_widget_show (labelcapobs);
b=0;
}
else {
		  gtk_widget_hide(labelcapobs);
}
if(strcmp(p.b_adr,"")==0){
		  gtk_widget_show (labelbadr);
b=0;
}
else {
		  gtk_widget_hide(labelbadr);
}
if(strcmp(p.salle,"")==0){
		  gtk_widget_show (labelsalle);
b=0;
}
else {
		  gtk_widget_hide(labelsalle);
}

if(strcmp(p.id_agentb,"....")==0){
		  gtk_widget_show (labelidagent);
b=0;
}
else {
		  gtk_widget_hide(labelidagent);
}
if(bureau_valid==0)
{
gtk_widget_show(labelcoche);
b=0;
}
else {gtk_widget_hide(labelcoche);}

if (b==1)
{
if (bureau_valid==1)
{
if (exist_bureau(p.id_b)==1)
{
gtk_widget_show(labelexist);
}
else
{
gtk_widget_hide(labelexist);
ajouter_bureau(p);
gtk_widget_show (labelvalid);
}
}
}
}



void
on_bv_retour3_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *affiche,*modifier,*treeview;
modifier=lookup_widget(objet,"bv_modifierunbureau");
gtk_widget_destroy(modifier);
affiche=create_Bv_page_d_acceuil();
gtk_widget_show(affiche);
treeview=lookup_widget(affiche,"liste_bureaux");
afficher_bureau(treeview);
}


void
on_bv_check2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
{modif_valid=1;}
else
{modif_valid=0;}
}


void
on_bv_valider2_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
bureau p;
int idb,salle;
int b=1;
GtkWidget *input1, *input2, *input3, *input4 ,*input5, *input6 , *modifier, *labelvalid, *labelid, *labelsalle, *labelcapelec, *labelcapobs, *labeladr, *labelidagent, *labelexist, *labelcoche;
modifier=lookup_widget(objet,"bv_modifierunbureau");
labelvalid=lookup_widget(objet,"bv_titresucces2");
labelid=lookup_widget(objet,"bv_label_idmodif");
labelcapelec=lookup_widget(objet,"bv_titrecapelec2");
labelcapobs=lookup_widget(objet,"bv_titrecapobs2");
labeladr=lookup_widget(objet,"bv_titreadr2");
labelsalle=lookup_widget(objet,"bv_titresalle2");
labelidagent=lookup_widget(objet,"bv_idagentb2");
labelexist=lookup_widget(objet,"bv_titreexiste2");
labelcoche=lookup_widget(objet,"bv_titrecoche2");
input1=lookup_widget(objet,"bv_spindid2");
input2=lookup_widget(objet,"entry_cap_elec2");
input3=lookup_widget(objet,"entry_cap_obs2");
input4=lookup_widget(objet,"entry_bv_adr2");
input5=lookup_widget(objet,"bv_spinsalle2");
input6=lookup_widget(objet,"bv_comboagentid2");

gtk_widget_show(labelid);
strcpy(p.id_b,gtk_label_get_text(GTK_LABEL(input1)));
strcpy(p.cap_elec,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cap_obs,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.b_adr,gtk_entry_get_text(GTK_ENTRY(input4)));
salle=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
sprintf(p.salle,"%d",salle);
strcpy(p.id_agentb,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)));

if(strcmp(p.cap_elec,"")==0){
		  gtk_widget_show (labelcapelec);
b=0;
}
else {
		  gtk_widget_hide(labelcapelec);
}
if(strcmp(p.cap_obs,"")==0){
		  gtk_widget_show (labelcapobs);
b=0;
}
else {
		  gtk_widget_hide(labelcapobs);
}

if(strcmp(p.b_adr,"")==0){
		  gtk_widget_show (labeladr);
b=0;
}
else {
		  gtk_widget_hide(labeladr);
}
if(strcmp(p.salle,"")==0){
		  gtk_widget_show (labelsalle);
b=0;
}
else {
		  gtk_widget_hide(labelsalle);
}

if (modif_valid==0)
{
gtk_widget_show(labelcoche);
b=0;
}
else{gtk_widget_hide(labelcoche);}

if(b==1)
{
	if (modif_valid==1)
{
        if(modif_bureau_exist(p)==1)
        {

		gtk_widget_show (labelexist);

        }
        else {
	gtk_widget_hide (labelexist);
	modifier_bureau(p);
        gtk_widget_show (labelvalid);
               
        }
       }
}               
}



void
on_ibti_confirmer_modif_clicked        (GtkButton       *objet,
                                        gpointer         user_data)
{/*
reclamation rec;
int id_r,salle;
int b=1;
GtkWidget *input1, *input2, *input3, *input4 ,*input5, *input6 , *modifier,*affiche_r,*treeview_r;
modifier=lookup_widget(objet,"ibtihel_modif_rec");

input1=lookup_widget(objet,"ibti_modif_type_rec1");
input2=lookup_widget(objet,"ibti_modif_noml");
input3=lookup_widget(objet,"ibti_modif_num_bv");
input4=lookup_widget(objet,"spinbutton_modif");
input5=lookup_widget(objet,"ibti_modif_objet");
input6=lookup_widget(objet,"ibti_text");



strcpy(rec.type,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(rec.nom_list,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(rec.num_bur,gtk_entry_get_text(GTK_ENTRY(input3)));
id_r=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
sprintf(rec.id_list,"%d",id_r);

strcpy(rec.objet,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(rec.text,gtk_entry_get_text(GTK_ENTRY(input6)));

	modifier_reclamation(rec);

gtk_widget_destroy(modifier);
affiche_r=create_ibtihel_reclamation();
gtk_widget_show(affiche_r);
treeview_r=lookup_widget(affiche_r,"treeview_aff");
afficher_reclamation(treeview_r);*/
}


void
on_ibti_retour_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ibtihel_reclamation , *ibtihel_modif_rec;
ibtihel_modif_rec = lookup_widget(button,"ibtihel_modif_rec");
ibtihel_reclamation=create_ibtihel_reclamation();
gtk_widget_show(ibtihel_reclamation);
gtk_widget_destroy (ibtihel_modif_rec);

}


void
on_ibti_msg_non_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		oui_non=0;

}


void
on_ibti_msg_oui_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		oui_non=1;

}


void
on_ibti_confirmer_supp_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *pInfo ;

if ( oui_non==1)
{	int tr=supprimer_reclamation(IDENT_LIST);
	if (tr==1)
	{
	 	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"SUPPRESSION EFFECTUÉ");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		
		{
			
			gtk_widget_destroy(pInfo);

		
		GtkWidget *ibtihel_reclamation ,*treeview_aff, *ibti_supp_confirmer , *w3;
			
		
		w3 = lookup_widget(button,"ibti_supp_confirmer");
		treeview_aff= lookup_widget(GTK_WIDGET(button),"treeview_aff");
		gtk_widget_show(treeview_aff);
		
		gtk_widget_destroy (w3);
              
		afficher_reclamation(treeview_aff) ;
		GtkWidget *ibti_msg_supp;
		ibti_msg_supp=create_ibti_msg_supp();
		ibti_msg_supp = lookup_widget(button,"ibti_msg_supp");
		gtk_widget_destroy (ibti_msg_supp);
		
		}}}
}
		
else 
{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"SUPPRESSION ANNULÉ");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		
		{gtk_widget_destroy(pInfo);
		GtkWidget *ibtihel_reclamation ,*treeview_aff, *ibti_supp_confirmer , *w3 ,*ibti_msg_supp;
		w3 = lookup_widget(button,"ibti_supp_confirmer");
		//ibtihel_reclamation=create_ibtihel_reclamation();
		//gtk_widget_show(sami_gl_window_gestion);
		gtk_widget_destroy (w3);

		//ibtihel_reclamation=create_ibtihel_reclamation();
		//gtk_widget_show(ibtihel_reclamation);

		afficher_reclamation(treeview_aff) ;
		}}
}               GtkWidget *ibtihel_reclamation ,*ibti_msg_supp;
		ibti_msg_supp=create_ibti_msg_supp();
		ibti_msg_supp = lookup_widget(button,"ibti_msg_supp");
		gtk_widget_destroy (ibti_msg_supp);
		ibtihel_reclamation=create_ibtihel_reclamation();
		gtk_widget_show(ibtihel_reclamation);



}


void
on_Bv_radioajout_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{btnradiointer=0;
}
}


void
on_Bv_radiopageacceuil_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{btnradiointer=1;
}
}


void
on_bv_confirinterface_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *inter,*affiche,*treeview, *result, *ajout;
if (btnradiointer==1)
{
inter=lookup_widget(objet,"Bv_affinterface");
gtk_widget_destroy(inter);
affiche=create_Bv_page_d_acceuil();
gtk_widget_show(affiche);
treeview=lookup_widget(affiche,"liste_bureaux");
afficher_bureau(treeview);
}
if(btnradiointer==0)
{
inter=lookup_widget(objet,"Bv_affinterface");
gtk_widget_destroy(inter);
ajout=create_bv_ajoutunbureau();
gtk_widget_show (ajout);
}
}


void
on_bv_retouradmin_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *acceuil, *treeview, *window;
acceuil=lookup_widget(objet,"Bv_affinterface");
gtk_widget_destroy(acceuil);
window=create_admin_page_accueil ();
gtk_widget_show(window);
}


void
on_sami_bt_logout_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *admin_authentification,*sami_gl_window_acceuil,*w3;
admin_authentification=create_admin_authentification();
w3 = lookup_widget(button,"sami_gl_window_acceuil");

gtk_widget_show(admin_authentification);
gtk_widget_destroy (w3);

}


void
on_sami_bt_acces_gestion_liste_clicked (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *sami_gl_window_acceuil , *sami_gl_window_gestion , *w3;
w3 = lookup_widget(button,"sami_gl_window_acceuil");

sami_gl_window_gestion=create_sami_gl_window_gestion();


gtk_widget_show(sami_gl_window_gestion);
gtk_widget_destroy (w3);


}


void
on_sami_bt_acces_window_voter_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *sami_gl_window_acceuil , *gl_sami_window_vote , *w3;
w3 = lookup_widget(button,"sami_gl_window_acceuil");

gl_sami_window_vote=create_gl_sami_window_vote();


gtk_widget_show(gl_sami_window_vote);
gtk_widget_destroy (w3);

}


void
on_gl_sami_retour_from_ajout_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *sami_gl_window_gestion , *sami_gl_window_aj , *w3;
w3 = lookup_widget(button,"sami_gl_window_aj");

sami_gl_window_gestion=create_sami_gl_window_gestion();


gtk_widget_show(sami_gl_window_gestion);
gtk_widget_destroy (w3);


}


void
on_gl_sami_bt_confirmer_ajout_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
listelec L ;

GtkWidget *entry_sami_municipalite ;
GtkWidget *entry_sami_nomliste ;
GtkWidget *entry_sami_idliste ;
GtkWidget *entry_sami_idteteliste ;
GtkWidget *entry_sami_id1 ;
GtkWidget *entry_sami_id2 ;
GtkWidget *entry_sami_id3 ;
GtkWidget *gl_sami_date_j;
GtkWidget *gl_sami_date_m;
GtkWidget *gl_sami_date_a;
GtkWidget *pInfo1;

//LABEl message

GtkWidget *gl_sami_erreur_nomliste ;
GtkWidget *gl_sami_erreur_idliste ;
GtkWidget *gl_sami_erreur_idteteliste ;
GtkWidget *gl_sami_erreur_id1 ;
GtkWidget *gl_sami_erreur_id2 ;
GtkWidget *gl_sami_erreur_id3 ;
GtkWidget *gl_sami_label_numliste ;



// STRUCT
char municipalite [50];
char nomListe[50] ;
char numListe ;
char idenListe [50] ;
char idenTeteliste [50];
char candidat1 [50];
char candidat2 [50];
char candidat3 [50];



entry_sami_municipalite = lookup_widget (button,"entry_sami_municipalite");
entry_sami_nomliste =lookup_widget (button,"entry_sami_nomliste");
entry_sami_idliste =lookup_widget (button,"entry_sami_idliste");
entry_sami_idteteliste =lookup_widget (button,"entry_sami_idteteliste") ;
entry_sami_id1 = lookup_widget (button,"entry_sami_id1") ;
entry_sami_id2 = lookup_widget (button,"entry_sami_id2") ;
entry_sami_id3 = lookup_widget (button,"entry_sami_id3");
gl_sami_date_j = lookup_widget (button,"gl_sami_date_j");
gl_sami_date_m = lookup_widget (button,"gl_sami_date_m");
//gl_sami_date_a = lookup_widget (button,"gl_sami_date_a ");

//MESSAGE ERREUR

gl_sami_erreur_nomliste = lookup_widget (button,"gl_sami_erreur_nomliste") ;
gl_sami_erreur_idliste = lookup_widget (button,"gl_sami_erreur_idliste") ;
gl_sami_erreur_idteteliste = lookup_widget (button,"gl_sami_erreur_idteteliste") ;
gl_sami_erreur_id1 = lookup_widget (button,"gl_sami_erreur_id1") ;
gl_sami_erreur_id2 = lookup_widget (button,"gl_sami_erreur_id2");
gl_sami_erreur_id3 = lookup_widget (button,"gl_sami_erreur_id3") ;
gl_sami_label_numliste = lookup_widget (button,"gl_sami_label_numliste") ;


strcpy(municipalite, gtk_entry_get_text(GTK_ENTRY(entry_sami_municipalite)));
strcpy(nomListe, gtk_entry_get_text(GTK_ENTRY(entry_sami_nomliste)));
strcpy(idenListe, gtk_entry_get_text(GTK_ENTRY(entry_sami_idliste)));
strcpy(idenTeteliste, gtk_entry_get_text(GTK_ENTRY(entry_sami_idteteliste)));
strcpy(candidat1, gtk_entry_get_text(GTK_ENTRY(entry_sami_id1)));
strcpy(candidat2, gtk_entry_get_text(GTK_ENTRY(entry_sami_id2)));
strcpy(candidat3, gtk_entry_get_text(GTK_ENTRY(entry_sami_id3)));

int NL,IdL,IdTL,id1,id2,id3;
NL=verifier_existant_NL(nomListe);
IdTL=verifier_existant_IdTL(idenTeteliste);
IdL=verifier_existant_IdL(idenListe);
id1=verifier_existant_id1(candidat1);
id2=verifier_existant_id2(candidat2);
id3=verifier_existant_id3(candidat3);


if((NL==0)||(IdTL==0)||(IdL==0)||(id1==0)||(id2==0)||(id3==0)||( strlen (municipalite)==0 )|| (strlen (nomListe)==0 )||(strlen (idenListe)==0 )||(strlen (idenTeteliste)==0 )||(strlen (candidat1)==0 )||(strlen (candidat2)==0) ||(strlen (candidat3)==0 ))


{	


			
			pInfo1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ECHEC D'AJOUT DU LISTE . \n \n    VÉRIFIEZ VOS INFORMATIONS ! ");
			switch(gtk_dialog_run(GTK_DIALOG(pInfo1)))
			{
			case GTK_RESPONSE_OK:
			gtk_widget_destroy(pInfo1);
			break;
			}

	if ( IdL == 0)
	gtk_label_set_text(GTK_LABEL(gl_sami_erreur_idliste), "Identifiant déja existe");
	else gtk_label_set_text(GTK_LABEL(gl_sami_erreur_idliste), "");

	if ( NL==0)
	gtk_label_set_text(GTK_LABEL(gl_sami_erreur_nomliste), "Nom de liste déja existe");
	else gtk_label_set_text(GTK_LABEL(gl_sami_erreur_nomliste), "");

	if (IdTL == 0 )
	gtk_label_set_text(GTK_LABEL(gl_sami_erreur_idteteliste), "Identifiant tête liste déja existe");
	else gtk_label_set_text(GTK_LABEL(gl_sami_erreur_idteteliste), "");

	if ( id1== 0 )
	gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id1), " ID Candidat 1 déja existe");
	else gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id1), "");

	if ( id2 == 0 )
	gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id2), " ID Candidat 2 déja existe");
	else gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id2), "");

	if ( id3 == 0 )
	gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id3), "ID Candidat 3 déja existe");
	else gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id3), "");
}

else
	{
		L.d.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(gl_sami_date_j));
		L.d.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(gl_sami_date_m));
		L.d.a = 2022 ;
		//L.d.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(gl_sami_date_m));
		strcpy(L.municipalite,municipalite);
		strcpy(L.nomListe,nomListe);
		strcpy(L.idenListe,idenListe);
		strcpy(L.idenTeteliste,idenTeteliste);
		strcpy(L.candidat1,candidat1);
		strcpy(L.candidat2,candidat2);
		strcpy(L.candidat3,candidat3);
		L.nbV=0;
		char num_liste [20] ;
		int nbl = det_numliste(L)+1;
		sprintf(num_liste, "%d" , nbl );
		strcpy(L.numListe, num_liste );
FILE * f=fopen("liste.txt", "r");
if ( f!=NULL)
{
while(fscanf(f,"%s \n", L.numListe)!=EOF)
{
if (strcmp(num_liste,L.numListe)!=0)
{ strcpy(L.numListe, num_liste );}
else {nbl ++ ; 
sprintf(num_liste, "%d" , nbl );
strcpy(L.numListe, num_liste );}

}
fclose (f);}


		
		
		
		if ( ajouter_liste(L)  == 1)
		{
			
			gtk_label_set_text(GTK_LABEL(gl_sami_erreur_idliste), "");
			gtk_label_set_text(GTK_LABEL(gl_sami_label_numliste),num_liste);
			gtk_label_set_text(GTK_LABEL(gl_sami_erreur_nomliste), "");
			gtk_label_set_text(GTK_LABEL(gl_sami_erreur_idteteliste), "");
			gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id1), "");
			gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id2), "");
			gtk_label_set_text(GTK_LABEL(gl_sami_erreur_id3), "");
			affichage_gl_flag = 0 ;
			
			
						pInfo1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"VOTRE LISTE A ÉTÉ AJOUTÉ AVEC SUCCÈS ");
			switch(gtk_dialog_run(GTK_DIALOG(pInfo1)))
			{
			case GTK_RESPONSE_OK:
			gtk_widget_destroy(pInfo1);
			GtkWidget *sami_gl_window_gestion , *sami_gl_window_aj , *w3;
			w3 = lookup_widget(button,"sami_gl_window_aj");

			sami_gl_window_gestion=create_sami_gl_window_gestion();


			gtk_widget_show(sami_gl_window_gestion);
			gtk_widget_destroy (w3);

			break;
			}
			
			
			
		}

	}

}


gboolean
on_sami_gl_window_modifier_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
listelec L ; 

affichage_gl_flag=0;
if (affichage_gl_flag==0){
GtkWidget *entry_sami_modifier_municipalite,*gl_sami_label_modifier_numliste,*entry_sami_modifier_nomliste,*entry_sami_modifier_id1,*entry_sami_modifier_id2,*entry_sami_modifier_id3,*gl_date_modifier_j,*gl_date_modifier_m,*gl_date_modifier_a, 
*gl_sami_erreur_modifier_idliste,*gl_sami_erreur_modifier_idteteliste;


entry_sami_modifier_municipalite = lookup_widget(GTK_WIDGET(widget),"entry_sami_modifier_municipalite"); 
entry_sami_modifier_nomliste = lookup_widget(GTK_WIDGET(widget),"entry_sami_modifier_nomliste");
gl_sami_label_modifier_numliste =lookup_widget(GTK_WIDGET(widget),"gl_sami_label_modifier_numliste");
gl_sami_erreur_modifier_idliste = lookup_widget(GTK_WIDGET(widget),"gl_sami_erreur_modifier_idliste");
gl_sami_erreur_modifier_idteteliste = lookup_widget(GTK_WIDGET(widget),"gl_sami_erreur_modifier_idteteliste");
entry_sami_modifier_id1 = lookup_widget(GTK_WIDGET(widget),"entry_sami_modifier_id1");
entry_sami_modifier_id2 = lookup_widget(GTK_WIDGET(widget),"entry_sami_modifier_id2");
entry_sami_modifier_id3 = lookup_widget(GTK_WIDGET(widget),"entry_sami_modifier_id3");




gl_date_modifier_j = lookup_widget(GTK_WIDGET(widget),"gl_date_modifier_j");
gl_date_modifier_m = lookup_widget(GTK_WIDGET(widget),"gl_date_modifier_m");
gl_date_modifier_a = lookup_widget(GTK_WIDGET(widget),"gl_date_modifier_a");


if (strcmp(NomListe,"")!=0){
L = chercher_liste(NomListe);

gtk_entry_set_text(GTK_ENTRY(entry_sami_modifier_municipalite),L.municipalite);
gtk_entry_set_text(GTK_ENTRY(entry_sami_modifier_nomliste),L.nomListe);

gtk_label_set_text(GTK_LABEL(gl_sami_label_modifier_numliste),L.numListe);
gtk_label_set_text(GTK_LABEL(gl_sami_erreur_modifier_idliste),L.idenListe);
gtk_label_set_text(GTK_LABEL(gl_sami_erreur_modifier_idteteliste),L.idenTeteliste);

gtk_entry_set_text(GTK_ENTRY(entry_sami_modifier_id1),L.candidat1);
gtk_entry_set_text(GTK_ENTRY(entry_sami_modifier_id2),L.candidat2);
gtk_entry_set_text(GTK_ENTRY(entry_sami_modifier_id3),L.candidat3);

gtk_spin_button_set_value(gl_date_modifier_j,L.d.j);
gtk_spin_button_set_value(gl_date_modifier_m,L.d.m);
gtk_spin_button_set_value(gl_date_modifier_a,L.d.a);
}

}
strcpy (NomListe,"");
affichage_gl_flag=1;



  return FALSE;
}


void
on_gl_sami_retour_from_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_sami,*sami_gl_window_gestion , *sami_gl_window_modifier , *w3;
w3 = lookup_widget(button,"sami_gl_window_modifier");

sami_gl_window_gestion=create_sami_gl_window_gestion();


gtk_widget_show(sami_gl_window_gestion);
gtk_widget_destroy (w3);
affichage_gl_flag=0 ;

afficher_liste(treeview_sami) ;


}


void
on_gl_sami_bt_confirmer_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_sami_modifier_municipalite,*pInfo1,*entry_sami_modifier_nomliste,*entry_sami_modifier_id1,*entry_sami_modifier_id2,*entry_sami_modifier_id3,*gl_date_modifier_j,*gl_date_modifier_m,*gl_date_modifier_a; 

listelec  NEW ; 



entry_sami_modifier_municipalite = lookup_widget(GTK_WIDGET(button),"entry_sami_modifier_municipalite"); 
entry_sami_modifier_nomliste = lookup_widget(GTK_WIDGET(button),"entry_sami_modifier_nomliste");
entry_sami_modifier_id1 = lookup_widget(GTK_WIDGET(button),"entry_sami_modifier_id1");
entry_sami_modifier_id2 = lookup_widget(GTK_WIDGET(button),"entry_sami_modifier_id2");
entry_sami_modifier_id3 = lookup_widget(GTK_WIDGET(button),"entry_sami_modifier_id3");




gl_date_modifier_j = lookup_widget(GTK_WIDGET(button),"gl_date_modifier_j");
gl_date_modifier_m = lookup_widget(GTK_WIDGET(button),"gl_date_modifier_m");
gl_date_modifier_a = lookup_widget(GTK_WIDGET(button),"gl_date_modifier_a");

GtkWidget *gl_sami_label_modifier_numliste ,*gl_sami_erreur_modifier_idliste,*gl_sami_erreur_modifier_idteteliste,*gl_modifier_erreur_nomliste,*gl_modifier_erreur_id1,*gl_modifier_erreur_id2,*gl_modifier_erreur_id3;

gl_sami_label_modifier_numliste = lookup_widget (button,"gl_sami_label_modifier_numliste") ;
gl_sami_erreur_modifier_idliste = lookup_widget (button,"gl_sami_erreur_modifier_idliste") ;
gl_sami_erreur_modifier_idteteliste = lookup_widget (button,"gl_sami_erreur_modifier_idteteliste") ;
gl_modifier_erreur_nomliste = lookup_widget (button,"gl_modifier_erreur_nomliste") ;
gl_modifier_erreur_id1 = lookup_widget (button,"gl_modifier_erreur_id1") ;
gl_modifier_erreur_id2 = lookup_widget (button,"gl_modifier_erreur_id2") ;
gl_modifier_erreur_id3 = lookup_widget (button,"gl_modifier_erreur_id3") ;



listelec L;





//*******************************


gtk_label_set_text(GTK_LABEL(gl_sami_label_modifier_numliste),"");
gtk_label_set_text(GTK_LABEL(gl_sami_erreur_modifier_idliste), "");
gtk_label_set_text(GTK_LABEL(gl_sami_erreur_modifier_idteteliste),"");


strcpy(NEW.municipalite, gtk_entry_get_text(GTK_ENTRY(entry_sami_modifier_municipalite)));
strcpy(NEW.nomListe, gtk_entry_get_text(GTK_ENTRY(entry_sami_modifier_nomliste)));
strcpy(NEW.candidat1, gtk_entry_get_text(GTK_ENTRY(entry_sami_modifier_id1)));
strcpy(NEW.candidat2, gtk_entry_get_text(GTK_ENTRY(entry_sami_modifier_id2)));
strcpy(NEW.candidat3, gtk_entry_get_text(GTK_ENTRY(entry_sami_modifier_id3)));

NEW.d.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(gl_date_modifier_j));
NEW.d.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(gl_date_modifier_m));
NEW.d.a = 2022 ;





/*int NL,ID1,ID2,ID3;
NL=verifierModNL(NEW.nomListe,NomListe);
ID1=verifierModC(NEW.candidat1,NomListe);
ID2=verifierModC(NEW.candidat2,NomListe);
ID3=verifierModC(NEW.candidat3,NomListe);



if((NL==0)||(ID1==0)||(ID2==0)||(ID3==0))
	{		
	
			


			GtkWidget *pInfo1;
			pInfo1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ECHEC DE MODIFICATION DU LISTE . \n \n    VÉRIFIEZ VOS INFORMATIONS ! ");
			switch(gtk_dialog_run(GTK_DIALOG(pInfo1)))
			{
			case GTK_RESPONSE_OK:

			{	
			gtk_widget_destroy(pInfo1);
			}}

			if (NL==0)
	 			gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_nomliste), "Nom de liste déja existe "); 
			else gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_nomliste), ""); 
				
			if (ID1==0)
				gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id1), "ID Candidat 1 déja existe "); 
			else gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id1), "");

			if (ID2==0)
				gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id2), "ID Candidat 2 déja existe "); 			
			else gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id2), ""); 

			if (ID3==0)
				gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id3), " ID Candidat 3 déja existe"); 
			else gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id3), ""); 



}



else {*/
				
int tr = modifier_liste(  NEW,NumListe ) ; 

if (tr==1)
{				gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_nomliste), ""); 
				gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id1), " "); 			
				gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id2), " "); 			
				gtk_label_set_text(GTK_LABEL(gl_modifier_erreur_id3), " "); 						
	

pInfo1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"VOTRE LISTE A ÉTÉ MODIFIÉE AVEC SUCCÈS ");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo1)))
	{
	case GTK_RESPONSE_OK:
	
	{	GtkWidget *sami_gl_window_gestion ,*treeview_sami, *sami_gl_window_modifier , *w3;
		gtk_widget_destroy(pInfo1);
		
		w3 = lookup_widget(button,"sami_gl_window_modifier");
		treeview_sami= lookup_widget(GTK_WIDGET(button),"treeview_sami");
		gtk_widget_show(treeview_sami);
		sami_gl_window_gestion=create_sami_gl_window_gestion();
		gtk_widget_show(sami_gl_window_gestion);
		gtk_widget_destroy (w3);
		afficher_liste(treeview_sami) ;
		affichage_gl_flag = 0 ;}
	
	break;
	}
}
else {GtkWidget *pInfo1;
			pInfo1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"ECHEC DE MODIFICATION DU LISTE . \n \n    VÉRIFIEZ VOS INFORMATIONS ! ");
			switch(gtk_dialog_run(GTK_DIALOG(pInfo1)))
			{
			case GTK_RESPONSE_OK:

			{	
			gtk_widget_destroy(pInfo1);
			}}}


}


gboolean
on_sami_gl_window_gestion_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
if (affichage_gl_flag ==0)
	{ GtkWidget *treeview_sami ;

	treeview_sami= lookup_widget(GTK_WIDGET(widget),"treeview_sami");

	strcpy(NomListe,"");
	  
	afficher_liste(treeview_sami);}
affichage_gl_flag ==1;


  return FALSE;
}


void
on_entry_sami_recherche_municipalite_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *entry_sami_recherche_municipalite;
char municipalite[50]= "";

GtkWidget *treeview_sami;
treeview_sami =  lookup_widget(editable,"treeview_sami");
GtkWidget *entry_sami_recherche_nomliste;

char nomliste[50]= "";

entry_sami_recherche_nomliste = lookup_widget(GTK_WIDGET(editable),"entry_sami_recherche_nomliste");
strcpy(nomliste,gtk_entry_get_text(GTK_ENTRY(entry_sami_recherche_nomliste)));
treeview_sami_rechercher_nl(treeview_sami,nomliste);

entry_sami_recherche_municipalite = lookup_widget(GTK_WIDGET(editable),"entry_sami_recherche_municipalite");
strcpy(municipalite,gtk_entry_get_text(GTK_ENTRY(entry_sami_recherche_municipalite)));
treeview_sami_rechercher_municip(treeview_sami,municipalite);


}


void
on_entry_sami_recherche_nomliste_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data)
{
GtkWidget *treeview_sami;
GtkWidget *entry_sami_recherche_nomliste;
char nomliste[50]= "";
char municipalite[50]= "";

GtkWidget *entry_sami_recherche_municipalite;



treeview_sami =  lookup_widget(editable,"treeview_sami");

entry_sami_recherche_municipalite = lookup_widget(GTK_WIDGET(editable),"entry_sami_recherche_municipalite");
strcpy(municipalite,gtk_entry_get_text(GTK_ENTRY(entry_sami_recherche_municipalite)));
treeview_sami_rechercher_municip(treeview_sami,municipalite);

entry_sami_recherche_nomliste = lookup_widget(GTK_WIDGET(editable),"entry_sami_recherche_nomliste");
strcpy(nomliste,gtk_entry_get_text(GTK_ENTRY(entry_sami_recherche_nomliste)));
treeview_sami_rechercher_nl(treeview_sami,nomliste);


}


void
on_treeview_sami_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;

gchar *nom_liste, *num_liste;
GtkTreeModel *model ;
model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,NOM_LISTE,&nom_liste,-1);
	strcpy(NomListe,nom_liste);
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,NUM_LISTE,&num_liste,-1);
	strcpy(NumListe,num_liste);
	}
affichage_gl_flag = 0 ;


}


void
on_gl_sami_retour_from_affichage_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *sami_gl_window_acceuil , *sami_gl_window_gestion , *w3;
w3 = lookup_widget(button,"sami_gl_window_gestion");

sami_gl_window_acceuil=create_sami_gl_window_acceuil();


gtk_widget_show(sami_gl_window_acceuil);
gtk_widget_destroy (w3);


}


void
on_gl_sami_bt_modifier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
listelec L ;
if (strlen(NomListe)>0){
GtkWidget *sami_gl_window_modifier , *sami_gl_window_gestion , *w3;
w3 = lookup_widget(button,"sami_gl_window_gestion");

sami_gl_window_modifier=create_sami_gl_window_modifier();


gtk_widget_show(sami_gl_window_modifier);
gtk_widget_destroy (w3);}
else {GtkWidget *gl_msg_double_click;
gl_msg_double_click = lookup_widget(button,"gl_msg_double_click");
gtk_label_set_text(gl_msg_double_click,"CLIQUER DOUBLE FOIS POUR SÉLECTIONNER UNE LISTE!");
}

}


void
on_gl_sami_bt_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
if (strlen(NomListe)>0){

GtkWidget *treeview_sami ;
GtkWidget *sami_gl_window_gestion,*gl_window_confirmation_supp,*w1;



treeview_sami= lookup_widget(GTK_WIDGET(button),"treeview_sami");
gl_window_confirmation_supp = create_gl_window_confirmation_supp();
w1 = lookup_widget(button,"sami_gl_window_gestion");
sami_gl_window_gestion=create_sami_gl_window_gestion();
gtk_widget_show(gl_window_confirmation_supp);
affichage_gl_flag = 0 ;
}

else{
GtkWidget *gl_msg_double_click;
gl_msg_double_click = lookup_widget(button,"gl_msg_double_click");
gtk_label_set_text(gl_msg_double_click,"CLIQUER DOUBLE FOIS POUR SÉLECTIONNER UNE LISTE!");
}

}


void
on_gl_sami_bt_actualiser_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_sami ;


GtkWidget *sami_gl_window_gestion,*w1;

treeview_sami= lookup_widget(GTK_WIDGET(button),"treeview_sami");



w1 = lookup_widget(button,"sami_gl_window_gestion");
sami_gl_window_gestion=create_sami_gl_window_gestion();
gtk_widget_show(sami_gl_window_gestion);
gtk_widget_hide(w1);
treeview_sami= lookup_widget(GTK_WIDGET(sami_gl_window_gestion),"treeview_sami");



afficher_liste(treeview_sami);


affichage_gl_flag = 0 ;

}


void
on_gl_sami_bt_ajouter_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *sami_gl_window_aj , *sami_gl_window_gestion , *w3;
w3 = lookup_widget(button,"sami_gl_window_gestion");
sami_gl_window_aj=create_sami_gl_window_aj();
gtk_widget_show(sami_gl_window_aj);
gtk_widget_destroy (w3);



}


void
on_gl_sami_combobox_changed            (GtkComboBox    *combobox,
                                        gpointer         user_data)
{
GtkWidget *gl_sami_combobox;
GtkWidget *pInfo ;
gl_sami_combobox= lookup_widget(GTK_WIDGET(combobox),"gl_sami_combobox");
strcpy(liste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gl_sami_combobox)));

if (strcmp(liste,"LISTE N°1")==0)
strcpy(liste_vote,"1");

if (strcmp(liste,"LISTE N°2")==0)
strcpy(liste_vote,"2");

if (strcmp(liste,"LISTE N°3")==0)
strcpy(liste_vote,"3");

if (strcmp(liste,"LISTE N°4")==0)
strcpy(liste_vote,"4");

if (strcmp(liste,"LISTE N°5")==0)
strcpy(liste_vote,"5");

if (strcmp(liste,"LISTE N°6")==0)
strcpy(liste_vote,"6");

if (strcmp(liste,"LISTE N°7")==0)
strcpy(liste_vote,"7");

if (strcmp(liste,"LISTE N°8")==0)
strcpy(liste_vote,"8");

if (strcmp(liste,"LISTE N°9")==0)
strcpy(liste_vote,"9");

if (strcmp(liste,"LISTE N°10")==0)
strcpy(liste_vote,"10");

if (strcmp(liste,"LISTE N°11")==0)
strcpy(liste_vote,"11");

if (strcmp(liste,"LISTE N°12")==0)
strcpy(liste_vote,"12");

if (strcmp(liste,"LISTE N°13")==0)
strcpy(liste_vote,"13");

if (strcmp(liste,"LISTE N°14")==0)
strcpy(liste_vote,"14");

if (strcmp(liste,"LISTE N°15")==0)
strcpy(liste_vote,"15");

if (strcmp(liste,"LISTE N°16")==0)
strcpy(liste_vote,"16");

if (strcmp(liste,"LISTE N°17")==0)
strcpy(liste_vote,"17");

if (strcmp(liste,"LISTE N°18")==0)
strcpy(liste_vote,"18");

if (strcmp(liste,"LISTE N°19")==0)
strcpy(liste_vote,"19");

if (strcmp(liste,"LISTE N°20")==0)
strcpy(liste_vote,"20");

if (strcmp(liste,"LISTE N°21")==0)
strcpy(liste_vote,"21");

if (strcmp(liste,"LISTE N°22")==0)
strcpy(liste_vote,"22");

if (strcmp(liste,"LISTE N°23")==0)
strcpy(liste_vote,"23");

if (strcmp(liste,"LISTE N°24")==0)
strcpy(liste_vote,"24");

if (strcmp(liste,"LISTE N°25")==0)
strcpy(liste_vote,"25");

if (strcmp(liste,"LISTE N°26")==0)
strcpy(liste_vote,"26");

if (strcmp(liste,"LISTE N°27")==0)
strcpy(liste_vote,"27");

if (strcmp(liste,"LISTE N°28")==0)
strcpy(liste_vote,"28");

if (strcmp(liste,"LISTE N°29")==0)
strcpy(liste_vote,"29");

if (strcmp(liste,"LISTE N°30")==0)
strcpy(liste_vote,"30");

if (strcmp(liste,"LISTE N°31")==0)
strcpy(liste_vote,"31");

if (strcmp(liste,"LISTE N°32")==0)
strcpy(liste_vote,"32");

if (strcmp(liste,"LISTE N°33")==0)
strcpy(liste_vote,"33");

if (strcmp(liste,"LISTE N°34")==0)
strcpy(liste_vote,"34");

if (strcmp(liste,"LISTE N°35")==0)
strcpy(liste_vote,"35");

if (strcmp(liste,"LISTE N°36")==0)
strcpy(liste_vote,"36");

if (strcmp(liste,"LISTE N°37")==0)
strcpy(liste_vote,"37");

if (strcmp(liste,"LISTE N°38")==0)
strcpy(liste_vote,"38");

if (strcmp(liste,"LISTE N°39")==0)
strcpy(liste_vote,"39");

if (strcmp(liste,"LISTE N°40")==0)
strcpy(liste_vote,"40");

if (strcmp(liste,"LISTE N°41")==0)
strcpy(liste_vote,"41");

if (strcmp(liste,"LISTE N°42")==0)
strcpy(liste_vote,"42");

if (strcmp(liste,"LISTE N°43")==0)
strcpy(liste_vote,"43");

if (strcmp(liste,"LISTE N°44")==0)
strcpy(liste_vote,"44");

if (strcmp(liste,"LISTE N°45")==0)
strcpy(liste_vote,"45");

if (strcmp(liste,"LISTE N°46")==0)
strcpy(liste_vote,"46");

if (strcmp(liste,"LISTE N°47")==0)
strcpy(liste_vote,"47");

if (strcmp(liste,"LISTE N°48")==0)
strcpy(liste_vote,"48");

if (strcmp(liste,"LISTE N°49")==0)
strcpy(liste_vote,"49");

if (strcmp(liste,"LISTE N°50")==0)
strcpy(liste_vote,"50");



}


void
on_gl_sami_checkbt_vote_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))


{vote_blanc = 1;}


}


void
on_gl_sami_retour_from_vote_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *sami_gl_window_acceuil , *gl_sami_window_vote , *w3;
w3 = lookup_widget(button,"gl_sami_window_vote");

sami_gl_window_acceuil=create_sami_gl_window_acceuil();


gtk_widget_show(sami_gl_window_acceuil);
gtk_widget_destroy (w3);


}


void
on_gl_sami_bt_confirmer_vote_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
if ( strcmp(liste,"")!=0  && vote_blanc==0)
{
int tr = vote(liste_vote);
strcpy(liste,"");
GtkWidget *pInfo ;
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"VOTRE CHOIX A ÉTÉ ENREGISTRÉ AVEC SUCCÈS");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
				{gtk_widget_destroy(pInfo);
GtkWidget *treeview_sami,*sami_gl_window_gestion , *gl_sami_window_vote , *w3;
w3 = lookup_widget(button,"gl_sami_window_vote");

sami_gl_window_gestion=create_sami_gl_window_gestion();


gtk_widget_show(sami_gl_window_gestion);
gtk_widget_destroy (w3);
affichage_gl_flag=0 ;

afficher_liste(treeview_sami) ;}}

}
else if ( strcmp(liste,"")==0 && vote_blanc==1)
{
		k++;
		GtkWidget *pInfo,*gl_sami_checkbt_vote ;
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"VOTRE CHOIX A ÉTÉ ENREGISTRÉ AVEC SUCCÈS");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		
		{
			
		gtk_widget_destroy(pInfo);
		GtkWidget *treeview_sami,*sami_gl_window_gestion , *gl_sami_window_vote , *w3;
		w3 = lookup_widget(button,"gl_sami_window_vote");

		sami_gl_window_gestion=create_sami_gl_window_gestion();


		gtk_widget_show(sami_gl_window_gestion);
		gtk_widget_destroy (w3);
		affichage_gl_flag=0 ;

		afficher_liste(treeview_sami) ;}}
		 vote_blanc =0;}

else  {
		GtkWidget *pInfo ;
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"VERIFIEZ VOTRE CHOIX");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		
		{
			
		gtk_widget_destroy(pInfo);
	vote_blanc =0;
}}}

}


void
on_gl_sami_radiobt_oui_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		radio_oui_non=1;

}


void
on_gl_sami_radiobt_non_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		radio_oui_non=0;

}


void
on_gl_sami_confirmer_supp_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *pInfo ;

if ( radio_oui_non ==1)
{	int tr=supprimer_liste(NomListe);
	if (tr==1)
	{			pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"LISTE SUPPRIMÉE AVEC SUCCÈS");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		
		{
			
		gtk_widget_destroy(pInfo);
		
		GtkWidget *sami_gl_window_gestion ,*treeview_sami, *gl_window_confirmation_supp , *w3;
			
		
		w3 = lookup_widget(button,"gl_window_confirmation_supp");
		treeview_sami= lookup_widget(GTK_WIDGET(button),"treeview_sami");
		gtk_widget_show(treeview_sami);
		sami_gl_window_gestion=create_sami_gl_window_gestion();
		gtk_widget_destroy (w3);
		afficher_liste(treeview_sami) ;
		affichage_gl_flag = 0 ;}}}
}
else 
{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"SUPPRESSION ANNULÉ");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		
		{gtk_widget_destroy(pInfo);
		GtkWidget *sami_gl_window_gestion ,*treeview_sami, *gl_window_confirmation_supp , *w3;
		w3 = lookup_widget(button,"gl_window_confirmation_supp");
		sami_gl_window_gestion=create_sami_gl_window_gestion();
		//gtk_widget_show(sami_gl_window_gestion);
		gtk_widget_destroy (w3);
		afficher_liste(treeview_sami) ;
		affichage_gl_flag = 0 ;}}
}


}
void
on_treeview_sami_stats_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;

gchar *nom_liste, *num_liste;
GtkTreeModel *model ;
model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,NOM_LISTE,&nom_liste,-1);
	strcpy(NomListe,nom_liste);
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,NUM_LISTE,&num_liste,-1);
	strcpy(NumListe,num_liste);
	}
affichage_gl_flag = 0 ;

}



void
on_MAConfirmC_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
int x ;
election E;
GtkWidget* input1,*input0, *msg;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* treeview;
char id0[50];
msg=lookup_widget(button,"SuccesM");
input0=lookup_widget(button,"MAIdM");
input2=lookup_widget(button,"MAJourM");
input3=lookup_widget(button,"MAMoisM");
input4=lookup_widget(button,"MAAnneeM");
input5=lookup_widget(button, "MANbrHabitantsM") ;
input6=lookup_widget(button, "MANbrconseillerM") ;
input7=lookup_widget(button, "MAMunicipM") ;
treeview=lookup_widget(button, "MAtree") ;


strcpy(id0, gtk_entry_get_text(GTK_ENTRY(input0)));

E.date.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
E.date.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
E.date.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));

strcpy(E.NbrH,gtk_entry_get_text(GTK_ENTRY(input5) ) );
strcpy(E.NbrC,gtk_label_get_text(GTK_LABEL(input6) ) );

strcpy(E.Municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));

strcpy(E.id,id0);


modifier(E.id,E);
gtk_widget_show(msg);
//Afficherproduit(treeview,"election.txt");

}



gboolean
on_ibtihel_reclamation_focus_in_event  (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{{ GtkWidget *treeview_aff ;

	treeview_aff= lookup_widget(GTK_WIDGET(widget),"treeview_aff");

	strcpy(IDENT_LIST,"");
	  
	afficher_reclamation(treeview_aff);  }



  return FALSE;
}



void
on_bv_btn_stat2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *resultat;
char vb[20];
resultat=lookup_widget(objet,"bv_stat2_vb");
sprintf(vb,"%d",k);
gtk_label_set_text(GTK_LABEL(resultat),vb);
}


void
on_bv_btn_stat1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *label1, *label2;
label1=lookup_widget(objet,"bv_stat_resobs1");
label2=lookup_widget(objet,"bv_stat_resobs2");
char fich[20]="coord.txt";
char taux_tn[20];
char taux_et[20];
int x,y;
float tn,et;
x=taux_obsertn(fich);
y=taux_obser(fich);
tn=((float)x/y)*100;
et=((float)(y-x)/y)*100;
sprintf(taux_tn,"%.2f",tn);
sprintf(taux_et,"%.2f",et);
strcat(taux_tn,"%");
strcat(taux_et,"%");
gtk_label_set_text(GTK_LABEL(label1),taux_tn);
gtk_label_set_text(GTK_LABEL(label2),taux_et);

}


gboolean
on_window_statistique_focus_in_event   (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{
if (affichage_gl_flag ==0)
	{ GtkWidget *treeview_sami_stats ;

	treeview_sami_stats= lookup_widget(GTK_WIDGET(widget),"treeview_sami_stats");

	strcpy(NomListe,"");
	  
	afficher_liste_trier(treeview_sami_stats);}
affichage_gl_flag ==1;





  return FALSE;
}


void
on_liste_stats_decroissant_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview_sami_stats ;


GtkWidget *window_statistique,*w1;

treeview_sami_stats= lookup_widget(GTK_WIDGET(button),"treeview_sami_stats");



w1 = lookup_widget(button,"window_statistique");
window_statistique=create_window_statistique();
gtk_widget_show(window_statistique);
gtk_widget_hide(w1);
treeview_sami_stats= lookup_widget(GTK_WIDGET(button),"treeview_sami_stats");
create_fichier_aff ( "liste_aff.txt");

trier_decroissant("liste_aff.txt");


afficher_liste_trier(treeview_sami_stats);


affichage_gl_flag = 0 ;



}


void
on_liste_stats_croissant_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview_sami_stats ;


GtkWidget *window_statistique,*w1;

treeview_sami_stats= lookup_widget(GTK_WIDGET(button),"treeview_sami_stats");



w1 = lookup_widget(button,"window_statistique");
window_statistique=create_window_statistique();
gtk_widget_show(window_statistique);
gtk_widget_hide(w1);
treeview_sami_stats= lookup_widget(GTK_WIDGET(button),"treeview_sami_stats");

create_fichier_aff ( "liste_aff.txt");

trier_croissant("liste_aff.txt");

afficher_liste_trier(treeview_sami_stats);



affichage_gl_flag = 0 ;


}


void
on_retour_from_stats_liste_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *window_statistique , *admin_page_accueil , *w3;
w3 = lookup_widget(button,"window_statistique");

admin_page_accueil=create_admin_page_accueil();


gtk_widget_show(admin_page_accueil);
gtk_widget_destroy (w3);


}


void
on_admin_nbr_obv_calcul_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
char obv[3];
GtkWidget *label;
label=lookup_widget(objet,"aff_nbr_obv_calcul");
int nbr_obv;
nbr_obv=nbr_tot_obv();

sprintf(obv,"%d",nbr_obv);

gtk_label_set_text(GTK_LABEL(label),obv);


}


void
on_ibti_retour_stat_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_statistique , *admin_page_accueil , *w3;
w3 = lookup_widget(button,"window_statistique");

admin_page_accueil=create_admin_page_accueil();


gtk_widget_show(admin_page_accueil);
gtk_widget_destroy (w3);

}


void
on_refreshNRLE_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;	
	treeview = lookup_widget(objet,"treeviewRLE");
	nombreReclListe(treeview);
}


void
on_ValiderNR_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *output ;

	output = lookup_widget(objet,"outputReclNb");

	int x = nbTotal("reclamtion.txt");
	char message[10] ; 

	sprintf(message,"%d",x);
	gtk_label_set_text(GTK_LABEL(output),message);	

}



void
on_id_mod_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *MAIdM, *MANbrHabitantsM, *MAJourM, *MAMoisM, *MAAnneeM, *MANbrconseillerM, *MAMunicipM;
char id0[50];
election E;

MAIdM= lookup_widget(GTK_WIDGET(button),"MAIdM"); 
MANbrHabitantsM = lookup_widget(GTK_WIDGET(button),"MANbrHabitantsM"); 
MAJourM = lookup_widget(GTK_WIDGET(button),"MAJourM");
MAMoisM = lookup_widget(GTK_WIDGET(button),"MAMoisM");
MAAnneeM = lookup_widget(GTK_WIDGET(button),"MAAnneeM");
MANbrconseillerM = lookup_widget(GTK_WIDGET(button),"MANbrconseillerM");
MAMunicipM = lookup_widget(GTK_WIDGET(button),"MAMunicipM");

strcpy(id0, gtk_entry_get_text(GTK_ENTRY(MAIdM)));
if (strcmp(id0,"")!=0)
{
E=chercher_id(id0); 


gtk_entry_set_text(GTK_ENTRY(MANbrHabitantsM),E.NbrH);
gtk_spin_button_set_value(MAJourM,E.date.jour);
gtk_spin_button_set_value(MAMoisM,E.date.mois);
gtk_spin_button_set_value(MAAnneeM,E.date.annee);
gtk_label_set_text(GTK_LABEL(MANbrconseillerM),E.NbrC);



if(strcmp(E.Municipalite,"Tunis")==0)
{
Munic=0;
}

else if(strcmp(E.Municipalite,"Bizerte")==0)
{
Munic=1;
}


else if(strcmp(E.Municipalite,"Sousse")==0)
{
Munic=2;
}

else if(strcmp(E.Municipalite,"Nabeul")==0)
{
Munic=3;
}

else if(strcmp(E.Municipalite,"Hammamet")==0)
{
Munic=4;
}

gtk_combo_box_set_active(GTK_COMBO_BOX(MAMunicipM),Munic);

}
}


void
on_admin_valider_modif_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
coord nouv; coord q; int test=0; int n=1;

GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7,
          *input8, *input9, *input10 , *input11, *input12 , *input13, *input14;

GtkWidget *fenetre1,  *fenetre2;
GtkWidget *saisie_coordonnee_modif, *CRUD_admin;
GtkWidget *treeview5;

GtkWidget *labelvalid, *labelexistant, *labelvide;

fenetre1=lookup_widget(objet_graphique,"saisie_coordonnee");
//fenetre2=lookup_widget (objet_graphique,"CRUD_admin");

//labelvalid=lookup_widget(objet_graphique,"label190");
//labelexistant=lookup_widget(objet_graphique,"label189");
//labelvide=lookup_widget(objet_graphique,"message-erreur");

input1=lookup_widget(objet_graphique,"admin_cin_modif");
input2=lookup_widget(objet_graphique,"admin_nom_modif");
input3=lookup_widget(objet_graphique,"admin_prenom_modif");
input4=lookup_widget(objet_graphique,"adm_date_j_modif");
input5=lookup_widget(objet_graphique,"adm_date_m_modif");
input6=lookup_widget(objet_graphique,"adm_date_a_modif");
input7=lookup_widget(objet_graphique,"admin_nationalite_modif");
input8=lookup_widget(objet_graphique,"admin_sexe_modif");
input9=lookup_widget(objet_graphique,"admin_tel_modif");
input10=lookup_widget(objet_graphique,"admin_mail_modif");
input11=lookup_widget(objet_graphique,"admin_role_modif");
input12=lookup_widget(objet_graphique,"admin_num_bureau_modif");
input13=lookup_widget(objet_graphique,"admin_profession_modif");
input14=lookup_widget(objet_graphique,"admin_vote_modif");


strcpy(nouv.id_CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nouv.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nouv.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nouv.nationalite,gtk_entry_get_text(GTK_ENTRY(input7)));

nouv.d_d_n.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
nouv.d_d_n.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
nouv.d_d_n.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(nouv.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));
 
strcpy(nouv.num_tel,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(nouv.adresse_mail,gtk_entry_get_text(GTK_ENTRY(input10)));

strcpy(nouv.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input11)));
 

strcpy(nouv.num_bureau,gtk_entry_get_text(GTK_ENTRY(input12)));
strcpy(nouv.profession,gtk_entry_get_text(GTK_ENTRY(input13)));

int input15=1;
choix_vote(input15,nouv.vote);

/*if ( (strcmp(p.id_CIN,"")==0) || (strcmp(p.nom,"")==0) ||(strcmp(p.prenom,"")==0) ||(strcmp(p.sexe,"")==0) ||(strcmp(p.nationalite,"")==0) ||(strcmp(p.adresse_mail,"")==0) ||(strcmp(p.num_tel,"")==0) ||(strcmp(p.num_bureau,"")==0) ||(strcmp(p.vote,"")==0) ||(strcmp(p.profession,"")==0) ||(strcmp(p.role,"")==0) )
{ n=0;
//gtk_widget_show (labelvide); 
}

if (n==1)
  {  FILE *f=fopen("coord.txt","a+");

if (strlen(p.id_CIN)==8) 
 { while (test==0&& fscanf(f,"%s %s %s %d %d %d %s %s %s %s %s %s %s %s",q.id_CIN, q.nom, q.prenom, &q.d_d_n.jour,&q.d_d_n.mois,&q.d_d_n.annee,q.sexe,q.nationalite, q.num_tel, q.adresse_mail, q.role, q.num_bureau, q.profession, q.vote)!=EOF)
  if (strcmp(p.id_CIN, q.id_CIN)==0) 
    test=1;
  }
else test=1;

if (test==0)*/
//{gtk_widget_show(labelvalid);
salma_modifier(nouv.id_CIN,nouv);
gtk_widget_destroy(fenetre1);
fenetre2=create_CRUD_admin();

gtk_widget_show(fenetre2);
treeview5=lookup_widget(fenetre2,"treeview5");
salma_afficher(treeview5);
//}
/*else 
 gtk_widget_show(labelexistant);
}*/
}


void
on_admin_retour_modif_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre1, *fenetre2, *treeview; 
fenetre1=lookup_widget(objet,"saisie_coordonnee_modif");
treeview=lookup_widget(objet,"treeview5");
fenetre2=create_CRUD_admin();
salma_afficher(treeview);
gtk_widget_show(fenetre2);
gtk_widget_destroy(fenetre1);
}


void
on_gl_sami_bt_stats_clicked   (GtkWidget       *button,
                               gpointer         user_data)
{
GtkWidget *window_statistique , *sami_gl_window_gestion , *w3;
w3 = lookup_widget(button,"sami_gl_window_gestion");

window_statistique=create_window_statistique();


gtk_widget_show(window_statistique);
gtk_widget_destroy (w3);


}

