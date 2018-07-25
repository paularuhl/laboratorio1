#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"



void feed_parseOut(ArrayList* lista,char filename[]);
void user_parseIn(ArrayList* l,char filename[]);
void post_parseIn(ArrayList* l,char filename[]);
void user_parseOut(ArrayList* lista,char filename[]);

#endif // PARSER_H_INCLUDED
