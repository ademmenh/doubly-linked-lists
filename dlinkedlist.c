
#include <stdio.h>
#include <stdlib.h>





struct intDNode
{
    int Value;
    struct intDNode *Previous;
    struct intDNode *Next;
};

struct intDList
{
    struct intDNode *H;
    struct intDNode *T;
    int length;
};

void fIntDListInit (struct intDList *pintDList)
{
    pintDList->H = NULL;
    pintDList->T = NULL;
    pintDList->length = 0;
}



struct intDNode* fIntDNodeCreate (int value)
{

    struct intDNode *vp = (struct intDNode *) malloc(sizeof(struct intDNode));
    
    
    vp->Value = value;
    vp->Next = NULL;
    vp->Previous = NULL;

    return vp;
}

void fIntDNodeAddbyIndex (struct intDList *pintDList, int index, int value)
{
    
    struct intDNode *vp;
    struct intDNode *vpCn = (*pintDList).H;
    struct intDNode *vpTemp;
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


    vp = fIntDNodeCreate (value);

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

void fIntDNodeAddatBegin (struct intDList *pintDList, int value)
{
    fIntDNodeAddbyIndex (&(*pintDList), 0, value);
}

void fIntDNodeAddatEnd (struct intDList *pintDList, int value)
{
    fIntDNodeAddbyIndex (&(*pintDList), (*pintDList).length, value);
}

/*
void fIntDNodeAddatBegin (struct intDList *pintDList, int value)
{

    struct intDNode *vp;
    struct intDNode *vpTemp;

    vp = fIntDNodeCreate (value);
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
        vpTemp->Previous = vp;
    }



    (*pintDList).length++;
}
*/

/*
void fIntDNodeAddatEnd (struct intDList *pintDList, int value)
{

    struct intDNode *vp = fIntDNodeCreate(value);
    struct intDNode *vpTemp = (*pintDList).T;

    if ( (*pintDList).length==0 )
    {
        (*pintDList).H = vp;
        (*pintDList).T = vp;
    }
    else
    {
        vpTemp = (*pintDList).H;
        (*pintDList).T = vp;

        (*pintDList).T->Previous = vpTemp;
        vpTemp->Next = (*pintDList).T;
    }



    (*pintDList).length++;
}
*/

void fIntDNodeFreebyIndex (struct intDList *pintDList, int index)
{


    int viCn = 0;
    struct intDNode *vpCn;
    struct intDNode *vpTemp;


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

        vpTemp->Next = NULL;
        vpTemp->Previous = NULL;
        vpTemp->Value=0;
        free (vpTemp);

        (*pintDList).H = NULL;
        (*pintDList).T = NULL;
    }
    else
    {
        if ( index==0 )
        {
            vpTemp = (*pintDList).H;
            (*pintDList).H = (*pintDList).H->Next;
            vpTemp->Next->Previous = NULL;

            vpTemp->Next = NULL;
            vpTemp->Previous = NULL;
            vpTemp->Value = 0;
            free(vpTemp);
        }
        else if ( index==(*pintDList).length-1 )
        {

            vpTemp = (*pintDList).T;
            (*pintDList).T = (*pintDList).T->Previous;
            vpTemp->Previous->Next = NULL;

            vpTemp->Next = NULL;
            vpTemp->Previous = NULL;
            vpTemp->Value = 0;
            free (vpTemp);
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
                    
                    vpTemp->Next=NULL;
                    vpTemp->Previous=NULL;
                    vpTemp->Value=0;
                    free (vpTemp);
                    break;
                }
                
                viCn++;
                vpCn = vpCn->Next;
            }
        }
    }
    



    (*pintDList).length--;
}

void fIntDNodeFreeatBegin (struct intDList *pintDList)
{
    fIntDNodeFreebyIndex (&(*pintDList), 0);
}

void fIntDNodeFreeatEnd (struct intDList *pintDList)
{
    fIntDNodeFreebyIndex (&(*pintDList), (*pintDList).length-1);
}

/*
void fIntDNodeFreeatBegin (struct intDList *pintDList)
{
    
    struct intDNode *vpTemp;

    if ( (*pintDList).length==0 )
    {
        printf ("The list is already empty !!!");
        return;
    }


    vpTemp = (*pintDList).H;
    (*pintDList).H = (*pintDList).H->Next;

    (*pintDList).H->Previous = NULL;    

    vpTemp->Next = NULL;
    vpTemp->Previous = NULL;
    vpTemp->Value = 0;
    free (vpTemp);


    (*pintDList).length--;
}
*/

/*
void fINtDNodeFreeatEnd (struct intDList *pintDList)
{
    
    struct intDNode *vpTemp;
    

    if ( (*pintDList).length==0 )
    {
        printf ("The DList is already empty !!!");
        return;
    }
    
    vpTemp = (*pintDList).T;
    (*pintDList).T = (*pintDList).T->Previous;

    (*pintDList).T->Next = NULL;

    vpTemp->Next = NULL;
    vpTemp->Previous = NULL;
    vpTemp->Value = 0;
    free (vpTemp);

    (*pintDList).length--;
}
*/

void fIntDNodeFreeAll (struct intDList *pintDList)
{

    while ( (*pintDList).length>0 )
    {
        fIntDNodeFreebyIndex(&(*pintDList), 0);
    }
}

/*
void fIntDNodeFreeAll (struct intDList *pintDList)
{


    struct intDNode *vpCn;
    struct intDNode *vpTemp;


    vpCn = (*pintDList).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;

        vpTemp->Next = NULL;
        vpTemp->Previous = NULL;
        vpTemp->Value = 0;
        free (vpTemp);
        
        vpCn = vpCn->Next;
    }


    (*pintDList).H = NULL;
    (*pintDList).T = NULL;
    (*pintDList).length = 0;
}
*/

void fIntDListDisplay (struct intDList intDList)
{

    struct intDNode *vpCn = intDList.H;
    int viCn = 1;

    if ( vpCn==NULL )
    {
        printf ("The DList is Empty !!!");
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

void fIntDListDisplayReversed (struct intDList intDList)
{

    struct intDNode *vpCn=intDList.T;
    int viCn = 1;

    if ( vpCn==NULL )
    {
        printf ("The Dlist is empty !!!");
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





int fQuerryInt ()
{

    int viNum1;
    printf ("Enter the value: ");
    scanf ("%d", &viNum1);

    return viNum1;
}

void fIntDListCreateFIFO (struct intDList *pintDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++ )
    {
        viValue = fQuerryInt ();
        fIntDNodeAddatEnd (&(*pintDList), viValue);
    }
}

void fIntDListCreateLIFO (struct intDList *pintDList, int DListSize)
{

    int viValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        viValue = fQuerryInt ();
        fIntDNodeAddatBegin (&(*pintDList), viValue);
    }
}



int main ()
{
    
    // clear the terminal
    system ("cls");





    struct intDList dliList1;
    fIntDListInit (&dliList1);



    printf ("\n");
    fIntDListCreateFIFO (&dliList1, 5);
    printf ("\n\n");
    
    printf ("Displaying the DList:\n");
    fIntDListDisplay (dliList1);
    printf ("\n\n");
    
    printf ("Displaying the DList in reversed:\n");
    fIntDListDisplayReversed (dliList1);
    printf ("\n\n");

    printf ("adding by index:\n");
    fIntDNodeAddbyIndex (&dliList1, 0, 0);
    fIntDNodeAddbyIndex (&dliList1, 1, 1);
    printf ("\n\n");
    
    printf ("Displaying the DList:\n");
    fIntDListDisplay (dliList1);
    printf ("\n\n");

    printf ("Displaying the DList in reversed:\n");
    fIntDListDisplayReversed (dliList1);
    printf ("\n\n");

    printf ("Removing by index:\n");
    fIntDNodeFreebyIndex (&dliList1, 0);
    fIntDNodeFreebyIndex (&dliList1, 0);
    printf ("\n\n");

    printf ("Displaying the DList:\n");
    fIntDListDisplay (dliList1);
    printf ("\n\n");
    


    printf ("Removing all DNodes:\n");
    fIntDNodeFreeAll (&dliList1);
    printf ("\n\n");

    printf ("Displaying the DList:\n");
    fIntDListDisplay (dliList1);
    printf ("\n\n");





    return 0;
}