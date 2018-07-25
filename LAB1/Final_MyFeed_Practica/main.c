#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "parser.h"
#include "user.h"
#include "post.h"
#include "feedItem.h"

int main()
{
    ArrayList* mensajes=al_newArrayList();
    ArrayList* usuarios=al_newArrayList();
    ArrayList* feed=al_newArrayList();
    ArrayList* feedOrdenado=NULL;

    user_parseIn(usuarios,"usuarios.csv");
    post_parseIn(mensajes,"mensajes.csv");
    feed_crear(usuarios,mensajes,feed);
    feedOrdenado=feed_doubleSort(feed);
    feed_parseOut(feed,"feedTest.csv");
    feed_parseOut(feedOrdenado,"myFeed.csv");


    return 0;
}
