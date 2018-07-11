#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"

static ArrayList* nominaSocios;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);

void cont_init()
{
    nominaSocios = al_newArrayList();
    setNewId(0);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    return 0;
}

int cont_bajaSocio (int id)
{
    return 0;
}


int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    return 0;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}


static int getNewId()
{
    return proximoIdSocio++;
}

static int setNewId(int id)
{
    proximoIdSocio = id;
    return 0;
}
