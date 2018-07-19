#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "dataManager.h"
#include "clientes.h"
#include "alquileres.h"


int ctes_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    client* c;
    int id=0, st;
    char name[40];
    char lastname[40];
    char dni[9];
    char idAux[4];
    char estado[2];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {

            c=clientes_newStruct();
            fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,estado,lastname,name,dni);
            id=atoi(idAux);
            st=atoi(estado);
            clientes_setId(c,&id);
            clientes_setState(c,st);
            clientes_setLastname(c,lastname);
            clientes_setName(c,name);
            clientes_setDni(c,dni);
            l->add(l,c);
        }
        while(!feof(fp));
        printf("**BIENVENIDO**\n");
    }
    else
    {
        printf("~~~~~~~~~~~~~~~\n");
    }
    fclose(fp);

    return id;
}

void ctes_parseOut(ArrayList* lista,char filename[])
{
    client* c;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                c=(client*) lista->get(lista,i);
                fprintf(fp,"%d,%d,%s,%s,%s\n",clientes_getId(c),clientes_getState(c),clientes_getLastname(c),clientes_getName(c),clientes_getDni(c));
            }
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo generar un archivo.");
    }
    fclose(fp);

}



int alq_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    rent* a;

    int idCte;
    int idAlq=0;
    int equipo;
    int state;
    int estTime;
    int realTime;
    int operador;
    char op[2];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {

            a=alq_newStruct();
            fscanf(fp,"%d,%d,%d,%d,%d,%d,%[^\n]\n",&idCte,&idAlq,&equipo,&state,&estTime,&realTime,op);
            operador=atoi(op);
            alq_setCte(a,idCte);
            alq_setId(a,&idAlq);
            alq_setEquipo(a,equipo);
            alq_setState(a,state);
            alq_setEstTime(a,estTime);
            alq_setRealTime(a,realTime);
            alq_setOp(a,operador);

            l->add(l,a);
        }
        while(!feof(fp));
        printf("***************\n");
    }
    else
    {
        printf("~~~~~~~~~~~~~~~\n");
    }
    fclose(fp);

    return idAlq;
}

void alq_parseOut(ArrayList* lista,char filename[])
{
    rent* a;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                a=(rent*) lista->get(lista,i);
                fprintf(fp,"%d,%d,%d,%d,%d,%d,%d\n",alq_getCte(a),alq_getId(a),alq_getEquipo(a),alq_getState(a),alq_getEstTime(a),alq_getRealTime(a),alq_getOp(a));
            }
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo generar un archivo.");
    }
    fclose(fp);

}
