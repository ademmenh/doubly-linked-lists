
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





typedef struct floatDNode
{
    float Value;
    struct intDNode *Previous;
    struct intDNode *Next;
} floatDNode;

typedef struct floatDList
{
    struct floatDNode *H;
    struct floatDNode *T;
    int length;
} floatDList;



void funcfloatDNodeInit (floatDNode *pDNode)
{
    pDNode->Value = 0;
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
}

floatDNode* funcfloatDNodeCreate (float value)
{

    floatDNode *vp = (struct floatDNode *) malloc(sizeof(struct floatDNode));
    if ( vp==NULL )
    {
        printf ("\nThe Allocation has failled !!!");
        exit (1);
    }

    funcfloatDNodeInit (vp);
    vp->Value = value;

    return vp;
}

floatDNode* funcfloatDNodePointer (floatDList DList, int index)
{
    floatDNode *vpCn;
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

void funcfloatDNodeFree (floatDNode *pDNode)
{
    pDNode->Next = NULL;
    pDNode->Previous = NULL;
    pDNode->Value = 0;
    free (pDNode);
}



void funcfloatDListInit (floatDList *pfloatDList)
{
    pfloatDList->H = NULL;
    pfloatDList->T = NULL;
    pfloatDList->length = 0;
}

bool funcfloatDListEmpty (floatDList floatDList)
{
    if ( floatDList.length==0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}


// do not have a dependency
void funcfloatDListInsert (floatDList *pfloatDList, int index, float value)
{

    floatDNode *vpNew;
    floatDNode *vpTemp;
    floatDNode *vpCn;
    int viCn;


    
    if ( 0<=index )
    {
        
        if ( (*pfloatDList).length<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpNew = funcfloatDNodeCreate (value);

        if ( (*pfloatDList).length==0 )
        {
            (*pfloatDList).H = vpNew;
            (*pfloatDList).T = vpNew;
        }
        else
        {
            if ( index==0 )
            {
                vpTemp = (*pfloatDList).H;
                (*pfloatDList).H = vpNew;

                (*pfloatDList).H->Next = vpTemp;
                vpTemp->Previous = (*pfloatDList).H;
            }
            else if ( index==(*pfloatDList).length )
            {
                vpTemp = (*pfloatDList).T;
                (*pfloatDList).T = vpNew;

                (*pfloatDList).T->Previous = vpTemp;
                vpTemp->Next = (*pfloatDList).T;
            }
            else
            {

                vpCn = (*pfloatDList).H;
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
        if ( (*pfloatDList).length+1<-index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }


        vpNew = funcfloatDNodeCreate (value);

        if ( (*pfloatDList).length==0 )
        {
            (*pfloatDList).H = vpNew;
            (*pfloatDList).T = vpNew;
        }
        else
        {
            if ( index==-1 )
            {
                vpTemp = (*pfloatDList).T;
                (*pfloatDList).T = vpNew;

                (*pfloatDList).T->Previous = vpTemp;
                vpTemp->Next = (*pfloatDList).T;
            }
            else if ( index==-((*pfloatDList).length)-1 )
            {
                vpTemp = (*pfloatDList).H;
                (*pfloatDList).H = vpNew;

                (*pfloatDList).H->Next = vpTemp;
                vpTemp->Previous = (*pfloatDList).H;
            }
            else
            {
                vpCn = (*pfloatDList).T;
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
        



    (*pfloatDList).length++;
}

void funcfloatDListInsertBegin (floatDList *pfloatDList, float value)
{
    funcintDListInsert (pfloatDList, 0, value);   //&(*pintDList)
}

void funcfloatDListInsertEnd (floatDList *pfloatDList, float value)
{
    funcintDListInsert (pfloatDList, pfloatDList->length, value);     // &(*pintDList), (*pintDList).length
}

/*
void funcfloatDListInsertBegin (floatDList *pfloatDList, float value)
{

    floatDNode *vp;
    floatDNode *vpTemp;

    vp = funcfloatDNodeCreate (value);
    if ( (*pfloatDList).length==0 )
    {
        (*pfloatDList).H = vp;
        (*pfloatDList).T = vp;
    }
    else
    {
        vpTemp = (*pfloatDList).H;
        (*pfloatDList).H = vp;

        (*pfloatDList).H->Next = vpTemp;
        vpTemp->Previous = (*pfloatDList).H;
    }



    (*pfloatDList).length++;
}
*/

/*
void funcfloatDListInsertEnd (floatDList *pfloatDList, float value)
{

    floatDNode *vp;
    floatDNode *vpTemp;

    vp = funcfloatDNodeCreate(value);
    if ( (*pfloatDList).length==0 )
    {
        (*pfloatDList).H = vp;
        (*pfloatDList).T = vp;
    }
    else
    {
        vpTemp = (*pfloatDList).T;
        (*pfloatDList).T = vp;

        (*pfloatDList).T->Previous = vpTemp;
        vpTemp->Next = (*pfloatDList).T;
    }



    (*pfloatDList).length++;
}
*/


float funcfloatDListat (floatDList floatDList, int index)
{

    floatDNode *vpCn;
    floatDNode *vp;
    int viCn = 0;



    vp = funcfloatDNodePointer (floatDList, index);

    return vp->Value;
}

int funcfloatDListIndex (floatDList floatDList, float value)
{

    floatDNode *vpCn;
    int viCn;

    vpCn = floatDList.H;
    for ( viCn=0; viCn<floatDList.length; viCn++ )
    {
        if ( vpCn->Value == value )
        {
            return viCn;
        }
        
        vpCn = vpCn->Next;
    }

    printf ("The Number %f do not exist in the DList !!!", value);
    exit(1);
}

int funcfloatDListCount (floatDList floatDList, float value)
{
    
    floatDNode *vpCn = floatDList.H;
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

void funcintDListModify (floatDList *pfloatDList, int index, float value)
{

    floatDNode *vp = funcfloatDNodePointer (*pfloatDList, index);

    vp->Value = value;
}


void funcfloatDListRemove (floatDList *pfloatDList, int index)
{

    floatDNode *vp;
    floatDNode *vpTemp;



    vp = funcfloatDNodePointer (*pfloatDList, index);



    if ( (*pfloatDList).length==1 )
    {
        vpTemp = vp;
        (*pfloatDList).H = NULL;
        (*pfloatDList).T = NULL;

        funcintDNodeFree (vpTemp);
    }
    else
    {
        if ( vp==(*pfloatDList).H )
        {
            vpTemp = (*pfloatDList).H;
            (*pfloatDList).H = (*pfloatDList).H->Next;

            (*pfloatDList).H->Previous = NULL;
            funcfloatDNodeFree (vpTemp);
        }
        else if ( vp==(*pfloatDList).T )
        {
            vpTemp = (*pfloatDList).T;
            (*pfloatDList).T = (*pfloatDList).T->Previous;

            (*pfloatDList).T->Next = NULL;
            funcfloatDNodeFree (vpTemp);
        }
        else
        {
            vpTemp = vp;

            vpTemp->Previous->Next = vpTemp->Next;
            vpTemp->Next->Previous = vpTemp->Previous;
            funcfloatDNodeFree (vpTemp);
        }
    }





    (*pfloatDList).length--;
}

void funcintDListRemoveBegin (floatDList *pfloatDList)
{
    funcintDListRemove (pfloatDList, 0);  // &(*pfloatDList)
}

void funcintDListRemoveEnd (floatDList *pfloatDList)
{
    funcintDListRemove (pfloatDList, pfloatDList->length-1);  // &(*pfloatDList), (*pfloatDList).length-1
}

/*
void funcfloatDListRemoveBegin (floatDList *pfloatDList)
{
    
    floatDNode *vpTemp;

    if ( (*pfloatDList).length==0 )
    {
        printf ("The list is already empty !!!");
        return;
    }


    if ( (*pfloatDList).length==1 )
    {
        vpTemp = (*pfloatDList).H;
        (*pfloatDList).H = NULL;
        (*pfloatDList).T = NULL;

        funcfloatDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pfloatDList).H;
        (*pfloatDList).H = (*pfloatDList).H->Next;

        (*pfloatDList).H->Previous = NULL;
        funcfloatDNodeFree (vpTemp);    
    }



    (*pfloatDList).length--;
}
*/

/*
void funcfloatDListRemoveEnd (intDList *pintDList)
{
    
    floatDNode *vpTemp;
    

    if ( (*pfloatDList).length==0 )
    {
        printf ("The DList is already empty !!!");
        return;
    }

    if ( (*pfloatDList.length==1) )
    {
        vpTemp = (*pfloatDList).H;
        (*pfloatDList).H = NULL;
        (*pfloatDList).T = NULL;

        funcfloatDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pfloatDList).T;
        (*pfloatDList).T = (*pfloatDList).T->Previous;

        (*pfloatDList).T->Next = NULL;
        funcfloatDNodeFree (vpTemp);
    }
    



    (*pfloatDList).length--;
}
*/


void funcfloatDListClear (floatDList *pfloatDList)
{

    while ( (*pfloatDList).length>0 )
    {
        funcintDListRemove (pfloatDList, 0);  // &(*pintDList)
    }
}

/*
void funcfloatDListClear (floatDList *pfloatDList)
{


    floatDNode *vpCn;
    floatDNode *vpTemp;


    vpCn = (*pfloatDList).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;
        vpCn = vpCn->Next;

        funcfloatDNodeFree (vpTemp);
    }


    (*pfloatDList).H = NULL;
    (*pfloatDList).T = NULL;
    (*pfloatDList).length = 0;
}
*/



int funcQuerryfloat ()
{

    float vfNum1;
    printf ("Enter the value: ");
    scanf ("%f", &vfNum1);

    return vfNum1;
}

void funcintDListCreateFIFO (floatDList *pDList, int DListSize)
{

    float vfValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++ )
    {
        vfValue = funcQuerryfloat ();
        funcintDListInsertEnd (pDList, vfValue); // &(*pDList)
    }
}

void funcintDListCreateLIFO (floatDList *pDList, int DListSize)
{

    float vfValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        vfValue = funcQuerryInt ();
        funcintDListInsertBegin (pDList, vfValue);   // &(*pintDList)
    }
}

void funcintDListSort (floatDList *pDList)
{
    floatDNode *vpCn1, *vpCn2, *vpMin;
    float vfMin;

    vpCn1 = (*pDList).H;
    while ( vpCn1!=NULL )
    {
        vfMin = vpCn1->Value;
        vpMin = vpCn1;
        vpCn2 = vpCn1->Next;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value<vfMin )
            {
                vfMin = vpCn2->Value;
                vpMin = vpCn2;
            }

            vpCn2 = vpCn2->Next;
        }
        
        vpMin->Value = vpCn1->Value;
        vpCn1->Value = vfMin;

        vpCn1 = vpCn1->Next;
    }
}

void funcintDListSortReversed (floatDList *pDList)
{
    floatDNode *vpCn1, *vpCn2, *vpMin;
    float vfMin;

    vpCn1 = (*pDList).T;
    while ( vpCn1!=NULL )
    {
        vfMin = vpCn1->Value;
        vpMin = vpCn1;
        vpCn2 = vpCn1->Previous;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value<vfMin )
            {
                vfMin = vpCn2->Value;
                vpMin = vpCn2;
            }

            vpCn2 = vpCn2->Previous;
        }
        
        vpMin->Value = vpCn1->Value;
        vpCn1->Value = vfMin;

        vpCn1 = vpCn1->Previous;
    }
}


void funcintDListDisplay (floatDList DList)
{

    floatDNode *vpCn;
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
        printf ("The value n %d is: %f.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
        viCn++;
    }
    
}

/*
void funcfloatDListDisplay (floatDList DList)
{

    floatDNode *vpCn;
    int viCn;

    if ( DList.length == 0 )
    {
        printf ("The DList is empty !!!");
        return;
    }

    vpCn = DList.H;
    for ( viCn=0; viCn<DList.length; viCn++ )
    {
        printf ("The value %d is: %f.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }
}
*/

void funcintDListDisplayReversed (floatDList DList)
{

    floatDNode *vpCn;
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
        printf ("The value n %d is: %f.\n", viCn, vpCn->Value);
        vpCn = vpCn->Previous;
        viCn++;
    }
}

/*
void funcintDListDisplayReversed (floatDList DList)
{
    floatDNode *vpCn;
    int viCn;

    if ( intDList.length == 0 )
    {
        printf ("The DList is Empty !!!");
        return;
    }

    vpCn = DList.H;
    for ( viCn=0; viCn<DList.length; viCn++ )
    {
        printf ("The value n %d is: %f.\n", viCn, vpCn->Value);
        vpCn = vpCn->Next;
    }

}
*/


