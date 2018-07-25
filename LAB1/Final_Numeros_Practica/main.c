#include <stdio.h>
#include <stdlib.h>
#include "letras.h"

#include "vista.h"
#include "dataManager.h"
#include "lib.h"
int main()
{
    ArrayList* letras=al_newArrayList();
    ArrayList* A=al_newArrayList();
    ArrayList* B=al_newArrayList();
    int idLetras=0;
    int idA=0;
    int idB=0;
    int opcion, salir=0;
    do
    {
        vista_menuPrincipal();
        switch(opcion=entero_get("opcion"))
        {
        case 1:
            letras_parseIn(letras,"datos.csv",&idLetras);
            letra_evaluate(letras);
            letra_mostrarLista(letras);
            break;
        case 2:
            nuevaCadena(letras,A,B);
            //mostrarLista(A);
            //B=cadenaB(A,&idB);
            //mostrarLista(B);
            break;
        case 3:
           // letras_parseOut(letras,"completo.csv");
            //letras_parseOut(letras,"repetido.csv");
            //letras_parseOut(letras,"depurado.csv");
            break;
        case 0:
            printf("Adios!\n");
            system("pause");
            salir = 1;
            break;
        default:
            vista_opcionInvalida();
            break;
        }
    }
    while(salir==0);
    return 0;
}
