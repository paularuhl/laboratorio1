#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define QTY_USERS 100
#define QTY_PRODUCTOS 1000
#define VACIO -1


int main()
{
    EUsuario user[QTY_USERS]; //auxUser[QTY_USERS];
    EProducto prod[QTY_PRODUCTOS]; //auxProd[QTY_PRODUCTOS];
    char auxUsuario[20], auxPass[20], auxProducto[50];
    int auxEstadoP, auxStock, auxCdadVendida, auxIdProd;
    double auxPrecio;
    int indexLibre, indexEncontradoU, indexEncontradoP, usuarioIngresadoID;
    char seguir='s', seguirModificando='s';
    int opcion=0, opcionModificar=0;


    inicializarArrayEstructuraUsuario(user,QTY_USERS,VACIO);
    initUserId(user,QTY_USERS);
    inicializarArrayEstructuraProd(prod,QTY_PRODUCTOS,VACIO);
    initProdId(prod,QTY_PRODUCTOS);
    inicializarUsuariosHardCode(user);
    inicializarProductosHardCode(prod);

    mostrarUsuarioPassParaTesting(user);

    while(seguir=='s')
    {
        indexLibre = VACIO;
        indexEncontradoP = VACIO;
        indexEncontradoU = VACIO;
        printf("\n1- Registrarse\n");
        printf("2- Modificar Usuario\n");
        printf("3- Baja Usuario\n");
        printf("4- Publicar Producto\n");
        printf("5- Modificar Publicacion\n");
        printf("6- Cancelar Publicacion\n");
        printf("7- Comprar Producto\n");
        printf("8- Listar Publicaciones de Usuario\n");
        printf("9- Listar Publicaciones\n");
        printf("10- Listar Usuarios\n");
        printf("11- Salir\n\n");

        opcion = ingresoValidadoStringNumericoMaxMin("opcion",1,11);

        switch(opcion)
        {
        case 1:
            indexLibre = buscarPrimerOcurrenciaEstructuraEstado(user, QTY_USERS, VACIO);
            if(indexLibre == VACIO)
            {
                printf("No hay lugares libres para el registro\n");
                break;
            }

            printf("\n *REGISTRAR USUARIO* \n");

            if(!getStringAlfaNumerico("Ingrese un usuario: ",auxUsuario))
            {
                printf("El usuario solo puede tener letras o numeros.\n");
                break;
            }

            if(!getStringAlfaNumerico("Ingrese una contrasenia: ",auxPass))
            {
                printf("La contrasenia solo puede tener letras o numeros.\n");
                break;
            }


            strcpy(user[indexLibre].usuario,auxUsuario);
            strcpy(user[indexLibre].password,auxPass);
            user[indexLibre].estadoU = 1;
            user[indexLibre].calificacion = 0;
            user[indexLibre].calificadores = 0;

            break;
        case 2:
            getStringAlfaNumerico("Ingrese su usuario: ",auxUsuario);
            getStringAlfaNumerico("Ingrese una contrasenia: ",auxPass);
            if((indexEncontradoU = iniciarSesion(user, QTY_USERS, auxUsuario, auxPass)) != VACIO)
            {
                printf("Bienvenido, %s !\n",auxUsuario);
                while(seguirModificando=='s')
                {
                    printf("\n*MODIFICAR USUARIO*\n");
                    printf("Que dato desea cambiar?\n");
                    printf("1- Usuario\n");
                    printf("2- Contrasenia\n");
                    printf("3- Volver atras\n");
                    opcionModificar = ingresoValidadoStringNumericoMaxMin("opcion",1,3);

                    switch(opcionModificar)
                    {
                    case 1:
                        if(!getStringAlfaNumerico("Ingrese un nuevo usuario: ",auxPass))
                        {
                            printf("El usuario solo puede tener letras o numeros.\n");
                            break;
                        }
                        strcpy(user[indexEncontradoU].usuario,auxUsuario);
                        break;
                    case 2:
                        if(!getStringAlfaNumerico("Ingrese una nueva contrasenia: ",auxPass))
                        {
                            printf("La contrasenia solo puede tener letras o numeros.\n");
                            break;
                        }
                        strcpy(user[indexEncontradoU].password,auxPass);
                        break;
                    case 3:
                        seguirModificando = 'n';
                        break;
                    }
                }
            }

            break;
        case 3:
            printf("\n*BAJA DE USUARIO*\n");
            getStringAlfaNumerico("Ingrese su usuario: ",auxUsuario);
            getStringAlfaNumerico("Para poder darlo de baja, ingrese su contrasenia: ",auxPass);
            if((indexEncontradoU = iniciarSesion(user, QTY_USERS, auxUsuario, auxPass)) != VACIO)
            {
                usuarioIngresadoID = user[indexEncontradoU].idUsuario;
                user[indexEncontradoU].estadoU = VACIO;
                bajaPublicacionesUsuario(prod,QTY_PRODUCTOS,usuarioIngresadoID);
                printf("El usuario %s ha sido dado de baja correctamente.\n", user[indexEncontradoU].usuario);
            }
            break;
        case 4:
            getStringAlfaNumerico("Ingrese su usuario: ",auxUsuario);
            getStringAlfaNumerico("Ingrese una contrasenia: ",auxPass);
            if((indexEncontradoU = iniciarSesion(user, QTY_USERS, auxUsuario, auxPass)) != VACIO)
            {
                printf("Bienvenido, %s !\n",auxUsuario);
                usuarioIngresadoID = user[indexEncontradoU].idUsuario;
                indexLibre = buscarPrimerOcurrenciaEstructuraEstadoProd(prod, QTY_PRODUCTOS, VACIO);
                if(indexLibre == VACIO)
                {
                    printf("No hay lugares libres para el registro.\n");
                    break;
                }
                printf("\n*PUBLICAR PRODUCTO*\n");
                if(!getStringLetras("\nIngrese un nombre: ",auxProducto))
                {
                    printf("El nombre debe estar compuesto solo por letras.\n");
                    break;
                }
                auxPrecio = getFloat("Ingrese el precio del producto: ");
                auxStock = ingresoValidadoStringNumerico("el stock disponible del producto");
                auxCdadVendida = 0;
                auxEstadoP = 1;

                strcpy(prod[indexLibre].producto,auxProducto);
                prod[indexLibre].precio = auxPrecio;
                prod[indexLibre].stock = auxStock;
                prod[indexLibre].cantidadVendida = auxCdadVendida;
                prod[indexLibre].estadoP = auxEstadoP;
                prod[indexLibre].idUser = usuarioIngresadoID;
                printf("Publicacion cargada satisfactoriamente!\n");
            }
            break;
        case 5:
            getStringAlfaNumerico("Ingrese su usuario: ",auxUsuario);
            getStringAlfaNumerico("Ingrese una contrasenia: ",auxPass);
            if((indexEncontradoU = iniciarSesion(user, QTY_USERS, auxUsuario, auxPass)) != VACIO)
            {
                printf("Bienvenido, %s!\n",auxUsuario);
                usuarioIngresadoID = user[indexEncontradoU].idUsuario;

                printf("\n*MODIFICAR PUBLICACION*\n");
                do
                {
                    opcion=0;
                    mostrarListaPublicacionesUsuario(prod,QTY_PRODUCTOS,usuarioIngresadoID);
                    printf("Busque e ingrese el ID de la publicacion que desea MODIFICAR\n");
                    auxIdProd = ingresoValidadoStringNumerico("ID");
                    while ((indexEncontradoP = buscarPrimerOcurrenciaEstructuraIdProd(prod, QTY_PRODUCTOS, auxIdProd)) == VACIO || prod[indexEncontradoP].estadoP == VACIO )
                    {
                        printf("Publicacion no encontrada. Verifique cual es y vuelva a intentar.\n");
                        auxIdProd = ingresoValidadoStringNumerico("publicacion");
                    }
                    prod[indexEncontradoP].precio = getFloat("Ingrese el nuevo precio: ");
                    prod[indexEncontradoP].stock = ingresoValidadoStringNumerico("el nuevo stock del producto");
                    printf("Publicacion modificada correctamente. Desea modificar otra?\n1. Si\n2. No\n");
                    opcion = ingresoValidadoStringNumericoMaxMin("opcion",1,2);
                }
                while(opcion==1);
            }
            break;
        case 6:
            getStringAlfaNumerico("Ingrese su usuario: ",auxUsuario);
            getStringAlfaNumerico("Ingrese una contrasenia: ",auxPass);
            if((indexEncontradoU = iniciarSesion(user, QTY_USERS, auxUsuario, auxPass)) != VACIO)
            {
                printf("Bienvenido, %s!\n",auxUsuario);
                usuarioIngresadoID = user[indexEncontradoU].idUsuario;

                printf("\n*CANCELAR PUBLICACION*\n");
                do
                {
                    opcion=0;
                    mostrarListaPublicacionesUsuario(prod,QTY_PRODUCTOS,usuarioIngresadoID);
                    printf("Busque e ingrese el ID de la publicacion que desea CANCELAR\n");
                    auxIdProd = ingresoValidadoStringNumerico("ID");
                    while ((indexEncontradoP = buscarPrimerOcurrenciaEstructuraIdProd(prod, QTY_PRODUCTOS, auxIdProd)) == VACIO || prod[indexEncontradoP].estadoP == VACIO )
                    {
                        printf("ID no encontrado. Verifique cual es y vuelva a intentar.\n");
                        auxIdProd = ingresoValidadoStringNumerico("ID");

                    }
                    prod[indexEncontradoP].estadoP = VACIO;
                    printf("Publicacion cancelada correctamente. Desea cancelada otra?\n1. Si\n2. No\n");
                    opcion = ingresoValidadoStringNumericoMaxMin("opcion",1,2);
                }
                while(opcion==1);
                break;
            case 7:
                printf("\n*COMPRAR PRODUCTO*\n");
                do
                {
                    opcion=0;
                    printf("Busque e ingrese el ID del producto a COMPRAR:\n");
                    auxIdProd = ingresoValidadoStringNumerico("producto");
                    if((indexEncontradoP = buscarPrimerOcurrenciaEstructuraIdProd(prod, QTY_PRODUCTOS, auxIdProd)) == VACIO || prod[indexEncontradoP].estadoP == VACIO )
                    {
                        printf("Publicacion no encontrada. Verifique cual es y vuelva a intentar.\n");
                        break;
                    }
                    if(prod[indexEncontradoP].stock == 0)
                    {
                        printf("Lo sentimos, el producto no tiene stock disponible para la compra.\n");
                        break;
                    }
                    usuarioIngresadoID = prod[indexEncontradoP].idUser;
                    CalificarUsuario(user,QTY_USERS,usuarioIngresadoID);
                    prod[indexEncontradoP].stock--;
                    prod[indexEncontradoP].cantidadVendida++;
                    printf("Compra realizada correctamente. Desea comprar otro producto?\n1. Si\n2. No\n");
                    opcion = ingresoValidadoStringNumericoMaxMin("opcion",1,2);
                }
                while(opcion ==1);
                break;
            case 8:
                getStringAlfaNumerico("Ingrese un usuario: ",auxUsuario);
                if((indexEncontradoU = (buscarIndexPorNombreDeUsuario(user,QTY_USERS,auxUsuario))) != VACIO)
                {
                    usuarioIngresadoID = user[indexEncontradoU].idUsuario;
                    printf("Lista de publicaciones de %s:\n",auxUsuario);
                    mostrarListaPublicacionesUsuario(prod,QTY_PRODUCTOS,usuarioIngresadoID);
                }
                break;
            case 9:
                MostrarListaDePublicaciones(prod,QTY_PRODUCTOS,user,QTY_USERS);
                break;
            case 10:
                MostrarListaDeUsuarios(user,QTY_USERS);
                break;
            case 11:
                seguir = 'n';
                break;
            }
        }

    }
    return 0;
}
