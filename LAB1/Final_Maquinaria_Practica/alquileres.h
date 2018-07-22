#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "clientes.h"

typedef struct {

    int equipo;
    int estTime;
    int realTime;
    int state;
    int idCte;
    int idAlq;
    int operador;

} rent;

void alq_equipoMax(ArrayList* alq);
void informes(ArrayList* clientes, ArrayList* alquileres);

void alq_clienteConMasAlquileres(ArrayList* ctes, ArrayList* alq);
void tiempoPromedioReal(ArrayList* alq);

int alq_tiempo();

void alq_alta(ArrayList* alq, ArrayList* ctes,int* id);
void alq_baja(ArrayList* alq, ArrayList* ctes);

void alq_mostrarSimple(rent* a,ArrayList* cte);
void alq_mostrarLista(ArrayList* alq, ArrayList* ctes);

void alq_printCte (rent* a,ArrayList* ctes);
void alq_printEquipo (rent* a);
void alq_printOp (rent* a);

rent* alq_buscarId(ArrayList* alq);


rent* alq_newStruct();

int alq_askCte(ArrayList* ctes);
int alq_askOp();
int alq_askEquipo();
int alq_askEstTime();
int alq_askRealTime();


void alq_setId(rent* a,int* id);
void alq_setCte(rent* a,int aux);
void alq_setEquipo(rent* a,int aux);
void alq_setEstTime(rent* a,int aux);
void alq_setRealTime(rent* a,int aux);
void alq_setOp(rent* a,int aux);
void alq_setState(rent* a,int aux);

int alq_getId(rent* a);
int alq_getCte(rent* a);
int alq_getEquipo(rent* a);
int alq_getRealTime(rent* a);
int alq_getEstTime(rent* a);
int alq_getOp(rent* a);
int alq_getState(rent* a);

#endif // ALQUILERES_H_INCLUDED
