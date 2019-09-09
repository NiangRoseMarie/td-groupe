#include<stdio.h>
#include<stdlib.h>
#include"planning.h"
#include"date.h"
#include"enregistrement.h"
#include"equipment.h"
#define AA 2019
void planing (infoEquipe f[6])
{
	int r=-1;
	char nom[10];
	printf("Saisir le nom de votre equipe :\n");
	scanf("%s",nom);
	for (int i=0;i<2;i++)
	{
		if (strcmp(nom,f[i].nom)==0)
		{
			r=i;
		}
	}
	if(r!=-1){
		printf("entrer la date du debut de votre intervention :\n");
		f[r].plann.Dd=Date();
		f[r].plann.Dd.Annee=AA;
		printf("entrer la date de la fin de votre intervention :\n");
		f[r].plann.Df=Date();
		f[r].plann.Df.Annee=AA;
		printf("Tache a effectuer :\n"); 
		scanf("%s",f[r].plann.tche);
	}
	else
		printf("vous n'etes pas enregistre \n");
}
void affichPlanning(infoEquipe f[6])
{
	for(int i=0;i<2;i++)
	{
		printf("nom division %s\n",f[i].nom );
		printf("Date debut :%d - %d - %d\n",f[i].plann.Dd.jour,f[i].plann.Dd.mois,f[i].plann.Dd.Annee);
		printf("Date fin :%d - %d - %d\n",f[i].plann.Df.jour,f[i].plann.Df.mois,f[i].plann.Dd.Annee );  
		printf("Tache a effectuer :\n",f[i].plann.tche);
		printf("-----------------------------------------------------------------\n");
	}
}
