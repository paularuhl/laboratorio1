#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    int id;
    int estado;
    char stringUno[40];
    int enteroUno;
    int enteroDos;
    float flotanteUno;

}eGen;

/** \brief muestra un menu principal generico
 * \param void
 * \return int opcion ingresada
 */ int generic_menu (void);

/** \brief agrega un "\n", pausa la aplicacion,
 * y limpia la pantalla al finalizar un case en el main
 * \param void
 * \return void
 */ void generic_finFuncion (void);


 /** \brief pide respuesta por si o por no
 * \param void
 * \return int [1] por si, [0] por no.
 */ int generic_confirmar(void);

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

int string_validaRango(char str[], int min, int max);

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


///genericas

eGen* gen_nuevaEstructura();
void gen_setString(eGen* g);
void gen_setEntero(eGen* g);
int gen_getEntero(eGen* g);
char* gen_getString (eGen* g);
void gen_mostrarUno (eGen* g);
void gen_mostrarLista(ArrayList* lista);
void gen_pasarAOtraLista(ArrayList* listaA, ArrayList* listaB);
int gen_compararItem(void* itemA, void* itemB);


#endif // LIB_H_INCLUDED
