#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "vista.h"
#include "alquileres.h"

//#include "alquileres.h"
//#include "ArrayList.h"

void vista_menuPrincipal()
{
    printf("Sitio principal\n");
    printf("1. Alta Cliente\n");
    printf("2. Modificar Cliente\n");
    printf("3. Baja Cliente\n");
    printf("4. Nuevo Alquiler\n");
    printf("5. Fin Alquiler\n");
    printf("6. Informes\n");
    printf("7. Exportar datos actuales\n");

    printf("\n0. Salir\n");
}

void vista_menuModificar()
{
    system("cls");
    printf("\n**Modificar cliente**\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");

    printf("\n0. Volver atras\n");
}
void vista_menuEquipos()
{
    printf("1. Amoladora\n");
    printf("2. Mezcladora\n");
    printf("3. Taladro\n");
}
void vista_menuOp()
{
    printf("1. Juan\n");
    printf("2. Lucas\n");
    printf("3. Roque\n");
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
    printf("\nID\t| DNI\t| Nombre y Apellido");
}

void vista_mostrarUnCte(client* c)
{
    printf("\n%d\t| %s\t| %s %s",clientes_getId(c),clientes_getDni(c),clientes_getName(c),clientes_getLastname(c));
}

void vista_encabezadoAlq()
{
    printf("\nID\t| T.Est\t| Equipo\t| Operador\t| Cliente");
}
void vista_mostrarUnAlq(rent* a, ArrayList* ctes)
{
    printf("\n%d\t| %dhs\t| ",alq_getId(a),alq_getEstTime(a));
    alq_printEquipo(a);
    printf("\t| ");
    alq_printOp(a);
    printf("\t\t| ");
    alq_printCte(a,ctes);
}
void vista_mostrarFinAlq(rent* a, ArrayList* ctes)
{
    printf("\n%d\t| %dhs\t| %dhs\t| ",alq_getId(a),alq_getEstTime(a),alq_getRealTime(a));
    alq_printEquipo(a);
    printf("\t| ");
    alq_printOp(a);
    printf("\t| ");
    alq_printCte(a,ctes);
}

void vista_encabezadoFinAlq()
{
    printf("\nID\t| Alq Est. | Alq Real | Equipo\t| Operador\t| Cliente");
}
void vista_mostrarAlqBajaCte(client* c, ArrayList* ctes, ArrayList* alq)
{
    int i;
    rent* a=NULL;
    printf("\nAlquileres a finalizar con  baja de cliente:");
    for(i=0; i<al_len(alq); i++)
    {
        a=al_get(alq,i);
        if(a->idCte==c->idCte&&a->state==1)
        {
            printf("\n%d\t| %dhs\t| ",alq_getId(a),alq_getEstTime(a));
            alq_printEquipo(a);
            printf("\t| ");
            alq_printOp(a);
        }
    }
}
