#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"

#define ERROR -1
#define LOW 2
#define HIGH 3


int generic_menuPrincipal (void)
{
    int opcion;

    fflush(stdin);
    printf("Sitio principal\n");
    printf("1. Tramite Urgente\n");
    printf("2. Tramite Regular\n");
    printf("3. Proximo Cliente\n");
    printf("4. Listar pendientes\n");
    printf("5. Informe atendidos\n");
    //printf("6. FFF\n");
    //printf("7. GGG\n");
    //printf("8. HHH\n");
    //printf("9. III\n");
    printf("\n0. Salir\n");

    opcion = string_ingresoEntero("opcion");

    return opcion;
}

void generic_finFuncion (void)
{
    printf("\n");
    system("pause");
    system("cls");
}



int main_nuevoTramite (ArrayList* tramitesRegulares, int turno, int prioridad)
{
    eTramite* t = turno_nuevoTramite();

    turno_setDni(t);
    t->prioridad=prioridad;
    t->turno=turno;

    printf("Confirmar tramite ");
    turno_printPrioridad(prioridad);
    printf(" para DNI: %s? s/n\n",turno_getDni(t));

    if(generic_confirmar())
    {

        tramitesRegulares->add(tramitesRegulares, t);
        printf("\nTurno creado correctamente. Aguarde a ser llamado.");
    }
    else
    {
        printf("\nTurno cancelado.");
    }
    return turno;
}

void main_proximoCliente(ArrayList* tramitesUrgentes, ArrayList* tramitesRegulares, ArrayList* atendidosUrg, ArrayList* atendidosReg)
{
    if(tramitesUrgentes !=NULL && tramitesRegulares !=NULL && atendidosUrg !=NULL && atendidosReg !=NULL)
    {
        if(!tramitesUrgentes->isEmpty(tramitesUrgentes))
        {
            turno_atender(tramitesUrgentes,atendidosUrg);

        }
        else if(!tramitesRegulares->isEmpty(tramitesRegulares))
        {
            turno_atender(tramitesRegulares,atendidosReg);
        }
        else
        {
            printf("No hay clientes en espera...");
        }
    }

}

void main_listarPendientes (ArrayList* tramitesUrgentes, ArrayList* tramitesRegulares)
{
    if(tramitesUrgentes!=NULL && tramitesRegulares!=NULL)
    {
        if(!tramitesUrgentes->isEmpty(tramitesUrgentes))
        {
            printf("\nTramites urgentes:");
            turno_mostrarLista(tramitesUrgentes);
            printf("\n");
        }
        else
        {
            printf("\nNo hay tramites urgentes pendientes...");
        }
        if(!tramitesRegulares->isEmpty(tramitesRegulares))
        {
            printf("\nTramites regulares:");
            turno_mostrarLista(tramitesRegulares);
            printf("\n");
        }
        else
        {
            printf("\nNo hay tramites regulares pendientes...");
        }

    }

}

void main_informes(ArrayList* atendidosUrg, ArrayList* atendidosReg)
{
    if(atendidosUrg!=NULL && atendidosReg!=NULL)
    {
        if(!atendidosUrg->isEmpty(atendidosUrg))
        {
            atendidosUrg->sort(atendidosUrg,turno_compararDni,0);
            printf("\nTramites urgentes atendidos:");
            turno_mostrarLista(atendidosUrg);
            printf("\n");
        }
        else
        {
            printf("\nNo se atendieron tramites urgentes...");
        }
        if(!atendidosReg->isEmpty(atendidosReg))
        {
            atendidosReg->sort(atendidosReg,turno_compararDni,0);
            printf("\nTramites regulares atendidos:");
            turno_mostrarLista(atendidosReg);
            printf("\n");
        }
        else
        {
            printf("\nNo se atendieron tramites regulares...");
        }
    }
}

eTramite* turno_nuevoTramite()
{
    eTramite* aux;

    aux=(eTramite*)malloc(sizeof(eTramite));

    return aux;
}

int turno_getTurno(eTramite* t)
{
    int turno;
    if(t!=NULL)
    {
        turno=t->turno;
    }
    return turno;
}

char* turno_getDni(eTramite* t)
{
    char* dni=NULL;
    if(t!=NULL)
    {
        dni=t->dni;
    }
    return dni;
}


void turno_setDni(eTramite* t)
{
    char dni[10];
    if(t!=NULL)
    {
        do
        {
            while(!string_getNumerico("\nIngrese DNI: ",dni))
            {
                printf("Error, el dni solo puede ser numerico.");
            }
        }
        while(!string_validaRango(dni,1000,9999));

        strcpy(t->dni,dni);
    }

}

void turno_atender(ArrayList* lista, ArrayList* atendidos)
{
    eTramite* proximo=turno_nuevoTramite();
    if(lista!=NULL && atendidos!=NULL)
    {
        proximo=lista->pop(lista,0);
        atendidos->add(atendidos,proximo);
        turno_mostrarUnTramite(proximo);
    }
}

void turno_mostrarUnTramite (eTramite* t)
{
    if(t!=NULL)
    {
        printf("\nTURNO\t| TRAMITE\t| DNI");
        printf("\n%d\t| ",turno_getTurno(t));
        turno_printPrioridad(t->prioridad);
        printf("\t| %s",turno_getDni(t));
    }
}

void turno_printPrioridad(int prioridad)
{
    switch(prioridad)
    {
    case HIGH:
        printf("URGENTE");
        break;
    case LOW:
        printf("REGULAR");
        break;
    }
}

void turno_mostrarLista(ArrayList* listado)
{
    int i, len;
    eTramite* t;
    if(listado!=NULL)
    {
        len=listado->len(listado);
        printf("\nTURNO\t| DNI");
        for(i=0; i<len; i++)
        {
            t=listado->get(listado,i);
            printf("\n%d\t| %s",turno_getTurno(t),turno_getDni(t));
        }
    }
}

int turno_compararDni(void* tramiteA, void* tramiteB)
{
    eTramite* tramite1;
    eTramite* tramite2;

    tramite1=(eTramite*)tramiteA;
    tramite2=(eTramite*)tramiteB;

    return strcmp(tramite1->dni,tramite2->dni);
}

int generic_confirmar(void)
{
    char respuesta;
    int flag = 0;
    do
    {
        if(flag)
        {
            printf("\nRespuesta incorrecta, ingrese s por SI o n por NO...");
        }
        respuesta = getche();
        respuesta = tolower(respuesta);
        flag = 1;
    }
    while(respuesta!='s'&&respuesta!='n');
    if(respuesta=='s')
        return 1;
    else
        return 0;
}

///validar strings

int string_isNull (char value)
{
    if(value=='\0' || value ==' ')
    {
        return 1;
    }
    return 0;
}

int string_esNumerico(char array[])
{
    int i=0;

    if(string_isNull(array[0]))
    {
        return 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])))
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int string_esSoloLetras(char array[])
{
    int i=0;
    if(string_isNull(array[0]))
    {
        return 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if( (!isspace(array[i])) && (!isalpha(array[i])) )
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int string_esAlfanumerico(char array[])
{
    int i=0;
    if(string_isNull(array[0]))
    {
        return 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])) && (!isalpha(array[i])) && (!isspace(array[i])))
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int string_esDescriptivo(char array[])
{
    int i=0;
    if(string_isNull(array[0]))
    {
        return 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])) && (!isalpha(array[i])) && (!isspace(array[i])) && (array[i] != ':') && (array[i] != '-') && (array[i] != ',') && (array[i] != '.') && (array[i] != '&') && (array[i] != '"') && (array[i] != '|'))
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int validarDatoMaxMin(int dato, char mensaje[], int min, int max)
{
    while((dato < min) || (dato > max))
    {
        printf("El item *%s* debe estar entre %d y %d.\n",mensaje,min,max);
        dato = string_ingresoEntero(mensaje);
    }
    return dato;
}

int string_validaRango(char str[], int min, int max)
{
    int aux;
    aux = atoi(str);
    if(aux>=min&&aux<=max)
        return 1;
    else
    {
        printf("Error, el numero ingresado esta fuera de rango. MIN: %d MAX: %d",min,max);
        return 0;
    }
}

///get strings
void string_get(char mensaje[],char input[])
{
    fflush(stdin);
    printf("%s",mensaje);
    gets(input);
}

int string_getNumerico(char mensaje[],char input[])
{
    char aux[256];
    string_get(mensaje,aux);
    if(string_esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int string_getAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    string_get(mensaje,aux);
    if(string_esAlfanumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int string_getLetras(char mensaje[],char input[])
{
    char aux[256];
    string_get(mensaje,aux);
    if(string_esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int string_ingresoEntero(char mensaje[])
{
    char auxDato[20];
    int dato;
    printf("\nIngrese %s:",mensaje);
    string_get(" ",auxDato);
    while(!string_esNumerico(auxDato))
    {
        printf("*%s* solo puede estar compuesto por numeros.\nReingrese %s: ",mensaje,mensaje);
        fflush(stdin);
        gets(auxDato);
    }
    dato = atoi(auxDato);

    return dato;
}
