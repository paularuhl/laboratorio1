#ifndef NUMEROS_H_INCLUDED
#define NUMEROS_H_INCLUDED
#include "ArrayList.h"
#include "dataManager.h"
#include "vista.h"
#include "lib.h"

typedef struct {
    int id;
    char letra;
    char name[10];
    int vocal;
    int consonante;

} eLetra;


/// CONSTRUCTOR
eLetra* letra_newStruct();
/// NUEVO NUM
void letra_new(eLetra* n, int* id, char letra, char* name, int vocal, int consonante);


/// SETTERS
void letra_setId(eLetra* n,int* aux);
void letra_setName(eLetra* n, char* aux);
void letra_setLetra(eLetra* n,char aux);
void letra_setVocal(eLetra* n,int aux);
void letra_setConsonante(eLetra* n,int aux);

/// GETTERS
char* letra_getName (eLetra* n);
char letra_getLetra (eLetra* n);
int letra_getVocal(eLetra* n);
int letra_getConsonante(eLetra* n);

/// CALCULOS
int letra_isConsonante(eLetra* n);
int letra_isVocal(eLetra* n);
int letra_isSpace(eLetra* n);
int letra_isMayus(eLetra* n);
int letra_isNumero(eLetra* n);

void letra_setCalculos(eLetra* n);

void letra_evaluate(ArrayList* lista);

void letra_mostrarLista(ArrayList* lista);
void mostrarUnaLetra(eLetra* c);
void mostrarLista(ArrayList* lista);

void muestroLetra(eLetra* c);
void nuevaCadena(ArrayList* lista, ArrayList* A,ArrayList* B);
ArrayList* cadenaB(ArrayList* lista,int* id);


#endif // NUMEROS_H_INCLUDED

