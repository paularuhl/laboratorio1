#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"
#include "vista.h"
#include "service.h"
#include "logEntry.h"


void ser_parseIn(ArrayList* l,char filename[]);
void log_parseIn(ArrayList* l,char filename[]);
void warnings_parseOut(ArrayList* log, ArrayList* ser);
void errors_parseOut(ArrayList* log, ArrayList* ser);




#endif // LIB_H_INCLUDED
