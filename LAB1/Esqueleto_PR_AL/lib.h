#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    int id;
    int estado;
    char stringUno[40];
    int enteroUno;
    float flotanteUno;

}eGen;


/** \brief muestra un menu principal generico
 * \param void
 * \return int opcion ingresada
 */ int menuPrincipal (void);


 ///validar strings

/** \brief verifica que un dato ingresado no est� vac�o
 * \param char value es el valor a analizar
 * \return [1] si cumple, [0] si no
 */ int isNull (char value);

/**
 * \brief Verifica si el valor recibido es num�rico
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int esNumerico(char array[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int esSoloLetras(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int esAlfanumerico(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras, n�meros, espacios, y los sig. simbolos: . , : - " & |.
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int esDescriptivo(char array[]);

/** \brief pide un string numerico, lo valida como tal, muestra error o lo transforma a entero y verifica que este entre x rango
 *
 * \param mensaje el item a validar "Ingrese *mensaje*:"
 * \param min, max rango
 * \return int numero validado
 */ int validarDatoMaxMin(int dato, char mensaje[], int min, int max);


 ///get strings
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */ void getString(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int getStringLetras(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto alfanum�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int getStringAlfaNumerico(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 */ int ingresoStringNumerico(char mensaje[]);



#endif // LIB_H_INCLUDED
