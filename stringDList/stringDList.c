
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





void funcstringDNodeInit (stringDNode *pDNode)
{
    funcstringInit (&(pDNode->Value));
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
}

stringDNode* funcstringDNodeCreate (string value)
{

    stringDNode *vpNew = (stringDNode *) malloc(sizeof(stringDNode));
    if ( vpNew==NULL )
    {
        printf ("The Allocation has failled !!!");
        exit (1);
    }

    funcstringDNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

stringDNode* funcstringDNodePointer (stringDList DList, int index)
{
    stringDNode *vpCn;
    int viCn;


    if ( 0<=index )
    {
        if ( DList.length-1<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpCn = DList.H;
        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }

        return vpCn;
    }
    else
    {
        if ( DList.length<-index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpCn = DList.T;
        for ( viCn=-1; index<viCn; viCn-- )
        {
            vpCn = vpCn->Previous;
        }

        return vpCn;
    }
}

void funcstringDNodeFree (stringDNode *pDNode)
{
    funcstringClear (&(pDNode->Value));
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
    free (pDNode);
}


