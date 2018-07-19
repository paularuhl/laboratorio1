#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"

void main_cargarLista(char msg[], char fn[], ArrayList* lista)
{
    char* fileName=gen_newString();
    if(fileName!=NULL && lista!=NULL)
    {
        printf("Ingrese nombre de archivo de la lista %s",msg);
        string_get(": ",fileName);
        strlwr(fileName);
        if(strcmp(fileName,fn)==0)
        {
            dest_parseData(fn,lista);
            printf("Lista %s cargada correctamente.",msg);
        }
        else
        {
            printf("Error, ese archivo no existe...");
        }
    }
    generic_finFuncion();
}


void main_depurar(ArrayList* listaA, ArrayList* listaB, ArrayList* depurados)
{
    filtroBlacklist(listaA,listaB,depurados);
    filtroRepetidos(depurados);
    dest_archivarDepurados(depurados);
    generic_finFuncion();
}


void filtroBlacklist(ArrayList* listaA, ArrayList* listaB, ArrayList* depurados)
{
    int i,j;
    int flag, found=0;
    eDestinatario* a;
    eDestinatario* b;
    for(i=0;i<(listaA->len(listaA));i++)
    {
        a=listaA->get(listaA,i);
        flag=0;
        for(j=0;j<(listaB->len(listaB));j++)
        {
            b=listaB->get(listaB,j);
            if(dest_compararMail(a,b)==0)
            {
                flag=1;
                found++;
                break;
            }
        }
        if(flag==0)
        {
            depurados->add(depurados,a);
        }
    }
    if(found!=0)
    {
    printf("\nSe eliminaron %d destinatarios a traves de la lista negra.",found);
    }else{
    printf("\nNo se encontraron destinatarios a traves de la lista negra.");
    }
}

void filtroRepetidos(ArrayList* depurados)
{
    int i,j,found=0;
    eDestinatario* a;
    eDestinatario* b;
    for(i=0;i<(depurados->len(depurados)-1);i++)
    {
        a=depurados->get(depurados,i);
        for(j=i+1;j<depurados->len(depurados);j++)
        {
            b=depurados->get(depurados,j);
            if(dest_compararMail(a,b)==0)
            {
                depurados->remove(depurados,j);
                found++;
            }
        }
    }
    if(found!=0)
    {
    printf("\nSe encontraron y eliminaron %d destinatarios repetidos.",found);
    }else{
    printf("\nNo se encontraron destinatarios repetidos.");
    }
}

void dest_mostrarLista(ArrayList* lista)
{
    int i, len;
    eDestinatario* d;
    if(lista!=NULL)
    {

        len=lista->len(lista);
        if(len!=0)
        {
        printf("\nNOMBRE\t\t| MAIL");
        for(i=0; i<len; i++)
        {
            d=lista->get(lista,i);
            printf("\n%s\t\t| %s",dest_getName(d),dest_getMail(d));
        }
        }else{
            printf("No hay datos para mostrar...");
        }
    }

    generic_finFuncion();
}

void dest_archivarDepurados(ArrayList* lista)
{
    eDestinatario* d;
    FILE* fp;
    int i;
    char fileName[50]="depurado.csv";
    if(lista!=NULL)
    {
        fp=fopen(fileName,"w");
        if(fp!=NULL)
        {
            for(i=0;i<lista->len(lista);i++)
            {
                    d=(eDestinatario*) lista->get(lista,i);
                    fprintf(fp,"%s,%s\n",dest_getName(d),dest_getMail(d));
            }
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo generar un archivo.");
    }
}

void dest_parseData(char* fn, ArrayList* l)
{
    FILE* fp;
    eDestinatario* d;
    char name[30];
    char mail[50];
    fp = fopen(fn,"r");
    if(fp!=NULL)
    {
        do
        {
            d=gen_newStruct();
            fscanf(fp,"%[^,],%[^\n]\n",name,mail);
            dest_setName(d,name);
            dest_setMail(d,mail);
            l->add(l,d);
        }
        while(!feof(fp));
    }
    fclose(fp);
}
char* dest_getName (eDestinatario* d)
{
    char* str=NULL;
    if(d!=NULL)
    {
        str=d->name;
    }
    return str;
}
char* dest_getMail (eDestinatario* d)
{
    char* str=NULL;
    if(d!=NULL)
    {
        str=d->mail;
    }
    return str;
}

///generics
int generic_menu (void)
{
    int opcion;

    fflush(stdin);
    printf("Sitio principal\n");
    printf("1. Cargar destinatarios\n");
    printf("2. Cargar lista negra\n");
    printf("3. Depurar lista negra y repetidos\n");
    printf("4. Listar destinatarios finales\n");
    //printf("5. test\n");
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


///funciones particulares del programa
eDestinatario* gen_newStruct()
{
    eDestinatario* aux=(eDestinatario*)malloc(sizeof(eDestinatario));

    return aux;
}
char* gen_newString()
{
    char* aux=(char*)malloc(sizeof(char)*50);
    return aux;
}
void dest_setName(eDestinatario* d, char* aux)
{
    if(d!=NULL)
    {
        strcpy(d->name,aux);
    }
}
void dest_setMail(eDestinatario* d, char* aux)
{
    if(d!=NULL)
    {
        strcpy(d->mail,aux);
    }
}
int dest_compararMail(void* itemA, void* itemB)
{
    eDestinatario* item1;
    eDestinatario* item2;

    item1=(eDestinatario*)itemA;
    item2=(eDestinatario*)itemB;

    return strcmp(item1->mail,item2->mail);
}

