#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "service.h"

Service* ser_newStruct()
{
    Service* aux=(Service*)malloc(sizeof(Service));

    return aux;
}

void ser_setEmail(Service* s, char* aux)
{
    if(s!=NULL)
    {
        strcpy(s->email,aux);
    }
}

void ser_setName(Service* s, char* aux)
{
    if(s!=NULL)
    {
        strcpy(s->name,aux);
    }
}

void ser_setId(Service* s, int aux)
{
    if(s!=NULL)
    {
        s->id=aux;
    }
}



int ser_getId(Service* s)
{
    int aux;
    if(s!=NULL)
    {
        aux=s->id;
    }
    return aux;
}
char* ser_getName (Service* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->name;
    }
    return str;
}

char* ser_getEmail (Service* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->email;
    }
    return str;
}

