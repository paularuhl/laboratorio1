#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"



/** \brief ingresa datos desde un archivo hacia un array de estructuras
 * \param l ArrayList*
 * \return int ultimo id de empleado para poder igresar uno nuevo en caso de que sea necesario
 */ int parseIn(ArrayList* l,char filename[],int* id);

 /** \brief egresa datos desde un array de estructura hacia un archivo .csv
 * \param l ArrayList*
 * \return void
 */ int parseOut(ArrayList* l,char filename[]);
#endif // PARSER_H_INCLUDED
