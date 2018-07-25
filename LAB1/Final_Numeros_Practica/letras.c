#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "letras.h"
/// CONSTRUCTOR
eLetra* letra_newStruct()
{
    eLetra* aux=(eLetra*)malloc(sizeof(eLetra));
    return aux;
}
/// NUEVO NUM
void letra_new(eLetra* n, int* id, char letra, char* name, int vocal, int consonante)
{
    letra_setId(n,id);
    letra_setLetra(n,letra);
    letra_setName(n,name);
    letra_setVocal(n,vocal);
    letra_setConsonante(n,consonante);
}


/// SETTERS
void letra_setName(eLetra* n, char* aux)
{
    if(n!=NULL&&aux!=NULL)
    {
        strcpy(n->name,aux);
    }
}
void letra_setLetra(eLetra* n, char aux)
{
    if(n!=NULL)
    {
        n->letra=aux;
    }
}
void letra_setVocal(eLetra* n,int aux)
{
    if(n!=NULL)
    {
        n->vocal=aux;
    }
}
void letra_setConsonante(eLetra* n,int aux)
{
    if(n!=NULL)
    {
        n->consonante=aux;
    }
}
void letra_setId(eLetra* n,int* aux)
{
    if(n!=NULL)
    {
        n->id=*aux;
    }
}
/// GETTERS
char* letra_getName (eLetra* n)
{
    char* str=NULL;
    if(n!=NULL)
    {
        str=n->name;
    }
    return str;
}
char letra_getLetra (eLetra* n)
{
    char aux;
    if(n!=NULL)
    {
        aux=n->letra;
    }
    return aux;
}
int letra_getVocal(eLetra* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->vocal;
    }
    return aux;
}
int letra_getConsonante(eLetra* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->consonante;
    }
    return aux;
}
int letra_getId(eLetra* n)
{
    int aux;
    if(n!=NULL)
    {
        aux=n->id;
    }
    return aux;
}
/// CALCULOS
int letra_isVocal(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u')
    {
        ret=1;
    }
    return ret;
}
int letra_isConsonante(eLetra* n)
{
    int ret=0;
    if(!letra_isVocal(n))
    {
        ret=1;
    }
    return ret;
}
int letra_isNumero(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(isdigit(letra))
    {
        ret=1;
    }
    return ret;
}
int letra_isMayus(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(letra<'Z'&&letra>'A')
    {
        ret=1;
    }
    return ret;
}
int letra_isSpace(eLetra* n)
{
    int ret=0;
    char letra=letra_getLetra(n);
    if(isspace(letra))
    {
        ret=1;
    }
    return ret;
}
/// SET CALCULOS
void letra_setCalculos(eLetra* n)
{
    letra_setVocal(n,letra_isVocal(n));
    letra_setConsonante(n,letra_isConsonante(n));
}
/// HACER CALCULOS
void letra_evaluate(ArrayList* lista)
{
    eLetra* n=NULL;
    int i;
    for(i=0; i<al_len(lista); i++)
    {
        n=al_get(lista,i);
        letra_setCalculos(n);
    }
}


void mostrarUnaLetra(eLetra* c)
{
    printf("\n%-3d|%-3c |%-12s|%-5d|%-4d",letra_getId(c),letra_getLetra(c),letra_getName(c),letra_getVocal(c),letra_getConsonante(c));
}

void muestroLetra(eLetra* c)
{
    printf("\n%-3d|%-3c |%5d|%4d",letra_getId(c),letra_getLetra(c),letra_getVocal(c),letra_getConsonante(c));
}
void letra_mostrarLista(ArrayList* lista)
{
    int i;
    eLetra* c;
    if(lista!=NULL)
    {
        if(al_len(lista)!=0)
        {
            printf("ID |Let |    Name    | Voc | Cons");
            for(i=0; i<al_len(lista); i++)
            {
                c=al_get(lista,i);
                mostrarUnaLetra(c);
            }
        }
    }

    vista_finFuncion();
}
void mostrarLista(ArrayList* lista)
{
    int i;
    eLetra* c;
    if(lista!=NULL)
    {
        if(al_len(lista)!=0)
        {
            printf("ID |Let | Voc | Cons");
            for(i=0; i<al_len(lista); i++)
            {
                c=al_get(lista,i);
                muestroLetra(c);
            }
        }
    }

    vista_finFuncion();
}
void nuevaCadena(ArrayList* lista, ArrayList* A,ArrayList* B)
{
    int i,j;
    char cadena[200];
    char letrita;
    eLetra* n;
    if(lista!=NULL)
    {
        string_get("Ingrese cadena: ",cadena);

        for(j=0; j<al_len(lista); j++)
        {
            n=al_get(lista,j);
            letrita=letra_getLetra(n);
            i=0;
            while(cadena[i]!='\0')
            {
                if(letrita==cadena[i])
                {
                    al_add(A,n);
                }
                i++;
            }
        }
       /* for(j=0; j<al_len(lista); j++)
        {
            n=al_get(lista,j);
            letrita=letra_getLetra(n);
            i=0;
            while(cadena[i]!='\0')
            {
                if(letrita!=cadena[i])
                {
                    al_add(A,n);
                }
                i++;
            }
        }*/
    }
   mostrarLista(A);
   mostrarLista(B);
}
/*ArrayList* cadenaB(ArrayList* lista,int* id)
{
    int i,j=0;
    eLetra* n;
    ArrayList* listaB=al_newArrayList();
    char letra;
    ///borro del array abcABC las letras que estan en la lista que ingrese por pantalla
    for(i=0; i<al_len(lista); i++)
    {
        n=al_get(lista,i);
        letra=letra_getLetra(n);
        for(i=0; i<27; i++)
        {
            if(letra==abcABC[i])
            {
                abcABC[i]='1';
            }
        }
    }

///cargo el arraylist con esas letras
        for(i=0; letras[i]!='\0'; i++)
        {
            (*id)++;
            n=letra_newStruct();
            letra_setLetra(n,letras[i]);
            letra_setCalculos(n);
            letra_setId(n,id);
            listaB->add(listaB,n);
        }
    return listaB;
}
*/
