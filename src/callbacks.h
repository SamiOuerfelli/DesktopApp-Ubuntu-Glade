#include <gtk/gtk.h>
#include "fonction_sami.h"


/*void
on_refreshNRLE_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_ValiderNR_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);*/
void
on_admin_connexion_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_admin_mdp_oublie_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_Retour1_CRUD_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_valider_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_admin_recherche_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_admin_ajoutp1_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_modif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_suppression_clicked           (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_retour_accueil_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_admin_liste_elec_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_admin_liste_utilisateur_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_liste_obv_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_reclamation_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_deconnexion_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_gest_bv_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_admin_gest_elec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_admin_gestion_util_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_admin_stat_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview7_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Retour_liste_accueil_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_renvoi_mdp_mail_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_renvoi_num_tel_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview_aff_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ibti_retour_acceuil_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_ibti_chercher_rec_clicked           (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ibti_modifier_rec_clicked           (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_ibti_supprimer_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_ibti_ajouter_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ibti_actualiser_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ibti_retour_ajout_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ibti_confirmer_ajout_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_MAAjouterA_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MAAffichA_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_MARetour_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_MAtree_row_activated                (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MAIdentAff_changed                  (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_MASuppAff_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_MARetourAff_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_MAOkA_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_MAaccepter_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MARetourA_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_MAOkM_clicked                       (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_MAConfirmM_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_liste_bureaux_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bv_retour1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_Ajouter1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_Modifier1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_Supprimer1_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_chercher_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_retour2_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_check1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bv_valider1_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_retour3_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_check2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bv_valider2_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ibti_confirmer_modif_clicked        (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ibti_retour_modif_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ibti_msg_non_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ibti_msg_oui_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ibti_confirmer_supp_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_Bv_radioajout_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Bv_radiopageacceuil_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bv_confirinterface_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_retouradmin_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_sami_bt_logout_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_sami_bt_acces_gestion_liste_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_sami_bt_acces_window_voter_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_retour_from_ajout_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_bt_confirmer_ajout_clicked  (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_sami_gl_window_modifier_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_gl_sami_retour_from_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_bt_confirmer_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_sami_gl_window_gestion_focus_in_event
                                        (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_entry_sami_recherche_municipalite_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry_sami_recherche_nomliste_changed
                                        (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_treeview_sami_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gl_sami_retour_from_affichage_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_bt_modifier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_bt_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_bt_actualiser_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_bt_ajouter_clicked          (GtkButton       *button,
                                        gpointer         user_data);


void
on_gl_sami_checkbt_vote_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gl_sami_retour_from_vote_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_bt_confirmer_vote_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_radiobt_oui_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gl_sami_radiobt_non_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gl_sami_confirmer_supp_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_MAConfirmC_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_gl_sami_combobox_changed            (GtkComboBox     *combobox,
                                        gpointer         user_data);

gboolean
on_ibtihel_reclamation_focus_in_event  (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);




void
on_treeview_sami_stats_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_bv_btn_stat2_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bv_btn_stat1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

gboolean
on_window_statistique_focus_in_event   (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_liste_stats_decroissant_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_liste_stats_croissant_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_from_stats_liste_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_admin_nbr_obv_calcul_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ibti_retour_stat_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_refreshNRLE_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ValiderNR_clicked                   (GtkButton       *objet,
                                        gpointer         user_data);

void
on_MAAjouter_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_MAModifierAff_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_id_mod_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_admin_valider_modif_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_admin_retour_modif_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_gl_sami_bt_stats_clicked   (GtkWidget       *button,
                               gpointer         user_data);
