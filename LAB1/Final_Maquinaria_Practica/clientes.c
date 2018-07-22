#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

#define INHABILITADO 0
#define HABILITADO 1
#define ERROR -1

///private functions
char* askName(char* aux);
char* askLastname(char* aux);
char* askDni(char* aux);
int dniRepetido(ArrayList* l,char* dni);
void mostrarUnCte(client* c);
void mostrarCte(client* c);
void mostrarAlqBajaCte(client* c, ArrayList* ctes, ArrayList* alq);

int tieneAlquileres(client* c, ArrayList* alq);

///public functions
void clientes_alta(ArrayList* clientes,int* id)
{
    client* c=clientes_newStruct();
    char name[40], lastname[40], dni[9];
    if(clientes!=NULL&&id!=NULL)
    {
        vista_clean();
        printf("**Alta de cliente**");
        clientes_setName(c,askName(name));
        clientes_setLastname(c,askLastname(lastname));
        do
        {
            clientes_setDni(c,askDni(dni));
        }
        while(dniRepetido(clientes,dni));
        clientes_setState(c,HABILITADO);
        mostrarCte(c);
        if(vista_confirmar("Confirmar alta de cliente?"))
        {
            (*id)++;
            clientes_setId(c,id);
            al_add(clientes,c);
            ctes_parseOut(clientes,"clientes.csv");
        }
        vista_clean();
    }
}
void clientes_modificar(ArrayList* clientes)
{
    client* c;
    int opcion, volver=0;
    char name[40], lastname[40];
    if(clientes!=NULL)
    {
        if(al_len(clientes)!=0)
        {
            clientes_mostrarLista(clientes);
            c=clientes_pedirId(clientes);
            do
            {
                mostrarCte(c);
                vista_menuModificar();
                opcion=entero_get("opcion");
                switch(opcion)
                {
                case 1:
                    askName(name);
                    if(vista_confirmar("Confirmar cambios?"))
                    {
                        clientes_setName(c,name);
                    }
                    break;
                case 2:
                    askLastname(lastname);
                    if(vista_confirmar("Confirmar cambios?"))
                    {
                        clientes_setLastname(c,lastname);
                    }
                    break;
                case 0:
                    volver = 1;
                    break;
                default:
                    vista_opcionInvalida();
                    break;
                }
                ctes_parseOut(clientes,"clientes.csv");

            }
            while(!volver);
        }
        else
        {
            vista_noData();
        }
    }
    else
    {
        vista_errorNotFound();
    }
    vista_finFuncion();
}
void clientes_baja(ArrayList* clientes,ArrayList* alq)
{
    client* c=NULL;
    rent* a=NULL;
    int i;
    if(clientes!=NULL)
    {
        if(al_len(clientes)!=0)
        {
            clientes_mostrarLista(clientes);
            c=clientes_pedirId(clientes);
            vista_clean();
            clientes_mostrarUno(c);
            if(tieneAlquileres(c,alq))
            {
                mostrarAlqBajaCte(c,clientes,alq);
                if(vista_confirmar("\nDar de baja cliente y finalizar alquileres?"))
                {
                    clientes_setState(c,INHABILITADO);
                    for(i=0; i<al_len(alq); i++)
                    {
                        a=al_get(alq,i);
                        if(alq_getCte(a)==clientes_getId(c)&&alq_getState(a)==1)
                        {
                            alq_setState(a,INHABILITADO);
                        }
                    }
                }
                vista_clean();
            }
            else if(vista_confirmar("\nDar de baja cliente? (s/n): "))
            {
                clientes_setState(c,INHABILITADO);
            }
            exportData(clientes,alq);
        }
        else
        {
            vista_noData();
        }
    }
    vista_finFuncion();
}

void clientes_mostrarUno (client* c)
{
    if(c!=NULL)
    {
        vista_encabezadoClientes();
        mostrarUnCte(c);
    }
}
void clientes_mostrarLista(ArrayList* lista)
{
    int i;
    client* c;
    if(lista!=NULL)
    {
        if(al_len(lista)!=0)
        {
            vista_encabezadoClientes();
            for(i=0; i<al_len(lista); i++)
            {
                c=al_get(lista,i);
                if(clientes_getState(c)==HABILITADO)
                {
                    mostrarUnCte(c);
                }
            }
        }
        else
        {
            vista_noData();
        }
    }
}

client* clientes_pedirId(ArrayList* clientes)
{
    client* aux=NULL;
    int id;
    if(clientes!=NULL)
    {
        id=entero_get("id de cliente");
        aux=clientes_buscarPorId(clientes,&id);
    }
    return aux;
}
client* clientes_buscarPorId(ArrayList* clientes, int* id)
{
    client* c;
    client* aux=NULL;
    int i;
    for(i=0; i<al_len(clientes); i++)
    {
        c=al_get(clientes,i);
        if(*id==clientes_getId(c)&&clientes_getState(c)==HABILITADO)
        {
            aux=c;
            break;
        }
    }
    return aux;
}

void clientes_conMasAlquileres(ArrayList* ctes, ArrayList* alq)
{
    client* c=NULL;
    client* b=NULL;
    rent* a=NULL;
    int i,j;
    int max=0;
    int cteUno;
    int cteDos;
    int contadorAlq;
    if(ctes!=NULL&&alq!=NULL)
    {
        if(al_len(ctes)!=0&&al_len(alq)!=0)
        {
            for(i=0; i<al_len(ctes); i++)
            {
                c=al_get(ctes,i);
                contadorAlq=0;
                for(j=0; j<al_len(alq); j++)
                {
                    a=al_get(alq,j);
                    if(alq_getCte(a)==clientes_getId(c))
                    {
                        contadorAlq++;
                    }
                }
                if(contadorAlq>max)
                {
                    max=contadorAlq;
                    cteUno=i;
                    cteDos=i;

                }
                else if(contadorAlq==max)
                {
                    cteDos=i;
                }
            }
            c=al_get(ctes,cteUno);
            if(cteUno!=cteDos&&al_len(alq)>1)
            {
                printf("\nLos clientes con mas alquileres son:");
                mostrarUnCte(c);
                b=al_get(ctes,cteDos);
                mostrarUnCte(b);
            }
            else
            {
                printf("\nEl cliente con mas alquileres es:");
                mostrarUnCte(c);
            }
        }
        else
        {
            vista_noData();
        }
    }
}


/// CONSTRUCTOR
client* clientes_newStruct()
{
    client* aux=(client*)malloc(sizeof(client));
    return aux;
}
/// SETTERS
void clientes_setName(client* c, char* aux)
{
    if(c!=NULL&&aux!=NULL)
    {
        strcpy(c->name,aux);
    }
}
void clientes_setLastname(client* c, char* aux)
{
    if(c!=NULL&&aux!=NULL)
    {
        strcpy(c->lastname,aux);
    }
}
void clientes_setDni(client* c, char* aux)
{
    if(c!=NULL&&aux!=NULL)
    {
        strcpy(c->dni,aux);
    }
}
void clientes_setState(client* c,int st)
{
    if(c!=NULL)
    {
        c->state=st;
    }
}
void clientes_setId(client* c,int* id)
{
    if(c!=NULL&&id!=NULL)
    {
        c->idCte=*id;
    }
}
/// GETTERS
char* clientes_getName (client* c)
{
    char* str=NULL;
    if(c!=NULL)
    {
        str=c->name;
    }
    return str;
}
char* clientes_getLastname (client* c)
{
    char* str=NULL;
    if(c!=NULL)
    {
        str=c->lastname;
    }
    return str;
}
char* clientes_getDni (client* c)
{
    char* str=NULL;
    if(c!=NULL)
    {
        str=c->dni;
    }
    return str;
}
int clientes_getId(client* c)
{
    int aux;
    if(c!=NULL)
    {
        aux=c->idCte;
    }
    return aux;
}
int clientes_getState(client* c)
{
    int aux;
    if(c!=NULL)
    {
        aux=c->state;
    }
    return aux;
}



///private functions
/** \brief asks name of client
 * \param [aux char*] pointer to auxiliar string
 * \return [char*] pointer to name
 */ char* askName(char* aux)
{
    while(!string_getLetras("\nIngrese el nombre: ",aux))
    {
        vista_errorItem("el nombre","letras");
    }
    string_initialUpper(aux);
    return aux;
}
/** \brief asks lastname of client
 * \param [aux char*] pointer to auxiliar string
 * \return [char*] pointer to lastname
 */ char* askLastname(char* aux)
{
    while(!string_getLetras("Ingrese el apellido: ",aux))
    {
        vista_errorItem("el apellido","letras");
    }
    string_initialUpper(aux);
    return aux;
}
/** \brief asks dni of client
 * \param [aux char*] pointer to auxiliar string
 * \return [char*] pointer to dni
 */ char* askDni(char* aux)
{
    do
    {
        while(!string_getNumerico("Ingrese DNI: ",aux))
        {
            vista_errorItem("el dni","numeros");
        }
    }
    while(!string_validaRango(aux,7000000,99999999));
    return aux;
}
/** \brief validates if the dni exists already
 * \param [l ArrayList*] pointer to list to search in
 * \param [dni char*] pointer to string
 * \return int [0] if it doesn't exist [1] if it does
 */ int dniRepetido(ArrayList* l,char* dni)
{
    int i,r=0;
    int doc=atoi(dni), aux;
    client* c=NULL;

    for(i=0; i<al_len(l); i++)
    {
        c=al_get(l,i);
        aux=atoi(clientes_getDni(c));
        if(aux==doc)
        {
            r=1;
            printf("Error, ya existe un cliente con ese dni");
            break;
        }
    }
    return r;
}
/** \brief shows a simpler version of the client struct without header
 * \param [client* c] pointer to struct
 * \return void
 */ void mostrarCte (client* c)
{
    if(c!=NULL)
    {
        printf("\n%s - %s - %s",clientes_getDni(c),clientes_getName(c),clientes_getLastname(c));
    }
}
/** \brief shows one client
 * \param [c client*] pointer to struct
 * \return void
 */ void mostrarUnCte(client* c)
{
    printf("\n%d\t| %s\t| %s %s",clientes_getId(c),clientes_getDni(c),clientes_getName(c),clientes_getLastname(c));
}
/** \brief shows a rental for when a client is taken down
 * \param [c client*] pointer to client struct
 * \param [ctes ArrayList*] pointer to client list
 * \param [alq ArrayList*] pointer to rental list
 * \return void
 */ void mostrarAlqBajaCte(client* c, ArrayList* ctes, ArrayList* alq)
{
    int i;
    rent* a=NULL;
    printf("\nAlquileres a finalizar con  baja de cliente (se tomara el tiempo estimado como real):");
    for(i=0; i<al_len(alq); i++)
    {
        a=al_get(alq,i);
        if(alq_getCte(a)==clientes_getId(c) && alq_getState(a))
        {
            vista_encabezadoFinAlq();
            alq_mostrarFinAlq(a,ctes);
        }
    }
}
/** \brief checks if a client has active rentals
 * \param [c client*] pointer to client struct
 * \param [alq ArrayList*] pointer to rental list
 * \return int [0] if it doesn't, [1] if it does
 */ int tieneAlquileres(client* c, ArrayList* alq)
{
    int i, r=0;
    rent* a=NULL;
    for(i=0; i<al_len(alq); i++)
    {
        a=al_get(alq,i);
        if(alq_getCte(a)==clientes_getId(c)&&alq_getState(a)==1)
        {
            r=1;
            break;
        }
    }
    return r;
}
