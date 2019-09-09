#ifndef __planning__
#define __planning__
#include"date.h"
//#include"enregistrement.h"
typedef struct planning planning;
struct planning
{
	date Dd;
	date Df;
	char tche[10];
};

#endif