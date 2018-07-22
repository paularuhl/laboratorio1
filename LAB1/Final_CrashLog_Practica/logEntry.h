#ifndef LOGENTRY_H_INCLUDED
#define LOGENTRY_H_INCLUDED
#include "ArrayList.h"

struct S_LogEntry
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];
};
typedef struct S_LogEntry LogEntry;

LogEntry* log_newStruct();

void log_setDate(LogEntry* l, char* aux);
void log_setTime(LogEntry* l, char* aux);
void log_setMsg(LogEntry* l, char* aux);
void log_setServiceId(LogEntry* l, int aux);
void log_setGravedad(LogEntry* l, int aux);

char* log_getDate (LogEntry* l);
char* log_getTime (LogEntry* l);
char* log_getMsg (LogEntry* l);
int log_getServiceId(LogEntry* l);
int log_getGravedad(LogEntry* l);


#endif // LOGENTRY_H_INCLUDED
