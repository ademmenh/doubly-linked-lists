
#ifndef _stringDLIST_C
    #define _stringDLIST_C
#endif

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _STRING_C
    #include "string.c"
#endif





typedef struct stringDNode
{
    string Value;
    struct stringDNode *Previous;
    struct stringDNode *Next;
} stringDNode;

typedef struct stringDList
{
    struct stringDNode *H;
    struct stringDNode *T;
    int length;
} stringDList;


