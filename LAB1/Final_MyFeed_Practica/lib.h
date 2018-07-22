#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    char name[30];
    char mail[50];

}eDestinatario;

/** \brief pide un nombre de archivo para abrir y cargar.
 * \param msg[] char archivo a pedir
 * \param fn[] char nombre del archivo(a validar)
 * \param lista ArrayList* lista a cargar
 * \return void
 */ void main_cargarLista(char msg[], char fn[], ArrayList* lista);

/** \brief reune funciones de depuración
 * \param listaA ArrayList*
 * \param listaB ArrayList*
 * \param depurados ArrayList*
 * \return void
 */ void main_depurar(ArrayList* listaA, ArrayList* listaB, ArrayList* depurados);


void ordenarUsuariosPop(ArrayList* user);
void ordenarPostPop(ArrayList* posts);
void mostrarUnUser(ArrayList* usu);

#endif // LIB_H_INCLUDED
