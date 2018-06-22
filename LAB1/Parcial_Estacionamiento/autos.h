#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include "propietario.h"

typedef struct
{
    int idAuto;
    char patente[4];
    int marca;
    int idProp;
    int estado;
} EAuto;

typedef struct
{
    char patente[4];
    char nombreYApellido[50];
    int tiempo;
    int marca;
    float importe;
    int estado;

} egresosEst;

/**
 * \brief Busca un lugar vacio en la estructura
 * \param array Es el array en el cual buscar
 * \param tamanho Indica el tamanio del array
 * \param valor Es el valor que se busca
 * \return Si no hay lugar disponible retorna (-1) y si la hay, la posición de la misma
 */ int buscarIndexAutos(EAuto autos[],int tamanho,int valor);

/**
 * \brief Busca la patente ingresada en la estructura
 * \param EAuto autos[] Es el array en el cual buscar
 * \param int tamanho Indica el tamanio del array
 * \param char patente Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 */ int buscarPatente(EAuto autos[],int tamanho, char patente[]);

/** \brief carga los datos de un automovil para ingresarlo a sistema
 *
 * \param prop[] EPropietario estructura con datos del propietario del auto
 * \param autos[] EAuto estructura de los autos
 * \param ta int tamanio de estructura auto
 * \param tp int tamanio de estructura propietario
 * \return void
 */ void ingresoAuto (EAuto autos[], int ta, EPropietario prop[], int tp);

/** \brief
 *
 * \param autos[] EAuto estructura de autos a copiar
 * \param ta int tamaño autos
 * \param prop[] EPropietario estructura propietario de cada auto
 * \param tp int tamaño propietarios
 * \param autosOut[] egresosEst estructura egresos
 * \param te int tamaño egresos
 * \return void
 *
 */
void egresoAuto(EAuto autos[], int ta, EPropietario prop[], int tp, egresosEst autosOut[], int te);


 /** \brief da de baja un propietario con sus autos estacionados
  *
  * \param prop[] EPropietario estructura prop a dar de baja
  * \param tp int tamaño prop
  * \param autos[] EAuto autos que corresponden al propietario a dar de baja
  * \param ta int tamaño estructura autos
  * \param autosOut[] egresosEst estructura de autos dados de baja
  * \param te int tamaño estructura egreso
  * \return void
  *
  */
 void bajaProp(EPropietario prop[],int tp, EAuto autos[], int ta, egresosEst autosOut[], int te);


/** \brief transfiere los datos de egreso de un auto hacia la estructura egreso y las registra como tales
 *
 * \param egresosEst autosOut[] estructura de egresos a colocar los datos
 * \param int te tamanho de estructura egresos
 * \param marca y patente del automovil, nombre del propietario, horas que paso en el estacionamiento e importe a pagar
 * \return void
 */ void transferDatosEgreso (egresosEst autosOut[],int te, char patente[], char nombre[],int marca, float importe, int horas);


/** \brief devuelve un entero generado aleatoriamente para usar como cantidad de horas en el estacionamiento
 *
 * \return int horas estacionado
 */ int horasEstadia();


/** \brief devuelve el importe a pagar segun la marca del auto y las horas que haya pasado en el estacionamiento
 *
 * \param marca int marca del auto
 * \param horas int horas estacionado
 * \return int importe final
 */ int valorEstadia(int marca, int horas);

/** \brief muestra los automoviles estacionados
 *
 * \param prop[] EPropietario estructura con datos del propietario del auto
 * \param autos[] EAuto estructura de los autos
 * \param ta int tamanio de estructura auto
 * \param tp int tamanio de estructura propietario
 * \return void
 */ void mostrarTodoAutos(EAuto autos[], int ta, EPropietario prop[], int tp);

/** \brief muestra los automoviles que tiene estacionado un propietario
 *
 * \param prop[] EPropietario estructura con datos del propietario del auto
 * \param autos[] EAuto estructura de los autos
 * \param ta int tamanio de estructura auto
 * \param tp int tamanio de estructura propietario
 * \return void
 */ void mostrarPropietarioConAutos(EPropietario prop[],int tp, EAuto autos[],int ta);

/** \brief muestra los propietarios que tienen automoviles de marca AUDI estacionados.
 *
 * \param prop[] EPropietario estructura con datos del propietario del auto
 * \param autos[] EAuto estructura de los autos
 * \param ta int tamanio de estructura auto
 * \param tp int tamanio de estructura propietario
 * \return void
 */ void mostrarPropAudi (EPropietario prop[], int tp, EAuto autos[], int ta);


/** \brief muestra la recaudacion total del estacionamiento en el momento
 *
 * \param autosOut egresosEst estructura de autos dados de baja
 * \param te int tamaño estructura
 * \return void
 *
 */
void recaudacionTotal(egresosEst autosOut[], int te);

/** \brief muestra la recaudacion total por cada marca en el momento
 *
 * \param autosOut egresosEst estructura de autos dados de baja
 * \param te int tamaño estructura
 * \return void
 *
 */
void recaudacionPorMarca (egresosEst autosOut[],int te);

/** \brief ordena mediante burbujeo una estructura auto, por orden alfabetico de patente
 *
 * \param autos[] EAuto estructura a ordenar
 * \param valor int tamanio del array de estructuras a ordenar
 * \return void
 */ void ordenarPatente(EAuto autos[],int valor);

/** \brief muestra por pantalla la lista ordenada de autos por patente, con datos del propietario
 *
 * \param prop[] EPropietario estructura con datos del propietario del auto
 * \param autos[] EAuto estructura auto ordenada
 * \param ta int tamaño de estructura auto
 * \param tp int tamaño de estructura propietario
 * \return void
 */ void mostrarPorPatente(EPropietario prop[],EAuto autos[], int ta, int tp);

/** \brief imprime la marca correspondiente con el entero brindado (ej 1 alpha romeo)
 *
 * \param entero correspondiente a la marca del auto
 */ void imprimirMarca (int marca);

/** \brief inicializa la estructura autos con el valor VACIO -1
 *
 * \param autos[] EAuto <- estructura a inicializar
 * \param int tamanho tamanho del array de estructuras
 * \param int estadoInicial -1 = vacio
 * \return void
 */ void initAutos(EAuto autos[],int tamanho,int estadoInicial);

/** \brief inicializa la estructura autosOut con el valor VACIO -1
 *
 * \param autosOut[] egresosEst <- estructura a inicializar
 * \param int tamanho tamanho del array de estructuras
 * \param int estadoInicial -1 = vacio
 * \return void
 */ void initEgresos(egresosEst autosOut[],int tamanho, int valor);

/** \brief hardcodea autos para testing
 *
 * \param autos[] EAuto estructura a hardcodear
 * \return void
 */ void autosHC(EAuto autos[]);

/** \brief hardcodea egresos para testing
 *
 * \param autosOut[] egresosEst estructura a hardcodear
 * \return void
 */ void egresosHC(egresosEst autosOut[]);




#endif // AUTOS_H_INCLUDED
