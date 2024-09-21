
#ifndef intDListisImported
    #define intDListisImported
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




typedef struct intDNode
{
    int Value;
    struct intDNode *Previous;
    struct intDNode *Next;
} intDNode;

typedef struct intDList
{
    struct intDNode *H;
    struct intDNode *T;
    int length;
} intDList;



void funcintDNodeInit (intDNode *pDNode)
{
    pDNode->Value = 0;
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
}

intDNode* funcintDNodeCreate (int value)
{

    intDNode *vpNew = (intDNode *) malloc(sizeof(intDNode));
    if ( vpNew==NULL )
    {
        printf ("The Allocation has failled !!!");
        exit (1);
    }

    funcintDNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
}

intDNode* funcintDNodePointer (intDList DList, int index)
{
    intDNode *vpCn;
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

void funcintDNodeFree (intDNode *pDNode)
{
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
    pDNode->Value = 0;
    free (pDNode);
}



void funcintDListInit (intDList *pDList)
{
    pDList->H = NULL;
    pDList->T = NULL;
    pDList->length = 0;
}

bool funcintDListEmpty (intDList pDList)
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


// do not have a dependency
void funcintDListInsert (intDList *pDList, int index, int value)
{

    intDNode *vpNew;
    intDNode *vpTemp;
    intDNode *vpCn;
    int viCn;


    
    if ( 0<=index )
    {
        
        if ( (*pDList).length<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpNew = funcintDNodeCreate (value);

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


        vpNew = funcintDNodeCreate (value);

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

void funcintDListInsertBegin (intDList *pDList, int value)
{
    funcintDListInsert (pDList, 0, value);   //&(*pintDList)
}

void funcintDListInsertEnd (intDList *pDList, int value)
{
    funcintDListInsert (pDList, pDList->length, value);     // &(*pDList), (*pDList).length
}

/*
void funcintDListInsertBegin (intDList *pDList, int value)
{

    intDNode *vp;
    intDNode *vpTemp;

    vp = funcintDNodeCreate (value);
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
void funcintDListInsertEnd (intDList *pDList, int value)
{

    intDNode *vp;
    intDNode *vpTemp;

    vp = funcintDNodeCreate(value);
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


int funcintDListat (intDList DList, int index)
{

    intDNode *vpCn;
    intDNode *vp;
    int viCn = 0;



    vp = funcintDNodePointer (DList, index);

    return vp->Value;
}

int funcintDListIndex (intDList DList, int value)
{

    intDNode *vpCn;
    int viCn;

    vpCn = DList.H;
    for ( viCn=0; viCn<DList.length; viCn++ )
    {
        if ( vpCn->Value == value )
        {
            return viCn;
        }
        
        vpCn = vpCn->Next;
    }

    printf ("The Number %d do not exist in the DList !!!", value);
    exit(1);
}

int funcintDListCount (intDList DList, int value)
{
    
    intDNode *vpCn = DList.H;
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

void funcintDListModify (intDList *pDList, int index, int value)
{

    intDNode *vp = funcintDNodePointer (*pDList, index);

    vp->Value = value;
}


void funcintDListRemove (intDList *pDList, int index)
{

    intDNode *vp;
    intDNode *vpTemp;



    vp = funcintDNodePointer (*pDList, index);



    if ( (*pDList).length==1 )
    {
        vpTemp = vp;
        (*pDList).H = NULL;
        (*pDList).T = NULL;

        funcintDNodeFree (vpTemp);
    }
    else
    {
        if ( vp==(*pDList).H )
        {
            vpTemp = (*pDList).H;
            (*pDList).H = (*pDList).H->Next;

            (*pDList).H->Previous = NULL;
            funcintDNodeFree (vpTemp);
        }
        else if ( vp==(*pDList).T )
        {
            vpTemp = (*pDList).T;
            (*pDList).T = (*pDList).T->Previous;

            (*pDList).T->Next = NULL;
            funcintDNodeFree (vpTemp);
        }
        else
        {
            vpTemp = vp;

            vpTemp->Previous->Next = vpTemp->Next;
            vpTemp->Next->Previous = vpTemp->Previous;
            funcintDNodeFree (vpTemp);
        }
    }





    (*pDList).length--;
}

void funcintDListRemoveBegin (intDList *pDList)
{
    funcintDListRemove (pDList, 0);  // &(*pDList)
}

void funcintDListRemoveEnd (intDList *pDList)
{
    funcintDListRemove (pDList, pDList->length-1);  // &(*pDList), (*pDList).length-1
}

/*
void funcintDListRemoveBegin (intDList *pDList)
{
    
    intDNode *vpTemp;

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

        functintDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pDList).H;
        (*pDList).H = (*pDList).H->Next;

        (*pDList).H->Previous = NULL;
        funcintDNodeFree (vpTemp);    
    }



    (*pDList).length--;
}
*/

/*
void funcintDListRemoveEnd (intDList *pDList)
{
    
    intDNode *vpTemp;
    

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

        funcintDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pDList).T;
        (*pDList).T = (*pDList).T->Previous;

        (*pDList).T->Next = NULL;
        funcintDNodeFree (vpTemp);
    }
    



    (*pDList).length--;
}
*/


void funcintDListClear (intDList *pDList)
{

    while ( (*pDList).length>0 )
    {
        funcintDListRemove (pDList, 0);  // &(*pDList)
    }
}

/*
void funcintDListClear (intDList *pDList)
{


    intDNode *vpCn;
    intDNode *vpTemp;


    vpCn = (*pDList).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;
        vpCn = vpCn->Next;

        funcintDNodeFree (vpTemp);
    }


    (*pDList).H = NULL;
    (*pDList).T = NULL;
    (*pDList).length = 0;
}
*/


intDList funcintDListUnion (intDList DList1, intDList DList2)
{
    intDList vdlList;
    funcintDListInit (&vdlList);

    intDNode *vpCn1, *vpCn2, *vpCn3;
    int viHolder;
    bool vbFound;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        viHolder = vpCn1->Value;

        vbFound = false;
        vpCn3 = vdlList.H;
        while ( vpCn3!=NULL )
        {
            if ( viHolder==vpCn3->Value )
            {
                vbFound = true;
                break;
            }

            vpCn3 = vpCn3->Next;
        }

        if (!vbFound)
        {
            funcintDListInsertEnd (&vdlList, viHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    vpCn2 = DList2.H;
    while ( vpCn2!=NULL )
    {
        viHolder = vpCn2->Value;

        vbFound = false;
        vpCn3 = vdlList.H;
        while ( vpCn3!=NULL )
        {
            if ( viHolder == vpCn3->Value )
            {
                vbFound = true;
            }

            vpCn3 = vpCn3->Next;
        }

        if (!vbFound)
        {
            funcintDListInsertEnd (&vdlList, viHolder);
        }
        
        vpCn2 = vpCn2->Next;
    }

    return vdlList;
}

intDList funcintDListIntersection (intDList DList1, intDList DList2)
{
    intDList vdlList;
    funcintDListInit (&vdlList);

    intDNode *vpCn1, *vpCn2;
    bool vbFound;
    int viHolder;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        viHolder = vpCn1->Value;

        vbFound = false;
        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( viHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }
            vpCn2 = vpCn2->Next;
        }

        if ( vbFound )
        {
            funcintDListInsertEnd (&vdlList, viHolder);
        }
        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}

intDList funcintDListDifference (intDList DList1, intDList DList2)
{
    intDList vdlList;
    funcintDListInit (&vdlList);

    intDNode *vpCn1, *vpCn2;
    int viHolder1;
    bool vbFound;

    vpCn1 = DList1.H;

    while ( vpCn1!=NULL )
    {
        viHolder1 = vpCn1->Value;
        vbFound = false;

        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value==viHolder1 )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funcintDListInsertEnd (&vdlList, viHolder1);
        }

        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}

/*
intDList funcintDListSymmetricDifference (intDList DList1, intDList DList2)
{
    intDList vdlIntersection, vdlUnion, vdlSymmDiff;
    funcintDListInit (&vdlIntersection);
    funcintDListInit (&vdlUnion);
    funcintDListInit (&vdlSymmDiff);

    vdlIntersection = funcintDListIntersection (DList1, DList2);
    vdlUnion = funcintDListUnion (DList1, DList2);
    vdlSymmDiff = funcintDListDifference (vdlUnion, vdlIntersection);
    
    return vdlSymmDiff;
}
*/
intDList funcintDListSymmetricDifference (intDList DList1, intDList DList2)
{
    intDList vdlList;
    funcintDListInit (&vdlList);

    intDNode *vpCn1, *vpCn2;
    int viHolder;
    bool vbFound;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        viHolder = vpCn1->Value;

        vbFound = false; 
        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( viHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funcintDListInsertEnd (&vdlList, viHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    vpCn1 = DList2.H;
    while ( vpCn1!=NULL )
    {
        viHolder = vpCn1->Value;

        vbFound = false; 
        vpCn2 = DList1.H;
        while ( vpCn2!=NULL )
        {
            if ( viHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funcintDListInsertEnd (&vdlList, viHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}



int funcQuerryInt ()
{

    int viNum1;
    printf ("Enter the value: ");
    scanf ("%d", &viNum1);

    return viNum1;
}

void funcintDListCreateFIFO (intDList *pDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++ )
    {
        viValue = funcQuerryInt ();
        funcintDListInsertEnd (pDList, viValue); // &(*pDList)
    }
}

void funcintDListCreateLIFO (intDList *pDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        viValue = funcQuerryInt ();
        funcintDListInsertBegin (pDList, viValue);   // &(*pDList)
    }
}

void funcintDListSort (intDList *pDList)
{
    intDNode *vpCn1, *vpCn2, *vpMin;
    int viMin;

    vpCn1 = (*pDList).H;
    while ( vpCn1!=NULL )
    {
        viMin = vpCn1->Value;
        vpMin = vpCn1;
        vpCn2 = vpCn1->Next;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value<viMin )
            {
                viMin = vpCn2->Value;
                vpMin = vpCn2;
            }

            vpCn2 = vpCn2->Next;
        }
        
        vpMin->Value = vpCn1->Value;
        vpCn1->Value = viMin;

        vpCn1 = vpCn1->Next;
    }
}

void funcintDListSortReversed (intDList *pDList)
{
    intDNode *vpCn1, *vpCn2, *vpMin;
    int viMin;

    vpCn1 = (*pDList).T;
    while ( vpCn1!=NULL )
    {
        viMin = vpCn1->Value;
        vpMin = vpCn1;
        vpCn2 = vpCn1->Previous;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value<viMin )
            {
                viMin = vpCn2->Value;
                vpMin = vpCn2;
            }

            vpCn2 = vpCn2->Previous;
        }
        
        vpMin->Value = vpCn1->Value;
        vpCn1->Value = viMin;

        vpCn1 = vpCn1->Previous;
    }
}


void funcintDListDisplay (intDList DList)
{

    intDNode *vpCn;
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
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
        viCn++;
    }
    
}

/*
void funcintDListDisplay (intDList DList)
{

    intDNode *vpCn;
    int viCn;

    if ( DList.length == 0 )
    {
        printf ("The DList is empty !!!");
        return;
    }

    vpCn = DList.H;
    for ( viCn=0; viCn<DList.length; viCn++ )
    {
        printf ("The value %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }
}
*/

void funcintDListDisplayReversed (intDList DList)
{

    intDNode *vpCn;
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
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Previous;
        viCn++;
    }
}

/*
void funcintDListDisplayReversed (intDList DList)
{
    intDNode *vpCn;
    int viCn;

    if ( DList.length == 0 )
    {
        printf ("The DList is Empty !!!");
        return;
    }

    vpCn = DList.H;
    for ( viCn=0; viCn<DList.length; viCn++ )
    {
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }


}
*/



int main ()
{

    intDList vdlList1, vdlList2, vdlList3;
    funcintDListInit (&vdlList1);
    funcintDListInit (&vdlList2);
    funcintDListInit (&vdlList3);

    printf ("creating list1:\n");
    funcintDListCreateFIFO (&vdlList1, 5);
    printf ("\n\n");

    printf ("Displaying list:\n");
    funcintDListDisplay (vdlList1);
    printf ("\n\n");

    printf ("create list2:\n");
    funcintDListCreateFIFO (&vdlList2, 5);
    printf ("\n\n");

    printf ("Displaying list:\n");
    funcintDListDisplay (vdlList2);
    printf ("\n\n");



    vdlList3 = funcintDListSymmetricDifference (vdlList1, vdlList2);
    printf ("Displaying list:\n");
    funcintDListDisplay (vdlList3);
    printf ("\n\n");
    return 0;
}