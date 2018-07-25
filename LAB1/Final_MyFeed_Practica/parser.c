#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "lib.h"
#include "user.h"
#include "post.h"
#include "feedItem.h"

void post_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    post* p;
    int idMsg, idUser, flag=0;
    char msg[1800];
    char id_Msg[4];
    char pop[6];
    char id_User[4];
    char aux[1];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {
            if(!flag)
            {
                fscanf(fp,"%[^\n]\n",aux);
                flag=1;
            }
            p=post_newStruct();
            fscanf(fp,"%[^,],%[^,],%[^,],%[^\n]\n",id_Msg,id_User,pop,msg);
            idMsg=atoi(id_Msg);
            idUser=atoi(id_User);
            post_new(p,idMsg,idUser,pop,msg);
            l->add(l,p);
        }
        while(!feof(fp));
        printf("\nArchivo %s cargado correctamente",filename);
        fclose(fp);
    }
}

void user_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    user* u;
    int id, flag=0;
    char nick[40];
    char idAux[4];
    char pop[10];
    char aux[1];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {
            if(!flag)
            {
                fscanf(fp,"%[^\n]\n",aux);
                flag=1;
            }
            u=user_newStruct();
            fscanf(fp,"%[^,],%[^,],%[^\n]\n",idAux,nick,pop);
            id=atoi(idAux);
            user_new(u,id,nick,pop);
            l->add(l,u);
        }
        while(!feof(fp));
        printf("\nArchivo %s cargado correctamente",filename);
        fclose(fp);
    }
}

void user_parseOut(ArrayList* lista,char filename[])
{
    user* d;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<al_len(lista); i++)
            {
                d=(user*) al_get(lista,i);
                fprintf(fp,"%d,%s,%s\n",user_getId(d),user_getPop(d),user_getNick(d));
            }
        }
        fclose(fp);
    }
}
void feed_parseOut(ArrayList* lista,char filename[])
{
    feedItem* f;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<al_len(lista); i++)
            {
                f=(feedItem*) al_get(lista,i);
                fprintf(fp,"%d,%s,%s,%d,%s,%s\n",feedItem_getIdMsg(f),feedItem_getMsg(f),feedItem_getMsgPop(f),
                        feedItem_getIdUser(f),feedItem_getNick(f),feedItem_getUserPop(f));
            }
        }
        fclose(fp);
    }
}

/*
void doublesort_lol (ArrayList* this)
{
    //auxiliar=al_pop(clone,i);
    //al_push(clone,i,aux2);
    //al_set(clone,j,auxiliar);
}*/
