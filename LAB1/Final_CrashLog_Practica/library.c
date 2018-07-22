#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "library.h"
#include "ArrayList.h"
#include "parser.h"

void procesarInformacion(ArrayList* log, ArrayList* ser)
{
    warnings_parseOut(log,ser);
    entreCuatroSiete(log,ser);
    errors_parseOut(log,ser);
    vista_finFuncion();
}
void leerLog(ArrayList* log, ArrayList* ser)
{
    log_parseIn(log,"log.txt");
    ser_parseIn(ser,"services.txt");
    vista_finFuncion();
}

void entreCuatroSiete(ArrayList* log, ArrayList* ser)
{
    Service* s=NULL;
    LogEntry* e=NULL;
    int i,j;
    if(log!=NULL&&ser!=NULL)
    {
        for(i=0; i<al_len(log); i++)
        {
            e=(LogEntry*) al_get(log,i);
            if(log_getGravedad(e)>=4&&log_getGravedad(e)<=7)
            {
                for(j=0; j<al_len(ser); j++)
                {
                    s=(Service*)al_get(ser,j);
                    if(log_getServiceId(e)==ser_getId(s))
                    {
                        printf("%s\t%s\t%s\t%s\t%d\n",log_getDate(e),log_getTime(e),ser_getName(s),log_getMsg(e),log_getGravedad(e));
                    }
                }
            }
        }
    }
}

void estadisticas(ArrayList* log, ArrayList* ser)
{
    Service* s;
    Service* aux;
    LogEntry* e;
    int i,j;
    int contadorSer=0;
    int serviceMax=0;
    int menorTres=0, tres=0, entreCuatroSiete=0, mayorSiete=0;
    if(log!=NULL&&ser!=NULL)
    {
        for(j=0; j<al_len(ser); j++)
        {
            s=(Service*)al_get(ser,j);
            for(i=0; i<al_len(log); i++)
            {
                e=(LogEntry*)al_get(log,i);
                if(ser_getId(s)==log_getServiceId(e))
                {
                    contadorSer++;
                }
            }
            if(contadorSer>serviceMax)
            {
                aux=s;
                serviceMax=contadorSer;
            }
        }
    }

    for(i=0; i<al_len(log); i++)
    {

        e=(LogEntry*)al_get(log,i);
        if(ser_getId(aux)==log_getServiceId(e))
        {
            if(log_getGravedad(e)<3)
            {
                menorTres++;
            }
            else if(log_getGravedad(e)==3)
            {
                tres++;
            }
            else if(log_getGravedad(e)>=4&&log_getGravedad(e)<=7)
            {
                entreCuatroSiete++;
            }
            else
            {
                mayorSiete++;
            }
        }
    }
    printf("\nEl servicio con mas fallos es: ");
    vista_mostrarUnSer(aux);
    printf("\nFallos por gravedad:");
    printf("\nMenores a 3: %d\nNivel 3: %d\nEntre 4 y 7 (inclusive): %d\nMayores a 7: %d\n",menorTres,tres,entreCuatroSiete,mayorSiete);
    vista_finFuncion();
}





///validar strings
int string_isNull (char value)
{
    if(value=='\0' || value ==' ')
    {
        return 1;
    }
    return 0;
}
int string_esNumerico(char array[])
{
    int i=0;

    if(string_isNull(array[0]))
    {
        return 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])))
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}
///get strings
void string_get(char mensaje[],char input[])
{
    fflush(stdin);
    printf("%s",mensaje);
    gets(input);
}
int string_getNumerico(char mensaje[],char input[])
{
    char aux[256];
    string_get(mensaje,aux);
    if(string_esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
///enteros
int entero_get(char mensaje[])
{
    char auxDato[20];
    int dato;
    printf("\nIngrese %s:",mensaje);
    while(!string_getNumerico(" ",auxDato))
    {
        printf("Error, *%s* solo puede estar compuesto por numeros. Reingrese %s:",mensaje,mensaje);
    }
    dato = atoi(auxDato);

    return dato;
}


