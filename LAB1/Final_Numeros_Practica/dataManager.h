#ifndef DATAMANAGER_H_INCLUDED
#define DATAMANAGER_H_INCLUDED
#include "ArrayList.h"
#include "numeros.h"

/** \brief reads a file and sets it's data on a structure on memory
 * \param [l ArrayList*] pointer to list to put items on
 * \param [filename[] char] to read
 * \return [int] last registered id
 */ void number_parseIn(ArrayList* l,char filename[]);
/** \brief exports data of a list to a file
 * \param [lista ArrayList*] pointer to list to export data of
 * \param [filename[] char] to export to
 * \return void
 */ void number_parseOut(ArrayList* lista,char filename[]);


#endif // DATAMANAGER_H_INCLUDED
