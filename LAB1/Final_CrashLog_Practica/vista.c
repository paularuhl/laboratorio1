#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vista.h"
#include "service.h"
#include "logEntry.h"
#include "library.h"

//#include "ArrayList.h"

void vista_menuPrincipal()
{
    printf("Sitio principal\n");
    printf("1. Leer Log\n");
    printf("2. Procesar Informacion\n");
    printf("3. Mostrar estadisticas\n");

    printf("\n0. Salir\n");
}


void vista_opcionInvalida()
{
    printf("\nOpcion invalida. Intente otra vez.");
    system("pause");
    system("cls");
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

void vista_noFile()
{
    printf("No se pudo cargar el archivo...\n");
}


void vista_mostrarUnSer(Service* s)
{
    printf("\n%d\t| %s\t| %s",ser_getId(s),ser_getName(s),ser_getEmail(s));
}

void vista_encabezadoSer()
{
    printf("\nID\t| Name\t| Mail");
}
