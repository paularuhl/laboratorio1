#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "vista.h"

void vista_menuPrincipal()
{
    printf("Sitio principal\n");
    printf("1. Importar\n");
    printf("2. Ingresar string y crear listas A y B\n");
    printf("3. Ingresar Lista y mostrar los dos\n");

    printf("\n0. Salir\n");
}

void vista_finFuncion ()
{
    printf("\n");
    system("pause");
    system("cls");
}void vista_opcionInvalida()
{
    printf("\nOpcion invalida. Intente otra vez.");
    system("pause");
    system("cls");
}
