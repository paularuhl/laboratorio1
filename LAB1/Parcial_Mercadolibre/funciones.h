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
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[]);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
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
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfanumerico(char array[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto alfanumérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene numeros y letras
 */
int getStringAlfaNumerico(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
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
 * \param tp int tamaño estructura a ordenar
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
mercadolibre. En este sistema existirán usuarios, los cuales ingresarán utilizando
su nombre de usuario y password. Mediante la plataforma se podrá comprar y
vender productos, estos se encuentran definidos por un nombre y precio. La
porción del sistema que deberá realizarse se centrará en la venta de productos y
consta de un menú con las siguientes opciones:
1. ALTA DE USUARIO: Se piden los datos del usuario requeridos para que el
sistema pueda funcionar.
2. MODIFICAR DATOS DEL USUARIO: Se ingresa el ID del usuario, permitiendo
modificar sus datos.
3. BAJA DEL USUARIO: Se ingresa el ID del usuario y eliminará junto con todos
sus productos a la venta.
4. PUBLICAR PRODUCTO: Se ingresará el ID del usuario y se pedirán los datos
del producto a publicar (nombre, precio y stock)
5. MODIFICAR PUBLICACIÓN: Se ingresará el ID del usuario y se listarán los
productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
cantidad vendida y stock), luego ingresar el ID del producto y se pedirá que se
ingrese un nuevo precio y stock.
6. CANCELAR PUBLICACIÓN: Se ingresará el ID del usuario y se listarán los
productos de dicho usuario mostrando todos sus campos (id, nombre, precio,
cantidad vendida y stock), luego ingresar el ID del producto que se quiere
cancelar su publicación.
7. COMPRAR PRODUCTO: Se ingresará el ID del producto a comprar, y en el
caso que haya stock se realizará la compra, en dicho caso se ingresará una
calificación para el vendedor.
8. LISTAR PUBLICACIONES DE USUARIO: Se ingresa el ID del usuario y se
mostrará una lista de productos indicando: id, nombre, precio, cantidad vendida y
stock.
9. LISTAR PUBLICACIONES: Se mostrará una lista de productos indicando: id,
nombre, precio, cantidad vendida, stock y nombre del usuario.
10. LISTAR USUARIOS: Se mostrará una lista de usuarios con la calificación
promedio de cada uno.
Nota 0: El sistema soportará una capacidad máxima de 100 usuarios y 1000 productos.
Nota 1: Se deberá desarrollar una biblioteca lib.c y lib.h la cual contendrá las funciones (Alta, Baja,
Modificar, etc.).
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y
respetar las reglas de estilo de la cátedra.

*/
#endif // FUNCIONES_H_INCLUDED

