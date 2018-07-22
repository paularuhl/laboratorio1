#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "lib.h"
#include "clientes.h"
#include "alquileres.h"
#include "vista.h"
#include "dataManager.h"

#define INHABILITADO 0
#define HABILITADO 1
#define ERROR -1

void clientes_alta(ArrayList* clientes,int* id)
{
    client* c=clientes_newStruct();
    char name[40], lastname[40], dni[9];
    if(clientes!=NULL&&id!=NULL)
    {
        printf("**Alta de cliente**");

        clientes_setName(c,clientes_askName(name));
        clientes_setLastname(c,clientes_askLastname(lastname));
        do
        {

            clientes_setDni(c,clientes_askDni(dni));
        }
        while(clientes_dniRepetido(clientes,dni));

        clientes_setState(c,HABILITADO);

        clientes_mostrarSimple(c);
        if(vista_confirmar("Confirmar alta de cliente?"))
        {
            (*id)++;
            clientes_setId(c,id);

            al_add(clientes,c);
        }
        vista_clean();
    }
}
int clientes_dniRepetido(ArrayList* l,char* dni)
{
    int i,r=0;
    int doc=atoi(dni), aux;
    client* c=NULL;

    for(i=0; i<al_len(l); i++)
    {
        c=al_get(l,i);
        aux=atoi(clientes_getDni(c));

        if(aux==doc)
        {
            r=1;
            printf("Error, ya existe un cliente con ese dni");
            break;
        }
    }
    return r;
}
void clientes_modificar(ArrayList* clientes)
{
    client* c;
    int opcion, volver=0;
    char name[40], lastname[40];
    if(clientes!=NULL)
    {
        if(al_len(clientes)!=0)
        {
            clientes_mostrarLista(clientes);
            c=clientes_buscarId(clientes);

            do
            {
                clientes_mostrarSimple(c);
                vista_menuModificar();
                opcion=entero_get("opcion");
                switch(opcion)
                {
                case 1:
                    clientes_askName(name);
                    if(vista_confirmar("Confirmar cambios?"))
                    {
                        clientes_setName(c,name);
                    }
                    break;
                case 2:
                    clientes_askLastname(lastname);
                    if(vista_confirmar("Confirmar cambios?"))
                    {
                        clientes_setLastname(c,lastname);
                    }
                    break;
                case 0:
                    volver = 1;
                    break;
                default:
                    vista_opcionInvalida();
                    break;
                }
            }
            while(!volver);
        }
        else
        {
            vista_noData();
        }
    }
    else
    {
        vista_errorNotFound();
    }
    vista_finFuncion();
}

void clientes_baja(ArrayList* clientes,ArrayList* alq)
{
    client* c=NULL;
    rent* a=NULL;
    int i,flag=0;
    if(clientes!=NULL)
    {
        if(al_len(clientes)!=0)
        {
            clientes_mostrarLista(clientes);
            c=clientes_buscarId(clientes);
            vista_clean();
            clientes_mostrarUno(c);
            for(i=0; i<al_len(alq); i++)
            {
                a=al_get(alq,i);
                if(alq_getCte(a)==clientes_getId(c)&&alq_getState(a)==1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                vista_mostrarAlqBajaCte(c,clientes,alq);
                if(vista_confirmar("\nDar de baja cliente y finalizar alquileres?"))
                {
                    clientes_setState(c,INHABILITADO);
                    for(i=0; i<al_len(alq); i++)
                    {
                        a=al_get(alq,i);
                        if(alq_getCte(a)==clientes_getId(c)&&alq_getState(a)==1)
                        {
                            alq_setState(a,INHABILITADO);
                        }
                    }
                }
                vista_clean();
            }
            else if(vista_confirmar("\nDar de baja cliente? (s/n): "))
            {
                clientes_setState(c,INHABILITADO);
            }
            parseOut(clientes,alq);
        }
        else
        {
            vista_noData();
        }

    }
    vista_finFuncion();

}




char* clientes_askName(char* aux)
{
    while(!string_getLetras("\nIngrese el nombre: ",aux))
    {
        vista_errorItem("el nombre","letras");
    }
    strlwr(aux);
    *(aux+0)=toupper(*aux+0);

    return aux;
}
char* clientes_askLastname(char* aux)
{
    while(!string_getLetras("Ingrese el apellido: ",aux))
    {
        vista_errorItem("el apellido","letras");
    }
    strlwr(aux);
    *(aux+0)=toupper(*aux+0);

    return aux;
}
char* clientes_askDni(char* aux)
{
    do
    {
        while(!string_getNumerico("Ingrese DNI: ",aux))
        {
            vista_errorItem("el dni","numeros");
        }
    }
    while(!string_validaRango(aux,7000000,99999999));
    return aux;
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

void clientes_mostrarUno (client* c)
{
    if(c!=NULL)
    {
        vista_encabezadoClientes();
        vista_mostrarUnCte(c);
    }
}

void clientes_mostrarSimple (client* c)
{
    if(c!=NULL)
    {
        printf("\n%s - %s - %s",clientes_getDni(c),clientes_getName(c),clientes_getLastname(c));
    }
}
void clientes_mostrarLista(ArrayList* lista)
{
    int i;
    client* c;
    if(lista!=NULL)
    {
        if(al_len(lista)!=0)
        {
            vista_encabezadoClientes();
            for(i=0; i<al_len(lista); i++)
            {
                c=al_get(lista,i);
                if(clientes_getState(c)==HABILITADO)
                {
                    vista_mostrarUnCte(c);
                }
            }
        }
        else
        {
            vista_noData();
        }
    }
}

client* clientes_newStruct()
{
    client* aux=(client*)malloc(sizeof(client));
    return aux;
}

client* clientes_buscarId(ArrayList* clientes)
{
    client* c;
    client* aux=NULL;
    int id, i;
    id=entero_get("id de cliente");

    for(i=0; i<al_len(clientes); i++)
    {

        c=al_get(clientes,i);
        if(id==clientes_getId(c))
        {
            aux=c;
            break;
        }
    }
    return aux;
}

client* clientes_forPrint(ArrayList* clientes, int* id)
{
    client* c;
    client* aux=NULL;
    int i;
    for(i=0; i<al_len(clientes); i++)
    {
        c=al_get(clientes,i);
        if(*id==c->idCte)
        {
            aux=c;
            break;
        }
    }
    return aux;
}
