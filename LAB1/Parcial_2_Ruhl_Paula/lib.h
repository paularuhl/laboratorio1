#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    int idEmpleado;
    int estado;
    int edad;
    int salary;
    char name[40];
    char profesion[10];

}eEmp;

/** \brief aloja memoria para estructura de empleado
 *
 * \return eEmp* puntero a dir de memoria que se alojó
 */ eEmp* emp_newStruct();



/*************************************************************/
///NEW SETTERS -- ALTA O MODIFICACION -- piden por pantalla///
/***********************************************************/
/** \brief pide ingresar un nombre para empleado
 *
 * \param s eEmp* estructura empleado
 * \return void
 */ void emp_newName(eEmp* s);

/** \brief pide ingresar una edad para empleado, entre 18 y 99.
 *
 * \param s eEmp* estructura empleado
 * \return void
 */ void emp_newEdad(eEmp* s);

/** \brief pide seleccionar opcion de profesion para empleado
 *
 * \param s eEmp* estructura empleado
 * \return int numero de acuerdo a profesion para poder setear salario
 */ int emp_newProfesion(eEmp* s);

/** \brief setea un salario para empleado de acuerdo a la profesion
 *
 * \param s eEmp* estructura empleado, prof int indicador de profesion
 * \return void
 */ void emp_newSalary(eEmp* s,int prof);


/**************/
/// SETTERS ///
/************/
/** \brief setea nombre de empleado
 *
 * \param s eEmp* estructura empleado, name char*.
 * \return void
 */ void emp_setName(eEmp* s, char* name);

/** \brief setea nombre de empleado
 *
 * \param s eEmp* estructura empleado, Profesion char*.
 * \return void
 */ void emp_setProfesion(eEmp* s, char* Profesion);

/** \brief setea salario de empleado
 *
 * \param s eEmp* estructura empleado, int salary.
 * \return void
 */ void emp_setSalary (eEmp* s, int salary);

/** \brief setea salario de empleado
 *
 * \param s eEmp* estructura empleado, int edad.
 * \return void
 */ void emp_setEdad (eEmp* s, int edad);

 /** \brief setea el id de un empleado
 *
 * \param s eEmp* estructura empleado,  id int* puntero a id autoincremental
 * \return void
 */ void emp_setId(eEmp* s,int* id);

/** \brief setea el estado de un empleado
 *
 * \param s eEmp*
 * \param st int estado a setear
 * \return void
 */ void emp_setState(eEmp* s,int st);


/**************/
/// GETTERS ///
/************/

/** \brief devuelve el nombre del empleado
 *
 * \param s eEmp* estructura empleado
 * \return char* nombre
 */ char* emp_getName (eEmp* s);

 /** \brief devuelve la profesion del empleado
 *
 * \param s eEmp* estructura empleado
 * \return char* profesion
 */ char* emp_getProfesion (eEmp* s);

/** \brief devuelve el salario del empleado
 *
 * \param s eEmp* estructura empleado
 * \return int salario
 */ int emp_getSalary(eEmp* s);

/** \brief devuelve el estado del empleado
 *
 * \param s eEmp* estructura empleado
 * \return int estado
 */ int emp_getState(eEmp* s);

/** \brief devuelve el id del empleado
 *
 * \param s eEmp* estructura empleado
 * \return int id
 */ int emp_getId(eEmp* s);

/** \brief devuelve la edad del empleado
 *
 * \param s eEmp*
 * \return int edad
 */ int emp_getEdad(eEmp* s);


/************/
/// OTRAS ///
/**********/

/** \brief evalua empleado en base a un criterio (mayor de 30, programador)
 *
 * \param empleado void*
 * \return int [1] si pasa el filtro, [0] si no
 */ int funcionQueFiltra(void* empleado);


/**************************************************************************/
///visuales (mostrar listas, menues extras)
/** \brief muestra una estructura de empleado
 *
 * \param eEmp* e estructura a mostrar
 * \return void
 */ void emp_mostrarUno (eEmp* e);

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


/** \brief pide los datos para dar de alta un nuevo empleado
 *
 * \param socio ArrayList* lista de empleados
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
