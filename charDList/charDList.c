
#define _charDLIST_C

#ifndef _STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif





typedef struct charDNode
{
    char Value;
    struct charDNode *Previous;
    struct charDNode *Next;
} charDNode;

typedef struct charDList
{
    struct charDNode *H;
    struct charDNode *T;
    int length;
} charDList;



void funccharDNodeInit (charDNode *pDNode)
{
    pDNode->Value = 0;
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
}

charDNode* funccharDNodeCreate (char value)
{

    charDNode *vpNew = (charDNode *) malloc(sizeof(charDNode));
    if ( vpNew==NULL )
    {
        printf ("\nThe Allocation has failled !!!");
        exit (1);
    }

    funccharDNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

charDNode* funccharDNodePointer (charDList DList, int index)
{
    charDNode *vpCn;
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

void funccharDNodeFree (charDNode *pDNode)
{
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
    pDNode->Value = 0;
    free (pDNode);
}



void funccharDListInit (charDList *pDList)
{
    pDList->H = NULL;
    pDList->T = NULL;
    pDList->length = 0;
}

bool funccharDListEmpty (charDList DList)
{
    if ( DList.length==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}


// do not have a dependency
void funccharDListInsert (charDList *pDList, int index, char value)
{

    charDNode *vpNew;
    charDNode *vpTemp;
    charDNode *vpCn;
    int viCn;


    
    if ( 0<=index )
    {
        
        if ( (*pDList).length<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpNew = funccharDNodeCreate (value);

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


        vpNew = funccharDNodeCreate (value);

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

void funccharDListInsertBegin (charDList *pDList, char value)
{
    funccharDListInsert (pDList, 0, value);   //&(*pDList)
}

void funccharDListInsertEnd (charDList *pDList, char value)
{
    funccharDListInsert (pDList, pDList->length, value);     // &(*pDList), (*pDList).length
}

/*
void funccharDListInsertBegin (charDList *pDList, char value)
{

    charDNode *vp;
    charDNode *vpTemp;

    vp = funccharDNodeCreate (value);
    if ( (*pDList).length==0 )
    {
        (*pDList).H = vp;
        (*pDList).T = vp;
    }
    else
    {
        vpTemp = (*pDList).H;
        (*pDList).H = vp;

        (*pDList).H->Next = vpTemp;
        vpTemp->Previous = (*pDList).H;
    }



    (*pDList).length++;
}
*/

/*
void funccharDListInsertEnd (charDList *pDList, char value)
{

    charDNode *vp;
    charDNode *vpTemp;

    vp = funccharDNodeCreate(value);
    if ( (*pDList).length==0 )
    {
        (*pDList).H = vp;
        (*pDList).T = vp;
    }
    else
    {
        vpTemp = (*pDList).T;
        (*pDList).T = vp;

        (*pDList).T->Previous = vpTemp;
        vpTemp->Next = (*pDList).T;
    }



    (*pDList).length++;
}
*/


char funccharDListat (charDList pDList, int index)
{

    charDNode *vpCn;
    charDNode *vp;
    int viCn = 0;



    vp = funccharDNodePointer (pDList, index);

    return vp->Value;
}

int funccharDListIndex (charDList pDList, char value)
{

    charDNode *vpCn;
    int viCn;

    vpCn = pDList.H;
    for ( viCn=0; viCn<pDList.length; viCn++ )
    {
        if ( vpCn->Value == value )
        {
            return viCn;
        }
        
        vpCn = vpCn->Next;
    }

    printf ("The Number %c do not exist in the DList !!!", value);
    exit(1);
}

int funccharDListCount (charDList pDList, char value)
{
    
    charDNode *vpCn = pDList.H;
    int viFound = 0;



    while ( vpCn!=NULL )
    {
        if ( value==vpCn->Value )
        {
            viFound ++;
        }

        vpCn = vpCn->Next;
    }

    return viFound;
}

void funccharDListModify (charDList *pDList, int index, char value)
{

    charDNode *vpNew = funccharDNodePointer (*pDList, index);

    vpNew->Value = value;
}


void funccharDListRemove (charDList *pDList, int index)
{

    charDNode *vp;
    charDNode *vpTemp;



    vp = funccharDNodePointer (*pDList, index);



    if ( (*pDList).length==1 )
    {
        vpTemp = vp;
        (*pDList).H = NULL;
        (*pDList).T = NULL;

        funccharDNodeFree (vpTemp);
    }
    else
    {
        if ( vp==(*pDList).H )
        {
            vpTemp = (*pDList).H;
            (*pDList).H = (*pDList).H->Next;

            (*pDList).H->Previous = NULL;
            funccharDNodeFree (vpTemp);
        }
        else if ( vp==(*pDList).T )
        {
            vpTemp = (*pDList).T;
            (*pDList).T = (*pDList).T->Previous;

            (*pDList).T->Next = NULL;
            funccharDNodeFree (vpTemp);
        }
        else
        {
            vpTemp = vp;

            vpTemp->Previous->Next = vpTemp->Next;
            vpTemp->Next->Previous = vpTemp->Previous;
            funccharDNodeFree (vpTemp);
        }
    }





    (*pDList).length--;
}

void funccharDListRemoveBegin (charDList *pDList)
{
    funccharDListRemove (pDList, 0);  // &(*pDList)
}

void funccharDListRemoveEnd (charDList *pDList)
{
    funccharDListRemove (pDList, pDList->length-1);  // &(*pDList), (*pDList).length-1
}

/*
void funccharDListRemoveBegin (charDList *pDList)
{

    charDNode *vpTemp;

    if ( (*pDList).length==0 )
    {
        printf ("The list is already empty !!!");
        return;
    }


    if ( (*pDList).length==1 )
    {
        vpTemp = (*pDList).H;
        (*pDList).H = NULL;
        (*pDList).T = NULL;

        funccharDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pDList).H;
        (*pDList).H = (*pDList).H->Next;

        (*pDList).H->Previous = NULL;
        funccharDNodeFree (vpTemp);    
    }



    (*pDList).length--;
}
*/

/*
void funccharDListRemoveEnd (charDList *pDList)
{
    
    charDNode *vpTemp;
    

    if ( (*pDList).length==0 )
    {
        printf ("The DList is already empty !!!");
        return;
    }

    if ( (*pDList.length==1) )
    {
        vpTemp = (*pDList).H;
        (*pDList).H = NULL;
        (*pDList).T = NULL;

        funccharDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pDList).T;
        (*pDList).T = (*pDList).T->Previous;

        (*pDList).T->Next = NULL;
        funccharDNodeFree (vpTemp);
    }
    



    (*pDList).length--;
}
*/


void funccharDListClear (charDList *pDList)
{

    while ( (*pDList).length>0 )
    {
        funccharDListRemove (pDList, 0);  // &(*pDList)
    }
}

/*
void funccharDListClear (charDList *pDList)
{


    charDNode *vpCn;
    charDNode *vpTemp;


    vpCn = (*pDList).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;
        vpCn = vpCn->Next;

        funccharDNodeFree (vpTemp);
    }


    (*pDList).H = NULL;
    (*pDList).T = NULL;
    (*pDList).length = 0;
}
*/



charDList funccharDListUnion (charDList DList1, charDList DList2)
{
    charDList vdlList;
    funccharDListInit (&vdlList);

    charDNode *vpCn1, *vpCn2, *vpCn3;
    char vcHolder;
    bool vbFound;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        vcHolder = vpCn1->Value;

        vbFound = false;
        vpCn3 = vdlList.H;
        while ( vpCn3!=NULL )
        {
            if ( vcHolder==vpCn3->Value )
            {
                vbFound = true;
                break;
            }

            vpCn3 = vpCn3->Next;
        }

        if (!vbFound)
        {
            funccharDListInsertEnd (&vdlList, vcHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    vpCn2 = DList2.H;
    while ( vpCn2!=NULL )
    {
        vcHolder = vpCn2->Value;

        vbFound = false;
        vpCn3 = vdlList.H;
        while ( vpCn3!=NULL )
        {
            if ( vcHolder == vpCn3->Value )
            {
                vbFound = true;
            }

            vpCn3 = vpCn3->Next;
        }

        if (!vbFound)
        {
            funccharDListInsertEnd (&vdlList, vcHolder);
        }
        
        vpCn2 = vpCn2->Next;
    }

    return vdlList;
}

charDList funccharDListIntersection (charDList DList1, charDList DList2)
{
    charDList vdlList;
    funccharDListInit (&vdlList);

    charDNode *vpCn1, *vpCn2;
    bool vbFound;
    char vcHolder;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        vcHolder = vpCn1->Value;

        vbFound = false;
        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( vcHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }
            vpCn2 = vpCn2->Next;
        }

        if ( vbFound )
        {
            funccharDListInsertEnd (&vdlList, vcHolder);
        }
        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}

charDList funccharDListDifference (charDList DList1, charDList DList2)
{
    charDList vdlList;
    funccharDListInit (&vdlList);

    charDNode *vpCn1, *vpCn2;
    char vcHolder;
    bool vbFound;

    vpCn1 = DList1.H;

    while ( vpCn1!=NULL )
    {
        vcHolder = vpCn1->Value;
        vbFound = false;

        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value==vcHolder )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funccharDListInsertEnd (&vdlList, vcHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}

charDList funccharDListSymmetricDifference (charDList DList1, charDList DList2)
{
    charDList vdlList;
    funccharDListInit (&vdlList);

    charDNode *vpCn1, *vpCn2;
    char vcHolder;
    bool vbFound;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        vcHolder = vpCn1->Value;

        vbFound = false; 
        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( vcHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funccharDListInsertEnd (&vdlList, vcHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    vpCn1 = DList2.H;
    while ( vpCn1!=NULL )
    {
        vcHolder = vpCn1->Value;

        vbFound = false; 
        vpCn2 = DList1.H;
        while ( vpCn2!=NULL )
        {
            if ( vcHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funccharDListInsertEnd (&vdlList, vcHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}


#ifndef _func_CHARINPUT
    char funccharInput ()
    {

        char vcChar, vcBuffer;

        printf ("Enter the value: ");
        vcChar = getchar(); // fgetc (stdin)
        vcBuffer = vcChar;
        while (vcBuffer!='\n')
        {vcBuffer = getchar();}

        return vcChar;
    }
#endif

void funccharDListCreateFIFO (charDList *pDList, int DListSize)
{

    char vcValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++ )
    {
        vcValue = funccharInput ();
        funccharDListInsertEnd (pDList, vcValue); // &(*pDList)
    }
}

void funccharDListCreateLIFO (charDList *pDList, int DListSize)
{

    char vcValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        vcValue = funccharInput ();
        funccharDListInsertBegin (pDList, vcValue);   // &(*pDList)
    }
}


void funccharDListDisplay (charDList DList)
{

    charDNode *vpCn;
    int viCn;

    
    if ( DList.length==0 )
    {
        printf ("The DList is Empty !!!\n");
        return;
    }
    
    vpCn = DList.H;
    viCn = 0;
    while (vpCn!=NULL)
    {
        printf ("The value n %d is: %c.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
        viCn++;
    }
    
}

/*
void funccharDListDisplay (charDList DList)
{

    charDNode *vpCn;
    int viCn;

    if ( DList.length == 0 )
    {
        printf ("The DList is empty !!!");
        return;
    }

    vpCn = DList.H;
    for ( viCn=0; viCn<DList.length; viCn++ )
    {
        printf ("The value %d is: %c.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }
}
*/

void funccharDListDisplayReversed (charDList DList)
{

    charDNode *vpCn;
    int viCn;

    if ( DList.length==0 )
    {
        printf ("The Dlist is empty !!!\n");
        return;
    }
    
    
    vpCn = DList.T;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: %c.\n", viCn, vpCn->Value);
        vpCn = vpCn->Previous;
        viCn++;
    }
}

/*
void funccharDListDisplayReversed (charDList DList)
{
    charDNode *vpCn;
    int viCn;

    if ( intDList.length == 0 )
    {
        printf ("The DList is Empty !!!");
        return;
    }

    vpCn = DList.H;
    for ( viCn=0; viCn<DList.length; viCn++ )
    {
        printf ("The value n %d is: %c.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }

}
*/
