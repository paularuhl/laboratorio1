#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "logEntry.h"
#include "service.h"

LogEntry* log_newStruct()
{
    LogEntry* aux=(LogEntry*)malloc(sizeof(LogEntry));

    return aux;
}

void log_setDate(LogEntry* l, char* aux)
{
    if(l!=NULL)
    {
        strcpy(l->date,aux);
    }
}
void log_setTime(LogEntry* l, char* aux)
{
    if(l!=NULL)
    {
        strcpy(l->time,aux);
    }
}
void log_setMsg(LogEntry* l, char* aux)
{
    if(l!=NULL)
    {
        strcpy(l->msg,aux);
    }
}
void log_setServiceId(LogEntry* l, int aux)
{
    if(l!=NULL)
    {
        l->serviceId=aux;
    }
}
void log_setGravedad(LogEntry* l, int aux)
{
    if(l!=NULL)
    {
        l->gravedad=aux;
    }
}

char* log_getDate (LogEntry* l)
{
    char* str=NULL;
    if(l!=NULL)
    {
        str=l->date;
    }
    return str;
}
char* log_getTime (LogEntry* l)
{
    char* str=NULL;
    if(l!=NULL)
    {
        str=l->time;
    }
    return str;
}
char* log_getMsg (LogEntry* l)
{
    char* str=NULL;
    if(l!=NULL)
    {
        str=l->msg;
    }
    return str;
}
int log_getServiceId(LogEntry* l)
{
    int aux;
    if(l!=NULL)
    {
        aux=l->serviceId;
    }
    return aux;
}
int log_getGravedad(LogEntry* l)
{
    int aux;
    if(l!=NULL)
    {
        aux=l->gravedad;
    }
    return aux;
}
