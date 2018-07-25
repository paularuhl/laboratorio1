#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "ArrayList.h"

typedef struct{

    int id;
    char pop[10];
    char nick[40];

}user;

user* user_newStruct();
void user_new(user* u, int id, char* nick, char* pop);

void user_setNick(user* u, char* aux);
void user_setPop(user* u, char* aux);
void user_setId(user* u, int aux);

char* user_getNick (user* u);
char* user_getPop (user* u);
int user_getId (user* u);

int user_compararPop(void* itemA, void* itemB);
int user_compararNick(void* itemA, void* itemB);



#endif // USER_H_INCLUDED
