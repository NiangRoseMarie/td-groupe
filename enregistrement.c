#include<stdio.h>
#include<stdlib.h>
#include"enregistrement.h"
#define AA 2019


void registreDivision(infoEquipe t[6])
{
	for(int i=0;i<2;i++){
		printf("Nom de la division :\n");
		scanf("%s",t[i].nom);
		printf("Effectif de la division :\n");
		scanf("%d",&t[i].N_effectif);
		printf("Tache :\n");
		scanf("%s",t[i].charge);
		printf("---------------------------------------------\n");
		t[i].n_equipment=0;
	}
}