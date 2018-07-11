#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaSocios;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);

void cont_init()
{
    nominaSocios = al_newArrayList();
    setNewId(dm_readAll(nominaSocios) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_bajaSocio (int id)
{
    Socio* auxSocio;
    auxSocio=soc_findById(nominaSocios,id);
    if(auxSocio!=NULL)
    {
        soc_setEstado(auxSocio,SOCIO_ESTADO_INACTIVO);
        dm_saveAll(nominaSocios);
    }

    return 0;
}


int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Socio* auxSocio;

    auxSocio=soc_findById(nominaSocios,id);

    if(auxSocio!=NULL)
    {
        soc_setNombre(auxSocio,nombre);
        soc_setApellido(auxSocio,apellido);
        soc_setDni(auxSocio,dni);
        soc_setEstado(auxSocio,estado);
        dm_saveAll(nominaSocios);
    }

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
