#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "lib.h"
#include "ctes.h"
#include "vista.h"

#define INHABILITADO 0
#define HABILITADO 1

void clientes_alta(ArrayList* clientes,int* idCte)
{
    client* c=clientes_newStruct();
    (*idCte)++;
    printf("**Alta de cliente**");

    clientes_newName(c);
    clientes_newLastname(c);
    clientes_newDni(c);
    clientes_setId(c,idCte);
    clientes_setState(c,HABILITADO);
    printf("Confirmar alta de cliente?");
    if(vista_confirmar())
    {
        al_add(clientes,c);
    }
    vista_finFuncion();
}

void clientes_modificar(ArrayList* clientes)
{
    client c;
    client* aux;
    int opcion, volver=0, i=-1, id=-1;
    id=entero_get("id de cliente a modificar");
    i=al_indexOf(clientes,&id);
    aux=(client*)al_get(clientes,i);
    c=*aux;

    do
    {
        vista_menuModificar();
        opcion=entero_get("opcion");

        switch(opcion)
        {
        case 1:
            clientes_newName(&c);
            printf("Confirmar cambios?");
            if(vista_confirmar())
            {
                *aux=c;
            }
            break;
        case 2:
            clientes_newLastname(&c);
            printf("Confirmar cambios?");
            if(vista_confirmar())
            {
                *aux=c;
            }
            break;
        case 0:
            printf("Adios!\n");
            system("pause");
            volver = 1;
            break;
        default:
            vista_opcionInvalida();
            break;
        }
    }
    while(volver==0);
    vista_finFuncion();
}

void clientes_newName(client* c)
{
    char aux[40];
    if(c!=NULL)
    {
        while(!string_getLetras("\nIngrese el nombre: ",aux))
        {
            vista_errorItem("el nombre","letras");
        }
        strlwr(aux);
        *(aux+0)=toupper(*aux+0);
        //strcpy(c->name,aux);

    }
}
void clientes_newLastname(client* c)
{
    char aux[40];
    if(c!=NULL)
    {
        while(!string_getLetras("\nIngrese el apellido: ",aux))
        {
            vista_errorItem("el apellido","letras");
        }
        strlwr(aux);
        *(aux+0)=toupper(*aux+0);
        clientes_setLastname(c,aux);
    }
}
void clientes_newDni(client* c)
{
    char aux[9];
    if(c!=NULL)
    {
        do
        {
            while(!string_getNumerico("\nIngrese DNI: ",aux))
            {
                vista_errorItem("el dni","numeros");
            }
        }
        while(!string_validaRango(aux,1000,9999));
        clientes_setDni(c,aux);
    }
}


void clientes_setName(client* c, char* aux)
{
    if(c!=NULL&&aux!=NULL)
    {
        strcpy(c->name,aux);
    }
}
void clientes_setLastname(client* c, char* aux)
{
    if(c!=NULL&&aux!=NULL)
    {
        strcpy(c->lastname,aux);
    }
}
void clientes_setDni(client* c, char* aux)
{
    if(c!=NULL&&aux!=NULL)
    {
        strcpy(c->dni,aux);
    }
}
void clientes_setState(client* c,int st)
{
    if(c!=NULL)
    {
        c->state=st;
    }
}
void clientes_setId(client* c,int* id)
{
    if(c!=NULL&&id!=NULL)
    {
        c->idCte=*id;
    }
}

char* clientes_getName (client* c)
{
    char* str=NULL;
    if(c!=NULL)
    {
        str=c->name;
    }
    return str;
}
char* clientes_getLastname (client* c)
{
    char* str=NULL;
    if(c!=NULL)
    {
        str=c->lastname;
    }
    return str;
}

char* clientes_getDni (client* c)
{
    char* str=NULL;
    if(c!=NULL)
    {
        str=c->dni;
    }
    return str;
}
int clientes_getId(client* c)
{
    int aux;
    if(c!=NULL)
    {
        aux=c->idCte;
    }
    return aux;
}
int clientes_getState(client* c)
{
    int aux;
    if(c!=NULL)
    {
        aux=c->state;
    }
    return aux;
}

client* clientes_newStruct()
{
    client* aux=(client*)malloc(sizeof(client));
    return aux;
}


void clientes_mostrarUno (client* c)
{
    if(c!=NULL)
    {
        vista_encabezadoClientes();
        vista_mostrarUno(c);
    }
}


void clientes_mostrarLista(ArrayList* lista)
{
    int i, len;
    client* c;
    if(lista!=NULL)
    {
        len=lista->len(lista);
        if(len!=0)
        {
            vista_encabezadoClientes();
            for(i=0; i<len; i++)
            {
                c=lista->get(lista,i);
                vista_mostrarUno(c);
            }
        }
        else
        {
            vista_noData();
        }
    }

    vista_finFuncion();
}

