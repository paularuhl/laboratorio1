#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "feedItem.h"

char* feedItem_getNick (feedItem* f)
{
    char* str=NULL;
    if(f!=NULL)
    {
        str=f->nick;
    }
    return str;
}
char* feedItem_getMsg (feedItem* f)
{
    char* str=NULL;
    if(f!=NULL)
    {
        str=f->msg;
    }
    return str;
}
char* feedItem_getUserPop (feedItem* f)
{
    char* str=NULL;
    if(f!=NULL)
    {
        str=f->popU;
    }
    return str;
}
char* feedItem_getMsgPop (feedItem* f)
{
    char* str=NULL;
    if(f!=NULL)
    {
        str=f->popM;
    }
    return str;
}
int feedItem_getIdUser (feedItem* f)
{
    int aux;
    if(f!=NULL)
    {
        aux=f->idUser;
    }
    return aux;
}
int feedItem_getIdMsg (feedItem* f)
{
    int aux;
    if(f!=NULL)
    {
        aux=f->idMsg;
    }
    return aux;
}

void feedItem_setNick(feedItem* f, char* aux)
{
    if(f!=NULL)
    {
        strcpy(f->nick,aux);
    }
}
void feedItem_setMsg(feedItem* f, char* aux)
{
    if(f!=NULL)
    {
        strcpy(f->msg,aux);
    }
}
void feedItem_setUserPop(feedItem* f, char* aux)
{
    if(f!=NULL)
    {
        strcpy(f->popU,aux);
    }
}
void feedItem_setMsgPop(feedItem* f, char* aux)
{
    if(f!=NULL)
    {
        strcpy(f->popM,aux);
    }
}
void feedItem_setIdUser(feedItem* f, int aux)
{
    if(f!=NULL)
    {
        f->idUser=aux;
    }
}
void feedItem_setIdMsg(feedItem* f, int aux)
{
    if(f!=NULL)
    {
        f->idMsg=aux;
    }
}

feedItem* feedItem_newStruct()
{
    feedItem* aux=(feedItem*)malloc(sizeof(feedItem));
    return aux;
}

void feedItem_new(feedItem* f,int idMsg, char* msg, char* popM, int idUser, char* nick, char* popU)
{
    feedItem_setIdMsg(f,idMsg);
    feedItem_setMsg(f,msg);
    feedItem_setMsgPop(f,popM);
    feedItem_setIdUser(f,idUser);
    feedItem_setNick(f,nick);
    feedItem_setUserPop(f,popU);
}
void feed_crear(ArrayList* usuarios, ArrayList* mensajes, ArrayList* feed)
{
    user* u=NULL;
    post* p=NULL;
    feedItem* f=NULL;
    int i,k;
    if(mensajes!=NULL&&usuarios!=NULL)
    {
        al_sort(usuarios,user_compararPop,0);
        for(i=0; i<al_len(usuarios); i++)
        {
            u=al_get(usuarios,i);
            for(k=0; k<al_len(mensajes); k++)
            {
                p=al_get(mensajes,k);
                if(user_getId(u)==post_getIdUser(p))
                {
                    f=feedItem_newStruct();
                    feedItem_new(f,post_getIdMsg(p),post_getMsg(p),post_getPop(p),user_getId(u),user_getNick(u),user_getPop(u));
                    al_add(feed,f);
                }
            }
        }
    }
}


ArrayList* feed_doubleSort(ArrayList* this)
{
    ArrayList* clone=al_clone(this);
    int i,j;
    feedItem* aux=NULL;
    feedItem* aux2=NULL;
    feedItem* auxiliar=NULL;
    if(this!=NULL&&clone!=NULL)
    {
        for(i=0; i<al_len(clone)-1; i++)
        {
            for(j=i+1; j<al_len(clone); j++)
            {
                aux=al_get(clone,i);
                aux2=al_get(clone,j);
                if(aux!=NULL&&aux2!=NULL)
                {
                    if(feedItem_getUserPop(aux)==feedItem_getUserPop(aux2))
                    {
                        if(strcmp(feedItem_getMsgPop(aux2),(feedItem_getMsgPop(aux))))
                        {
                            auxiliar=al_pop(clone,i);
                            al_push(clone,i,aux2);
                            al_set(clone,j,auxiliar);
                        }
                    }
                }
            }
        }
    }
    return clone;
}

