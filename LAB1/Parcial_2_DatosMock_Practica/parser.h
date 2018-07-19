#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"



/** \brief ingresa datos desde un archivo hacia un array de estructuras
 * \param l ArrayList*
 * \param char filename nombre de archivo
 * \return int if filepointer is null[-1], else [ultimoID]
 */ int txt_parseIn(ArrayList* l,char filename[]);

 /** \brief egresa datos desde un array de estructura hacia un archivo .csv
 * \param l ArrayList*
 * \return int if lista a cargar is null[-1], else [0]
 */ int txt_parseOut(ArrayList* l,char filename[]);
#endif // PARSER_H_INCLUDED
