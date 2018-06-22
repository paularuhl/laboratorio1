#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

typedef struct
{
    int idPropietario;
    char nombreYapellido[50];
    char direccion[50];
    char tarjetaDeCredito[7];
    int edad;
    int estado;

} EPropietario;

/** \brief muestra el menu principal
 *
 * \param void
 * \return void
 *
 */
void menuPrincipal(void);


/** \brief verifica que un dato ingresado no esté vacío
 *
 * \param char value es el valor a analizar
 * \return 1 si es null, 0 si no lo es.
 */
int isNull (char value);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */ void getString(char mensaje[],char input[]);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param array Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */ int esNumerico(char array[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param array Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */ int esSoloLetras(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param array Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */ int esAlfanumerico(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo números y -
 * \param array Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */ int esTarjeta(char array[]);


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */ int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */ int getStringLetras(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto alfanumérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene numeros y letras
 */ int getStringAlfaNumerico(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto numerico y con guion al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números y guion
 */ int getStringTarjeta(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 */ int ingresoStringNumerico(char mensaje[]);

/** \brief pide un string numerico, lo valida como tal, muestra error o lo transforma a entero y verifica que este entre x rango
 *
 * \param mensaje el item a validar "Ingrese *mensaje*:"
 * \param min, max rango
 * \return int numero validado
 */ int validarDatoMaxMin(int dato, char mensaje[], int min, int max);

/**
 * \brief Busca un index VACIO = -1 para ubicar un dato nuevo
 * \param prop Es el array de estructuras en el cual buscar
 * \param int tamanho Indica el tamanio del array
 * \param int valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */ int buscarIndexEstado(EPropietario prop[],int tamanho,int valor);

 /**
 * \brief Busca un ID ingresado por pantalla
 * \param prop Es el array de estructuras en el cual buscar
 * \param int tamanho Indica el tamanio del array
 * \param int valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */ int buscarID (EPropietario prop[],int tamanho,int valor);

 /**
 * \brief Busca una tarjeta de credito ingresada por pantalla
 * \param prop Es el array de estructuras en el cual buscar
 * \param int tamanho Indica el tamanio del array
 * \param char valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */ int buscarTarjeta(EPropietario prop[],int tamanho,char valor[]);

/** \brief da de alta un propietario pidiendo los datos correspondientes y confirmando la operacion
 *
 * \param prop[] EPropietario estructura donde se ubicara el nuevo propietario
 * \param tp int tamanio de estructura
 * \return void
 */void altaProp(EPropietario prop[], int tp);


/** \brief modifica la tarjeta de credito de un propietario, pidiendo ID por pantalla y confirmando la modificacion
 *
 * \param prop[] EPropietario estructura a modificar
 * \param tp int tamanio del array de estructuras
 * \return void
 */ void modificarProp(EPropietario prop[], int tp);


/** \brief muestra por pantalla a los propietarios en orden de ingreso
 *
 * \param prop[] EPropietario estructura a mostrar
 * \param tp int tamanio del array de estructuras
 * \return void
 */ void mostrarTodoProp(EPropietario prop[], int tp);

/** \brief inicializa la estructura autosOut con el valor VACIO -1
 *
 * \param autosOut[] egresosEst <- estructura a inicializar
 * \param int tamanho tamanho del array de estructuras
 * \param int estadoInicial -1 = vacio
 * \return void
 */ void initPropietarios(EPropietario prop[],int tamanho,int estadoInicial);

/** \brief hardcodea propietarios para testing
 *
 * \param prop[] EPropietario estructura a hardcodear
 * \return void
 */ void propietariosHC(EPropietario prop[]);


/** \brief genera un id autoincremental para los propietarios
 *
 * \param prop[] EPropietario estructura a revisar para generar el id
 * \param limite int tamanho del array de estructuras
 * \return int devuelve el ultimo id encontrado +1 para asignar a nuevo propietario
 */ int idIncremental(EPropietario prop[],int limite);



/** \brief ordena mediante burbujeo una estructura propietario, por orden alfabetico segun lo que pida usuario
 *
 * \param prop[] Epropietario estructura a ordenar
 * \param valor int tamanio del array de estructuras a ordenar
 * \return void
 */ void ordenarPropietarios(EPropietario prop[],int valor);

/** \brief ordena mediante burbujeo una estructura propietario A-Z
 *
 * \param prop[] Epropietario estructura a ordenar
 * \param valor int tamanio del array de estructuras a ordenar
 * \return void
 */ void ordenarPropAscendente (EPropietario prop[],int valor);

/** \brief ordena mediante burbujeo una estructura propietario Z-A
 *
 * \param prop[] Epropietario estructura a ordenar
 * \param valor int tamanio del array de estructuras a ordenar
 * \return void
 */ void ordenarPropDescendente (EPropietario prop[],int valor);

/** \brief ordena mediante burbujeo una estructura propietario A-Z
 *
 * \param prop[] Epropietario estructura a ordenar
 * \param valor int tamanio del array de estructuras a ordenar
 * \return void
 */void mostrarPropAscendente(EPropietario prop[],int tp);

void mostrarPropDescendente(EPropietario prop[],int tp);

void mostrarSuperanEdad (EPropietario prop[],int tp);




#endif // PROPIETARIO_H_INCLUDED
