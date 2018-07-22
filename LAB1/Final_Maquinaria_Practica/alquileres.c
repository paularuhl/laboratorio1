#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"

#define FINALIZADO 0
#define ALQUILADO 1
#define AMOLADORA 2
#define MEZCLADORA 3
#define TALADRO 4
#define JUAN 5
#define LUCAS 6
#define ROQUE 7

///private functions
int askCte(ArrayList* ctes);
int askOp();
int askEquipo();
int askEstTime();
rent* buscarId(ArrayList* alq);

void mostrarAlq(rent* a,ArrayList* cte);
void mostrarLista(ArrayList* alq, ArrayList* ctes);
void printEquipoMax(int amo,int mez,int tal);

///
void alq_alta(ArrayList* rentals, ArrayList* ctes,int* id)
{
    rent* a=alq_newStruct();
    if(rentals!=NULL&&ctes!=NULL&&id!=NULL)
    {
        alq_setCte(a,askCte(ctes));
        alq_setEquipo(a,askEquipo());
        alq_setOp(a,askOp());
        alq_setEstTime(a,askEstTime());
        alq_setRealTime(a,alq_getEstTime(a));
        alq_setState(a,ALQUILADO);
        mostrarAlq(a,ctes);
        if(vista_confirmar("Confirmar alquiler?"))
        {
            (*id)++;
            alq_setId(a,id);
            al_add(rentals,a);
        }
    }
    exportData(ctes,rentals);
    vista_finFuncion();
}

void alq_baja(ArrayList* rentals, ArrayList* ctes)
{
    rent* a=NULL;
    if(ctes!=NULL&&rentals!=NULL)
    {
        if(al_len(rentals)!=0)
        {
            mostrarLista(rentals,ctes);
            a=buscarId(rentals);
            alq_mostrarUnAlq(a,ctes);
            alq_setRealTime(a,alq_askRealTime());

            if(vista_confirmar("\nConfirmar fin de alquiler?"))
            {
                vista_encabezadoFinAlq();
                alq_mostrarFinAlq(a,ctes);
                alq_setState(a,FINALIZADO);
            }
            vista_clean();
            exportData(ctes,rentals);
        }
        else
        {
            vista_noData();
        }
    }
}



int alq_askRealTime()
{
    int aux;

    aux=entero_get("tiempo real de alquiler (hs)");

    return aux;
}



void alq_printEquipo (rent* a)
{
    switch(alq_getEquipo(a))
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
    switch(alq_getOp(a))
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


void alq_printCte (rent* a, ArrayList* ctes)
{
    client* c;
    int aux = alq_getCte(a);
    c=clientes_buscarPorId(ctes,&aux);
    printf("%s %s\t",clientes_getName(c),clientes_getLastname(c));
}

void alq_equipoMax(ArrayList* alq)
{
    rent* a=NULL;
    int i;
    int amo=0;
    int mez=0;
    int tal=0;
    if(alq!=NULL)
    {
        if(al_len(alq)!=0)
        {
            for(i=0; i<al_len(alq); i++)
            {
                a=al_get(alq,i);
                switch(alq_getEquipo(a))
                {
                case AMOLADORA:
                    amo++;
                    break;
                case MEZCLADORA:
                    mez++;
                    break;
                case TALADRO:
                    tal++;
                    break;
                }
            }
            printEquipoMax(amo,mez,tal);
        }
        else
        {
            vista_noData();
        }
    }
}
void alq_tiempoPromedioReal(ArrayList* alq)
{
    rent* a=NULL;
    int contador=0, acumulador=0;
    int i,promedio,flag=1;
    for(i=0; i<al_len(alq); i++)
    {
        a=al_get(alq,i);
        if(alq_getState(a)==FINALIZADO)
        {
            flag=0;
            contador++;
            acumulador+=alq_getRealTime(a);
        }
    }
    if(flag)
    {
        printf("\n\nAun no hay alquileres finalizados...\n");
    }
    else
    {
        promedio=acumulador/contador;
        printf("\n\nEl tiempo promedio real de alquiler de los equipos es de %dhs. ",promedio);
    }
}



/// CONSTRUCTOR
rent* alq_newStruct()
{
    rent* aux=(rent*)malloc(sizeof(rent));
    return aux;
}
/// SETTERS
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
/// GETTERS
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


void alq_mostrarUnAlq(rent* a, ArrayList* ctes)
{
    printf("\n%d\t| %dhs\t| ",alq_getId(a),alq_getEstTime(a));
    alq_printEquipo(a);
    printf("\t| ");
    alq_printOp(a);
    printf("\t\t| ");
    alq_printCte(a,ctes);
}
void alq_mostrarFinAlq(rent* a, ArrayList* ctes)
{
    printf("\n%d\t| %dhs  \t| %dhs  \t| ",alq_getId(a),alq_getEstTime(a),alq_getRealTime(a));
    alq_printEquipo(a);
    printf("\t| ");
    alq_printOp(a);
    printf("\t\t| ");
    alq_printCte(a,ctes);
}

///privadas

/** \brief asks for the id of the client to assign the rental
 * \param [ctes ArrayList*] list of clients to search in
 * \return [int] id of client
 */ int askCte(ArrayList* ctes)
{
    client* c;
    clientes_mostrarLista(ctes);
    c=clientes_pedirId(ctes);
    return clientes_getId(c);
}
/** \brief asks for the kind of equipment to rent
 * \return int [2] Amoladora, [3] Mezcladora, [4] Taladro
 */ int askEquipo()
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
/** \brief asks for the operator entering the rent
 * \return int [5] Juan, [6] Lucas, [7] Roque
 */ int askOp()
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
/** \brief asks for the estimated time of rent
 * \return [int] time
 */ int askEstTime()
{
    int aux;

    aux=entero_get("tiempo estimado de alquiler (hs)");

    return aux;
}
/** \brief shows list and asks for an id on it and returns
 * \param  [alq ArrayList*] to search
 * \return [rent*] pointer to struct that corresponds with the given id.
 */ rent* buscarId(ArrayList* alq)
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
            if(id==alq_getId(a))
            {
                aux=a;
                break;
            }
        }
    }
    return aux;
}
 /** \brief shows a list of items with its corresponding header
 * \param [ArrayList* alq] pointer to list to show
 * \param [ArrayList* ctes] pointer to list of clients to show some items of
 * \return void
 */ void mostrarLista(ArrayList* alq, ArrayList* ctes)
{
    int i;
    rent* a;
    if(alq!=NULL&&ctes!=NULL)
    {
        if(al_len(alq)!=0)
        {
            vista_encabezadoAlq();
            for(i=0; i<al_len(alq); i++)
            {
                a=al_get(alq,i);
                if(alq_getState(a)==ALQUILADO)
                {
                    alq_mostrarUnAlq(a,ctes);
                }
            }
        }
        else
        {
            vista_noData();
        }
    }
}
/** \brief shows a single item with its corresponding header
 * \param [rent* a] pointer to struct to show
 * \param [ArrayList* ctes] pointer to list of clients to show some items of
 * \return void
 */ void mostrarAlq(rent* a,ArrayList* cte)
{
    alq_printEquipo(a);
    printf(" -- %dhs",alq_getEstTime(a));
    printf(" -- ");
    alq_printCte(a,cte);
}
/** \brief prints which equipment was rented the most times
 * \param [amo int] for amoladora
 * \param [mez int] for mezcladora
 * \param [tal int] for taladro
 * \return void
 */ void printEquipoMax(int amo,int mez,int tal)
{
    printf("\n\n");
    if(amo>mez&&amo>tal)
    {
        printf("El equipo mas alquilado es la amoladora, y se alquilaron %d en total.",amo);

    }
    if(mez>amo||tal>amo)
    {
        if(mez>tal)
        {
            printf("El equipo mas alquilado es la mezcladora, y se alquilaron %d en total.",mez);
        }
        else
        {
            printf("El equipo mas alquilado es el taladro, y se alquilaron %d en total.",tal);
        }
    }
    else if(mez==amo||tal==amo)
    {
        if(mez==tal)
        {
            printf("Los tres equipos se alquilaron por igual, %d de cada uno.",amo);
        }
        else if(mez==amo)
        {
            printf("La mezcladora y la amoladora se alquilaron por igual, %d de cada una.",amo);
        }
        else
        {
            printf("La amoladora y el taladro se alquilaron por igual, %d de cada uno.",amo);
        }
    }
}
