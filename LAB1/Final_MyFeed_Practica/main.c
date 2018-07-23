#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "parser.h"
#include "user.h"
#include "post.h"

int main()
{
    ArrayList* mensajes=al_newArrayList();
    ArrayList* usuarios=al_newArrayList();


    user_parseIn(usuarios,"usuarios.csv");
    post_parseIn(mensajes,"mensajes.csv");
    feed_parseOut(usuarios,mensajes);

    return 0;
}
