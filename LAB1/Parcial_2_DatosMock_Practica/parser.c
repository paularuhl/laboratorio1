#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "parser.h"


int parseIn(ArrayList* l,char filename[],int* id)
{
    FILE* fp;
    soc* s;
    char name[40];
    char lastname[40];
    char mail[50];
    int aux;
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {
            (*id)++;
            s=soc_newStruct();
            fscanf(fp,"%d,%[^,],%[^,],%[^\n]\n",&aux,name,lastname,mail);
            s->idSocio = *id;
            soc_setName(s,name);
            soc_setLastname(s,lastname);
            soc_setMail(s,mail);
            soc_setState(s,1);
            l->add(l,s);
        }
        while(!feof(fp));
        fclose(fp);
    }
    else
    {
        *id=-1;
    }
    fclose(fp);

    return *id;
}

int parseOut(ArrayList* lista,char filename[])
{
    soc* s;
    FILE* fp;
    int i, r=-1;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                s=(soc*) lista->get(lista,i);
                fprintf(fp,"%d,%d,%s,%s,%s\n",soc_getId(s),soc_getState(s),soc_getName(s),soc_getLastname(s),soc_getMail(s));
            }
        }
        fclose(fp);
        r=0;
    }
    return r;
}
