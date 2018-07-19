#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED
#include "alquileres.h"

void vista_menuPrincipal();

void vista_menuModificar();

void vista_opcionInvalida();

void vista_errorItem(char item[],char tipo[]);

 /** \brief pide respuesta por si o por no
 * \param char pregunta a confirmar
 * \return int [1] por si, [0] por no.
 */ int vista_confirmar(char pregunta[]);

/** \brief agrega un "\n", pausa la aplicacion,
 * y limpia la pantalla al finalizar un case en el main
 * \param void
 * \return void
 */ void vista_finFuncion (void);

void vista_encabezadoClientes();
void vista_mostrarUnCte(client* c);

void vista_encabezadoAlq();
void vista_mostrarUnAlq(rent* c, ArrayList* ctes);
void vista_mostrarFinAlq(rent* a, ArrayList* ctes);

void vista_mostrarAlqBajaCte(client* c, ArrayList* ctes, ArrayList* alq);

void vista_encabezadoFinAlq();

void vista_noData();

void vista_clean ();

void vista_errorNotFound();

void vista_menuEquipos();

void vista_menuOp();


#endif // VISTA_H_INCLUDED

