#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "ArrayList.h"
#include "dataManager.h"
#include "alquileres.h"
#include "lib.h"
#include "vista.h"

typedef struct {

    int idCte;
    int state;
    char dni[9];
    char name[40];
    char lastname[40];

} client;

/** \brief genera el alta de un cliente pidiendo los datos correspondientes
 * \param [clientes ArrayList*] pointer to list of clients
 * \param [idCte int*] pointer to last id registered.
 * \return void
 */ void clientes_alta(ArrayList* clientes,int* idCte);

/** \brief permite modificar nombre o apellido del cliente
 * \param [clientes ArrayList*] pointer to list of clients
 * \return void
 */ void clientes_modificar(ArrayList* clientes);

/** \brief genera la baja de un cliente y los alquileres que tenga activos
 * \param [clientes ArrayList*] pointer to list of clients
 * \param [alq ArrayList*] pointer to list of rentals to match to client
 * \return void
 */ void clientes_baja(ArrayList* clientes,ArrayList* alq);

/** \brief shows a single item with its corresponding header
 * \param [client* c] pointer to struct to show
 * \return void
 */ void clientes_mostrarUno (client* c);

 /** \brief shows a list of items with its corresponding header
 * \param [ArrayList* lista] pointer to list to show
 * \return void
 */ void clientes_mostrarLista(ArrayList* lista);

/** \brief searchs for the first ocurrence of an id on a list
 * \param clientes ArrayList* list to be searched on
 * \param  [id int*] pointer to id for search
 * \return [client*] pointer to struct corresponding to given id
 */ client* clientes_buscarPorId(ArrayList* clientes, int* id);

/** \brief shows list and asks for an id on it and returns
 * \param  [clientes ArrayList*] to search
 * \return [client*] pointer to struct that corresponds with the given id.
 */ client* clientes_pedirId(ArrayList* clientes);

/** \brief calculates which client has had the most rentals
 * \param [ctes ArrayList*] pointer to list of clients
 * \param [alq ArrayList*] pointer to list of rentals to match to client
 * \return void
 */ void clientes_conMasAlquileres(ArrayList* ctes, ArrayList* alq);


/// CONSTRUCTOR
/** \brief allocates memory for a structure
 * \return [client*] pointer to struct to allocate
 */ client* clientes_newStruct();

/** SETTERS
 * \brief these functions set an item of the structure.
 * \param [c client*] pointer to struct
 * \param [aux char*] string content to assign
 *     or [aux int] content to assign
 *     or [id int*] pointer to last id registered.
 * \return void                                 */
void clientes_setName(client* c, char* aux);
void clientes_setLastname(client* c, char* aux);
void clientes_setDni(client* c, char* aux);
void clientes_setState(client* c,int st);
void clientes_setId(client* c,int* id);

/** GETTERS
 * \brief these functions return the content of an item on the structure
 * \param  [c client*] pointer to struct
 * \return [int] content of the item
 *      or [char*] pointer to string content of the item               */
int clientes_getId(client* c);
int clientes_getState(client* c);
char* clientes_getName (client* c);
char* clientes_getLastname (client* c);
char* clientes_getDni (client* c);

#endif // CLIENTES_H_INCLUDED

