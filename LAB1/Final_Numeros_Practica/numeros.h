#ifndef NUMEROS_H_INCLUDED
#define NUMEROS_H_INCLUDED
#include "ArrayList.h"
#include "dataManager.h"
#include "vista.h"

typedef struct {

    int num;
    char name[20];
    int par;
    int impar;
    int primo;

} number;


/// CONSTRUCTOR
number* number_newStruct();
/// NUEVO NUM
void number_new(number* n, int num, char* name, int par, int impar, int primo);


/// SETTERS
void number_setName(number* n, char* aux);
void number_setNum(number* n,int aux);
void number_setPar(number* n,int aux);
void number_setImpar(number* n,int aux);
void number_setPrimo(number* n,int aux);

/// GETTERS
char* number_getName (number* n);
int number_getNum(number* n);
int number_getPar(number* n);
int number_getImpar(number* n);
int number_getPrimo(number* n);

/// CALCULOS
int number_isPrimo(number* n);
int number_isPar(number* n);
int number_isImpar(number* n);

void number_setCalculos(number* n);

void numeros_evaluate(ArrayList* lista);


#endif // NUMEROS_H_INCLUDED
