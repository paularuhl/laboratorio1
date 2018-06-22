#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include "autos.h"
#include "propietario.h"

#define VACIO -1
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4


int buscarIndexAutos(EAuto autos[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(autos[i].estado == valor)
        {
            return i;
        }
    }
    return VACIO;
}
int buscarIndexEgreso(egresosEst autosout[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(autosout[i].estado == valor)
        {
            return i;
        }
    }
    return VACIO;
}
int buscarPatente(EAuto autos[],int tamanho, char patente[])
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if((stricmp(patente,autos[i].patente) == 0)&& (autos[i].estado != VACIO))
        {
            return i;
        }
    }
    return VACIO;
}
int buscarIDAutos (EAuto autos[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if((autos[i].idAuto == valor)&& (autos[i].estado != VACIO))
        {
            return i;
        }
    }
    return VACIO;
}



void ingresoAuto (EAuto autos[], int ta, EPropietario prop[],int tp)
{
    int flag=0, indexLibre, indexPatenteDuplicada, auxIdProp, indexProp;
    int auxMarca;
    char patente[4], respuesta='x';
    do
    {
        indexLibre = buscarIndexAutos(autos, ta, VACIO);
        if(indexLibre == VACIO)
        {
            printf("No hay lugares libres para el registro!\n");
            break;
        }
        else
        {
            do
            {
                mostrarTodoProp(prop,tp);
                auxIdProp = ingresoStringNumerico("ID de propietario del auto");
                indexProp = buscarID(prop,tp,auxIdProp);
                printf("El auto se registrara a nombre de %s\n",prop[indexProp].nombreYapellido);
                printf("De que marca es el automovil?\n");
                printf("1- Alpha Romeo\n");
                printf("2- Ferrari\n");
                printf("3- Audi\n");
                printf("4- Otros\n");
                auxMarca = validarDatoMaxMin(ingresoStringNumerico("la marca del auto"),"la marca del auto",1,4);

                while((!getStringAlfaNumerico("Ingrese la patente: ",patente)) || (strlen(patente)!=3))
                {
                    printf("La patente solo puede tener letras, numeros, y un maximo de tres caracteres. Intente nuevamente.\n\n");
                }
                indexPatenteDuplicada = buscarPatente(autos,ta,patente);
                if( indexPatenteDuplicada != VACIO )
                {
                    printf("Ya se ha registrado un automovil con esa patente. Reingresar otra? s/n: ");
                    fflush(stdin);
                    respuesta = getche();
                    if((respuesta!='s')&&(respuesta!='S'))
                    {
                        flag = 1;
                        break;
                    }
                    printf("\n");
                }
                else
                {
                    break;
                }
            }
            while((respuesta=='s')||(respuesta=='S'));
            if(!flag)
            {
                printf("Confirmar ingreso? s/n: ");
                fflush(stdin);
                respuesta = getche();
                if((respuesta=='s')||(respuesta=='S'))
                {
                    strupr(patente);
                    strcpy(autos[indexLibre].patente,patente);
                    autos[indexLibre].estado = 1;
                    autos[indexLibre].idProp = auxIdProp;
                    autos[indexLibre].idAuto = idIncremental(prop, tp);
                    autos[indexLibre].marca = auxMarca;
                    printf("\nIngreso realizado correctamente, desea realizar otro? s/n: ");
                    fflush(stdin);
                    respuesta = getche();
                    if((respuesta!='s')&&(respuesta!='S'))
                    {
                        break;
                    }
                }
                else
                {
                    printf("\nIngreso cancelado, desea realizar otro? s/n: ");
                    fflush(stdin);
                    respuesta = getche();
                    if((respuesta!='s')&&(respuesta!='S'))
                    {
                        break;
                    }
                }
            }
            else
            {
                printf("\nPatente no registrada, ingreso cancelado.\n\nDesea realizar otro? s/n: ");
                fflush(stdin);
                respuesta = getche();
                if((respuesta!='s')&&(respuesta!='S'))
                {
                    break;
                }
            }
        }
        system("cls");
    }
    while((respuesta=='s')||(respuesta=='S'));
}

void egresoAuto(EAuto autos[],int ta,EPropietario prop[],int tp,egresosEst autosOut[],int te)
{
    int indexA, indexP, auxIdProp, marca, horas;
    char auxNombre[50], auxPatente[5], respuesta = 'x';
    float estadia=0;
    do
    {
        mostrarTodoAutos(autos,ta,prop,tp);
        while((!getStringAlfaNumerico("Ingrese la patente del automovil a egresar: ",auxPatente)) || (strlen(auxPatente)!=3))
        {
            printf("La patente solo puede ser alfanumerica y tener un maximo de tres caracteres.\n Intente nuevamente.\n");
        }
        indexA = buscarPatente(autos,ta,auxPatente);

        if(indexA!=VACIO)
        {
            auxIdProp = autos[indexA].idProp;
            indexP = buscarID(prop,tp,auxIdProp);
            ///copiamos datos a auxiliares
            marca = autos[indexA].marca;
            horas = horasEstadia();
            strcpy(auxNombre,prop[indexP].nombreYapellido);
            strcpy(auxPatente,autos[indexA].patente);
            estadia=valorEstadia(marca,horas);

            printf("Datos del coche: %s\t%s\t$%.2f\t\n", prop[indexP].nombreYapellido, autos[indexA].patente,estadia);
            printf("Confirmar egreso? s/n: ");
            fflush(stdin);
            respuesta = getche();
            if((respuesta=='s')||(respuesta=='S'))
            {
                transferDatosEgreso(autosOut,te,auxPatente,auxNombre,marca,estadia,horas);
                system("cls");
                autos[indexA].estado = VACIO;
                printf("\nPropietario:\t %s\n",prop[indexP].nombreYapellido);
                printf("Patente:\t %s\n", autos[indexA].patente);
                printf("Marca:\t\t ");
                imprimirMarca(marca);
//                        importesTot[0].egresosTotales = importesTot[0].egresosTotales+estadia;
                printf("\nValor estadia:\t %dhs\t$%.2f\n",horas,estadia);
                printf("Gracias por elegirnos!\n\n");

                printf("Egreso exitoso, desea realizar otro? s/n: ");
                fflush(stdin);
                respuesta = getche();
                if((respuesta!='s')&&(respuesta!='S'))
                {
                    break;
                }
            }
            else
            {
                printf("\nEgreso cancelado, desea realizar otro? s/n: ");
                fflush(stdin);
                respuesta = getche();
                if((respuesta!='s')&&(respuesta!='S'))
                {
                    break;
                }
            }

        }
        else
        {
            printf("\nPatente no registrada, reintentar? s/n: ");
            fflush(stdin);
            respuesta = getche();
            if((respuesta!='s')&&(respuesta!='S'))
            {
                break;
            }
        }
        system("cls");

    }
    while((respuesta=='s')||(respuesta=='S'));
    printf("\n");
    system("pause");
}


void bajaProp(EPropietario prop[],int tp, EAuto autos[], int ta, egresosEst autosOut[], int te)
{

    int i, indexP, auxIdProp, marca, horas;
    char auxNombre[50], auxPatente[5], respuesta = 'x';
    float estadia=0, estadiaAcumulada=0;
    do
    {
        mostrarTodoProp(prop,tp);
        auxIdProp = ingresoStringNumerico("ID de propietario a realizar BAJA");
        indexP = (buscarID(prop,tp,auxIdProp));
        if(indexP!=VACIO)
        {

            for(i=0; i<ta; i++)
            {
                if(auxIdProp==autos[i].idProp && autos[i].estado != VACIO)
                {
                    marca = autos[i].marca;
                    horas = horasEstadia();
                    estadia=valorEstadia(marca,horas);
                    estadiaAcumulada=estadiaAcumulada+estadia;
                }
            }
            printf("\n%s IMPORTE A PAGAR: $%.2f",prop[indexP].nombreYapellido, estadiaAcumulada);
            printf("\n\nConfirmar baja? s/n: ");
            fflush(stdin);
            respuesta = getche();
            if((respuesta!='s')&&(respuesta!='S'))
            {
                break;
            }
            else
            {
                prop[indexP].estado=VACIO;
                system("cls");
                for(i=0; i<ta; i++)
                {
                    if(auxIdProp==autos[i].idProp && autos[i].estado != VACIO)
                    {
                        autos[i].estado = VACIO;
                        marca = autos[i].marca;
                        horas = horasEstadia();
                        estadia=valorEstadia(marca,horas);
                        strcpy(auxNombre,prop[indexP].nombreYapellido);
                        strcpy(auxPatente,autos[i].patente);
                        transferDatosEgreso(autosOut,te,auxPatente,auxNombre,marca,estadia,horas);
                        //printf("Importe por baja de automovil patente %s: $%.2f\n",auxPatente,estadia);

                    }
                }
                printf("%s, usted pago: $%.2f, fueron debitados de su tarjeta %s",prop[indexP].nombreYapellido, estadiaAcumulada, prop[indexP].tarjetaDeCredito);
                printf("\nGracias por elegirnos!");
                printf("\n\nBaja de propietario exitosa.\nDesea realizar otra? s/n: ");
                fflush(stdin);
                respuesta = getche();
                if((respuesta!='s')&&(respuesta!='S'))
                {
                    break;
                }
            }
        }
        else
        {
            printf("\nID Incorrecto, intentar nuevamente? s/n: ");
            fflush(stdin);
            respuesta = getche();
            if((respuesta!='s')&&(respuesta!='S'))
            {
                break;
            }
        }
        system("cls");
    }
    while((respuesta=='s')||(respuesta=='S'));
    printf("\n");
    system("pause");
}


void mostrarTodoAutos(EAuto autos[], int ta, EPropietario prop[], int tp)
{
    int i, marca, auxId, index;
    printf("PATENTE\tPROPIETARIO\t\tMARCA\n");
    for(i=0; i<ta; i++)
    {

        if(autos[i].estado != VACIO)
        {
            marca=autos[i].marca;
            auxId=autos[i].idProp;
            index = buscarID(prop,tp,auxId);
            if(prop[index].estado!=VACIO)
            {
                printf("%s\t%s\t\t", autos[i].patente, prop[index].nombreYapellido);
                switch(marca)
                {
                case ALPHA_ROMEO:
                    printf("ALPHA ROMEO\n");
                    break;
                case FERRARI:
                    printf("FERRARI\n");
                    break;
                case AUDI:
                    printf("AUDI\n");
                    break;
                case OTROS:
                    printf("OTROS\n");
                    break;
                }
            }
        }
    }

}

void mostrarPropietarioConAutos(EPropietario prop[],int tp, EAuto autos[],int ta)
{
    int i,auxIdProp, indexP;
    char respuesta = 'x';
    do
    {
        mostrarTodoProp(prop,tp);
        auxIdProp = ingresoStringNumerico("ID de propietario");
        indexP = buscarID(prop,tp,auxIdProp);
        if(indexP != VACIO)
        {
            printf("**%s**\nPatente\tMarca\n",prop[indexP].nombreYapellido);
            printf("---------------------\n");
            for(i=0; i<ta; i++)
            {
                if((autos[i].idProp == auxIdProp) && (autos[i].estado != VACIO))
                {
                    printf("%s\t",autos[i].patente);
                    switch(autos[i].marca)
                    {
                    case ALPHA_ROMEO:
                        printf("ALPHA ROMEO\n");
                        break;
                    case FERRARI:
                        printf("FERRARI\n");
                        break;
                    case AUDI:
                        printf("AUDI\n");
                        break;
                    case OTROS:
                        printf("OTROS\n");
                        break;
                    }

                }
            }
            printf("\nDesea ver la lista de otro propietario? s/n: ");
            fflush(stdin);
            respuesta = getche();
            if(respuesta != 's')
            {
                break;
            }
        }
        else
        {
            printf("ID no encontrado. Reintentar? s/n: ");
            fflush(stdin);
            respuesta = getche();
            if(respuesta != 's')
            {
                break;
            }
        }
        system("cls");
    }
    while((respuesta=='s')||(respuesta=='S'));
}
void mostrarPropAudi (EPropietario prop[], int tp, EAuto autos[], int ta)
{
    int i, j;
    for(i=0; i<tp; i++)
    {
        for(j=0; j<ta; j++)
        {
            if((prop[i].idPropietario == autos[j].idProp ) && (prop[i].estado != VACIO ) && (autos[j].estado != VACIO) && (autos[j].marca == AUDI))
            {
                printf("%d\t%s\t\t%s\t\t%s\n", prop[i].idPropietario,prop[i].nombreYapellido,prop[i].tarjetaDeCredito,prop[i].direccion);
                break;
            }
        }
    }
}

void mostrarPorPatente(EPropietario prop[],EAuto autos[], int ta, int tp)
{
    ordenarPatente(autos,ta);
    int index, i;
    system("cls");

    printf("Se ha reordenado la lista por orden alfabetico de patente.\n");
    printf("Patente\tMarca\t\tPropietario\n");
    for(i=0; i<ta; i++)
    {
        if(autos[i].estado!=VACIO)
        {
            printf("%s\t",autos[i].patente);
            imprimirMarca(autos[i].marca);
            index = buscarID(prop,tp,autos[i].idProp);
            printf("\t%s\t\n",prop[index].nombreYapellido);
        }
    }
}


void recaudacionTotal(egresosEst autosOut[], int te)
{

    float totalEstacionamiento=0;
    int i;
    for(i=0; i<te; i++)
    {
        if(autosOut[i].estado == VACIO)
        {
            break;
        }
        totalEstacionamiento = totalEstacionamiento + autosOut[i].importe;
        /*printf("%s\t\t%s\t",autosOut[i].nombreYApellido,autosOut[i].patente);
        imprimirMarca(autosOut[i].marca);
        printf("\t%d\t%.2f\n",autosOut[i].tiempo,autosOut[i].importe);*/
    }
    printf("La recaudacion total actual del estacionamiento es de $%.2f",totalEstacionamiento);
    printf("\n");
}
void recaudacionPorMarca (egresosEst autosOut[],int te)
{
    float totalAlpha=0, totalFerrari=0, totalAudi=0, totalOtros=0;
    int i;
    for(i=0; i<te; i++)
    {
        if(autosOut[i].estado != VACIO)
        {
            switch(autosOut[i].marca)
            {
            case ALPHA_ROMEO:
                totalAlpha = totalAlpha + autosOut[i].importe;
                break;
            case FERRARI:
                totalFerrari = totalFerrari + autosOut[i].importe;
                break;
            case AUDI:
                totalAudi = totalAudi + autosOut[i].importe;
                break;
            case OTROS:
                totalOtros = totalOtros + autosOut[i].importe;
                break;
            }
        }
    }
    printf("Recaudacion total por marca: \n\n");
    printf("ALPHA ROMEO:\t %.2f\n",totalAlpha);
    printf("FERRARI:\t %.2f\n",totalFerrari);
    printf("AUDI:\t\t %.2f\n",totalAudi);
    printf("OTROS:\t\t %.2f\n",totalOtros);
    system("pause");
}

///templates para el parcial
void recaudacionMarcaEquis (egresosEst autosOut[],int te)
{
    float total=0,xxx;
    int i;
    for(i=0; i<te; i++)
    {
        if(autosOut[i].estado != VACIO && autosOut[i].marca == xxx)
        {

                total = total + autosOut[i].importe;

        }
    }
    printf("Recaudacion total por xxx: $%.2f\n\n",total);
    system("pause");
}



void ordenarPatente(EAuto autos[],int valor)
{
    int i, j;
    EAuto auxAuto;
    for(i=0; i < valor-1; i++)
    {
        if(autos[i].estado == VACIO)
        {
            continue;
        }
        for(j=i+1; j < valor; j++)
        {
            if(autos[j].estado == -1)
            {
                continue;
            }
            if(stricmp(autos[i].patente,autos[j].patente) > 0)
            {
                auxAuto = autos[j];
                autos[j] = autos[i];
                autos[i] = auxAuto;
                //
            }
        }
    }

}
int valorEstadia(int marca, int horas)
{
    int horaPorMarca, valorEstadia;
    switch(marca)
    {
    case ALPHA_ROMEO:
        horaPorMarca = 150;
        break;
    case FERRARI:
        horaPorMarca = 175;
        break;
    case AUDI:
        horaPorMarca = 200;
        break;
    case OTROS:
        horaPorMarca = 250;
        break;
    }
    valorEstadia = (horas * horaPorMarca);
    return valorEstadia;
}
int horasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}







void transferDatosEgreso (egresosEst autosOut[],int te, char patente[], char nombre[],int marca, float importe, int horas)
{
    int indexE;
    indexE = buscarIndexEgreso(autosOut,te,VACIO);
    strcpy(autosOut[indexE].nombreYApellido,nombre);
    strcpy(autosOut[indexE].patente,patente);
    autosOut[indexE].marca = marca;
    autosOut[indexE].importe = importe;
    autosOut[indexE].tiempo = horas;
    autosOut[indexE].estado = 1;
}









void egresosHC (egresosEst autosOut[])
{
    char patente[][20]= {"ALL","THE","SMA","LLT","HIN","GSA","HLL","EFG","FGA"};
    char nombreYapellido[][256]= {"Alfredo Lopez","Ana Rodriguez","Ricardo Sul", "Tefi Luzio", "Paula Ruhl", "Ruben Lamas","Sabrina Pardo","Jay Garrick","Barry Allen"};
    int marca[]= {1,3,3,1,2,3,3,4,3};
    int tiempo[]= {5,3,12,16,14,4,9,1,11};
    int i;
    for(i=0; i<9; i++)
    {
        strcpy(autosOut[i].patente,patente[i]);
        strcpy(autosOut[i].nombreYApellido,nombreYapellido[i]);

        autosOut[i].marca=marca[i];
        autosOut[i].tiempo=tiempo[i];
        autosOut[i].estado=1;
        autosOut[i].importe = valorEstadia(marca[i],tiempo[i]);


    }
}
void autosHC(EAuto autos[])
{

    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    int i;

    for(i=0; i<10; i++)
    {
        autos[i].idAuto=id[i];
        strcpy(autos[i].patente,patente[i]);
        autos[i].marca=marca[i];
        autos[i].idProp=propietario[i];
        autos[i].estado = 1;
    }
}
void initAutos(EAuto autos[],int tamanho,int estadoInicial)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        autos[i].estado = estadoInicial;
        autos[i].idAuto = estadoInicial;
        autos[i].idProp = estadoInicial;
    }

}
void initEgresos(egresosEst autosOut[],int tamanho, int valor)
{
    int i;
    for(i=0; i<tamanho; i++)
    {
        autosOut[i].estado = valor;
    }
}
void imprimirMarca (int marca)
{
    switch(marca)
    {
    case 1:
        printf("ALPHA ROMEO");
        break;
    case 2:
        printf("FERRARI\t");
        break;
    case 3:
        printf("AUDI\t");
        break;
    case 4:
        printf("OTROS\t");
        break;
    }
}






