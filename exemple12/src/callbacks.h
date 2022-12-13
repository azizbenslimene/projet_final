#include <gtk/gtk.h>


void
on_tableau_row_activated               (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_rechercher_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_nbv_4_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbv_3_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbv_2_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbv_1_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_urg_rec_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_moy_rec_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fai_rec_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajouter2_rec_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_afficher_rec_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_supp_rec_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_rech_mod_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_nbv_1_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbv_2_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbv_3_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbv_4_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mod_mod_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_retour_mod_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_urg_mod_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_moy_mod_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fai_mod_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbv_stat_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_nle_stat_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_somme_stat_clicked                  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ret_stat_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_statistique_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);
