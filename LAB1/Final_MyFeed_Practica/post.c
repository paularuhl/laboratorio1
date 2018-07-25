#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"

post* post_newStruct()
{
    post* aux=(post*)malloc(sizeof(post));

    return aux;
}
void post_new(post* p, int idMsg, int idUser, char* pop, char* msg)
{
    post_setIdMsg(p,idMsg);
    post_setIdUser(p,idUser);
    post_setPop(p,pop);
    post_setMsg(p,msg);
}
void post_setMsg(post* p, char* aux)
{
    if(p!=NULL)
    {
        strcpy(p->msg,aux);
    }
}
void post_setIdMsg(post* p, int aux)
{
    if(p!=NULL)
    {
        p->idMsg=aux;
    }
}
void post_setIdUser(post* p, int aux)
{
    if(p!=NULL)
    {
        p->idUser=aux;
    }
}
void post_setPop(post* p, char* aux)
{
    if(p!=NULL)
    {
        strcpy(p->pop,aux);
    }
}

char* post_getMsg (post* p)
{
    char* str=NULL;
    if(p!=NULL)
    {
        str=p->msg;
    }
    return str;
}
int post_getIdMsg (post* p)
{
    int aux;
    if(p!=NULL)
    {
        aux=p->idMsg;
    }
    return aux;
}
int post_getIdUser (post* p)
{
    int aux;
    if(p!=NULL)
    {
        aux=p->idUser;
    }
    return aux;
}
char* post_getPop (post* p)
{
    char* str=NULL;
    if(p!=NULL)
    {
        str=p->pop;
    }
    return str;
}

int post_compararPop(void* itemA, void* itemB)
{
    post* item1;
    post* item2;
    int a, b, r;

    item1=(post*)itemA;
    item2=(post*)itemB;

    a=atoi(post_getPop(item1));
    b=atoi(post_getPop(item2));
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

