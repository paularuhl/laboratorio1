#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    int idMsg;
    int idUser;
    char pop[10];
    char msg[1800];

}post;

post* post_newStruct();

void post_setMsg(post* p, char* aux);
void post_setIdMsg(post* p, int aux);
void post_setIdUser(post* p, int aux);
void post_setPop(post* p, char* aux);

char* post_getMsg (post* p);
int post_getIdMsg (post* p);
int post_getIdUser (post* p);
char* post_getPop (post* p);

int post_compararPop(void* itemA, void* itemB);

#endif // POST_H_INCLUDED
