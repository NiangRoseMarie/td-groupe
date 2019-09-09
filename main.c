#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"date.h"
#include"enregistrement.h"
#include"equipment.h"
#include"planning.h"
#define AA 2019

int choix;//TU UTILISE CHOIX AVANT LE MAIN DONC MIEUX VAU LE DECLARER ICI O APRES LES TYPE ENREGISTREMENT MAIS PAS APRES LES FONCTION

int menu () 
{
	int choix;
	do{
		printf("1-Gerer le planning\n");
		printf("2-Gerer le stock\n");
		printf("3-afficher les statistiques\n");
		scanf("%d",&choix);	
	}while(choix<1 || choix>3);//"while(choix<1 && choix>3)"CEST 2 CONDITION NE PEEUVENT PAAS ETRE REALISER EN MEME TEMPS DONC CEST OU(||) QUE TU DOIS METTRE A LA PLACE DU ET(&&) JE RECTIFI EN MEME TEMPS
	return choix;
}

int main()
{
	int c;
infoEquipe P[6];
equipment eqment[50];
planning plann;
int z;
	printf("\tBienvenue\t\n");
	registreDivision(P);
	do{
		printf("Que voulez-vous faire ?\n");
		choix=menu(choix);
		if(choix==2)
		{
			do{
				printf("Tapez :\n1-ajouter un ou plusieurs equipment\n2-retirer un ou plusieurs equipment\n");
				scanf("%d",&c);
			}while(c<1 || c>2);
			if(c==1)
				registreEquipment(P);
			else
				sortiEquipment (P);
		}
		else if(choix==1)
		{
			do{
				printf("Tapez :\n1-faire le planing\n2-afficher les planing");
				scanf("%d",&c);
			}while(c<1 || c>2);
			if (c==1)
				planing(P);
			else
				affichPlanning(P);
		}
		else if (choix==3)
		{
			float pourcentage=1;
			pourcentage=perfomanceE(P);
			printf("-------------------------------------------------------\n");
			float pourcentages=1;
			pourcentages=frequencePanne(P);
		}
		do{
			printf("voulez-vous recommencer?\n1-oui\n2-non\n");
			scanf("%d",&z);
		}while(z<1 || z>2);
	}while(z==1);
	getch ();
	return 0;
}
