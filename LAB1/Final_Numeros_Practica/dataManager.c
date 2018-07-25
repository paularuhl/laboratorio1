#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "numeros.h"
#include "dataManager.h"

void exportData(ArrayList* clientes,ArrayList* alquileres)
{

}

void number_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    number* n;
    int num, par, impar, primo;
    char name[21], numAux[2], parAux[2], imparAux[2], primoAux[2];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {
            n=number_newStruct();
            fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numAux,name,parAux,imparAux,primoAux);
            num=atoi(numAux);
            par=atoi(parAux);
            impar=atoi(imparAux);
            primo=atoi(primoAux);
            number_new(n,num,name,par,impar,primo);
            l->add(l,n);
        }
        while(!feof(fp));
        fclose(fp);
    }
}
void number_parseOut(ArrayList* lista,char filename[])
{
    number* n;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<al_len(lista); i++)
            {
                n=(number*) al_get(lista,i);
                fprintf(fp,"%d,%s,%d,%d,%d\n",number_getNum(n),number_getName(n),number_getPar(n),number_getImpar(n),number_getPrimo(n));
            }
        }
        fclose(fp);
        printf("\nExportado Correctamente.");
        vista_finFuncion();
    }
    else
    {
        printf("No se pudo generar un archivo.");
    }
}
