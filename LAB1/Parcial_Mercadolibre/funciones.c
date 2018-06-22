#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

///INPUT

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

int esNumerico(char array[])
{
    int i=0, flag=1;
    while(array[i] != '\0')
    {
        if((!isdigit(array[i])))
        {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}

int esSoloLetras(char array[])
{
    int i=0, flag=1;
    while(array[i] != '\0')
    {
        if( (!isspace(array[i])) && (!isalpha(array[i])) )
        {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}

int esAlfanumerico(char array[])
{
    int i=0, flag=1;
    while(array[i] != '\0')
    {
        if((!isdigit(array[i])) && (!isalpha(array[i])))
        {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfanumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int ingresoValidadoStringNumerico(char mensaje[])
{
    char auxDato[20];
    int dato;
    printf("Ingrese %s",mensaje);
    while(!getStringNumeros(": ",auxDato))
    {
        printf("El item *%s* solo puede estar compuesto por numeros",mensaje);
        printf("Ingrese %s",mensaje);
        getStringNumeros(" nuevamente: ",auxDato);
    }
    dato = atoi(auxDato);

    return dato;
}
int ingresoValidadoStringNumericoMaxMin(char mensaje[], int min, int max)
{
    char auxDato[20];
    int dato;
    printf("Ingrese %s",mensaje);
    if(getStringNumeros(": ",auxDato))
    {
        dato = atoi(auxDato);
    }

    while((dato < min) || (dato > max))
    {
        printf("El item *%s* solo puede estar compuesto por numeros, y debe estar entre %d y %d.\n",mensaje,min,max);
        printf("Ingrese %s",mensaje);
        if(getStringNumeros(" nuevamente: ",auxDato))
        {
            dato = atoi(auxDato);
        }
    }
    return dato;
}

/// INIT ARRAY

void inicializarArrayEstructuraUsuario(EUsuario user[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        user[i].estadoU = valor;
    }
}

void initUserId(EUsuario user[], int tamanho)
{
    int id = 1000;
    int i;
    for(i=0; i < tamanho; i++)
    {
        user[i].idUsuario = id;
        id++;
    }
}

void inicializarArrayEstructuraProd(EProducto prod[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        prod[i].estadoP = valor;
    }
}

void initProdId(EProducto prod[], int tamanho)
{
    int id = 10000;
    int i;
    for(i=0; i < tamanho; i++)
    {
        prod[i].idProd = id;
        id++;
    }
}


///BUSQUEDA

int buscarPrimerOcurrenciaEstructuraEstado(EUsuario user[],int tamanho, int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(user[i].estadoU == valor)
        {
            return i;
        }
    }
    return -1;
}

int buscarPrimerOcurrenciaEstructuraEstadoProd (EProducto prod[],int tamanho, int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(prod[i].estadoP == valor)
        {
            return i;
        }
    }
    return -1;
}

int buscarPrimerOcurrenciaEstructuraIdProd (EProducto prod[],int tamanho, int id)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(prod[i].idProd == id)
        {
            return i;
        }
    }
    return -1;
}

int buscarPrimerOcurrenciaEstructuraIdUser (EUsuario user[],int tamanho, int id)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(user[i].idUsuario == id)
        {
            return i;
        }
    }
    return -1;
}

int buscarIndexPorNombreDeUsuario (EUsuario user[],int tamanho, char auxUser[])
{
    int i;
    int entro=-1;

    for(i=0; i < tamanho; i++)
    {
        if(strcmp(user[i].usuario,auxUser) == 0 && user[i].estadoU != -1)
        {
            entro = i;
            break;
        }
    }
    if(entro == -1)
    {
        printf("Usuario inexistente. Por favor, verifique e intente nuevamente.\n");
    }
    return entro;
}



///OTROS
int iniciarSesion (EUsuario user[],int tamanho, char auxUser[], char auxPass[])
{
    int i;
    int entro=-1;

    for(i=0; i < tamanho; i++)
    {
        if(strcmp(user[i].usuario,auxUser) == 0 && user[i].estadoU != -1)
        {
            if(strcmp(user[i].password,auxPass) == 0)
            {
                entro = i;
                break;
            }
        }

    }
    if(entro == -1)
    {
        printf("Datos incorrectos. Por favor, verifique e intente nuevamente.\n");
    }
    return entro;
}

void bajaPublicacionesUsuario(EProducto prod[], int tp, int idUsuario)
{
    int i;
    for(i=0; i<tp; i++)
    {
        if((prod[i].idUser == idUsuario) && (prod[i].estadoP != -1) )
        {
            prod[i].estadoP = -1;
        }
    }
}

void CalificarUsuario (EUsuario user[], int tu, int idUsuario)
{
    int indexUsuarioACalificar, calificacionComprador;
    indexUsuarioACalificar = buscarPrimerOcurrenciaEstructuraIdUser(user,tu,idUsuario);
    calificacionComprador = ingresoValidadoStringNumericoMaxMin("calificacion para el vendedor",1,10);
    user[indexUsuarioACalificar].calificacion = user[indexUsuarioACalificar].calificacion + calificacionComprador;
    user[indexUsuarioACalificar].calificadores++;
    printf("Gracias por su calificacion! ");
}



///LISTAR
void mostrarListaPublicacionesUsuario(EProducto prod[], int tp, int idUsuario)
{
    int i;
    for(i=0; i<tp; i++)
    {
        if((prod[i].idUser == idUsuario) && (prod[i].estadoP != -1) )
        {
            printf("ID: %d | Nombre: %s | Precio: $%.2f | Vendidos : %d | Stock: %d \n",prod[i].idProd, prod[i].producto, prod[i].precio, prod[i].cantidadVendida, prod[i].stock);
        }
    }
}


void MostrarListaDeUsuarios(EUsuario user[], int tu)
{
    int i;
    int promedio;
    printf("Lista de Usuarios:\n");
    for(i=0; i<tu; i++)
    {
        if(user[i].estadoU != -1)
        {
            if(user[i].calificadores==0)
            {
                printf("ID de Usuario: %d | Usuario: %s | Este usuario no tiene calificaciones aun! \n", user[i].idUsuario, user[i].usuario);
            }
            else
            {
                promedio=user[i].calificacion / user[i].calificadores;
                printf("ID de Usuario: %d | Usuario: %s | Calificacion Promedio: %d \n", user[i].idUsuario, user[i].usuario, promedio);
            }

        }
    }

}


void MostrarListaDePublicaciones(EProducto prod[], int tp, EUsuario user[], int tu)
{
    int i;
    int j;
    char usuarioString[20];
    printf("Lista completa de publicaciones:");
    for(i=0; i<tu; i++)
    {
        if(user[i].estadoU != -1)
        {
            strcpy(usuarioString,user[i].usuario);
            for(j=0; j<tp; j++)
            {
                if((prod[j].idUser == user[i].idUsuario) && (prod[i].estadoP != -1) )
                {
                    printf("ID: %d | Nombre: %s | Precio: $%.2f | Vendidos : %d | Stock: %d | USUARIO: %s\n",prod[j].idProd, prod[j].producto, prod[j].precio, prod[j].cantidadVendida, prod[j].stock, user[i].usuario);
                }
            }
        }
    }

}


/** \brief incrementa por 1 un valor y lo devuelve
 *
 * \param int valor a incrementar
 * \return valor incrementado
 *
 */
int incrementarValor (int valor)
{
    valor++;
    return valor;
}



///TESTING
void inicializarUsuariosHardCode(EUsuario user[])
{

    char usuario[][20] = {"luisito", "jay", "adolfo", "palu"};
    char pass[][20] = {"milanesa", "garrick","nein","ahre"};
    int i;

    for(i=0; i<4; i++)
    {
        user[i].estadoU = 1;
        strcpy(user[i].usuario, usuario[i]);
        strcpy(user[i].password, pass[i]);
        user[i].calificacion = 90;
        user[i].calificadores = 15;
    }
}

void inicializarProductosHardCode(EProducto prod[])
{

    char produttoLuisito[][50]= {"lapiz", "lapicera", "goma", "cuaderno", "cosa cinco"};
    int idluisito = 1000;
    int cdadVentasLuisito[] = {2, 3, 1, 5, 4};
    float auxPrecioLuisito[] = {20,10.33,2,30,5.50};
    int auxStockLuisito[] = {2, 5, 2, 1,4};
    int i;

    for(i=0; i<5; i++)
    {

        strcpy(prod[i].producto,produttoLuisito[i]);
        prod[i].precio = auxPrecioLuisito[i];
        prod[i].stock = auxStockLuisito[i];
        prod[i].cantidadVendida = cdadVentasLuisito[i];
        prod[i].estadoP = 1;
        prod[i].idUser = idluisito;
    }

    char produttoJay[][50]= {"encendedor", "celular", "mouse", "teclado", "joystick"};
    int idJay = 1001;
    int cdadVentasJay[] = {1, 2, 3, 4, 5};
    float auxPrecioJay[] = {30.40,22,77,10,7.20};
    int auxStockJay[] = {2, 5, 2, 1, 4};
    int j = 0;
    for(i=6; i<10; i++)
    {

        strcpy(prod[i].producto,produttoJay[j]);
        prod[i].precio = auxPrecioJay[j];
        prod[i].stock = auxStockJay[j];
        prod[i].cantidadVendida = cdadVentasJay[j];
        prod[i].estadoP = 1;
        prod[i].idUser = idJay;
        j++;
    }

    char produttoAdolf[][50]= {"tv", "auriculares", "guitarra", "bajo", "escritorio"};
    int idAdolf = 1002;
    int cdadAdolf[] = {4, 2, 3, 5, 1};
    float auxPrecioAdolf[] = {3.40,298,99,1,3.89};
    int auxStockAdolf[] = {2, 5, 2, 1, 4};
    int k = 0;
    for(i=11; i<15; i++)
    {

        strcpy(prod[i].producto,produttoAdolf[k]);
        prod[i].precio = auxPrecioAdolf[k];
        prod[i].stock = auxStockAdolf[k];
        prod[i].cantidadVendida = cdadAdolf[k];
        prod[i].estadoP = 1;
        prod[i].idUser = idAdolf;
        k++;
    }

    char produttoPalu[][50]= {"caja", "jean", "remera", "zapatillas", "adaptador"};
    int idPalu = 1003;
    int cdadPalu[] = {3, 2, 4, 5, 1};
    float auxPrecioPalu[] = {11,7,91,97.33,40.10};
    int auxStockPalu[] = {2, 5, 2, 1, 4};
    int l = 0;
    for(i=16; i<20; i++)
    {
        strcpy(prod[i].producto,produttoPalu[l]);
        prod[i].precio = auxPrecioPalu[l];
        prod[i].stock = auxStockPalu[l];
        prod[i].cantidadVendida = cdadPalu[l];
        prod[i].estadoP = 1;
        prod[i].idUser = idPalu;
        l++;

    }

}

void mostrarUsuarioPassParaTesting(EUsuario user[])
{
    int i;
    printf("USER, PASS // TESTING\n");
    for(i=0; i<4; i++)
    {
        printf("%s, %s\n", user[i].usuario, user[i].password);
    }
}
