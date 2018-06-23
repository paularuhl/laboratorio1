#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int idUsuario;
    char usuario[20];
    char password[20];
    int estadoU;
    int calificacion;
    int calificadores;

} EUsuario;

typedef struct
{
    int idProd;
    int idUser;
    char producto[50];
    double precio;
    int stock;
    int cantidadVendida;
    int estadoP;

} EProducto;

///INPUT
/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un n�mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n�mero ingresado por el usuario
 *
 */
float getFloat(char mensaje[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras y n�meros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y n�meros, y 0 si no lo es
 *
 */
int esAlfanumerico(char array[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto alfanum�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene numeros y letras
 */
int getStringAlfaNumerico(char mensaje[],char input[]);

/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de serlo la devuelve como entero
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 *
 */
int ingresoValidadoStringNumerico(char mensaje[]);

/** \brief pide un string numerico, lo valida como tal, lo transforma a entero y verifica que este entre x rango
 *
 * \param mensaje lo que vera el usuario "Ingrese *mensaje*:"
 * \param min, max rango
 * \return
 *
 */
int ingresoValidadoStringNumericoMaxMin(char mensaje[], int min, int max);


///INIT
void initProdId(EProducto prod[], int tamanho);
/** \brief inicializa id's de producto
 *
 * \param user[] EUsuario
 * \param tamanho int
 * \return void
 *
 */
void initUserId(EUsuario user[], int tamanho);
void inicializarArrayEstructuraUsuario(EUsuario user[],int tamanho,int valor);
void inicializarArrayEstructuraProd(EProducto prod[],int tamanho,int valor);

///BUSQUEDA
int buscarPrimerOcurrenciaEstructuraEstado(EUsuario user[],int tamanho, int valor);
int buscarPrimerOcurrenciaEstructuraEstadoProd(EProducto prod[],int tamanho, int valor);
int buscarPrimerOcurrenciaEstructuraIdProd (EProducto prod[],int tamanho, int id);
int buscarIndexPorNombreDeUsuario (EUsuario user[],int tamanho, char auxUser[]);

///OTROS
int iniciarSesion (EUsuario user[],int tamanho, char auxUser[], char auxPass[]);
void bajaPublicacionesUsuario(EProducto prod[], int tp, int idUsuario);
void CalificarUsuario (EUsuario user[], int tu, int idUsuario);

///LISTAR
/** \brief muestra una lista ordenada de usuarios si estan activos
 *
 * \param user[] EUsuario estructura a ordenar
 * \param tu int tamanio estructura
 * \return void
 *
 */
void MostrarListaDeUsuarios(EUsuario user[], int tu);
/** \brief muestra una lista con informacion de dos estructuras
 *
 * \param prod[] EProducto estructura principal para ordenar
 * \param tp int tamanio 1 estructura
 * \param user[] EUsuario estructura secundaria para ordenar
 * \param tu int tamanio 2 estructura
 * \return void
 *
 */
void MostrarListaDePublicaciones(EProducto prod[], int tp, EUsuario user[], int tu);
/** \brief muestra una lista d epublicaciones pidiendo el id de usuario antes
 *
 * \param prod[] EProducto estructura a ordenar
 * \param tp int tama�o estructura a ordenar
 * \param idUsuario int numero a matchear con la primera estructura
 * \return void
 *
 */
void mostrarListaPublicacionesUsuario(EProducto prod[], int tp, int idUsuario);

///TESTING
void inicializarUsuariosHardCode(EUsuario user[]);
void inicializarProductosHardCode(EProducto prod[]);
void mostrarUsuarioPassParaTesting(EUsuario user[]);


/*
Se debe desarrollar un sistema (en ANSI C) de venta de productos al estilo
mercadolibre. En este sistema existir�n usuarios, los cuales ingresar�n utilizando
su nombre de usuario y password. Mediante la plataforma se podr� comprar y
vender productos, estos se encuentran definidos por un nombre y precio. La
porci�n del sistema que deber� realizarse se centrar� en la venta de productos y
consta de un men� con las siguientes opciones:
1. ALTA DE USUARIO: Se piden los datos del usuario requeridos para que el
sistema pueda funcionar.
2. MODIFICAR DATOS DEL USUARIO: Se ingresa el ID del usuario, permitiendo
modificar sus datos.
3. BAJA DEL USUARIO: Se ingresa el ID del usuario y eliminar� junto con todos
sus productos a la venta.
4. PUBLICAR PRODUCTO: Se ingresar� el ID del usuario y se pedir�n los datos
del producto a publicar (nombre, precio y stock)
5. MODIFICAR PUBLICACI�N: Se ingresar� el ID del usuario y se listar�n los
productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
cantidad vendida y stock), luego ingresar el ID del producto y se pedir� que se
ingrese un nuevo precio y stock.
6. CANCELAR PUBLICACI�N: Se ingresar� el ID del usuario y se listar�n los
productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
cantidad vendida y stock), luego ingresar el ID del producto que se quiere
cancelar su publicaci�n.
7. COMPRAR PRODUCTO: Se ingresar� el ID del producto a comprar, y en el
caso que haya stock se realizar� la compra, en dicho caso se ingresar� una
calificaci�n para el vendedor.
8. LISTAR PUBLICACIONES DE USUARIO: Se ingresa el ID del usuario y se
mostrar� una lista de productos indicando: id, nombre, precio, cantidad vendida y
stock.
9. LISTAR PUBLICACIONES: Se mostrar� una lista de productos indicando: id,
nombre, precio, cantidad vendida, stock y nombre del usuario.
10. LISTAR USUARIOS: Se mostrar� una lista de usuarios con la calificaci�n
promedio de cada uno.
Nota 0: El sistema soportar� una capacidad m�xima de 100 usuarios y 1000 productos.
Nota 1: Se deber� desarrollar una biblioteca lib.c y lib.h la cual contendr� las funciones (Alta, Baja,
Modificar, etc.).
Nota 2: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y
respetar las reglas de estilo de la c�tedra.

*/
#endif // FUNCIONES_H_INCLUDED

