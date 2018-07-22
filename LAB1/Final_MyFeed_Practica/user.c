#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

user* user_newStruct()
{
    user* aux=(user*)malloc(sizeof(user));

    return aux;
}

void user_setNick(user* u, char* aux)
{
    if(u!=NULL)
    {
        strcpy(u->nick,aux);
    }
}
void user_setPop(user* u, char* aux)
{
    if(u!=NULL)
    {
        strcpy(u->pop,aux);
    }
}
void user_setId(user* u, int aux)
{
    if(u!=NULL)
    {
        u->id=aux;
    }
}

char* user_getNick (user* u)
{
    char* str=NULL;
    if(u!=NULL)
    {
        str=u->nick;
    }
    return str;
}
char* user_getPop (user* u)
{
    char* str=NULL;
    if(u!=NULL)
    {
        str=u->pop;
    }
    return str;
}
int user_getId (user* u)
{
    int aux;
    if(u!=NULL)
    {
        aux=u->id;
    }
    return aux;
}

int user_compararPop(void* itemA, void* itemB)
{
    user* item1;
    user* item2;
    int a, b, r;

    item1=(user*)itemA;
    item2=(user*)itemB;

    a=atoi(user_getPop(item1));
    b=atoi(user_getPop(item2));
    if(a>b)
    {
        r=1;
    }
    else if(a<b)
    {
        r=-1;
    }
    else if(a==b)
    {
        r=0;
    }

    return r;
}


int user_compararNick(void* itemA, void* itemB)
{
    user* item1=NULL;
    user* item2=NULL;

    item1=(user*)itemA;
    item2=(user*)itemB;

    return strcmp(item1->nick,item2->nick);
}
