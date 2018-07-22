#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "parser.h"


void ser_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    Service* s;
    int id;
    char name[33];
    char email[65];
    char idAux[4];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {

            s=ser_newStruct();
            fscanf(fp,"%[^;];%[^;];%[^\n]\n",idAux,name,email);
            id=atoi(idAux);
            ser_setId(s,id);
            ser_setName(s,name);
            ser_setEmail(s,email);
            l->add(l,s);
        }
        while(!feof(fp));
        printf("\nArchivo %s cargado correctamente",filename);
        fclose(fp);
    }
}
void log_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    LogEntry* e;
    int sId, gravedad;
    char date[11];
    char time[6];
    char msg[65];
    char idAux[4];
    char gAux[2];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {
            e=log_newStruct();
            fscanf(fp,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,idAux,gAux,msg);
            sId=atoi(idAux);
            gravedad=atoi(gAux);
            log_setDate(e,date);
            log_setTime(e,time);
            log_setServiceId(e,sId);
            log_setGravedad(e,gravedad);
            log_setMsg(e,msg);
            l->add(l,e);
        }
        while(!feof(fp));
        printf("Archivo %s cargado correctamente",filename);

    }

    fclose(fp);
}


void errors_parseOut(ArrayList* log, ArrayList* ser)
{
    Service* s;
    LogEntry* e;
    FILE* fp;
    int i,j;
    if(log!=NULL&&ser!=NULL)
    {
        fp=fopen("errors.txt","w");
        if(fp!=NULL)
        {
            for(i=0; i<al_len(log); i++)
            {
                e=(LogEntry*) al_get(log,i);
                if(log_getGravedad(e)>7)
                {
                    for(j=0; j<al_len(ser); j++)
                    {
                        s=(Service*)al_get(ser,j);
                        if(log_getServiceId(e)==ser_getId(s))
                        {
                            fprintf(fp,"%s;%s;%s;%s;%s\n",log_getDate(e),log_getTime(e),ser_getName(s),log_getMsg(e),ser_getEmail(s));
                            break;
                        }
                    }
                }
            }
        }
        fclose(fp);
    }
    else
    {
vista_noFile();
    }
}
void warnings_parseOut(ArrayList* log, ArrayList* ser)
{
    Service* s;
    LogEntry* e;
    FILE* fp;
    int i,j;
    if(log!=NULL&&ser!=NULL)
    {
        fp=fopen("warnings.txt","w");
        if(fp!=NULL)
        {
            for(i=0; i<al_len(log); i++)
            {

                e=(LogEntry*) al_get(log,i);
                if(log_getGravedad(e)==3&&log_getServiceId(e)!=45)
                {
                    for(j=0; j<al_len(ser); j++)
                    {
                        s=(Service*)al_get(ser,j);
                        if(log_getServiceId(e)==ser_getId(s))
                        {
                            fprintf(fp,"%s;%s;%s;%s;%s\n",log_getDate(e),log_getTime(e),ser_getName(s),log_getMsg(e),ser_getEmail(s));
                            break;
                        }
                    }
                }
            }
        }
        fclose(fp);
    }
    else
    {
    vista_noFile();
    }
}




