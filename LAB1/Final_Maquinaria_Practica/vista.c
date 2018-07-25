#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "vista.h"

void vista_menuPrincipal()
{
    printf("Sitio principal\n");
    printf("1. Alta Cliente\n");
    printf("2. Modificar Cliente\n");
    printf("3. Baja Cliente\n");
    printf("4. Nuevo Alquiler\n");
    printf("5. Fin Alquiler\n");
    printf("6. Informes\n");

    printf("\n0. Salir\n");
}
void vista_menuModificar()
{
    system("cls");
    printf("**Modificar cliente**\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");

    printf("\n0. Volver atras\n");
}
void vista_menuEquipos()
{
    printf("\n1. Amoladora\n");
    printf("2. Mezcladora\n");
    printf("3. Taladro");
}
void vista_menuOp()
{
    printf("\n1. Juan\n");
    printf("2. Lucas\n");
    printf("3. Roque");
}
void vista_opcionInvalida()
{
    printf("\nOpcion invalida. Intente otra vez.");
    system("pause");
    system("cls");
}
void vista_errorItem(char item[],char tipo[])
{
    printf("Error, %s solo puede tener %s.\n",item,tipo);
}
void vista_errorNotFound()
{
    printf("Ups! No encontramos lo que estabas buscando. Intenta nuevamente.\n");
}
void vista_clean ()
{
    system("cls");
}
void vista_finFuncion ()
{
    printf("\n");
    system("pause");
    system("cls");
}
int vista_confirmar(char pregunta[])
{
    char respuesta;
    int flag = 0, r;
    printf("\n%s s/n: ",pregunta);
    do
    {
        if(flag)
        {
            printf("\nRespuesta incorrecta, ingrese s por SI o n por NO: ");
        }
        respuesta = getche();
        respuesta = tolower(respuesta);
        flag = 1;
    }
    while(respuesta!='s'&&respuesta!='n');
    if(respuesta=='s')
    {
        r=1;
        printf("\nAccion completada.\n");
        getche();
    }
    else
    {
        r=0;
        printf("\nAccion cancelada.\n");
        getche();
    }

    return r;
}
void vista_noData()
{
    printf("No hay datos para mostrar...\n");
}
void vista_encabezadoClientes()
{
    printf("\nID | DNI      | Nombre y Apellido");
}
void vista_encabezadoAlq()
{
    printf("\nID | T.Est. | Equipo\t| Operador\t| Cliente");
}
void vista_encabezadoFinAlq()
{
    printf("\nID | T.Est. | T.Real | Equipo   \t| Operador\t| Cliente");
}

