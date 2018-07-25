#ifndef FEEDITEM_H_INCLUDED
#define FEEDITEM_H_INCLUDED
#include "ArrayList.h"
#include "post.h"
#include "user.h"

typedef struct{

    int idUser;
    char popU[10];
    char nick[40];
    int idMsg;
    char popM[10];
    char msg[1800];

}feedItem;

char* feedItem_getNick (feedItem* f);
char* feedItem_getMsg (feedItem* f);
char* feedItem_getUserPop (feedItem* f);
char* feedItem_getMsgPop (feedItem* f);
int feedItem_getIdUser (feedItem* f);
int feedItem_getIdMsg (feedItem* f);

void feedItem_setNick(feedItem* f, char* aux);
void feedItem_setMsg(feedItem* f, char* aux);
void feedItem_setUserPop(feedItem* f, char* aux);
void feedItem_setMsgPop(feedItem* f, char* aux);
void feedItem_setIdUser(feedItem* f, int aux);
void feedItem_setIdMsg(feedItem* f, int aux);

feedItem* feedItem_newStruct();
void feedItem_new(feedItem* f, int idMsg, char* msg, char* popM, int idUser, char* nick, char* popU);
void feed_crear(ArrayList* usuarios, ArrayList* mensajes, ArrayList* feed);

ArrayList* feed_doubleSort(ArrayList* this);

#endif // FEEDITEM_H_INCLUDED

