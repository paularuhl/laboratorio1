#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED
#include "ArrayList.h"
#include "service.h"

void vista_menuPrincipal();

void vista_opcionInvalida();


void vista_errorNotFound();


void vista_clean ();
void vista_finFuncion ();

int vista_confirmar(char pregunta[]);

void vista_noData();
void vista_noFile();


void vista_mostrarUnSer(Service* s);

void vista_encabezadoSer();
#endif // VISTA_H_INCLUDED

