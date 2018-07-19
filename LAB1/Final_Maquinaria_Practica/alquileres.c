#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include "lib.h"
#include "alquileres.h"
#include "clientes.h"
#include "vista.h"

#define FINALIZADO 0
#define ALQUILADO 1
#define AMOLADORA 2
#define MEZCLADORA 3
#define TALADRO 4
#define JUAN 5
#define LUCAS 6
#define ROQUE 7



void alq_alta(ArrayList* rentals, ArrayList* ctes,int* id)
{
    rent* a=alq_newStruct();
    if(rentals!=NULL&&ctes!=NULL&&id!=NULL)
    {
        alq_setCte(a,alq_askCte(ctes));
        alq_setEquipo(a,alq_askEquipo());
        alq_setOp(a,alq_askOp());
        alq_setEstTime(a,alq_askEstTime());
        alq_setState(a,ALQUILADO);
        alq_mostrarSimple(a,ctes);
        if(vista_confirmar("Confirmar alquiler?"))
        {
            (*id)++;
            alq_setId(a,id);

            al_add(rentals,a);
        }
    }
    vista_clean();
}

void alq_baja(ArrayList* rentals, ArrayList* ctes)
{
    rent* a=NULL;

    alq_mostrarLista(rentals,ctes);
    a=alq_buscarId(rentals);
    alq_setRealTime(a,alq_askRealTime());
    vista_mostrarFinAlq(a,ctes);
    if(vista_confirmar("Confirmar fin de alquiler?"))
    {
        a->state=FINALIZADO;
    }

}

int alq_askCte(ArrayList* ctes)
{
    client* c;
    clientes_mostrarLista(ctes);
    c=clientes_buscarId(ctes);
    return c->idCte;
}

int alq_askEquipo()
{
    int aux, flag=0;
    do
    {
        vista_menuEquipos();
        aux=entero_get("equipo a alquilar");
        switch(aux)
        {
        case 1:
            aux=AMOLADORA;
            flag=1;
            break;
        case 2:
            aux=MEZCLADORA;
            flag=1;
            break;
        case 3:
            aux=TALADRO;
            flag=1;
            break;
        default:
            vista_opcionInvalida();
            break;
        }
    }
    while(!flag);
    return aux;
}

int alq_askOp()
{
    int aux, flag=0;
    do
    {
        vista_menuOp();
        aux=entero_get("operador actual");
        switch(aux)
        {
        case 1:
            aux=JUAN;
            flag=1;
            break;
        case 2:
            aux=LUCAS;
            flag=1;
            break;
        case 3:
            aux=ROQUE;
            flag=1;
            break;
        default:
            vista_opcionInvalida();
            break;
        }
    }
    while(!flag);
    return aux;
}

void alq_setId(rent* a,int* id)
{
    if(a!=NULL&&id!=NULL)
    {
        a->idAlq=*id;
    }
}
void alq_setCte(rent* a,int aux)
{
    if(a!=NULL)
    {
        a->idCte=aux;
    }
}
void alq_setEquipo(rent* a,int aux)
{
    if(a!=NULL)
    {
        a->equipo=aux;
    }
}
void alq_setRealTime(rent* a,int aux)
{
    if(a!=NULL)
    {
        a->realTime=aux;
    }
}
void alq_setEstTime(rent* a,int aux)
{
    if(a!=NULL)
    {
        a->estTime=aux;
    }
}
void alq_setOp(rent* a,int aux)
{
    if(a!=NULL)
    {
        a->operador=aux;
    }
}
void alq_setState(rent* a,int aux)
{
    if(a!=NULL)
    {
        a->state=aux;
    }
}

int alq_getId(rent* a)
{
    int aux;
    if(a!=NULL)
    {
        aux=a->idAlq;
    }
    return aux;
}
int alq_getCte(rent* a)
{
    int aux;
    if(a!=NULL)
    {
        aux=a->idCte;
    }
    return aux;
}
int alq_getEquipo(rent* a)
{
    int aux;
    if(a!=NULL)
    {
        aux=a->equipo;
    }
    return aux;
}
int alq_getRealTime(rent* a)
{
    int aux;
    if(a!=NULL)
    {
        aux=a->realTime;
    }
    return aux;
}
int alq_getEstTime(rent* a)
{
    int aux;
    if(a!=NULL)
    {
        aux=a->estTime;
    }
    return aux;
}
int alq_getOp(rent* a)
{
    int aux;
    if(a!=NULL)
    {
        aux=a->operador;
    }
    return aux;
}
int alq_getState(rent* a)
{
    int aux;
    if(a!=NULL)
    {
        aux=a->state;
    }
    return aux;
}

rent* alq_newStruct()
{
    rent* aux=(rent*)malloc(sizeof(rent));
    return aux;
}

int alq_askEstTime()
{
    int aux;

    aux=entero_get("tiempo estimado de alquiler");

    return aux;
}
int alq_askRealTime()
{
    int aux;

    aux=entero_get("tiempo real de alquiler");

    return aux;
}

void alq_mostrarSimple(rent* a,ArrayList* cte)
{
    alq_printEquipo(a);
    printf("- %dhs ",alq_getEstTime(a));
    alq_printCte(a,cte);
}

void alq_printEquipo (rent* a)
{
    switch(a->equipo)
    {
    case AMOLADORA:
        printf("Amoladora");
        break;
    case MEZCLADORA:
        printf("Mezcladora");
        break;
    case TALADRO:
        printf("Taladro");
        break;
    }
}
void alq_printOp (rent* a)
{
    switch(a->operador)
    {
    case JUAN:
        printf("Juan");
        break;
    case LUCAS:
        printf("Lucas");
        break;
    case ROQUE:
        printf("Roque");
        break;
    }
}

rent* alq_buscarId(ArrayList* alq)
{
    rent* a;
    rent* aux=NULL;
    int id, i;
    if(alq!=NULL)
    {
    id=entero_get("id de alquiler");

    for(i=0; i<al_len(alq); i++)
    {

        a=al_get(alq,i);
        if(id==a->idAlq)
        {
            aux=a;
            break;
        }
    }
    }
    return aux;
}

void alq_mostrarLista(ArrayList* alq, ArrayList* ctes)
{
    int i, len;
    rent* a;
    if(alq!=NULL&&ctes!=NULL)
    {
        len=al_len(alq);
        if(len!=0)
        {
            vista_encabezadoAlq();
            for(i=0; i<len; i++)
            {
                a=al_get(alq,i);
                if(a->state==ALQUILADO)
                {
                    vista_mostrarUnAlq(a,ctes);
                }
            }
        }
        else
        {
            vista_noData();
        }
    }
}



void alq_printCte (rent* a, ArrayList* ctes)
{
    client* c;
    int aux = a->idCte;
    c=clientes_forPrint(ctes,&aux);
    printf("- %s %s\t",clientes_getName(c),clientes_getLastname(c));
}
