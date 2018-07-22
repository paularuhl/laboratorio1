#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"

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
    int i=0, r=1;

    if(string_isNull(array[0]))
    {
        r=0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])))
            {
                r=0;
            }
            i++;
        }
    }
    return r;
}
int string_esSoloLetras(char array[])
{
    int i=0,r=1;
    if(string_isNull(array[0]))
    {
        r= 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if( (!isspace(array[i])) && (!isalpha(array[i])) )
            {
                r= 0;
            }
            i++;
        }
    }
    return r;
}

int string_validateLength(char* str, int len)
{
    int i, r=1;
    if(str != NULL)
    {
        for(i=0; *(str+i)!='\0'; i++)
        {
            if(i>len)
            {
                r=0;
                break;
            }
        }
    }
    return r;
}
int string_validaRango(char str[], int min, int max)
{
    int aux,r=1;
    aux = atoi(str);
    if(aux<min || aux>max)
    {
        printf("Error, el numero ingresado esta fuera de rango. MIN: %d MAX: %d\n",min,max);
        r=0;
    }
    else
    {
        r=1;
    }
    return r;
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


int string_getLetras(char mensaje[],char input[])
{
    char aux[256];
    string_get(mensaje,aux);
    if(string_esSoloLetras(aux))
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


///funciones particulares del programa

char* gen_newString()
{
    char* aux=(char*)malloc(sizeof(char)*50);
    return aux;
}

