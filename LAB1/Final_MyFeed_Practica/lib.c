#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
#include "ArrayList.h"
#include "post.h"
#include "user.h"

void mostrarUnUser(ArrayList* usu)
{
    user* u=NULL;
    int i;
    for(i=0;i<al_len(usu);i++)
    {
        u=al_get(usu,i);
        if(user_getId(u)>96)
        {
        printf("\n%d\t|%s\t|%s",user_getId(u),user_getNick(u),user_getPop(u));
        }
    }
}


void ordenarUsuariosPop(ArrayList* user)
{
    al_sort(user,user_compararPop,1);
}

void ordenarPostPop(ArrayList* posts)
{
    al_sort(posts,post_compararPop,1);
}





/*void double_sort_agus(ArrayList* this)
{
    ArrayList* clone;
    clone=al_newArrayList();
    int i;
    int j;
    ejemplo* aux;
    ejemplo* aux2;
    void* auxiliar;
    if(this!=NULL&&clone!=NULL)
    {
        clone=al_clone(this);
        al_sort(clone,sort_string,1);
        printf("\nLista alfabeticamente\n");
        printAll(clone);
        printf("\n\n\n\n");
        for(i=0;i<clone->len(clone)-1;i++)
        {
            aux=clone->get(clone,i);
            for(j=i+1;j<clone->len(clone);j++)
            {
                aux2=clone->get(clone,j);
                if(aux!=NULL&aux2!=NULL)
                {
                    if(get_char(aux)==get_char(aux2))
                    {
                        if(get_float(aux)>get_float(aux2))
                        {
                            auxiliar=al_pop(clone,i);
                            al_push(clone,i,aux2);
                            al_set(clone,j,auxiliar);
                        }
                    }
                }
            }
        }
        printAll(clone);
    }
}


*/
