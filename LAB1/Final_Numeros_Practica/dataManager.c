#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "letras.h"
#include "dataManager.h"

void exportData(ArrayList* clientes,ArrayList* alquileres)
{

}

void letras_parseIn(ArrayList* l,char filename[], int* id)
{
    FILE* fp;
    eLetra* n;
    int vocal, cons;
    char letra;
    char name[10], vocalAux[2], consAux[2];
    char lalala[30];

    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        fscanf(fp,"%[^\n]\n",lalala);
        do
        {
            (*id)++;
            n=letra_newStruct();
            fscanf(fp,"%[^,],%[^,],%[^,],%[^\n]\n",&letra,name,vocalAux,consAux);
            vocal=atoi(vocalAux);
            cons=atoi(consAux);
            letra_new(n,id,letra,name,vocal,cons);
            l->add(l,n);
        }
        while(!feof(fp));
        fclose(fp);
    }
}
void letra_parseOut(ArrayList* lista,char filename[])
{
    eLetra* n;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<al_len(lista); i++)
            {
                n=(eLetra*) al_get(lista,i);
                fprintf(fp,"%c,%s,%d,%d\n",letra_getLetra(n),letra_getName(n),letra_getVocal(n),letra_getConsonante(n));
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
