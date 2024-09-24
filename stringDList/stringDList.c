
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



void funcstringDListInit (stringDList *pDList)
{
    pDList->H = NULL;
    pDList->T = NULL;
    pDList->length = 0;
}

bool funcstringDListEmpty (stringDList pDList)
{
    if ( pDList.length==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void funcstringDListInsert (stringDList *pDList, int index, string value)
{

    stringDNode *vpNew;
    stringDNode *vpTemp;
    stringDNode *vpCn;
    int viCn;


    
    if ( 0<=index )
    {
        
        if ( (*pDList).length<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpNew = funcstringDNodeCreate (value);

        if ( (*pDList).length==0 )
        {
            (*pDList).H = vpNew;
            (*pDList).T = vpNew;
        }
        else
        {
            if ( index==0 )
            {
                vpTemp = (*pDList).H;
                (*pDList).H = vpNew;

                (*pDList).H->Next = vpTemp;
                vpTemp->Previous = (*pDList).H;
            }
            else if ( index==(*pDList).length )
            {
                vpTemp = (*pDList).T;
                (*pDList).T = vpNew;

                (*pDList).T->Previous = vpTemp;
                vpTemp->Next = (*pDList).T;
            }
            else
            {

                vpCn = (*pDList).H;
                for ( viCn=0; viCn<index; viCn++ )
                {
                    vpCn = vpCn->Next;
                }
                vpTemp = vpCn;


                vpNew->Next = vpTemp;
                vpNew->Previous = vpTemp->Previous;

                vpTemp->Previous->Next = vpNew;
                vpTemp->Previous = vpNew;
            }
        }
    }
    else
    {
        if ( (*pDList).length+1<-index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }


        vpNew = funcstringDNodeCreate (value);

        if ( (*pDList).length==0 )
        {
            (*pDList).H = vpNew;
            (*pDList).T = vpNew;
        }
        else
        {
            if ( index==-1 )
            {
                vpTemp = (*pDList).T;
                (*pDList).T = vpNew;

                (*pDList).T->Previous = vpTemp;
                vpTemp->Next = (*pDList).T;
            }
            else if ( index==-((*pDList).length)-1 )
            {
                vpTemp = (*pDList).H;
                (*pDList).H = vpNew;

                (*pDList).H->Next = vpTemp;
                vpTemp->Previous = (*pDList).H;
            }
            else
            {
                vpCn = (*pDList).T;
                for ( viCn=-1; index<viCn; viCn-- )
                {
                    vpCn = vpCn->Previous;
                }
                vpTemp = vpCn;

                vpNew->Previous = vpTemp;
                vpNew->Next = vpTemp->Next;

                vpTemp->Next->Previous = vpNew;
                vpTemp->Next = vpNew;
            }
        }
    }
        



    (*pDList).length++;
}


void funcstringDListInsertBegin (stringDList *pDList, string value)
{
    funcstringDListInsert (pDList, 0, value);   //&(*pintDList)
}

void funcstringDListInsertEnd (stringDList *pDList, string value)
{
    funcstringDListInsert (pDList, -1, value);     // &(*pDList), pDList->length
}

string funcstringDListat (stringDList DList, int index)
{

    stringDNode *vpCn;
    stringDNode *vp;
    int viCn = 0;



    vp = funcstringDNodePointer (DList, index);

    return vp->Value;
}
