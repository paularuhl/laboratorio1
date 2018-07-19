#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "parser.h"

int txt_parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    soc* s;
    char name[40];
    char lastname[40];
    char mail[50];
    char socid[5];
    int aux;
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {
            s=soc_newStruct();
            fscanf(fp,"%[^,],%[^,],%[^,],%[^\n]\n",socid,name,lastname,mail);
            aux = atoi(socid);
            soc_setId(s,&aux);
            soc_setName(s,name);
            soc_setLastname(s,lastname);
            soc_setMail(s,mail);
            soc_setState(s,1);
            l->add(l,s);
        }
        while(!feof(fp));
        fclose(fp);
        return aux;
    }
    else
    {
        return -1;
    }

}

int txt_parseOut(ArrayList* lista,char filename[])
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


void bin_parseIn(ArrayList* lista,int* id)
{
    soc* s;
    FILE* binFile;
    binFile=fopen("socios.bin","rb");
    if(binFile!=NULL)
    {
        while(!feof(binFile))
        {
            s=soc_newStruct();
            fread((s),sizeof(soc),1,binFile);
            lista->add(lista,s);
            *id=s->idSocio;
        }
        fclose(binFile);
        printf("Existe una base de datos para este programa.\n");
    }
}

int bin_parseOut(ArrayList* lista,char filename[])
{
    soc* s;
    FILE* fp;
    int i, r=-1;
    if(lista!=NULL)
    {
        fp=fopen(filename,"wb");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                s=(soc*)lista->get(lista,i);
                fwrite(s,sizeof(soc),1,fp);
            }
        }
        fclose(fp);
        r=0;
    }
    return r;
}
