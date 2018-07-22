#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "ArrayList.h"

struct S_Service
{
    int id;
    char name[33];
    char email[65];

};
typedef struct S_Service Service;

Service* ser_newStruct();
void ser_setEmail(Service* s, char* aux);
void ser_setName(Service* s, char* aux);
void ser_setId(Service* s, int aux);

char* ser_getEmail (Service* s);
char* ser_getName (Service* s);
int ser_getId(Service* s);

#endif // SERVICE_H_INCLUDED
