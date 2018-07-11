#include "ArrayList.h"

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    int estado;
}Socio;
#endif // SOCIO_H_INCLUDED

#define SOCIO_ESTADO_ACTIVO 0
#define SOCIO_ESTADO_INACTIVO 1

Socio* soc_new(char* nombre, char* apellido, char* dni, int id, int estado);
int soc_delete(Socio*);
int soc_setNombre(Socio*,char* nombre);
char* soc_getNombre(Socio*);
int soc_setApellido(Socio* this,char* apellido);
char* soc_getApellido(Socio* this);
int soc_setDni(Socio* this,char* dni);
char* soc_getDni(Socio* this);
int soc_setId(Socio* this,int id);
int soc_getId(Socio* this);
int soc_setEstado(Socio* this,int estado);
int soc_getEstado(Socio* this);




Socio* soc_findById(ArrayList*, int);




