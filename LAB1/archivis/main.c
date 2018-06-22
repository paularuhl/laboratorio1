#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /* <html>
    <head> </head>
    </html>

    la extension es .html*/

    FILE* miHtml;
    char msj[]="hola a todos";
    char buffer[1080]= {};

    strcat(buffer,"<html><head></head><body><h1>");
    strcat(buffer,msj);
    strcat(buffer,"</h1></body></html>");

    miHtml = fopen("ahre.html","w");

    if(miHtml!=NULL)
    {
        fprintf(miHtml,buffer);
        //fprintf(miHtml,"<html><head>");
        //fprintf(miHtml,msj);
        //fprintf(miHtml,"</head></html>");


        fclose(miHtml);
        printf("Guardado!");
    }
    else
    {
        printf("Imposible guardar");
    }




    return 0;
}
