#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

/** \brief shows start menu
 * \return void
 */ void vista_menuPrincipal();

/** \brief shows modify menu
 * \return void
 */ void vista_menuModificar();

/** \brief shows invalid option error
 * \return void
 */ void vista_opcionInvalida();

/** \brief shows error when entering wrong type of item
 * \param [char item] item to re enter
 * \param [char tipo] type of item (number, letters, etc)
 * \return void
 */ void vista_errorItem(char item[],char tipo[]);

 /** \brief pide respuesta por si o por no
 * \param char pregunta a confirmar
 * \return int [1] por si, [0] por no.
 */ int vista_confirmar(char pregunta[]);

/** \brief prints a line-jump, pauses app and cleans screen.
 * \return void
 */ void vista_finFuncion();

/** \brief shows header for clients
 * \return void
 */ void vista_encabezadoClientes();

/** \brief shows header for rentals
 * \return void
 */ void vista_encabezadoAlq();

/** \brief shows header for the end of a rental
 * \return void
 */ void vista_encabezadoFinAlq();

/** \brief show error for when there's no data in a list to show
 * \return void
 */ void vista_noData();

/** \brief cleans screen
 * \return void
 */ void vista_clean();

void vista_errorNotFound();

/** \brief shows menu of equipment for rental
 * \return void
 */ void vista_menuEquipos();

/** \brief shows menu of operators for rental
 * \return void
 */ void vista_menuOp();


#endif // VISTA_H_INCLUDED

