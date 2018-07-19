#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "parser.h"

#define INACTIVO 0
#define ACTIVO 1

#define AN 4
#define PR 5
#define TE 6



eEmp* emp_newStruct()
{
    eEmp* aux;

    aux=(eEmp*)malloc(sizeof(eEmp));

    return aux;
}

/*************************************************************/
///NEW SETTERS -- ALTA O MODIFICACION -- piden por pantalla///
/***********************************************************/
void emp_newName(eEmp* s)
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

int emp_newProfesion(eEmp* s)
{
    int opcion;
    if(s!=NULL)
    {
        printf("\nCual es la profesion del nuevo empleado?\n1.Analista\n2.Programador\n3.Tester");
        opcion=entero_get("opcion");
        switch(opcion)
        {
        case 1:
            strcpy(s->profesion,"Analista");
            break;
        case 2:
            strcpy(s->profesion,"Programador");
            break;
        case 3:
            strcpy(s->profesion,"Tester");
            break;
        }
    }
    return opcion;
}

void emp_newSalary(eEmp* s, int prof)
{
    if(s!=NULL)
    {
        switch(prof)
        {
        case 1:
            s->salary=15000;
            break;
        case 2:
            s->salary=20000;
            break;
        case 3:
            s->salary=10000;
            break;
        }
    }
}

void emp_newEdad(eEmp* s)
{
    int aux;
    if(s!=NULL)
    {
        do
        {
            aux=entero_get("edad");
        }
        while(!entero_validaRango(aux,"edad",18,99));
        s->edad=aux;
    }

}


/**************/
/// SETTERS ///
/************/
void emp_setId(eEmp* s,int* id)
{
    if(s!=NULL)
    {
        s->idEmpleado=*id;
    }
}

void emp_setState(eEmp* s,int st)
{
    if(s!=NULL)
    {
        s->estado=st;
    }
}

void emp_setName(eEmp* s, char* name)
{
    if(s!=NULL)
    {
        strcpy(s->name,name);
    }
}

void emp_setSalary (eEmp* s, int salary)
{
    if(s!=NULL)
    {
        s->salary=salary;
    }
}

void emp_setEdad (eEmp* s, int edad)
{
    if(s!=NULL)
    {
        s->edad=edad;
    }
}

void emp_setProfesion(eEmp* s, char* profesion)
{
    if(s!=NULL)
    {
        strcpy(s->profesion,profesion);
    }
}







///genericas
int generic_menu (void)
{
    fflush(stdin);
    printf("Sitio principal\n");
    printf("1. Alta\n");
    printf("2. Filtrar programadores >30 anios\n");
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
    eEmp* s=emp_newStruct();
    int sal;
    system("cls");

    printf("\n**ALTA EMPLEADO**");
    emp_newName(s);
    emp_newEdad(s);
    sal=emp_newProfesion(s);
    emp_newSalary(s,sal);
    emp_setId(s,id);
    emp_setState(s,1);

    printf("\nDar de alta empleado? s/n: ");
    if(generic_confirmar())
    {
        lista->add(lista,s);
        parseOut(lista,"empleados.csv");
    }
    generic_finFuncion();
}





/**************/
/// GETTERS ///
/************/
int emp_getId(eEmp* s)
{
    int id;
    if(s!=NULL)
    {
        id=s->idEmpleado;
    }
    return id;
}

int emp_getState(eEmp* s)
{
    int st;
    if(s!=NULL)
    {
        st=s->estado;
    }
    return st;
}

int emp_getSalary (eEmp* s)
{
    float aux;
    if(s!=NULL)
    {
        aux=s->salary;
    }
    return aux;
}

char* emp_getProfesion(eEmp* s)
{
    char* str;
    if(s!=NULL)
    {
        str=s->profesion;
    }
    return str;
}

char* emp_getName (eEmp* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->name;
    }
    return str;
}

int emp_getEdad(eEmp* s)
{
    int edad;
    if(s!=NULL)
    {
        edad=s->edad;
    }
    return edad;
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





void emp_mostrarUno (eEmp* s)
{
    if(s!=NULL)
    {
        printf("\nID\t| DNI\t| Nombre\t| Apellido");
        printf("\n%d\t| %d\t| %s\t| %s",emp_getId(s),emp_getSalary(s),emp_getName(s),emp_getProfesion(s));
    }
}

void main_mostrarLista(ArrayList* lista)
{
    int i, len;
    eEmp* g;
    if(lista!=NULL)
    {
        len=lista->len(lista);
        printf("\nID\t| Salary\t| Profesion\t| Edad\t| Nombre\n");
        for(i=0; i<len; i++)
        {
            g=lista->get(lista,i);
            if(emp_getState(g)!=0)
            {
                printf("\n%d\t| $%d\t| %s\t| %d\t| %s",emp_getId(g),emp_getSalary(g),emp_getProfesion(g),emp_getEdad(g),emp_getName(g));
            }
        }
        printf("\n");
    }
}


///otras
int funcionQueFiltra(void* empleado)
{
    int r=0;
    eEmp* e;
    e = (eEmp*)empleado;
    if(empleado!=NULL)
    {
        if(emp_getEdad(e)>30)
        {
            if(strcmp(emp_getProfesion(e),"Programador")==0)
            {
                r=1;
            }
        }
        else
        {
            r=0;
        }
    }
    return r;
}

///funciones que no use aca
/*
void main_modificar(ArrayList* lista)
{

    eEmp* s;
    eEmp* aux;
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

        emp_mostrarUno(s);
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

    eEmp* s;
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

    emp_mostrarUno(s);

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
