#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "ArrayList.h"

typedef struct {

    int idCte;
    int state;
    char dni[9];
    char name[40];
    char lastname[40];

} client;

void clientes_alta(ArrayList* clientes,int* idCte);

void clientes_modificar(ArrayList* clientes);

void clientes_baja(ArrayList* clientes,ArrayList* alq);

void clientes_mostrarUno (client* c);
void clientes_mostrarLista(ArrayList* lista);
void clientes_mostrarSimple (client* c);
client* clientes_forPrint(ArrayList* clientes, int* id);

client* clientes_newStruct();

char* clientes_askName(char* aux);
char* clientes_askLastname(char* aux);
char* clientes_askDni(char* aux);

void clientes_setName(client* c, char* aux);
void clientes_setLastname(client* c, char* aux);
void clientes_setDni(client* c, char* aux);
void clientes_setState(client* c,int st);
void clientes_setId(client* c,int* id);

char* clientes_getName (client* c);
char* clientes_getLastname (client* c);
char* clientes_getDni (client* c);
int clientes_getId(client* c);
int clientes_getState(client* c);

/** \brief allocates memory for a structure
 * \return client* struct to allocate
 */ client* gen_newStruct();

client* clientes_buscarId(ArrayList* clientes);
int clientes_dniRepetido(ArrayList* l,char* dni);



#endif // CLIENTES_H_INCLUDED

