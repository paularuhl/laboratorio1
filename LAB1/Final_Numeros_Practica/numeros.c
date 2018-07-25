#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numeros.h"

/// CONSTRUCTOR
number* number_newStruct()
{
    number* aux=(number*)malloc(sizeof(number));
    return aux;
}
/// NUEVO NUM
void number_new(number* n, int num, char* name, int par, int impar, int primo)
{
    number_setNum(n,num);
    number_setName(n,name);
    number_setPar(n,par);
    number_setImpar(n,impar);
    number_setPrimo(n,primo);
}


/// SETTERS
void number_setName(number* n, char* aux)
{
    if(n!=NULL&&aux!=NULL)
    {
        strcpy(n->name,aux);
    }
}
void number_setNum(number* n,int aux)
{
    if(n!=NULL)
    {
        n->num=aux;
    }
}
void number_setPar(number* n,int aux)
{
    if(n!=NULL)
    {
        n->par=aux;
    }
}
void number_setImpar(number* n,int aux)
{
    if(n!=NULL)
    {
        n->impar=aux;
    }
}
void number_setPrimo(number* n,int aux)
{
    if(n!=NULL)
    {
        n->primo=aux;
    }
}

/// GETTERS
char* number_getName (number* n)
{
    char* str=NULL;
    if(n!=NULL)
    {
        str=n->name;
    }
    return str;
}
int number_getNum(number* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->num;
    }
    return aux;
}
int number_getPar(number* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->par;
    }
    return aux;
}
int number_getImpar(number* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->impar;
    }
    return aux;
}
int number_getPrimo(number* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->primo;
    }
    return aux;
}


/// CALCULOS
int number_isPrimo(number* n)
{
    int i, contador=0, ret=0;
    for(i=number_getNum(n); i>0; i--)
    {
        if(number_getNum(n)%i==0)
        {
            contador++;
        }
    }
    if(contador==2)
    {
        ret=1;
    }
    return ret;
}

int number_isPar(number* n)
{
    int ret=0;
    if(number_getNum(n)%2==0)
    {
        ret=1;
    }
    return ret;
}
int number_isImpar(number* n)
{
    int ret=0;
    if(number_getNum(n)%2!=0)
    {
        ret=1;
    }
    return ret;
}
/// SET CALCULOS
void number_setCalculos(number* n)
{
    number_setPar(n,number_isPar(n));
    number_setImpar(n,number_isImpar(n));
    number_setPrimo(n,number_isPrimo(n));
}
/// HACER CALCULOS
void numeros_evaluate(ArrayList* lista)
{
    number* n=NULL;
    int i;
    for(i=0;i<al_len(lista);i++)
    {
        n=al_get(lista,i);
        number_setCalculos(n);
    }
    printf("Evaluado correctamente");
    vista_finFuncion();
}

