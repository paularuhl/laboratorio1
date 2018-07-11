#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "parser.h"

void main_parseIn(int* id,ArrayList* database)
{
    if((*id=parseIn(database,"datos1.csv",id)!=-1)&&(*id=parseIn(database,"datos2.csv",id)!=-1))
    {
        printf("\nDatos cargados satisfactoriamente. Exportar lista nueva? s/n: ");
        if(generic_confirmar())
        {
            if(-1!=parseOut(database,"database.csv"))
            {
                printf("\nLista exportada correctamente!\n");
            }
        }
    }
    generic_finFuncion();
}


void main_depurar(ArrayList* listaA, ArrayList* listaB, ArrayList* depurados)
{
//    filtroBlacklist(listaA,listaB,depurados);
//   filtroRepetidos(depurados);

    generic_finFuncion();
}


void filtroRepetidos(ArrayList* depurados)
{
    /*int i,j,found=0;
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
    }*/
}




soc* soc_newStruct()
{
    soc* aux;

    aux=(soc*)malloc(sizeof(soc));

    return aux;
}

/*************************************************************/
///NEW SETTERS -- ALTA O MODIFICACION -- piden por pantalla///
/***********************************************************/
void soc_newName(soc* s)
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

void soc_newLastname(soc* s)
{
    char aux[40];
    if(s!=NULL)
    {
        while(!string_getLetras("\nIngrese el apellido: ",aux))
        {
            printf("Error, el apellido solo puede ser letras.");
        }
        strlwr(aux);
        *(aux+0)=toupper(*aux+0);
        strcpy(s->lastname,aux);
    }
}

void soc_newEdad(soc* s)
{
    int aux;
    if(s!=NULL)
    {
        do
        {
            aux=entero_get("edad");
        }
        while(!entero_validaRango(aux,"edad",18,99));
        //s->edad=aux;
    }

}


/**************/
/// SETTERS ///
/************/
void soc_setId(soc* s,int* id)
{
    if(s!=NULL)
    {
        s->idSocio=*id;
    }
}

void soc_setState(soc* s,int st)
{
    if(s!=NULL)
    {
        s->estado=st;
    }
}

void soc_setName(soc* s, char* name)
{
    if(s!=NULL)
    {
        strcpy(s->name,name);
    }
}


void soc_setLastname(soc* s, char* aux)
{
    if(s!=NULL)
    {
        strcpy(s->lastname,aux);
    }
}

void soc_setMail(soc* s, char* aux)
{
    if(s!=NULL)
    {
        strcpy(s->mail,aux);
    }
}







///genericas
int vista_menu (void)
{
    fflush(stdin);
    printf("Sitio principal\n");
    printf("1. Cargar bases de datos\n");
    printf("2. Eliminar nombres con A y nombres con E\n");
    printf("3. Listar\n");

    printf("\n0. Salir\n");

    int opcion = entero_get("opcion");

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

void generic_alta(ArrayList* lista, int* id)
{
    soc* s;
    system("cls");

    printf("\n**ALTA SOCIO**");
    s=soc_newStruct();
    soc_newName(s);
    soc_newLastname(s);
    soc_setId(s,id);
    soc_setState(s,1);

    printf("\nDar de alta socio? s/n: ");
    if(generic_confirmar())
    {
        lista->add(lista,s);
        parseOut(lista,"socios.csv");
    }
    generic_finFuncion();
}





/**************/
/// GETTERS ///
/************/
int soc_getId(soc* s)
{
    int id;
    if(s!=NULL)
    {
        id=s->idSocio;
    }
    return id;
}

int soc_getState(soc* s)
{
    int st;
    if(s!=NULL)
    {
        st=s->estado;
    }
    return st;
}

char* soc_getMail(soc* s)
{
    char* str;
    if(s!=NULL)
    {
        str=s->mail;
    }
    return str;
}

char* soc_getLastname(soc* s)
{
    char* str;
    if(s!=NULL)
    {
        str=s->lastname;
    }
    return str;
}

char* soc_getName (soc* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->name;
    }
    return str;
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





void soc_mostrarUno (soc* s)
{
    if(s!=NULL)
    {
        printf("\nID\t| DNI\t| Nombre\t| Apellido");
        printf("\n%d\t| %s\t| %s\t| %s",soc_getId(s),soc_getName(s),soc_getLastname(s),soc_getMail(s));
    }
}

void main_mostrarLista(ArrayList* lista)
{
    int i, len;
    soc* g;
    if(lista!=NULL)
    {
        len=lista->len(lista);
        printf("\nID\t| Nombre\t| Apellido\t| Mail\n");
        for(i=0; i<len; i++)
        {
            g=lista->get(lista,i);

            printf("\n%d\t| %s\t| %s\t| %s",soc_getId(g),soc_getName(g),soc_getLastname(g),soc_getMail(g));
        }
        printf("\n");
    }
}


///otras
int funcionQueFiltra(void* socio)
{
    int i,r=1;
    soc* e;
    e = (soc*)socio;
    char nombre[50];
    char apellido[50];
    if(socio!=NULL)
    {
        strcpy(nombre,soc_getName(e));
        strlwr(nombre);
        for(i=0; nombre[i] !='\0'; i++)
        {
            if(nombre[i]=='i'||nombre[i]=='a'||nombre[i]=='e')
            {
                r=0;
                break;
            }
        }
        strcpy(apellido,soc_getLastname(e));
        strlwr(apellido);
        for(i=0; apellido[i] !='\0'; i++)
        {

            if(apellido[i]=='o'||apellido[i]=='u')
            {
                r=0;
                break;
            }
        }

    }
    return r;
}


///funciones que no use aca
/*
void main_modificar(ArrayList* lista)
{

    soc* s;
    soc* aux;
    int id=-1, i=0, volver=0;
    int opcion;
    printf("\n**MODIFICACION SOCIO**");
    id=entero_get("id de socio");
    for(i=0; i<lista->len(lista); i++)
    {
        s=lista->get(lista,i);
        if(id==s->idSocio)
        {
            aux=s;
            break;
        }
    }
    do
    {
        system("cls");

        soc_mostrarUno(s);
        opcion=modificar_menu();
        switch(opcion)
        {
        case 1:
            alta_newName(aux);
            printf("\nConfirmar cambios? s/n: ");
            if(generic_confirmar())
            {
                s=aux;
                main_archivar(lista);
            }
            break;
        case 2:
            alta_newProfesion(aux);
            printf("\nConfirmar cambios? s/n: ");
            if(generic_confirmar())
            {
                s=aux;
                main_archivar(lista);
            }
            break;
        case 3:
            alta_newDni(aux);
            printf("\nConfirmar cambios? s/n: ");
            if(generic_confirmar())
            {
                s=aux;
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

    soc* s;
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

    soc_mostrarUno(s);

    printf("\nDar de baja socio? s/n: ");
    if(generic_confirmar())
    {
        s->estado=0;
        main_archivar(lista);
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

