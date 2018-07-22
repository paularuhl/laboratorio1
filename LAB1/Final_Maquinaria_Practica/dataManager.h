#ifndef DATAMANAGER_H_INCLUDED
#define DATAMANAGER_H_INCLUDED

void parseOut(ArrayList* clientes,ArrayList* alquileres);
int ctes_parseIn(ArrayList* l,char filename[]);
void ctes_parseOut(ArrayList* lista,char filename[]);
int alq_parseIn(ArrayList* l,char filename[]);
void alq_parseOut(ArrayList* lista,char filename[]);

#endif // DATAMANAGER_H_INCLUDED
