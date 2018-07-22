#ifndef DATAMANAGER_H_INCLUDED
#define DATAMANAGER_H_INCLUDED
#include "ArrayList.h"
#include "clientes.h"
#include "alquileres.h"
#include "lib.h"

/** \brief exports two list to their corresponding files
 * \param [clientes ArrayList*] pointer to a list to export
 * \param [alquileres ArrayList*] pointer to a list to export
 * \return void
 */ void exportData(ArrayList* clientes,ArrayList* alquileres);

/** \brief reads a file and sets it's data on a structure on memory
 * \param [l ArrayList*] pointer to list to put items on
 * \param [filename[] char] to read
 * \return [int] last registered id
 */int ctes_parseIn(ArrayList* l,char filename[]);
/** \brief exports data of a list to a file
 * \param [lista ArrayList*] pointer to list to export data of
 * \param [filename[] char] to export to
 * \return void
 */ void ctes_parseOut(ArrayList* lista,char filename[]);

/** \brief reads a file and sets it's data on a structure on memory
 * \param [l ArrayList*] pointer to list to put items on
 * \param [filename[] char] to read
 * \return [int] last registered id
 */ int alq_parseIn(ArrayList* l,char filename[]);
/** \brief exports data of a list to a file
 * \param [lista ArrayList*] pointer to list to export data of
 * \param [filename[] char] to export to
 * \return void
 */void alq_parseOut(ArrayList* lista,char filename[]);

#endif // DATAMANAGER_H_INCLUDED
