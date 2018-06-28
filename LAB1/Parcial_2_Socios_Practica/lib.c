#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"

#define INACTIVO 0
#define ACTIVO 1

int modificar_menu (void)
{
    int opcion;

    fflush(stdin);
    printf("\nQue item desea modificar?\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. DNI\n");
    printf("\n0. Volver atras\n");

    opcion = entero_get("opcion");

    return opcion;
}
void main_alta(ArrayList* lista, int* id)
{
    eSoc* s;
    system("cls");


    printf("\n**ALTA SOCIO**");
    s=socio_newStruct();
    alta_newName(s);
    alta_newSurname(s);
    alta_newDni(s);
    alta_newId(s,id);
    alta_newState(s,1);

    printf("\nDar de alta socio? s/n: ");
    if(generic_confirmar())
    {
        lista->add(lista,s);
        main_archivar(lista);
    }
    generic_finFuncion();
}

void main_modificar(ArrayList* lista)
{
    eSoc* s;
    int id=-1, i=0, volver=0;
    int opcion;
    printf("\n**MODIFICACION SOCIO**");
    id=entero_get("id de socio");
    for(i=0; i<lista->len(lista); i++)
    {
        s=lista->get(lista,i);
        if(id==s->idSocio)
        {
            break;
        }
    }
    do
    {
        system("cls");

        socio_mostrarUno(s);
        opcion=modificar_menu();
        switch(opcion)
        {
        case 1:
            alta_newName(s);
            printf("\nConfirmar cambios? s/n: ");
            if(generic_confirmar())
            {
                main_archivar(lista);
            }
            break;
        case 2:
            alta_newSurname(s);
            printf("\nConfirmar cambios? s/n: ");
            if(generic_confirmar())
            {
                main_archivar(lista);
            }
            break;
        case 3:
            alta_newDni(s);
            printf("\nConfirmar cambios? s/n: ");
            if(generic_confirmar())
            {
                main_archivar(lista);
            }
            break;
        case 0:
            volver=1;
            break;
        default:
            printf("\nOpcion incorrecta. Ingrese otra...");
            break;
        }
    }
    while(!volver);
    system("cls");
}

void main_baja(ArrayList* lista)
{
    eSoc* s;
    int id=-1, i=0;
    printf("\n**BAJA SOCIO**");
    id=entero_get("id de socio");
    for(i=0; i<lista->len(lista); i++)
    {
        s=lista->get(lista,i);
        if(id==s->idSocio)
        {
            break;
        }
    }
    system("cls");

    socio_mostrarUno(s);

    printf("\nDar de baja socio? s/n: ");
    if(generic_confirmar())
    {
        s->estado=0;
        main_archivar(lista);
    }
}

void socio_setName(eSoc* s, char* name)
{
    if(s!=NULL)
    {
        strcpy(s->name,name);
    }
}
void socio_setSurname(eSoc* s, char* surname)
{
    if(s!=NULL)
    {
        strcpy(s->surname,surname);
    }
}
void socio_setDni(eSoc* s, char* dni)
{
    if(s!=NULL)
    {
        strcpy(s->dni,dni);
    }
}




void alta_newName(eSoc* s)
{
    char aux[40];
    if(s!=NULL)
    {
        while(!string_getLetras("\nIngrese el nombre: ",aux))
        {
            printf("Error, el nombre solo puede ser letras.");
        }
        strlwr(aux);
        *(aux+0)=toupper(*aux+0);
        strcpy(s->name,aux);
    }
}
void alta_newSurname(eSoc* s)
{
    char aux[40];
    if(s!=NULL)
    {
        while(!string_getLetras("\nIngrese apellido: ",aux))
        {
            printf("Error, el apellido solo puede ser letras.");
        }
        strlwr(aux);
        *(aux+0)=toupper(*aux+0);
        strcpy(s->surname,aux);
    }
}
void alta_newDni(eSoc* s)
{
    char aux[9];
    if(s!=NULL)
    {
        do
        {
            while(!string_getNumerico("\nIngrese DNI: ",aux))
            {
                printf("Error, el DNI solo puede ser numeros.");
            }
        }
        while(!string_validaRango(aux,1000,9999));
        strcpy(s->dni,aux);
    }
}
void alta_newState(eSoc* s,int st)
{
    if(s!=NULL)
    {
        s->estado=st;
    }
}
void alta_newId(eSoc* s,int* id)
{
    if(s!=NULL)
    {
        s->idSocio=*id;
    }
}


eSoc* socio_newStruct()
{
    eSoc* aux;

    aux=(eSoc*)malloc(sizeof(eSoc));

    return aux;
}



void main_archivar(ArrayList* lista)
{
    eSoc* s;
    FILE* fp;
    int i;
    char fileName[50]="socios.csv";
    if(lista!=NULL)
    {
        fp=fopen(fileName,"w");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                s=(eSoc*) lista->get(lista,i);
                fprintf(fp,"%d,%d,%s,%s,%s\n",socio_getId(s),socio_getState(s),socio_getName(s),socio_getSurname(s),socio_getDni(s));
            }
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo generar un archivo.");
    }
}

///genericas
int generic_menu (void)
{
    int opcion;

    fflush(stdin);
    printf("Sitio principal\n");
    printf("1. Alta\n");
    printf("2. Baja\n");
    printf("3. Modificacion\n");
    printf("4. Listar\n");
    //printf("5. 555\n");
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
        printf("\nAccion cancelada.");
    return 0;
}






int socio_getId(eSoc* s)
{
    int id;
    if(s!=NULL)
    {
        id=s->idSocio;
    }
    return id;
}
int socio_getState(eSoc* s)
{
    int st;
    if(s!=NULL)
    {
        st=s->estado;
    }
    return st;
}
char* socio_getDni (eSoc* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->dni;
    }
    return str;
}
char* socio_getSurname (eSoc* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->surname;
    }
    return str;
}
char* socio_getName (eSoc* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->name;
    }
    return str;
}

///validar strings






int main_cargarAnteriores(ArrayList* l)
{
    FILE* fp;
    eSoc* s;
    int id=0;
    int estado;
    char name[40];
    char surname[40];
    char dni[9];
    fp = fopen("socios.csv","r");
    if(fp!=NULL)
    {
        do
        {
            s=socio_newStruct();
            fscanf(fp,"%d,%d,%[^,],%[^,],%[^\n]\n",&id,&estado,name,surname,dni);
            s->idSocio=id;
            s->estado=estado;
            socio_setName(s,name);
            socio_setSurname(s,surname);
            socio_setDni(s,dni);
            l->add(l,s);
        }
        while(!feof(fp));
        printf("**");
    }
    else
    {
        printf("+");
    }
    return id;
}


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





void socio_mostrarUno (eSoc* s)
{
    if(s!=NULL)
    {
        printf("\nID\t| DNI\t| Nombre\t| Apellido");
        printf("\n%d\t| %s\t| %s\t| %s",s->idSocio,socio_getDni(s),socio_getName(s),socio_getSurname(s));
    }
}




void main_mostrarLista(ArrayList* lista)
{
    int i, len;
    eSoc* g;
    if(lista!=NULL)
    {
        len=lista->len(lista);
        printf("\nID\t| DNI\t| Nombre\t| Apellido");
        for(i=0; i<len; i++)
        {
            g=lista->get(lista,i);
            if(g->estado!=0)
            {
            printf("\n%d\t| %s\t| %s\t| %s",g->idSocio,socio_getDni(g),socio_getName(g),socio_getSurname(g));
            }
        }
    }
}

///funciones para implementacion de arraylist
/*






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



*/
