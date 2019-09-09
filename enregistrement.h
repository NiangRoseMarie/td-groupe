#ifndef __enregistrement__
#define __enregistrement__
#include"planning.h"
#include"equipment.h"
#include "date.h"
#include <string.h>
typedef struct infoEquipe infoEquipe;
struct infoEquipe
{
	char nom[10];
	int N_effectif;
	char charge[10];
	equipment eqment[25];
	planning plann;
	int n_equipment;
};
void registreDivision(infoEquipe t[6]);
date Date ();
void registreEquipment(infoEquipe f[6]);
void sortiEquipment (infoEquipe f[6]) ;
float perfomanceE(infoEquipe f[6]);
float frequencePanne(infoEquipe f[6]);
void planing (infoEquipe f[6]);
void affichPlanning(infoEquipe f[6]);
#endif