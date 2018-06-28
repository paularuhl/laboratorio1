#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "parser.h"


int parseIn(ArrayList* l,char filename[])
{
    FILE* fp;
    eEmp* s;
    int id=0;
    int estado, edad, salary;
    char name[40];
    char profesion[40];
    fp = fopen(filename,"r");
    if(fp!=NULL&&l!=NULL)
    {
        do
        {
            s=emp_newStruct();
            fscanf(fp,"%d,%d,%d,%d,%[^,],%[^\n]\n",&id,&estado,&salary,&edad,profesion,name);
            emp_setId(s,&id);
            emp_setState(s,estado);
            emp_setName(s,name);
            emp_setProfesion(s,profesion);
            emp_setSalary(s,salary);
            emp_setEdad(s,edad);
            l->add(l,s);
        }
        while(!feof(fp));
        printf("***************\n");
    }
    else
    {
        printf("~~~~~~~~~~~~~~~\n");
    }
    fclose(fp);

    return id;
}

void parseOut(ArrayList* lista,char filename[])
{
    eEmp* s;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                s=(eEmp*) lista->get(lista,i);
                fprintf(fp,"%d,%d,%d,%d,%s,%s\n",emp_getId(s),emp_getState(s),emp_getSalary(s),emp_getEdad(s),emp_getProfesion(s),emp_getName(s));
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
