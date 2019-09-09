#ifndef __equipment__
#define __equipment__
//#include"enregistrement.h"
#include "date.h"
typedef struct equipment equipment;
struct equipment
{
	char nomE[10];
	int etat[3];
	date dat_Entree;
	date dat_Entretien;
	date dat_Changement;
	int stock;
};

#endif