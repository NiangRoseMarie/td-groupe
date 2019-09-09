#include <stdio.h>
#include <stdlib.h>
#include "date.h"
date Date ()//fonction
{
	date d;
	printf("entrez le mois:\n");
	scanf("%d",&d.mois);
 
    while(d.mois<=0  || d.mois>12){
        printf("ERREUR \n");
        printf("entrez le mois:\n");
        scanf("%d",&d.mois);
    }
	printf("entrez le jour:\n");
	scanf("%d",&d.jour);
	while(d.jour<=0 || d.jour>31)
	{
		printf("ERREUR \n");
    	printf("entrez le jour:\n");
		scanf("%d",&d.jour);
	}
	if(d.mois==02)
    {
       	while(d.jour>28)
       	{
              printf("ces mois-ci ne comptent que 28 jours \n");
              printf("entrez le jour:\n");
              scanf("%d",&d.jour);
       	}
    }
	else if(d.mois==06 || d.mois==11 ||d.mois==4 ||d.mois==9 )
	{
	    while(d.jour>30)
	    {
    	 	printf("ces mois-ci ne comptent que 30 jours \n");
	        printf("entrez le jour:\n");
	   	 	scanf("%d",&d.jour);
	    }
	}
	return d;
}