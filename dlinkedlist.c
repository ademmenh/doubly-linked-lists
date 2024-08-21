
#include <stdbool.h>
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
    (*pintDNode).Value = 0;
    (*pintDNode).Next = NULL;
    (*pintDNode).Previous = NULL;
}

intDNode* funcintDNodeCreate (int value)
{

    intDNode *vp = (struct intDNode *) malloc(sizeof(struct intDNode));
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

void funcintDNodeFree (intDNode *pintDNode)
{
    (*pintDNode).Next = NULL;
    (*pintDNode).Previous = NULL;
    (*pintDNode).Value = 0;
    free (pintDNode);   // free (&(*pintDNode));
}



void funcintDListInit (intDList *pintDList)
{
    pintDList->H = NULL;
    pintDList->T = NULL;
    pintDList->length = 0;
}

void funcintDListInsert (intDList *pintDList, int index, int value)
{
    
    intDNode *vp;
    intDNode *vpCn = (*pintDList).H;
    intDNode *vpTemp;
    int viCn = 0;


    if ( index<0)
    {
        printf ("The Index is negative !!!");
        return;
    }

    if ( (*pintDList).length<index )
    {
        printf ("The index is bigger than the length of DList !!!");
        return;
    }


    vp = funcintDNodeCreate (value);

    if ( (*pintDList).length==0 ) 
    {
        (*pintDList).H = vp;
        (*pintDList).T = vp;
    }
    else
    {
        if ( index==0 )
        {
            vpTemp = (*pintDList).H;
            (*pintDList).H = vp;

            (*pintDList).H->Next = vpTemp;
            vpTemp->Previous = (*pintDList).H;
        }
        else if ( index==(*pintDList).length )
        {
            vpTemp = (*pintDList).T;
            (*pintDList).T = vp;

            (*pintDList).T->Previous = vpTemp;
            vpTemp->Next = (*pintDList).T;
        }
        else
        {
            while ( vpCn!=NULL )
            {
                if ( viCn==index )
                {
                    vpTemp = vpCn;

                    vp->Next = vpTemp;
                    vp->Previous = vpTemp->Previous;

                    vpTemp->Previous->Next=vp;
                    vpTemp->Previous = vp;
                    break;
                }

                vpCn = vpCn->Next;
                viCn++;
            }
        }
    }



    (*pintDList).length++;
}

void funcintDListInsertBegin (intDList *pintDList, int value)
{
    funcintDListInsert (&(*pintDList), 0, value);
}

void funcintDListInsertEnd (intDList *pintDList, int value)
{
    funcintDListInsert (&(*pintDList), (*pintDList).length, value);
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
    int viCn;


    if ( 0<=index )
    {
        if ( intDList.length-1<index )
        {
            printf ("The index is out the range of the DList !!!");
            return;
        }

        vpCn = intDList.H;
        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }
        
        return vpCn->Value;
    }
    else
    {
        if ( index<0 )
        {
            if ( intDList.length<-index )
            {
                printf ("The index is out the range of the DList !!!");
                return;
            }
        }

        vpCn = intDList.T;
        for ( viCn=-1; index<viCn; viCn--)
        {
            vpCn = vpCn->Previous;
        }

        return vpCn->Value;
    }
}

int funcintDListIndex (intDList intDList, int value)
{

    bool vbFound;
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
}

// int funcintDListcount


void funcintDListModify (intDList *pintDList, int index, int value)
{
    intDNode *vp = funcintDNodePointer (*pintDList, index);

    vp->Value = value;
}

/*
void funcintDListModify (intDList *pintDList, int index, int value)
{
    intDNode *vpCn;
    int viCn;

    if ( 0<=index )
    {
        if ( (*pintDList).length-1<index )
        {
            printf ("The index is out the range of the DList !!!");
            return;
        }

        vpCn = (*pintDList).H;
        for ( viCn=0; viCn<index; viCn++ )
        {
            vpCn = vpCn->Next;
        }
        
        vpCn->Value = value;
    }
    else
    {
        if ( index<0 )
        {
            if ( (*pintDList).length<-index )
            {
                printf ("The index is out the range of the DList !!!");
                return;
            }
        }

        vpCn = (*pintDList).T;
        for ( viCn=-1; index<viCn; viCn--)
        {
            vpCn = vpCn->Previous;
        }

        vpCn->Value = value;
    } 
}
*/

/*
void funcintDListRemove (intDList *pintDList, int index)
{


    int viCn = 0;
    intDNode *vpCn;
    intDNode *vpTemp;


    if ( index<0 )
    {
        printf ("The index is negative !!!");
    }

    if ( (*pintDList).length-1<index )
    {
        printf ("The Index is bigger then the size of the DList !!!");
        return;
    }
    



    if ( (*pintDList).length==1 )
    {
        vpTemp = (*pintDList).H;
        (*pintDList).H = NULL;
        (*pintDList).T = NULL;

        funcintDNodeFree (vpTemp);
    }
    else
    {
        if ( index==0 )
        {
            vpTemp = (*pintDList).H;
            (*pintDList).H = (*pintDList).H->Next;

            (*pintDList).H->Previous = NULL;
            funcintDNodeFree (vpTemp);
        }
        else if ( index==(*pintDList).length-1 )
        {

            vpTemp = (*pintDList).T;
            (*pintDList).T = (*pintDList).T->Previous;

            (*pintDList).T->Next = NULL;
            funcintDNodeFree (vpTemp);
        }
        else
        {
            vpCn = (*pintDList).H;
            while ( vpCn!=NULL )
            {

                if ( viCn==index )
                {
                    vpTemp = vpCn;

                    vpTemp->Previous->Next = vpTemp->Next;
                    vpTemp->Next->Previous = vpTemp->Previous;
                    
                    funcintDNodeFree (vpTemp);
                    break;
                }
                
                viCn++;
                vpCn = vpCn->Next;
            }
        }
    }
    



    (*pintDList).length--;
}
*/

void funcintDListRemoveBegin (intDList *pintDList)
{
    funcintDListRemove (&(*pintDList), 0);
}

void funcintDListRemoveEnd (intDList *pintDList)
{
    funcintDListRemove (&(*pintDList), (*pintDList).length-1);
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


    vpTemp = (*pintDList).H;
    (*pintDList).H = (*pintDList).H->Next;

    (*pintDList).H->Previous = NULL;
    funcintDNodeFree (vpTemp);


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
    
    vpTemp = (*pintDList).T;
    (*pintDList).T = (*pintDList).T->Previous;

    (*pintDList).T->Next = NULL;
    funcintDNodeFree (vpTemp);



    (*pintDList).length--;
}
*/

void funcintDListClear (intDList *pintDList)
{

    while ( (*pintDList).length>0 )
    {
        funcintDListRemove (&(*pintDList), 0);
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

void funcintDListsort (intDList *pintDList)
{
    
}



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
        funcintDListInsertEnd (&(*pintDList), viValue);
    }
}

void funcintDListCreateLIFO (intDList *pintDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        viValue = funcQuerryInt ();
        funcintDListInsertBegin (&(*pintDList), viValue);
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



    printf ("Display at:\n");
    printf ("the value at index 0 is: %d.\n", funcintDListat (dliList1, 0));
    printf ("the value at index -1 is: %d.\n", funcintDListat (dliList1, -1));
    printf ("\n\n");



    printf ("Return the First Index: \n");
    printf ("Number 4 first appeared at index: %d.\n", funcintDListIndex (dliList1, 4));
    printf ("Number 6 first appeared at index: %d.\n", funcintDListIndex (dliList1, 6));
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