#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"

#define ERROR -1




int generic_menu (void)
{
    int opcion;

    fflush(stdin);
    printf("Sitio principal\n");
    printf("1. 111\n");
    printf("2. 222\n");
    printf("3. 333\n");
    //printf("4. 444\n");
    //printf("5. 555\n");
    //printf("6. 666\n");
    //printf("7. 777\n");
    //printf("8. 888\n");
    //printf("9. 999\n");
    printf("\n0. Salir\n");

    opcion = entero_get("opcion");

    return opcion;
}

void generic_finFuncion (void)
{
    printf("\n");
    system("pause");
    system("cls");
}

int generic_confirmar(void)
{
    char respuesta;
    int flag = 0;
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

///enteros
int entero_get(char mensaje[])
{
    char auxDato[20];
    int dato;
    printf("\nIngrese %s:",mensaje);
    while(!string_getNumerico(" ",auxDato))
    {
        printf("Error, *%s* solo puede estar compuesto por numeros. Reingrese %s:",mensaje,mensaje);
    }
    dato = atoi(auxDato);

    return dato;
}

int entero_validaRango(int dato, char mensaje[], int min, int max)
{
    if(dato >= min && dato <= max)
        return 1;
    else
    {
        printf("El item *%s* debe estar entre %d y %d.\n",mensaje,min,max);
        return 0;
    }
}


///funciones para implementacion de arraylist
eGen* gen_nuevaEstructura()
{
    eGen* aux;

    aux=(eGen*)malloc(sizeof(eGen));

    return aux;
}


void gen_setString(eGen* g)
{
    char aux[10];
    if(g!=NULL)
    {
        //do{
        while(!string_getLetras("\nIngrese xxx: ",aux))
        {
            printf("Error, xxx solo puede ser letras.");
        }
        //}while(!string_validaRango(dni,1000,9999));
        strcpy(g->stringUno,aux);
    }
}
void gen_setEntero(eGen* g)
{
    if(g!=NULL)
    {
        g->enteroUno=entero_get("xxx");
    }
}


int gen_getEntero(eGen* g)
{
    int entero;
    if(g!=NULL)
    {
        entero=g->enteroUno;
    }
    return entero;
}
char* gen_getString (eGen* g)
{
    char* str=NULL;
    if(g!=NULL)
    {
        str=g->stringUno;
    }
    return str;
}

void gen_mostrarUno (eGen* g)
{
    if(g!=NULL)
    {
        printf("\nENTERO\t| STRING\t| xxx");
        printf("\n%d\t| %s\t| xxx",gen_getEntero(g),gen_getString(g));
    }
}
void gen_mostrarLista(ArrayList* lista)
{
    int i, len;
    eGen* g;
    if(lista!=NULL)
    {
        len=lista->len(lista);
        printf("\nENTERO\t| STRING");
        for(i=0; i<len; i++)
        {
            g=lista->get(lista,i);
            printf("\n%d\t| %s",gen_getEntero(g),gen_getString(g));
        }
    }
}

void gen_pasarAOtraLista(ArrayList* listaA, ArrayList* listaB)
{
    eGen* g=gen_nuevaEstructura();
    if(listaA!=NULL && listaB!=NULL)
    {
        g=listaA->pop(listaA,0); ///pasa el primero
        listaB->add(listaB,g);
        ///gen_mostrarUno(g);  muestra lo q poppeó
    }
}


int gen_compararItem(void* itemA, void* itemB)
{
    eGen* item1;
    eGen* item2;

    item1=(eGen*)itemA;
    item2=(eGen*)itemB;

    return strcmp(item1->stringUno,item2->stringUno);
}
