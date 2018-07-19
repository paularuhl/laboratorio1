#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    char name[30];
    char mail[50];

}eDestinatario;

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

/** \brief setea un nombre
 * \param d eDestinatario* estructura donde pertenece el item
 * \param aux char* nombre a setear
 * \return void
 */ void dest_setName(eDestinatario* d, char* aux);

/** \brief setea un mail
 * \param d eDestinatario* estructura donde pertenece el item
 * \param aux char* mail a setear
 * \return void
 */ void dest_setMail(eDestinatario* d, char* aux);

/** \brief coloca datos desde un archivo a una lista en memoria dinamica
 * \param fn char* nombre de archivo a abrir para parsear
 * \param l ArrayList* lista de arrays par colocar los datos
 * \return void
 */ void dest_parseData(char* fn, ArrayList* l);

 void dest_archivarDepurados(ArrayList* lista);

/** \brief Crea una nueva lista en base a una lista original y una blacklist
 * \param listaA ArrayList* lista de datos a evaluar
 * \param listaB ArrayList* lista de datos a eliminar
 * \param depurados ArrayList* lista a generar con los datos restantes
 * \return void
 */ void filtroBlacklist(ArrayList* listaA, ArrayList* listaB, ArrayList* depurados);

/** \brief Filtra repetidos en una misma lista
 * \param depurados ArrayList* lista a filtrar
 * \return void
 */ void filtroRepetidos(ArrayList* depurados);


/** \brief muestra un menu principal generico
 * \param void
 * \return int opcion ingresada
 */ int generic_menu (void);




 ///VALIDATING STRINGS

/** \brief verifica si un dato ingresado está vacío o no
 * \param char value es el valor a analizar
 * \return [1] si cumple, [0] si no
 */ int string_isNull (char value);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */ int string_esNumerico(char array[]);

 int string_validaRango(char str[], int min, int max);


 ///GETTING STRINGS
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
 * \brief Solicita un texto de letras al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */ int string_getLetras(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 */ int entero_get(char mensaje[]);


///genericas

/** \brief muestra un listado
 * \param lista ArrayList* listado a mostrar
 * \return void
 */ void dest_mostrarLista(ArrayList* lista);


/** \brief allocates memory for a string
 * \return char* pointer to where the str will be
 */ char* gen_newString();

/** \brief gets an element from a structure
 * \param eDestinatario structure from where to get the item
 * \return pointer to string item
 */ char* dest_getMail (eDestinatario* d);

/** \brief gets an element from a structure
 * \param eDestinatario structure from where to get the item
 * \return pointer to string item
 */ char* dest_getName (eDestinatario* d);

/** \brief compares two items of whichever type
 * \param itemA void*
 * \param itemB void*
 * \return int
 */ int dest_compararMail(void* itemA, void* itemB);


int string_validateLength(char* str, int len);

#endif // LIB_H_INCLUDED
