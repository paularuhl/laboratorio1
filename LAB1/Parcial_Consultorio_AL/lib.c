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


int menuPrincipal (void)
{
    int opcion;

    fflush(stdin);
    printf("Sitio principal\n");
    printf("1. Tramite Urgente\n");
    printf("2. Tramite Regular\n");
    printf("3. Proximo Cliente\n");
    printf("4. Listar\n");
    printf("5. Informar\n");
    //printf("6. FFF\n");
    //printf("7. GGG\n");
    //printf("8. HHH\n");
    //printf("9. III\n");
    printf("\n0. Salir\n");

    opcion = ingresoStringNumerico("opcion");

    return opcion;
}



int nuevoTramite (ArrayList* tramitesRegulares, int turno, int prioridad)
{
    eTramites* aux=(eTramites*)malloc(sizeof(eTramites));
    int dni, ans;

    dni=turno_getDni();

    printf("Confirmar tramite ");
    turno_printPrioridad(prioridad);
    printf(" para DNI: %d? s/n\n",dni);

    ans=confirmar();
    if(ans)
    {
        aux->dni=dni;
        aux->prioridad=prioridad;
        aux->turno=turno++;
        tramitesRegulares->add(tramitesRegulares, aux);
        printf("\nTurno creado correctamente. Aguarde a ser llamado.");
    }
    else
    {
        printf("\nTurno cancelado.");
    }
    return turno;
}

void proximoCliente(ArrayList* tramitesUrgentes, ArrayList* tramitesRegulares, ArrayList* atendidosUrg, ArrayList* atendidosReg)
{
    eTramites* proximo=(eTramites*)malloc(sizeof(eTramites*));
    if(tramitesUrgentes !=NULL && tramitesRegulares !=NULL && atendidosUrg !=NULL && atendidosReg !=NULL && proximo !=NULL)
    {
        if(!tramitesUrgentes->isEmpty(tramitesUrgentes))
        {
            proximo=tramitesUrgentes->pop(tramitesUrgentes,0);
            atendidosUrg->add(atendidosUrg,proximo);
            turno_mostrarUnTramite(proximo);
        }
        else if(!tramitesRegulares->isEmpty(tramitesRegulares))
        {
            proximo=tramitesRegulares->pop(tramitesRegulares,0);
            atendidosReg->add(atendidosReg,proximo);
            turno_mostrarUnTramite(proximo);
        }
        else
        {
            printf("No hay clientes en espera...");
        }
    }

}

void listarPendientes (ArrayList* tramitesUrgentes, ArrayList* tramitesRegulares)
{
    if(tramitesUrgentes!=NULL && tramitesRegulares!=NULL)
    {
        if(!tramitesUrgentes->isEmpty(tramitesUrgentes))
        {
            printf("\nTramites urgentes:");
            turno_mostrarLista(tramitesUrgentes);
        }
        if(!tramitesUrgentes->isEmpty(tramitesUrgentes))
        {
            printf("\nTramites regulares:");
            turno_mostrarLista(tramitesRegulares);
        }

    }

}


int turno_getDni(void)
{
    int aux;
    aux = ingresoStringNumerico("DNI");
    //aux = validarDatoMaxMin(aux,"DNI",1000000,99999999);

    return aux;
}

void turno_mostrarUnTramite (eTramites* tramite)
{
    printf("DNI: %d / TIPO DE TRAMITE: ",tramite->dni);
    turno_printPrioridad(tramite->prioridad);
    printf(" / TURNO: %d\n",tramite->turno);
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
    eTramites* tramite;
    if(listado!=NULL)
    {
        len=listado->len(listado);
        for(i=0; i<len; i++)
        {
            tramite=listado->get(listado,i);
            printf("\nTURNO: %d\tDNI: %d",tramite->turno,tramite->dni);
        }
    }
}

int turno_compararDni(void* tramiteA, void* tramiteB)
{
    eTramites* tramite1;
    eTramites* tramite2;

    tramite1=(eTramites*)tramiteA;
    tramite2=(eTramites*)tramiteB;

    return strcmp(tramite1->dni,tramite2->dni);
}

int confirmar(void)
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

int isNull (char value)
{
    if(value=='\0' || value ==' ')
    {
        return 1;
    }
    return 0;
}

int esNumerico(char array[])
{
    int i=0;

    if(isNull(array[0]))
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

int esSoloLetras(char array[])
{
    int i=0;
    if(isNull(array[0]))
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

int esAlfanumerico(char array[])
{
    int i=0;
    if(isNull(array[0]))
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

int esDescriptivo(char array[])
{
    int i=0;
    if(isNull(array[0]))
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
        dato = ingresoStringNumerico(mensaje);
    }
    return dato;
}


///get strings
void getString(char mensaje[],char input[])
{
    fflush(stdin);
    printf("%s",mensaje);
    gets(input);
}

int getStringNumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfanumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int ingresoStringNumerico(char mensaje[])
{
    char auxDato[20];
    int dato;
    printf("\nIngrese %s:",mensaje);
    getString(" ",auxDato);
    while(!esNumerico(auxDato))
    {
        printf("*%s* solo puede estar compuesto por numeros.\nReingrese %s: ",mensaje,mensaje);
        fflush(stdin);
        gets(auxDato);
    }
    dato = atoi(auxDato);

    return dato;
}
