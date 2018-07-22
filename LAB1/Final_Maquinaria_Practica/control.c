#include <stdio.h>
#include <stdlib.h>
#include "control.h"

///private functions
void informes(ArrayList* clientes, ArrayList* alquileres);

void control_init()
{
    ArrayList* clientes=al_newArrayList();
    ArrayList* alquileres=al_newArrayList();
    int opcion, salir=0;
    int idCte=ctes_parseIn(clientes,"clientes.csv");
    int idAlq=alq_parseIn(alquileres,"alq.csv");
    do
    {
        vista_menuPrincipal();
        switch(opcion=entero_get("opcion"))
        {
        case 1:
            clientes_alta(clientes,&idCte);
            break;
        case 2:
            clientes_modificar(clientes);
            break;
        case 3:
            clientes_baja(clientes,alquileres);
            break;
        case 4:
            alq_alta(alquileres,clientes,&idAlq);
            break;
        case 5:
            alq_baja(alquileres,clientes);
            break;
        case 6:
            informes(clientes,alquileres);
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
}

///private functions
/** \brief displays statistics
 * \param [clientes ArrayList*] pointer to client list
 * \param [alquileres ArrayList*] pointer to rental list
 * \return void
 */ void informes(ArrayList* clientes, ArrayList* alquileres)
{
    if(al_len(clientes)!=0)
    {
        clientes_conMasAlquileres(clientes,alquileres);
        alq_equipoMax(alquileres);
        alq_tiempoPromedioReal(alquileres);
        vista_finFuncion();
    }
}
