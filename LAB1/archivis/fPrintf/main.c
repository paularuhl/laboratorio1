#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv)
{
    ///LEER CLASE ARCHIVOS

    /*FILE *fp;

    char buffer[100] = "esto es un texto en el fichero\n";
    char bufferIn[100];

    fp = fopen("D:\\Pruhl\\fPrintf\\fichero.txt", "w");  //ww de write (para escribir) - si solo pongo el nombre de archivo.x
    //se guarda en la raiz del programa, tiene que existir el directorio para instruccion to worrk
    //p ej ("D:\\clase\\fichero.txt")
    //si el archivo no existe, w, lo crea. si existe, lo reescribe.
    fprintf(fp, buffer);
    fprintf(fp, "Esto es otro texto en el fixeraaaa\n");
    fprintf(fp, "y esto es uno mas, que lee %s\n",buffer);

    system("pause");
    system("cls");

    fclose(fp); //cierra. si no se cierra, no voy a poder usar el archivo uego, s perdera informacion, etc.

    fp = fopen ("D:\\Pruhl\\fPrintf\\fichero.txt","r"); //para leer, si no existe ese path dara error y habria que mostrarlo o algopor eso vvv
    if(fp==NULL)
    {
        printf("archivo no encontrado!");
    }
    else
    {
        while(!feof(fp))    //para saber si llegue al final findEndOfFile... feof
        {
            fgets(bufferIn,100,fp); //100 es hasta donde puede leer
            puts(bufferIn); //printf sin formato
        }
    }
    //los archivos trabajan con señaladores en el archivo, cada vez que leo una linea o abro el archivo para recrrerlo
    //ese señalador queda marcando el final de la lectura, al final del primer fgets, y el siguiente leera los iguiente.
    //El acceso al archivo es secuencial, leo 1ro, leo 2do y asi
    //es mas facil y inexpensive usar los datos en memoria, y no tocar el texto en si mientras tanto.
    */





    /*FILE* pArchivo; //puntero al archivo
    char cadena[50]="hola ";

    //archivo binario es rb o wb
    pArchivo = fopen("archivo.txt","w"); //abro para leer - devuelve un puntero a FILE, si pudo abrir archivo
    //si no lo pudo abrir, devuelve NULL. por lo tanto hay que hacer un chequeo de nulidad(? para que no crashee

    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"%s %d",cadena,156); //esto guarda el 156 porque hay un %d, lo toma como valor
        //si al fprintf le paso un entero como variable (pArchivo,x); va a crashear pues pasa cadenas.
        fclose(pArchivo);
        printf("Guardado!");
    }
    else
    {
        printf("Imposible guardar");
    }


    pArchivo = fopen("archivo.txt","r");

    if(pArchivo!=NULL)
    {
        ///El indicador se puede ir modificando, de acuerdo a la necesidad del programa.
        ///usaremos leo archivo, traigo a memoria, proceso info en memoria ram, y vuelco en archivo o vuelvo a crearlo
        ///otra forma es usar las cosas en disco, pero es otro modo de programar.
        ///acceso a disco es mas caro q acceso a memoria
        while(!feof(pArchivo))//FIND END OF FILE
        {
        fgets(cadena,50,pArchivo);//LEE POR LINEAS, se ejecuta hasta encontrar el indicador/señalador de fin de str (\n)
        puts(cadena);
        }
        fclose(pArchivo);
    }
    else
    {
        printf("Imposible leer");
    }
    */


        /* FILE* miArchivo;
    int numero = 64; //si guardo este entero en archivo de texto, como entero me genera error de compilacion

    miArchivo = fopen("prueba1.txt","w");

    fwrite(&numero,sizeof(int),1,miArchivo);
    // origen del dato (ref, dir de memoria o puntero)
    //sizeof(int) devuelve el peso en bytes del dato (p/arq donde se ejecuta)
    //en caso de windows 64 bits, devuelve un 4
    //en caso de windows xp viejo, devuelve 2 (entonces, si le paso un nro en vez de sizeofint, va a creer que
    //queremos ingresar el tamaño de DOS ENTEROS en vez de uno solo. por eso, siempre usamos sizeof.
    //si ponemos (&numero,4,1,miArchivo)y la arquitectura cambia, el programa se vuelve OBSOLETO.
    //despues recibe la cantidad de enteros que queremos pasar. si es 1, sera uno, si dos etc.
    fclose(miArchivo);*/

    /*miArchivo=fopen("prueba1.txt","r");//para leer

    fread(&numero,sizeof(int),1,miArchivo); //recibe LO MISMO que fwrite, pero con destino y origen al reves
    //lee entero, se lo pasa a un entero, y lo devuelve como entero!
    fclose(miArchivo);
    printf("NUMERO: %d", numero);
    */
}

    FILE* miArchivo;
    int i=0;
    int numero;
    int lista[5]={1,5,9,6,4};

    miArchivo = fopen("prueba1.txt","w");

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);  //aca pedimos numero para guardar en el archivo.
        fwrite(&numero,sizeof(int),1,miArchivo);
        //aca no estamos trabajando en memoria, estamos grabando dato por dato en tiempo real.
    }
    fclose(miArchivo);


    miArchivo = fopen("prueba1.txt","r");
    i=0;
    while(!feof(miArchivo))
    {
        //fread(&numero,sizeof(int),1,miArchivo);
        fread(&lista[i],sizeof(int),1,miArchivo);
        //accede a cada numero y lo muestra en pantalla secuencialmente
        //printf("%d\n",numero);
        if(feof(miArchivo))
            break;


        i++;
    }

    fclose(miArchivo);

    //hay casos donde el feof no se da cuenta que llego al final del archivo porque el dato coincide.
    //entonces hay un dato extra! itera una vez mas. se corrige dentro del while con un if.

    for(i=0; i<5; i++)
    {

        printf("%d\n",lista[i]);

    }

    return 0;
}
