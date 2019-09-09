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
	while(d.jour<=0 || d.jour>31)// C'EST ICI JAI MIS 
	{
		printf("ERREUR \n");
    	printf("entrez le jour:\n");
		scanf("%d",&d.jour);
	}
	//C'EST BIEN PENSEE MAIS TU PEUT ENLEVER TOU CA EN AJOUTANT "|| d.jour>31" OU  JAI MIS 
   /* if(d.mois==01 || d.mois==03 || d.mois==05 || d.mois==07 || d.mois==8 || d.mois==12 ||d.mois==10)
    {
    	while(d.jour>31)
	    {
	       	printf("ces mois-ci ne comptent que 31 jours \n");
	        printf("entrez le jour:\n");
	        scanf("%d",&d.jour);
	    }
    }
    else*/ if(d.mois==02)
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