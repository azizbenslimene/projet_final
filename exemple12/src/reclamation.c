
#include "reclamation.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


enum 
{
	ID,
	JOUR,
	MOIS,
	ANNEE,
	NUMERO_DE_LISTE,
	NUMERO_DE_BUREAU,
	CATEGORIE,
	DESCRIPTION,
	COLUMNS,
};



void ajouter (reclamation rec , int ET,int OU)
{
    
        if(ET==3)
	strcpy(rec.categ_rec,"faible");
	if(ET==2)
	strcpy(rec.categ_rec,"moyenne");
	if(ET==1)
	strcpy(rec.categ_rec,"urgent");
	if(OU==4)
	strcpy(rec.nbv_rec,"4");
	if(OU==3)
	strcpy(rec.nbv_rec,"3");
	if(OU==2)
	strcpy(rec.nbv_rec,"2");
	if(OU==1)
	strcpy(rec.nbv_rec,"1");
   FILE *f=fopen("reclamation.txt","a");
  
  
    if(f!=NULL)
    {
        fprintf(f,"%s %d %d %d %s %s %s %s \n",rec.id_rec,rec.date_rec.jour_rec,rec.date_rec.mois_rec,rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec);
      
    
}  
fclose(f);
}

void modifier(char id_rec [8],reclamation nouv, char * filename)
{
reclamation rec ;
	

    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if((f!=NULL) && (f2!=NULL))
{
while(fscanf(f,"%s %d %d %d %s %s %s %s\n",rec.id_rec,&rec.date_rec.jour_rec,&rec.date_rec.mois_rec,&rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec)!=EOF)
{
if( strcmp(rec.id_rec,id_rec)!=0)
        fprintf(f2,"%s %d %d %d %s %s %s %s\n",rec.id_rec,rec.date_rec.jour_rec,rec.date_rec.mois_rec,rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec);
else

  fprintf(f2,"%s %d %d %d %s %s %s %s\n",nouv.id_rec,nouv.date_rec.jour_rec,nouv.date_rec.mois_rec,nouv.date_rec.annee_rec,nouv.nbv_rec,nouv.nle_rec,nouv.categ_rec,nouv.desc_rec);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        
    }

}

void supprimer_rec (char id [8], char * filename)
{
reclamation rec ;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if((f!=NULL) || (f2!=NULL))



    {
while(fscanf(f,"%s %d %d %d %s %s %s %s",rec.id_rec,&rec.date_rec.jour_rec,&rec.date_rec.mois_rec,&rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec)!=EOF)
{
if(strcmp(rec.id_rec,id)!=0)
        fprintf(f2,"%s %d %d %d %s %s %s %s\n",rec.id_rec,rec.date_rec.jour_rec,rec.date_rec.mois_rec,rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
       
    }
}

reclamation chercher(char id_rec[8], char * filename)
{
reclamation rec; 
int tr=0;
strcpy(rec.id_rec," ");
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while((fscanf(f,"%s %d %d %d %s %s %s %s\n",rec.id_rec,&rec.date_rec.jour_rec,&rec.date_rec.mois_rec,&rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec)!=EOF) && (tr==0))
{if(strcmp(id_rec,rec.id_rec)==0){
tr=1;
fclose(f);}
}
}
if(tr==0)
strcpy(rec.id_rec,"-1");


return rec;

}

void afficher_rec (GtkWidget *liste, char*filname) 
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char id_rec [2000];
	int  jour_rec; 
	int  mois_rec;
	int  annee_rec;       
	char nle_rec [20]  ;
	char nbv_rec [20];
	char categ_rec [100];
	char desc_rec [100];
	reclamation rec ;
	store=NULL;
	FILE  *f;
	
	store = gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	
	
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	column = gtk_tree_view_column_new_with_attributes("mois", renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	column = gtk_tree_view_column_new_with_attributes("annee", renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero_de_liste", renderer,"text",NUMERO_DE_LISTE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
		column = 	gtk_tree_view_column_new_with_attributes("numero_de_bureau",renderer,"text",NUMERO_DE_BUREAU,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("categorie", renderer,"text",CATEGORIE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("description", renderer,"text",DESCRIPTION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	
	
	store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen(filname,"r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		
		while(fscanf(f,"%s %d %d %d %s %s %s %s\n",rec.id_rec,&rec.date_rec.jour_rec,&rec.date_rec.mois_rec,&rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec)!=EOF)
		{
		
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,rec.id_rec,JOUR,rec.date_rec.jour_rec,MOIS,rec.date_rec.mois_rec,ANNEE,rec.date_rec.annee_rec,NUMERO_DE_LISTE,rec.nle_rec,NUMERO_DE_BUREAU,rec.nbv_rec,CATEGORIE,rec.categ_rec,DESCRIPTION,rec.desc_rec,-1);
			
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
	}  
	
}}
int RecPerList(char liste[]){
FILE *f=fopen("reclamation.txt","r");
reclamation rec;
int nb=0;
while(fscanf(f,"%s %d %d %d %s %s %s %s\n",rec.id_rec,&rec.date_rec.jour_rec,&rec.date_rec.mois_rec,&rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec)!=EOF)
{

if(strcmp(liste,rec.nle_rec)==0)nb++;
}
fclose(f);
return nb;
}
int nombreRec(){
FILE *f=fopen("reclamation.txt","r");
reclamation rec;
int nb=0;
while(fscanf(f,"%s %d %d %d %s %s %s %s\n",rec.id_rec,&rec.date_rec.jour_rec,&rec.date_rec.mois_rec,&rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec)!=EOF)
{

nb++;
}
fclose(f);
return nb;
}

int RecPerbv(char bv[]){
FILE *f=fopen("reclamation.txt","r");
reclamation rec;
int nb=0;
while(fscanf(f,"%s %d %d %d %s %s %s %s\n",rec.id_rec,&rec.date_rec.jour_rec,&rec.date_rec.mois_rec,&rec.date_rec.annee_rec,rec.nbv_rec,rec.nle_rec,rec.categ_rec,rec.desc_rec)!=EOF)
{

if(strcmp(bv,rec.nbv_rec)==0)nb++;
}
fclose(f);
return nb;
}



int verif(char id[]){
if(strlen(id)==8)return 1;
else 
return 0;


}




