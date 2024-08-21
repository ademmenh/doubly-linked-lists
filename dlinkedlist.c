
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



void funcintDListInit (intDList *pintDList)
{
    pintDList->H = NULL;
    pintDList->T = NULL;
    pintDList->length = 0;
}

void funcintDNodeInit (intDNode *pintDNode)
{
    (*pintDNode).Value = 0;
    (*pintDNode).Next = NULL;
    (*pintDNode).Previous = NULL;
}

void funcintDNodeFree (intDNode *pintDNode)
{
    (*pintDNode).Next = NULL;
    (*pintDNode).Previous = NULL;
    (*pintDNode).Value = 0;
    free (pintDNode);   // free (&(*pintDNode));
}



intDNode* funcintDNodeCreate (int value)
{

    intDNode *vp = (struct intDNode *) malloc(sizeof(struct intDNode));
    funcintDNodeInit (vp);

    vp->Value = value;

    return vp;
}

void funcintDNodeInsert (intDList *pintDList, int index, int value)
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

void funcintDNodeInsertBegin (intDList *pintDList, int value)
{
    funcintDNodeInsert (&(*pintDList), 0, value);
}

void funcintDNodeInsertEnd (intDList *pintDList, int value)
{
    funcintDNodeInsert (&(*pintDList), (*pintDList).length, value);
}

/*
void funcintDNodeInsertBegin (intDList *pintDList, int value)
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
void funcintDNodeInsertEnd (intDList *pintDList, int value)
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



int funcintDNodeat (intDList pintDList, int index)
{
    intDNode *vpCn;
    int viCn;

    if ( 0<=index )
    {
        if ( pintDList.length-1<index )
        {
            printf ("The index is out the range of the DList !!!");
            return;
        }

        vpCn = pintDList.H;
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
            if ( pintDList.length<-index )
            {
                printf ("The index is out the range of the DList !!!");
                return;
            }
        }

        vpCn = pintDList.T;
        for ( viCn=-1; index<viCn; viCn--)
        {
            vpCn = vpCn->Previous;
        }

        return vpCn->Value;
    }
}



void funcintDNodeModify (intDList *pintDList, int index, int value)
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



void funcintDNodeRemove (intDList *pintDList, int index)
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

void funcintDNodeRemoveBegin (intDList *pintDList)
{
    funcintDNodeRemove (&(*pintDList), 0);
}

void funcintDNodeRemoveEnd (intDList *pintDList)
{
    funcintDNodeRemove (&(*pintDList), (*pintDList).length-1);
}

/*
void funcintDNodeRemoveBegin (intDList *pintDList)
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
void funcintDNodeRemoveEnd (intDList *pintDList)
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

void funcintDNodeRemoveAll (struct intDList *pintDList)
{

    while ( (*pintDList).length>0 )
    {
        funcintDNodeRemove (&(*pintDList), 0);
    }
}

/*
void funcintDNodeRemoveAll (intDList *pintDList)
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



void funcintDListDisplay (intDList intDList)
{

    intDNode *vpCn = intDList.H;
    int viCn = 1;

    if ( vpCn==NULL )
    {
        printf ("The DList is Empty !!!\n");
    }
    else
    {
        while (vpCn!=NULL)
        {
            printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
            vpCn = vpCn->Next;
            viCn++;
        }
    }
}

void funcintDListDisplayReversed (intDList intDList)
{

    intDNode *vpCn=intDList.T;
    int viCn = 1;

    if ( vpCn==NULL )
    {
        printf ("The Dlist is empty !!!\n");
    }
    else
    {
        while ( vpCn!=NULL )
        {
            printf ("The value n %d is: %d.\n", viCn, vpCn->Value);
            vpCn = vpCn->Previous;
            viCn++;
        }
    }
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
        funcintDNodeInsertEnd (&(*pintDList), viValue);
    }
}

void funcintDListCreateLIFO (intDList *pintDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        viValue = funcQuerryInt ();
        funcintDNodeInsertBegin (&(*pintDList), viValue);
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



    printf ("adding by index:\n");
    funcintDNodeInsert (&dliList1, 0, 0);
    funcintDNodeInsert (&dliList1, 1, 1);
    printf ("\n\n");
    


    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    printf ("Displaying the DList in reversed:\n");
    funcintDListDisplayReversed (dliList1);
    printf ("\n\n");



    printf ("Display at:");
    printf ("the value at index 0 is: %d.\n", funcintDNodeat (dliList1, 0));
    printf ("the value at index -1 is: %d.\n", funcintDNodeat (dliList1, -1));
    printf ("\n\n");



    printf ("Modify at:");
    funcintDNodeModify (&dliList1, -1, 101);
    funcintDNodeModify (&dliList1, -2, 100);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    printf ("Removing by index:\n");
    funcintDNodeRemove (&dliList1, 0);
    funcintDNodeRemove (&dliList1, 0);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");
    


    printf ("Removing all DNodes:\n");
    funcintDNodeRemoveAll (&dliList1);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    printf ("adding by index:\n");
    funcintDNodeInsert (&dliList1, 0, 0);
    funcintDNodeInsert (&dliList1, 1, 1);
    printf ("\n\n");



    printf ("Displaying the DList:\n");
    funcintDListDisplay (dliList1);
    printf ("\n\n");



    return 0;
}