
#include <stdio.h>
#include <stdlib.h>





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



void funcintDNodeInit (intDNode *pintDNode)
{
    pintDNode->Value = 0;
    pintDNode->Next = NULL;
    pintDNode->Previous = NULL;
}

intDNode* funcintDNodeCreate (int value)
{

    intDNode *vp = (struct intDNode *) malloc(sizeof(struct intDNode));
    if ( vp==NULL )
    {
        printf ("The Allocation has failled !!!");
        exit (1);
    }

    funcintDNodeInit (vp);
    vp->Value = value;

    return vp;
}

intDNode* funcintDNodePointer (intDList intDList, int index)
{
    intDNode *vpCn;
    int viCn;


    if ( 0<=index )
    {
        if ( intDList.length-1<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpCn = intDList.H;
        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }

        return vpCn;
    }
    else
    {
        if ( intDList.length<-index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpCn = intDList.T;
        for ( viCn=-1; index<viCn; viCn-- )
        {
            vpCn = vpCn->Previous;
        }

        return vpCn;
    }
}

/*
intDNode* funcintDNodePointerTesting (intDList intDList, int index)
{

    intDNode *vpCn;
    int viCn;


    if ( 0<=index )
    {
        
        if ( intDList.length-1<index )
        {
            printf ("The index is out the range of the DList !!!");
            return;
        }
        else
        {
            vpCn = intDList.H;
            for ( viCn=0; viCn<index; viCn++ )
            {
                vpCn = vpCn->Next;
            }

            return vpCn;
        }
    }
    else
    {
        if ( intDList.length<-index )
        {
            printf ("The index is out the range of the DList !!!");
            return;
        }
        else
        {
            vpCn = intDList.T;
            for ( viCn=-1; index<viCn; viCn-- )
            {
                vpCn = vpCn->Previous;
            }

            return vpCn;
        }
    }

}
*/

void funcintDNodeFree (intDNode *pintDNode)
{
    pintDNode->Next = NULL;
    pintDNode->Previous = NULL;
    pintDNode->Value = 0;
    free (pintDNode);
}



void funcintDListInit (intDList *pintDList)
{
    pintDList->H = NULL;
    pintDList->T = NULL;
    pintDList->length = 0;
}

// do not have a dependency
void funcintDListInsert (intDList *pintDList, int index, int value)
{

    intDNode *vpNew;
    intDNode *vpTemp;
    intDNode *vpCn;
    int viCn;



    
    if ( 0<=index )
    {
        
        if ( (*pintDList).length<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpNew = funcintDNodeCreate (value);

        if ( (*pintDList).length==0 )
        {
            (*pintDList).H = vpNew;
            (*pintDList).T = vpNew;
        }
        else
        {
            if ( index==0 )
            {
                vpTemp = (*pintDList).H;
                (*pintDList).H = vpNew;

                (*pintDList).H->Next = vpTemp;
                vpTemp->Previous = (*pintDList).H;
            }
            else if ( index==(*pintDList).length )
            {
                vpTemp = (*pintDList).T;
                (*pintDList).T = vpNew;

                (*pintDList).T->Previous = vpTemp;
                vpTemp->Next = (*pintDList).T;
            }
            else
            {
                vpCn = (*pintDList).H;
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
        if ( (*pintDList).length+1<-index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }


        vpNew = funcintDNodeCreate (value);

        if ( (*pintDList).length==0 )
        {
            (*pintDList).H = vpNew;
            (*pintDList).T = vpNew;
        }
        else
        {
            if ( index==-1 )
            {
                vpTemp = (*pintDList).T;
                (*pintDList).T = vpNew;

                (*pintDList).T->Previous = vpTemp;
                vpTemp->Next = (*pintDList).T;
            }
            else if ( index==-((*pintDList).length)-1 )
            {
                vpTemp = (*pintDList).H;
                (*pintDList).H = vpNew;

                (*pintDList).H->Next = vpTemp;
                vpTemp->Previous = (*pintDList).H;
            }
            else
            {
                vpCn = (*pintDList).T;
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
        



    (*pintDList).length++;
}

void funcintDListInsertBegin (intDList *pintDList, int value)
{
    funcintDListInsert (pintDList, 0, value);   //&(*pintDList)
}

void funcintDListInsertEnd (intDList *pintDList, int value)
{
    funcintDListInsert (pintDList, pintDList->length, value);     // &(*pintDList), (*pintDList).length
}

/*
void funcintDListInsertBegin (intDList *pintDList, int value)
{

    intDNode *vp;
    intDNode *vpTemp;

    vp = funcintDNodeCreate (value);
    if ( (*pintDList).length==0 )
    {
        (*pintDList).H = vp;
        (*pintDList).T = vp;
    }
    else
    {
        vpTemp = (*pintDList).H;
        (*pintDList).H = vp;

        (*pintDList).H->Next = vpTemp;
        vpTemp->Previous = (*pintDList).H;
    }



    (*pintDList).length++;
}
*/

/*
void funcintDListInsertEnd (intDList *pintDList, int value)
{

    intDNode *vp;
    intDNode *vpTemp;

    vp = funcintDNodeCreate(value);
    if ( (*pintDList).length==0 )
    {
        (*pintDList).H = vp;
        (*pintDList).T = vp;
    }
    else
    {
        vpTemp = (*pintDList).T;
        (*pintDList).T = vp;

        (*pintDList).T->Previous = vpTemp;
        vpTemp->Next = (*pintDList).T;
    }



    (*pintDList).length++;
}
*/


int funcintDListat (intDList intDList, int index)
{

    intDNode *vpCn;
    intDNode *vp;
    int viCn = 0;



    vp = funcintDNodePointer (intDList, index);

    return vp->Value;
}

int funcintDListIndex (intDList intDList, int value)
{

    intDNode *vpCn;
    int viCn;

    vpCn = intDList.H;
    for ( viCn=0; viCn<intDList.length; viCn++ )
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

int funcintDListCount (intDList intDList, int value)
{
    
    intDNode *vpCn = intDList.H;
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

void funcintDListModify (intDList *pintDList, int index, int value)
{

    intDNode *vp = funcintDNodePointer (*pintDList, index);

    vp->Value = value;
}

void funcintDListRemove (intDList *pintDList, int index)
{

    intDNode *vp;
    intDNode *vpTemp;



    vp = funcintDNodePointer (*pintDList, index);



    if ( (*pintDList).length==1 )
    {
        vpTemp = vp;
        (*pintDList).H = NULL;
        (*pintDList).T = NULL;

        funcintDNodeFree (vpTemp);
    }
    else
    {
        if ( vp==(*pintDList).H )
        {
            vpTemp = (*pintDList).H;
            (*pintDList).H = (*pintDList).H->Next;

            (*pintDList).H->Previous = NULL;
            funcintDNodeFree (vpTemp);
        }
        else if ( vp==(*pintDList).T )
        {
            vpTemp = (*pintDList).T;
            (*pintDList).T = (*pintDList).T->Previous;

            (*pintDList).T->Next = NULL;
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





    (*pintDList).length--;
}

void funcintDListRemoveBegin (intDList *pintDList)
{
    funcintDListRemove (pintDList, 0);  // &(*pintDList)
}

void funcintDListRemoveEnd (intDList *pintDList)
{
    funcintDListRemove (pintDList, pintDList->length-1);  // &(*pintDList), (*pintDList).length-1
}

/*
void funcintDListRemoveBegin (intDList *pintDList)
{
    
    intDNode *vpTemp;

    if ( (*pintDList).length==0 )
    {
        printf ("The list is already empty !!!");
        return;
    }


    if ( (*pintDList).length==1 )
    {
        vpTemp = (*pintDList).H;
        (*pintDList).H = NULL;
        (*pintDList).T = NULL;

        functintDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pintDList).H;
        (*pintDList).H = (*pintDList).H->Next;

        (*pintDList).H->Previous = NULL;
        funcintDNodeFree (vpTemp);    
    }



    (*pintDList).length--;
}
*/

/*
void funcintDListRemoveEnd (intDList *pintDList)
{
    
    intDNode *vpTemp;
    

    if ( (*pintDList).length==0 )
    {
        printf ("The DList is already empty !!!");
        return;
    }

    if ( (*pintDList.length==1) )
    {
        vpTemp = (*pintDList).H;
        (*pintDList).H = NULL;
        (*pintDList).T = NULL;

        funcintDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pintDList).T;
        (*pintDList).T = (*pintDList).T->Previous;

        (*pintDList).T->Next = NULL;
        funcintDNodeFree (vpTemp);
    }
    



    (*pintDList).length--;
}
*/

void funcintDListClear (intDList *pintDList)
{

    while ( (*pintDList).length>0 )
    {
        funcintDListRemove (pintDList, 0);  // &(*pintDList)
    }
}

/*
void funcintDListClear (intDList *pintDList)
{


    intDNode *vpCn;
    intDNode *vpTemp;


    vpCn = (*pintDList).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;
        vpCn = vpCn->Next;

        funcintDNodeFree (vpTemp);
    }


    (*pintDList).H = NULL;
    (*pintDList).T = NULL;
    (*pintDList).length = 0;
}
*/



int funcQuerryInt ()
{

    int viNum1;
    printf ("Enter the value: ");
    scanf ("%d", &viNum1);

    return viNum1;
}

void funcintDListCreateFIFO (intDList *pintDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++ )
    {
        viValue = funcQuerryInt ();
        funcintDListInsertEnd (pintDList, viValue); // &(*pintDList)
    }
}

void funcintDListCreateLIFO (intDList *pintDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        viValue = funcQuerryInt ();
        funcintDListInsertBegin (pintDList, viValue);   // &(*pintDList)
    }
}

void funcintDListDisplay (intDList intDList)
{

    intDNode *vpCn;
    int viCn;

    if ( vpCn==NULL )
    {
        printf ("The DList is Empty !!!\n");
        return;
    }
    
    vpCn = intDList.H;
    viCn = 0;
    while (vpCn!=NULL)
    {
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
        viCn++;
    }
    
}

/*
void funcintDListDisplay (intDList intDList)
{

    intDNode *vpCn;
    int viCn;

    if ( intDList.length == 0 )
    {
        printf ("The DList is empty !!!");
        return;
    }

    vpCn = intDList.H;
    for ( viCn=0; viCn<intDList.length; viCn++ )
    {
        printf ("The value %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }
}
*/

void funcintDListDisplayReversed (intDList intDList)
{

    intDNode *vpCn;
    int viCn;

    if ( vpCn==NULL )
    {
        printf ("The Dlist is empty !!!\n");
        return;
    }
    
    
    vpCn = intDList.T;
    viCn = 0;
    while ( vpCn!=NULL )
    {
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Previous;
        viCn++;
    }
}

/*
void funcintDListDisplayReversed (intDList intDList)
{
    intDNode *vpCn;
    int viCn;

    if ( intDList.length == 0 )
    {
        printf ("The DList is Empty !!!");
        return;
    }

    vpCn = intDList.H;
    for ( viCn=0; viCn<intDList.length; viCn++ )
    {
        printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }


}
*/

void funcintDListSort (intDList *pintDList)
{
    intDNode *vpCn1, *vpCn2, *vpMin;
    int viMin;

    vpCn1 = (*pintDList).H;
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

void funcintDListSortReversed (intDList *pintDList)
{
    intDNode *vpCn1, *vpCn2, *vpMin;
    int viMin;

    vpCn1 = (*pintDList).T;
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

int main ()
{
    
    // clear the terminal
    system ("cls");



    intDList dliList1;
    funcintDListInit (&dliList1);



    printf ("\n");
    funcintDListCreateFIFO (&dliList1, 5);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    printf ("Displaying the DList in reversed:\n");
    funcintDListDisplayReversed (dliList1);
    printf ("\n\n");




    printf ("Sorting Reversed the DList:\n");
    funcintDListSortReversed (&dliList1);
    printf ("\n\n");



    printf ("Displaying the DList after Sorting !!!\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");


    printf ("The count of number 6 is: %d.", funcintDListCount (dliList1, 6));
    printf ("\n\n");



    printf ("adding by index:\n");
    funcintDListInsert (&dliList1, 0, 0);
    funcintDListInsert (&dliList1, 1, 1);
    printf ("\n\n");
    


    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    printf ("Displaying the DList in reversed:\n");
    funcintDListDisplayReversed (dliList1);
    printf ("\n\n");


    int viValue;
    printf ("Display at:\n");
    viValue = funcintDListat (dliList1, 0);
    printf ("the value at index 0 is: %d.\n", viValue);
    viValue = funcintDListat (dliList1, -1);
    printf ("the value at index -1 is: %d.\n", viValue);
    printf ("\n\n");


    int viIndex;
    printf ("Return the First Index: \n");
    viIndex = funcintDListIndex (dliList1, 0);
    printf ("Number 51 first appeared at index: %d.\n", viIndex);
    viIndex = funcintDListIndex (dliList1, 1);
    printf ("Number 52 first appeared at index: %d.\n", viIndex);
    printf ("\n\n");


    printf ("Modify at:");
    funcintDListModify (&dliList1, -1, 100);
    funcintDListModify (&dliList1, -2, 101);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    printf ("Removing by index:\n");
    funcintDListRemove (&dliList1, 0);
    funcintDListRemove (&dliList1, 0);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");
    


    printf ("Removing all DNodes:\n");
    funcintDListClear (&dliList1);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    printf ("adding by index:\n");
    funcintDListInsert (&dliList1, 0, 0);
    funcintDListInsert (&dliList1, 1, 1);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    return 0;
}