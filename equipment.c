#include<stdio.h>
#include<stdlib.h>

#include"equipment.h"

#include"planning.h"
#include"date.h"
#include"enregistrement.h"
#define AA 2019

void registreEquipment(infoEquipe f[6])
{
	int r,l,NE=0;
	char nom[10];
	printf("Saisir le nom de votre equipe :\n");
	scanf("%s",nom);
	r=-1;
	for (int i=0;i<2;i++)
	{
		if (strcmp(nom,f[i].nom)==0)
		{
			 r=i;
		}
	}
	if(r!=-1)
	{
		do{
			printf(" Equipment (entree) \n");
			printf("Nom \n");
			scanf("%s",f[r].eqment[f[r].n_equipment].nomE);
			printf("Date de venue :\n");
			f[r].eqment[f[r].n_equipment].dat_Entree=Date();
			f[r].eqment[f[r].n_equipment].dat_Entree.Annee=AA;
			printf("Date d'entretient de l'equipment :\n");
			f[r].eqment[f[r].n_equipment].dat_Entretien=Date();
			do{
				printf("Annee :\n");
				scanf("%d",&f[r].eqment[f[r].n_equipment].dat_Entretien.Annee);
			}while(f[r].eqment[f[r].n_equipment].dat_Entree.Annee<AA);
			printf("Date de renouvellement :\n");
			f[r].eqment[f[r].n_equipment].dat_Changement=Date();
			do{
				printf("Annee :\n");
				scanf("%d",&f[r].eqment[f[r].n_equipment].dat_Changement.Annee);
			}while(f[r].eqment[f[r].n_equipment].dat_Changement.Annee<AA);
			printf("quantite :\n");
			scanf("%d",&f[r].eqment[f[r].n_equipment].stock);
			while(f[r].eqment[f[r].n_equipment].stock<0)
			{
				printf("quantite inferieur a 0 reessayer:\n");
				scanf("%d",&f[r].eqment[f[r].n_equipment].stock);
			}
			
			f[r].n_equipment++;
			printf("souhaiter vous enregistre un autre equipment?\n1-oui\n2-non\n");
			scanf("%d",&l);
		}while(l==1);
		if(l==2)
		{
			printf("-----------------------------------------------------\n");
			printf("\t\tliste des equipments de la division %d\n",r+1);
			printf("Numero\t|Nom\t|Quantite\t|Date d'entretient\t|Date de Changement\n");
			for(int j=0;j<f[r].n_equipment;j++){
				printf("%d\t|%s\t|%d \t\t|%d-%d-%d\t\t|%d-%d-%d\n",j+1,f[r].eqment[j].nomE,f[r].eqment[j].stock,f[r].eqment[j].dat_Entretien.jour,f[r].eqment[j].dat_Entretien.mois,f[r].eqment[j].dat_Entretien.Annee,f[r].eqment[j].dat_Changement.jour,f[r].eqment[j].dat_Changement.mois,f[r].eqment[j].dat_Changement.Annee);
			}
			printf("-----------------------------------------------------\n");

		}
	}
	else
		printf("Incorrect\n");
}
void sortiEquipment (infoEquipe f[6]) 
{
	int r,l;
	char nom[10];
	printf("Saisir le nom de votre equipe :\n");
	scanf("%s",nom);
	r=-1;
	for (int i=0;i<2;i++)
	{
		if (strcmp(nom,f[i].nom)==0)
		{
			 r=i;
		}
	}
	if(r!=-1)
	{
		do{
			for(int j=0;j<f[r].n_equipment;j++) 
			{
				printf("%d - Nom de l'equipment : %s \t\t||",j+1,f[r].eqment[j].nomE);
				printf("Quantite:%d\n",f[r].eqment[j].stock);
				printf("--------------------------------\n");
			}
			int t,n;
			do{
				printf("Saisir le numero de l'equipment :\n");
				scanf("%d",&t);
			}while(t<0);
			t=t-1;//ou "t--;" 
			printf("Combien vous en voulez\n");
			scanf("%d",&n);
			f[r].eqment[t].stock-=n;
				printf("souhaiter vous prendre un autre equipment?\n1-oui\n2-non\n");
				scanf("%d",&l);
		}while(l==1);
		if(l==2)
		{
			printf("-----------------------------------------------------\n");
			printf("\t\tliste des equipments\n");
			printf("Numero\t\t\t|Nom\t\t\t|Quantite\n");
			for(int j=0;j<f[r].n_equipment;j++){
				printf("%d\t\t\t|%s\t\t\t|%d\n",j+1,f[r].eqment[j].nomE,f[r].eqment[j].stock);
				printf("-----------------------------------------------------\n");
			}
		}
	}else
		printf("Incorrect\n");
}
float perfomanceE(infoEquipe f[6])
{
	float pourcentage=-1;
	int n,r;
	char nom[10];
	r=-1;
	printf("Saisir le nom de votre equipe :\n");
	scanf("%s",nom);
	for (int i=0;i<2;i++)
	{
		if (strcmp(nom,f[i].nom)==0)
		{
			r=i;
		}
	}
	if(r!=-1)
	{
		printf("\t statistique  des equipments defaillants\n");
		do{
			printf("entrer le nombre d'equipment defaillant \n");
			scanf("%d",&n); 
		}while(n<0);
		if(n==0)
			printf("il n'y a pas d'equipments defaillants\n");
		if(n>0 && n<=f[r].n_equipment){
			pourcentage=(n*100)/f[r].n_equipment;
			printf("pourcentage des equipment defaillants %f % .\n",pourcentage);
		}
		else if(n>f[r].n_equipment)
		{
			printf("le nombre d'equipement defaillant est SUPERIEUR au nombre disponible\n");
		}
		return pourcentage;
	}
}
float frequencePanne(infoEquipe f[6])
{
	float pourcentages=-1;
	int n,r;
	char nom[10];
	printf("Saisir le nom de votre equipe :\n");
	r=-1; 
	scanf("%s",nom);
	for (int i=0;i<2;i++)
	{
		if (strcmp(nom,f[i].nom)==0)
		{
			 r=i;
		}
	}
	if(r!=-1)
	{
		printf("\t statistique  des pannes sur 30 jours \t\n");
		do{
			printf("entrer le nombre de fois qu'il ya eu panne \n");
			scanf("%d",&n);
		}while(n<0);
		if(n==0)
			printf("il n'y a pas eu de panne durant ces un mois\n");
		if(n>0 && n<=30){
			pourcentages=(n*100)/30;
			printf("Frenquence des pannes : %f % \n.",pourcentages);
		}
		else
			printf("le nombre de fois qu'il a eu panne est SUPERIEUR au 30 jours du mois\n");
		return pourcentages;
	}
}