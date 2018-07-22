#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "parser.h"
#include "user.h"
#include "post.h"

int main()
{
    ArrayList* mensajes=al_newArrayList();
    ArrayList* usuarios=al_newArrayList();

    int opcion, salir=0;

    do
    {
        printf("\nMENU:\n1. Cargar mensajes y usuarios.\n2. Procesar y ordenar.\n3. Exportar feed.\n\n Ingrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            user_parseIn(usuarios,"usuarios.csv");
            post_parseIn(mensajes,"mensajes.csv");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            al_sort(usuarios,user_compararNick,1);
            user_parseOut(usuarios,"test.csv");
            system("pause");
            system("cls");
            break;
        case 3:
            //mostrarUnUser(usuarios);
            feed_parseOut(usuarios,mensajes);
            break;
        case 0:
            printf("Adios!\n");
            system("pause");
            salir = 1;
            break;
        default:
            printf("\nOpcion invalida. Intente otra vez.");
            system("pause");
            system("cls");
            break;
        }
    }
    while(salir==0);
    return 0;
}
