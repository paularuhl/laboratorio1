#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    int idSocio;
    int estado;
    char name[40];
    char lastname[40];
    char mail[50];

}soc;


int generic_confirmar(void);

void main_parseIn(int* id,ArrayList* database);

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

/** \brief aloja memoria para estructura de socio
 *
 * \return soc* puntero a dir de memoria que se alojó
 */ soc* soc_newStruct();



/*************************************************************/
///NEW SETTERS -- ALTA O MODIFICACION -- piden por pantalla///
/***********************************************************/
/** \brief pide ingresar un nombre para socio
 *
 * \param s soc* estructura socio
 * \return void
 */ void soc_newName(soc* s);




/**************/
/// SETTERS ///
/************/
/** \brief setea nombre de socio
 *
 * \param s soc* estructura socio, name char*.
 * \return void
 */ void soc_setName(soc* s, char* name);

/** \brief setea apellido de socio
 *
 * \param s soc* estructura socio, apellido char*.
 * \return void
 */ void soc_setLastname(soc* s, char* apellido);

 /** \brief setea mail de socio
 *
 * \param s soc* estructura socio, apellido char*.
 * \return void
 */ void soc_setMail(soc* s, char* mail);

 /** \brief setea el id de un socio
 *
 * \param s soc* estructura socio,  id int* puntero a id autoincremental
 * \return void
 */ void soc_setId(soc* s,int* id);

/** \brief setea el estado de un socio
 *
 * \param s soc*
 * \param st int estado a setear
 * \return void
 */ void soc_setState(soc* s,int st);


/**************/
/// GETTERS ///
/************/

/** \brief devuelve el nombre del socio
 *
 * \param s soc* estructura socio
 * \return char* nombre
 */ char* soc_getName (soc* s);

/** \brief devuelve el apellido del socio
 *
 * \param s soc* estructura socio
 * \return char* apellido
 */ char* soc_getLastname (soc* s);

/** \brief devuelve el mail del socio
 *
 * \param s soc* estructura socio
 * \return char* mail
 */ char* soc_getMail (soc* s);

/** \brief devuelve el estado del socio
 *
 * \param s soc* estructura socio
 * \return int estado
 */ int soc_getState(soc* s);

/** \brief devuelve el id del socio
 *
 * \param s soc* estructura socio
 * \return int id
 */ int soc_getId(soc* s);


/************/
/// OTRAS ///
/**********/

/** \brief evalua socio en base a un criterio (mayor de 30, programador)
 *
 * \param socio void*
 * \return int [1] si pasa el filtro, [0] si no
 */ int funcionQueFiltra(void* socio);


/**************************************************************************/
///visuales (mostrar listas, menues extras)
/** \brief muestra una estructura de socio
 *
 * \param soc* e estructura a mostrar
 * \return void
 */ void soc_mostrarUno (soc* e);

/** \brief muestra una lista
 *
 * \param lista ArrayList*
 * \return void
 */ void main_mostrarLista(ArrayList* lista);




/**************************************************************************/
///validar strings

/** \brief verifica si un dato ingresado está vacío o no
 * \param char value es el valor a analizar
 * \return [1] si cumple, [0] si no
 */ int string_isNull (char value);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esNumerico(char array[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esSoloLetras(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esAlfanumerico(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras, números, espacios, y los sig. simbolos: . , : - " & |.
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esDescriptivo(char array[]);

/** \brief pide un string numerico, lo valida como tal, muestra error o lo transforma a entero y verifica que este entre x rango
 *
 * \param mensaje el item a validar "Ingrese *mensaje*:"
 * \param min, max rango
 * \return int numero validado
 */ int validarDatoMaxMin(int dato, char mensaje[], int min, int max);

/**************************************************************************/
 ///get strings
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */ void string_get(char mensaje[],char input[]);


 /**
 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int string_getNumerico(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int string_getLetras(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto alfanumérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int string_getAlfaNumerico(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 */ int entero_get(char mensaje[]);

/** \brief valida un entero dentro de un rango
 *
 * \param int dato a evaluar
 * \param mensaje[] char visual de que es lo que se ingreso
 * \param min int, max int
 * \return int [1] si esta dentro del rango, [0] si no
 */ int entero_validaRango(int dato, char mensaje[], int min, int max);

/**************************************************************************/
///genericas

/** \brief muestra un menu principal generico
 * \param void
 * \return int opcion ingresada
 */ int vista_menu (void);

/** \brief agrega un "\n", pausa la aplicacion,
 * y limpia la pantalla al finalizar un case en el main
 * \param void
 * \return void
 */ void generic_finFuncion (void);

 /** \brief pide respuesta por si o por no
 * \param void
 * \return int [1] por si, [0] por no.
 */ int vista_confirmar(void);


/** \brief pide los datos para dar de alta un nuevo socio
 *
 * \param socio ArrayList* lista de socios
 * \param id int* puntero a id auto-incremental
 * \return void
 */ void generic_alta(ArrayList* lista, int* id);


/*
void main_baja(ArrayList* lista);
void main_modificar(ArrayList* lista);
void gen_pasarAOtraLista(ArrayList* listaA, ArrayList* listaB);
int gen_compararItem(void* itemA, void* itemB);
*/



#endif // LIB_H_INCLUDED
