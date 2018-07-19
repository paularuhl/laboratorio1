#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    ArrayList* destinatarios=al_newArrayList();
    ArrayList* listaNegra=al_newArrayList();
    ArrayList* depurados=al_newArrayList();

    int opcion, salir=0;

    do
    {
        opcion = generic_menu();
        switch(opcion)
        {
        case 1:
            main_cargarLista("de destinatarios","destinatarios.csv",destinatarios);
            break;
        case 2:
            main_cargarLista("negra","black_list.csv",listaNegra);
            break;
        case 3:
            main_depurar(destinatarios,listaNegra,depurados);
            break;
        case 4:
            dest_mostrarLista(depurados);
            break;
    /*  case 5:
            generic_finFuncion();
            break;
        case 6:
            generic_finFuncion();
            break;
        case 7:
            generic_finFuncion();
            break;
        case 8:
            generic_finFuncion();
            break;
        case 9:
            generic_finFuncion();
            break;
            */
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
