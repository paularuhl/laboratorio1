#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "user.h"
#include "post.h"

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
            post_setIdMsg(p,idMsg);
            post_setIdUser(p,idUser);
            post_setPop(p,pop);
            post_setMsg(p,msg);
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
            user_setId(u,id);
            user_setPop(u,pop);
            user_setNick(u,nick);
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

void feed_parseOut(ArrayList* usuarios, ArrayList* mensajes)
{
    user* u=NULL;
    user* s=NULL;
    post* p=NULL;
    FILE* fp;
    int i,j,k;
    if(mensajes!=NULL&&usuarios!=NULL)
    {
        al_sort(usuarios,user_compararPop,0);
        al_sort(mensajes,post_compararPop,0);

        fp=fopen("feed.csv","w");
        if(fp!=NULL)
        {
            for(i=0; i<al_len(usuarios); i++)
            {
                j=i+1;
                u=al_get(usuarios,i);
                s=al_get(usuarios,j);
                if(user_getPop(u)==user_getPop(s))
                {
                    for(k=0; k<al_len(mensajes); k++)
                    {
                        p=al_get(mensajes,k);
                        if(user_getId(u)==post_getIdUser(p))
                        {
                            fprintf(fp,"%d,%s,%s,%d,%s,%s\n",post_getIdMsg(p),post_getMsg(p),post_getPop(p),user_getId(u),user_getNick(u),user_getPop(u));
                        }
                        else if(user_getId(s)==post_getIdUser(p))
                        {
                            fprintf(fp,"%d,%s,%s,%d,%s,%s\n",post_getIdMsg(p),post_getMsg(p),post_getPop(p),user_getId(s),user_getNick(s),user_getPop(s));
                        }
                    }
                }
                else
                {
                    for(k=0; k<al_len(mensajes); k++)
                    {
                        p=al_get(mensajes,k);
                        if(user_getId(u)==post_getIdUser(p))
                        {
                            fprintf(fp,"%d,%s,%s,%d,%s,%s\n",post_getIdMsg(p),post_getMsg(p),post_getPop(p),user_getId(u),user_getNick(u),user_getPop(u));
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
}


