#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "clientes.h"

typedef struct {

    int equipo;
    int estTime;
    int realTime;
    int state;
    int idCte;
    int idAlq;
    int operador;

} rent;

/** \brief allocates memory for a structure
 * \return rent* struct to allocate
 */ rent* alq_newStruct();

/** \brief calculates which equipment was the most rented
 * \param [alq ArrayList*] list of rentals
 * \return void
 */ void alq_equipoMax(ArrayList* alq);
/** \brief calculates the average real time of rental
 * \param [alq ArrayList*] list of rentals
 * \return void
 */ void alq_tiempoPromedioReal(ArrayList* alq);

/** \brief genera el alta de un alquiler pidiendo los datos correspondientes
 * \param [alq ArrayList*] pointer to list of rentals
 * \param [ctes ArrayList*] pointer to list of clients
 * \param [id int*] pointer to last id registered.
 * \return void
 */ void alq_alta(ArrayList* alq, ArrayList* ctes,int* id);

/** \brief genera el fin de un alquiler
 * \param [alq ArrayList*] pointer to list of rentals
 * \param [ctes ArrayList*] pointer to list of clients
 * \return void
 */ void alq_baja(ArrayList* alq, ArrayList* ctes);



/** \brief prints the name and lastname of the client matching a rent
 * \param [a rent*] pointer to rental struct
 * \param [ctes ArrayList*] pointer to list of clients
 * \return void
 */ void alq_printCte (rent* a, ArrayList* ctes);
/** \brief prints the equipment of a rental
 * \param [a rent*] pointer to rental struct
 * \return void
 */ void alq_printEquipo (rent* a);
/** \brief prints the operator of a rental
 * \param [a rent*] pointer to rental struct
 * \return void
 */void alq_printOp (rent* a);

/** \brief
 * \param c rent*
 * \param ctes ArrayList*
 * \return void
 */ void alq_mostrarUnAlq(rent* c, ArrayList* ctes);

 /** \brief
 * \param a rent*
 * \param ctes ArrayList*
 * \return void
 */ void alq_mostrarFinAlq(rent* a, ArrayList* ctes);


/** \brief asks for the real time of rent
 * \return [int] time
 */ int alq_askRealTime();

/** SETTERS
 * \brief these functions assign an int to an item of the structure.
 * \param [a rent*] pointer to struct
 * \param [aux int] to assign
 *     or [id int*] pointer to last id registered.
 * \return void                                 */
void alq_setId(rent* a,int* id);
void alq_setCte(rent* a,int aux);
void alq_setEquipo(rent* a,int aux);
void alq_setEstTime(rent* a,int aux);
void alq_setRealTime(rent* a,int aux);
void alq_setOp(rent* a,int aux);
void alq_setState(rent* a,int aux);

/** GETTERS
 * \brief these functions return the content of an item on the structure
 * \param [a rent*] pointer to struct
 * \return [int] content of the item */
int alq_getId(rent* a);
int alq_getCte(rent* a);
int alq_getEquipo(rent* a);
int alq_getRealTime(rent* a);
int alq_getEstTime(rent* a);
int alq_getOp(rent* a);
int alq_getState(rent* a);

#endif // ALQUILERES_H_INCLUDED
