#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"


int ET=0;
int OU=0;
int OR=0;
int AND=0;
reclamation recDeleted;
void
on_tableau_row_activated               (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;

gchar*id;
gint* jour;
gint* mois;
gint* annee;
gchar* nle_rec;
gchar* nbv_rec ;
gchar* categ_rec ;
gchar* desc_rec ;


GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&jour,2,&mois,3,&annee,4,&nle_rec,5,&nbv_rec,6,&categ_rec,7,&desc_rec,-1);


strcpy(recDeleted.id_rec,id);
recDeleted.date_rec.jour_rec=jour;
recDeleted.date_rec.mois_rec=mois;
recDeleted.date_rec.annee_rec=annee;

strcpy(recDeleted.nle_rec,nle_rec);
strcpy(recDeleted.nbv_rec,nbv_rec);
strcpy(recDeleted.categ_rec,categ_rec);
strcpy(recDeleted.desc_rec,desc_rec);





}
}

void
on_rechercher_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;

GtkWidget *treeview;

GtkWidget  *id_entry;
reclamation rec ;
char id[20];
id_entry = lookup_widget (objet,"entry1");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(id_entry)));

rec=chercher(id,"reclamation.txt");
 FILE *f=fopen("search.txt","w");
if(f!=NULL){
        fprintf(f," %s %d %d %d %s %s %s %s \n",rec.id_rec,rec.date_rec.jour_rec,rec.date_rec.mois_rec,rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec);
      
   
}
 fclose(f);
w1=lookup_widget(objet,"affichage");
fenetre_afficher=create_affichage();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"tableau");
afficher_rec(treeview,"search.txt");
}


void
on_supprimer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*fenetre_ajout;
GtkWidget*fenetre_afficher;
GtkWidget*treeview;

fenetre_ajout = lookup_widget(objet,"affichage");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"supprimer");
fenetre_afficher=create_supprimer();
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"tableau");
}


void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*fenetre_ajout;
GtkWidget*fenetre_afficher;
GtkWidget*treeview;

fenetre_ajout = lookup_widget(objet,"affichage");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"modifier");
fenetre_afficher=create_modifier();
gtk_widget_show(fenetre_afficher);









GtkWidget *id;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *nle_rec;
GtkWidget *categ_rec;
GtkWidget *desc_rec;
GtkWidget *nbv1,*nbv2,*nbv3,*nbv4;
GtkWidget *urg_mod,*moy_mod,*fai_mod;



id=lookup_widget(fenetre_afficher,"entry2");
jour=lookup_widget(fenetre_afficher,"jour_mod");
mois=lookup_widget(fenetre_afficher,"mois_mod");
annee=lookup_widget(fenetre_afficher,"annee_mod");
nle_rec=lookup_widget(fenetre_afficher,"nle_mod");
nbv1=lookup_widget(fenetre_afficher,"nbv_1_mod");
nbv2=lookup_widget(fenetre_afficher,"nbv_2_mod");
nbv3=lookup_widget(fenetre_afficher,"nbv_3_mod");
nbv4=lookup_widget(fenetre_afficher,"nbv_4_mod");
urg_mod=lookup_widget(fenetre_afficher,"urg_mod");
moy_mod=lookup_widget(fenetre_afficher,"moy_mod");
fai_mod=lookup_widget(fenetre_afficher,"fai_mod");
desc_rec=lookup_widget(fenetre_afficher,"desc_mod");



reclamation rec=chercher("utilisateur.txt",recDeleted.id_rec);





gtk_entry_set_text(GTK_ENTRY(id),recDeleted.id_rec);
gtk_entry_set_text(GTK_ENTRY(desc_rec),recDeleted.desc_rec);


int i;
if(strcmp(recDeleted.nle_rec,"1")==0)i=0;
if(strcmp(recDeleted.nle_rec,"2")==0)i=1;
if(strcmp(recDeleted.nle_rec,"3")==0)i=2;


 gtk_combo_box_set_active(GTK_COMBO_BOX(nle_rec),i);

	 gtk_spin_button_set_value(jour,recDeleted.date_rec.jour_rec);
	 gtk_spin_button_set_value(mois,recDeleted.date_rec.mois_rec);
	 gtk_spin_button_set_value(annee,recDeleted.date_rec.annee_rec);




if(strcmp(recDeleted.nbv_rec,"1")==0) {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv1),TRUE);gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv2),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv3),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv4),FALSE);
}
           
	


else if(strcmp(recDeleted.nbv_rec,"2")==0) {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv2),TRUE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv1),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv3),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv4),FALSE);
}
           
else if(strcmp(recDeleted.nbv_rec,"3")==0) {   gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv3),TRUE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv1),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv2),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv4),FALSE);
}
           
else{gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv4),TRUE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv1),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv2),FALSE);
gtk_toggle_button_set_active(GTK_CHECK_BUTTON(nbv3),FALSE);
}
           


if(strcmp(recDeleted.categ_rec,"urgent")==0) {  
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(urg_mod),TRUE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(moy_mod),FALSE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(fai_mod),FALSE);

}
           

if(strcmp(recDeleted.categ_rec,"faible")==0) {  
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(urg_mod),FALSE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(moy_mod),FALSE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(fai_mod),TRUE);

}

if(strcmp(recDeleted.categ_rec,"moyenne")==0) {  
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(urg_mod),FALSE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(moy_mod),TRUE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(fai_mod),FALSE);

}






}



void
on_ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*fenetre_ajout;
GtkWidget*fenetre_afficher;
GtkWidget*treeview;
GtkWidget*output;

fenetre_ajout = lookup_widget(objet,"affichage");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"remplissage");
fenetre_afficher=create_remplissage();
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"tableau");



}


void
on_nbv_4_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OU=4;
}


void
on_nbv_3_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OU=3;
}


void
on_nbv_2_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OU=2;
}


void
on_nbv_1_rec_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OU=1;
}


void
on_urg_rec_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 ET=1;
}


void
on_moy_rec_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 ET=2;
}


void
on_fai_rec_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 ET=3;
}


void
on_ajouter2_rec_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*id_rec;
GtkWidget*jour_rec;
GtkWidget*mois_rec;
GtkWidget*annee_rec;
GtkWidget*nle_rec;

GtkWidget*desc_rec;
GtkWidget*fenetre_ajout;
reclamation rec ;


id_rec = lookup_widget (objet,"id2_rec" );
jour_rec = lookup_widget (objet,"jour_rec" );
mois_rec = lookup_widget (objet,"mois_rec" );
annee_rec = lookup_widget (objet,"annee_rec" );
nle_rec = lookup_widget (objet,"nle_rec" );
desc_rec = lookup_widget (objet,"desc_rec" );

GtkWidget* msg;
GtkWidget* cmnt;
strcpy(rec.id_rec,gtk_entry_get_text(GTK_ENTRY(id_rec)));
rec.date_rec.jour_rec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_rec));
rec.date_rec.mois_rec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_rec));
rec.date_rec.annee_rec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_rec));
strcpy(rec.nle_rec,gtk_combo_box_get_active_text (GTK_COMBO_BOX(nle_rec)));
strcpy(rec.desc_rec,gtk_entry_get_text(GTK_ENTRY(desc_rec)));
fenetre_ajout=lookup_widget(objet,"remplissage");

msg=lookup_widget(fenetre_ajout,"aj");
cmnt=lookup_widget(fenetre_ajout,"cmnt");
if(verif(rec.id_rec)==1){
ajouter (rec,ET,OU);
gtk_widget_show(msg);
} else {gtk_widget_hide(msg);
gtk_widget_show(cmnt);}
}



void
on_afficher_rec_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{

GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview;
reclamation rec;

fenetre_ajout = lookup_widget(objet,"remplissage");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"affichage");
fenetre_afficher=create_affichage();
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"tableau");
afficher_rec(treeview,"reclamation.txt");

}


void
on_supp_rec_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
char supp [20];
reclamation rec ;

GtkWidget *fenetre_afficher,*sup,*w1;
GtkWidget *treeview;

sup= lookup_widget (objet,"entrysupp" );
strcpy(supp,gtk_entry_get_text(GTK_ENTRY(sup)));
supprimer_rec( supp ,"reclamation.txt");

w1=lookup_widget(objet,"affichage");
fenetre_afficher=create_affichage();
gtk_widget_hide(fenetre_afficher);
gtk_widget_hide(w1);

gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"tableau");
afficher_rec(treeview,"reclamation.txt");
}


void
on_rech_mod_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_nbv_1_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OR=1;
}


void
on_nbv_2_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OR=2;
}


void
on_nbv_3_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OR=3;
}


void
on_nbv_4_mod_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 OR=4;
}


void
on_mod_mod_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
reclamation rec;
GtkWidget*id_rec;
GtkWidget*jour_rec;
GtkWidget*mois_rec;
GtkWidget*annee_rec;
GtkWidget*nle_rec;
GtkWidget*desc_rec;


id_rec = lookup_widget (objet,"entry2" );
jour_rec = lookup_widget (objet,"jour_mod" );
mois_rec = lookup_widget (objet,"mois_mod" );
annee_rec = lookup_widget (objet,"annee_mod" );
nle_rec = lookup_widget (objet,"nle_mod" );
desc_rec = lookup_widget (objet,"desc_mod" );


strcpy(rec.id_rec,gtk_entry_get_text(GTK_ENTRY(id_rec)));
rec.date_rec.jour_rec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_rec));
rec.date_rec.mois_rec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_rec));
rec.date_rec.annee_rec=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_rec));
strcpy(rec.nle_rec,gtk_combo_box_get_active_text (GTK_COMBO_BOX(nle_rec)));
strcpy(rec.desc_rec,gtk_entry_get_text(GTK_ENTRY(desc_rec)));

if(AND==3)
	strcpy(rec.categ_rec,"faible");
	if(AND==2)
	strcpy(rec.categ_rec,"moyenne");
	if(AND==1)
	strcpy(rec.categ_rec,"urgent");
	if(OR==4)
	strcpy(rec.nbv_rec,"4");
	if(OR==3)
	strcpy(rec.nbv_rec,"3");
	if(OR==2)
	strcpy(rec.nbv_rec,"2");
	if(OR==1)
	strcpy(rec.nbv_rec,"1");


modifier(rec.id_rec,rec,"reclamation.txt");



}


void
on_retour_mod_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*fenetre_ajout;
GtkWidget*fenetre_afficher;
GtkWidget*treeview;

fenetre_ajout = lookup_widget(objet,"modifier");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"affichage");
fenetre_afficher=create_affichage();
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"tableau");
afficher_rec(treeview,"reclamation.txt");
}


void
on_urg_mod_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 AND=1;
}


void
on_moy_mod_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 AND=2;
}


void
on_fai_mod_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (togglebutton)))
 AND=3;
}


void
on_nbv_stat_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
int a=RecPerbv("1");
char str4[10];
sprintf(str4,"%d",a);
int b=RecPerbv("2");
char str5[10];
sprintf(str5,"%d",b);
int c=RecPerbv("3");
char str6[10];
sprintf(str6,"%d",c);
int d=RecPerbv("d");
char str7[10];
sprintf(str7,"%d",d);
GtkWidget*bv1;
GtkWidget*bv2;
GtkWidget*bv3;
GtkWidget*bv4;
bv1 = lookup_widget(objet,"bv1");
bv2 = lookup_widget(objet,"bv2");
bv3 = lookup_widget(objet,"bv3");
bv4 = lookup_widget(objet,"bv4");
gtk_label_set_text(GTK_LABEL(bv1),str4);
gtk_label_set_text(GTK_LABEL(bv2),str5);
gtk_label_set_text(GTK_LABEL(bv3),str6);
gtk_label_set_text(GTK_LABEL(bv4),str7);
}


void
on_nle_stat_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*l1;
GtkWidget*l2;
GtkWidget*l3;
int z=RecPerList("1");
char str1[10];
sprintf(str1,"%d",z);
int e=RecPerList("2");
char str2[10];
sprintf(str2,"%d",e);
int r=RecPerList("3");
char str3[10];
sprintf(str3,"%d",r);
l1 = lookup_widget(objet,"l1");
l2 = lookup_widget(objet,"l2");
l3 = lookup_widget(objet,"l3");
gtk_label_set_text(GTK_LABEL(l1),str1);
gtk_label_set_text(GTK_LABEL(l2),str2);
gtk_label_set_text(GTK_LABEL(l3),str3);
}


void
on_somme_stat_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
int p=nombreRec();
char str[10];
sprintf(str,"%d",p);
GtkWidget*somme;
somme = lookup_widget(objet,"somme");
gtk_label_set_text(GTK_LABEL(somme),str);
}


void
on_ret_stat_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*fenetre_ajout;
GtkWidget*fenetre_afficher;
GtkWidget*treeview;

fenetre_ajout = lookup_widget(objet,"stat");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"affichage");
fenetre_afficher=create_affichage();
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"tableau");
afficher_rec(treeview,"reclamation.txt");
}


void
on_statistique_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget*fenetre_ajout;
GtkWidget*fenetre_afficher;
GtkWidget*treeview;

fenetre_ajout = lookup_widget(objet,"affichage");

gtk_widget_hide(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"stat");
fenetre_afficher=create_stat();
gtk_widget_show(fenetre_afficher);
treeview=lookup_widget(fenetre_afficher,"tableau");
afficher_rec(treeview,"reclamation.txt");
}

