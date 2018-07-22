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



