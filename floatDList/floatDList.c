
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





typedef struct floatDNode
{
    float Value;
    struct floatDNode *Previous;
    struct floatDNode *Next;
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

    floatDNode *vpNew = (floatDNode *) malloc(sizeof(floatDNode));
    if ( vpNew==NULL )
    {
        printf ("\nThe Allocation has failled !!!");
        exit (1);
    }

    funcfloatDNodeInit (vpNew);
    vpNew->Value = value;

    return vpNew;
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



void funcfloatDListInit (floatDList *pDList)
{
    pDList->H = NULL;
    pDList->T = NULL;
    pDList->length = 0;
}

bool funcfloatDListEmpty (floatDList DList)
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
void funcfloatDListInsert (floatDList *pDList, int index, float value)
{

    floatDNode *vpNew;
    floatDNode *vpTemp;
    floatDNode *vpCn;
    int viCn;


    
    if ( 0<=index )
    {
        
        if ( (*pDList).length<index )
        {
            printf ("The index is out the range of the DList !!!");
            exit (1);
        }

        vpNew = funcfloatDNodeCreate (value);

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


        vpNew = funcfloatDNodeCreate (value);

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

void funcfloatDListInsertBegin (floatDList *pDList, float value)
{
    funcfloatDListInsert (pDList, 0, value);   //&(*pDList)
}

void funcfloatDListInsertEnd (floatDList *pDList, float value)
{
    funcfloatDListInsert (pDList, pDList->length, value);     // &(*pDList), (*pDList).length
}

/*
void funcfloatDListInsertBegin (floatDList *pDList, float value)
{

    floatDNode *vpNew;
    floatDNode *vpTemp;

    vpNew = funcfloatDNodeCreate (value);
    if ( (*pDList).length==0 )
    {
        (*pDList).H = vpNew;
        (*pDList).T = vpNew;
    }
    else
    {
        vpTemp = (*pDList).H;
        (*pDList).H = vpNew;

        (*pDList).H->Next = vpTemp;
        vpTemp->Previous = (*pDList).H;
    }



    (*pDList).length++;
}
*/

/*
void funcfloatDListInsertEnd (floatDList *pDList, float value)
{

    floatDNode *vpNew;
    floatDNode *vpTemp;

    vpNew = funcfloatDNodeCreate(value);
    if ( (*pDList).length==0 )
    {
        (*pDList).H = vpNew;
        (*pDList).T = vpNew;
    }
    else
    {
        vpTemp = (*pDList).T;
        (*pDList).T = vpNew;

        (*pDList).T->Previous = vpTemp;
        vpTemp->Next = (*pDList).T;
    }



    (*pDList).length++;
}
*/


float funcfloatDListat (floatDList pDList, int index)
{

    floatDNode *vpCn;
    floatDNode *vp;
    int viCn = 0;



    vp = funcfloatDNodePointer (pDList, index);

    return vp->Value;
}

int funcfloatDListIndex (floatDList pDList, float value)
{

    floatDNode *vpCn;
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

    printf ("The Number %f do not exist in the DList !!!", value);
    exit(1);
}

int funcfloatDListCount (floatDList pDList, float value)
{
    
    floatDNode *vpCn = pDList.H;
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

void funcfloatDListModify (floatDList *pDList, int index, float value)
{

    floatDNode *vpNew = funcfloatDNodePointer (*pDList, index);

    vpNew->Value = value;
}


void funcfloatDListRemove (floatDList *pDList, int index)
{

    floatDNode *vp;
    floatDNode *vpTemp;



    vp = funcfloatDNodePointer (*pDList, index);



    if ( (*pDList).length==1 )
    {
        vpTemp = vp;
        (*pDList).H = NULL;
        (*pDList).T = NULL;

        funcfloatDNodeFree (vpTemp);
    }
    else
    {
        if ( vp==(*pDList).H )
        {
            vpTemp = (*pDList).H;
            (*pDList).H = (*pDList).H->Next;

            (*pDList).H->Previous = NULL;
            funcfloatDNodeFree (vpTemp);
        }
        else if ( vp==(*pDList).T )
        {
            vpTemp = (*pDList).T;
            (*pDList).T = (*pDList).T->Previous;

            (*pDList).T->Next = NULL;
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





    (*pDList).length--;
}

void funcfloatDListRemoveBegin (floatDList *pDList)
{
    funcfloatDListRemove (pDList, 0);  // &(*pDList)
}

void funcfloatDListRemoveEnd (floatDList *pDList)
{
    funcfloatDListRemove (pDList, pDList->length-1);  // &(*pDList), (*pDList).length-1
}

/*
void funcfloatDListRemoveBegin (floatDList *pDList)
{
    
    floatDNode *vpTemp;

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

        funcfloatDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pDList).H;
        (*pDList).H = (*pDList).H->Next;

        (*pDList).H->Previous = NULL;
        funcfloatDNodeFree (vpTemp);    
    }



    (*pDList).length--;
}
*/

/*
void funcfloatDListRemoveEnd (intDList *pDList)
{
    
    floatDNode *vpTemp;
    

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

        funcfloatDNodeFree (vpTemp);
    }
    else
    {
        vpTemp = (*pDList).T;
        (*pDList).T = (*pDList).T->Previous;

        (*pDList).T->Next = NULL;
        funcfloatDNodeFree (vpTemp);
    }
    



    (*pDList).length--;
}
*/


void funcfloatDListClear (floatDList *pDList)
{

    while ( (*pDList).length>0 )
    {
        funcfloatDListRemove (pDList, 0);  // &(*pDList)
    }
}

/*
void funcfloatDListClear (floatDList *pDList)
{


    floatDNode *vpCn;
    floatDNode *vpTemp;


    vpCn = (*pDList).H;
    while ( vpCn!=NULL )
    {
        vpTemp = vpCn;
        vpCn = vpCn->Next;

        funcfloatDNodeFree (vpTemp);
    }


    (*pDList).H = NULL;
    (*pDList).T = NULL;
    (*pDList).length = 0;
}
*/



floatDList funcfloatDListUnion (floatDList DList1, floatDList DList2)
{
    floatDList vdlList;
    funcfloatDListInit (&vdlList);

    floatDNode *vpCn1, *vpCn2, *vpCn3;
    float vfHolder;
    bool vbFound;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        vfHolder = vpCn1->Value;

        vbFound = false;
        vpCn3 = vdlList.H;
        while ( vpCn3!=NULL )
        {
            if ( vfHolder==vpCn3->Value )
            {
                vbFound = true;
                break;
            }

            vpCn3 = vpCn3->Next;
        }

        if (!vbFound)
        {
            funcfloatDListInsertEnd (&vdlList, vfHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    vpCn2 = DList2.H;
    while ( vpCn2!=NULL )
    {
        vfHolder = vpCn2->Value;

        vbFound = false;
        vpCn3 = vdlList.H;
        while ( vpCn3!=NULL )
        {
            if ( vfHolder == vpCn3->Value )
            {
                vbFound = true;
            }

            vpCn3 = vpCn3->Next;
        }

        if (!vbFound)
        {
            funcfloatDListInsertEnd (&vdlList, vfHolder);
        }
        
        vpCn2 = vpCn2->Next;
    }

    return vdlList;
}

floatDList funcfloatDListIntersection (floatDList DList1, floatDList DList2)
{
    floatDList vdlList;
    funcfloatDListInit (&vdlList);

    floatDNode *vpCn1, *vpCn2;
    bool vbFound;
    float vfHolder;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        vfHolder = vpCn1->Value;

        vbFound = false;
        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( vfHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }
            vpCn2 = vpCn2->Next;
        }

        if ( vbFound )
        {
            funcfloatDListInsertEnd (&vdlList, vfHolder);
        }
        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}

floatDList funcfloatDListDifference (floatDList DList1, floatDList DList2)
{
    floatDList vdlList;
    funcfloatDListInit (&vdlList);

    floatDNode *vpCn1, *vpCn2;
    float vfHolder1;
    bool vbFound;

    vpCn1 = DList1.H;

    while ( vpCn1!=NULL )
    {
        vfHolder1 = vpCn1->Value;
        vbFound = false;

        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( vpCn2->Value==vfHolder1 )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funcfloatDListInsertEnd (&vdlList, vfHolder1);
        }

        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}

floatDList funcfloatDListSymmetricDifference (floatDList DList1, floatDList DList2)
{
    floatDList vdlList;
    funcfloatDListInit (&vdlList);

    floatDNode *vpCn1, *vpCn2;
    float vfHolder;
    bool vbFound;

    vpCn1 = DList1.H;
    while ( vpCn1!=NULL )
    {
        vfHolder = vpCn1->Value;

        vbFound = false; 
        vpCn2 = DList2.H;
        while ( vpCn2!=NULL )
        {
            if ( vfHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funcfloatDListInsertEnd (&vdlList, vfHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    vpCn1 = DList2.H;
    while ( vpCn1!=NULL )
    {
        vfHolder = vpCn1->Value;

        vbFound = false; 
        vpCn2 = DList1.H;
        while ( vpCn2!=NULL )
        {
            if ( vfHolder==vpCn2->Value )
            {
                vbFound = true;
                break;
            }

            vpCn2 = vpCn2->Next;
        }

        if ( !vbFound )
        {
            funcfloatDListInsertEnd (&vdlList, vfHolder);
        }

        vpCn1 = vpCn1->Next;
    }

    return vdlList;
}




float funcQuerryfloat ()
{

    float vfNum1;
    printf ("Enter the value: ");
    scanf ("%f", &vfNum1);

    return vfNum1;
}

void funcfloatDListCreateFIFO (floatDList *pDList, int DListSize)
{

    float vfValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++ )
    {
        vfValue = funcQuerryfloat ();
        funcfloatDListInsertEnd (pDList, vfValue); // &(*pDList)
    }
}

void funcfloatDListCreateLIFO (floatDList *pDList, int DListSize)
{

    float vfValue;
    int viCn;
    for ( viCn=0; viCn<DListSize; viCn++)
    {
        vfValue = funcQuerryfloat ();
        funcfloatDListInsertBegin (pDList, vfValue);   // &(*pDList)
    }
}


void funcfloatDListSort (floatDList *pDList)
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

void funcfloatDListSortReversed (floatDList *pDList)
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


void funcfloatDListDisplay (floatDList DList)
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

void funcfloatDListDisplayReversed (floatDList DList)
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
void funcfloatDListDisplayReversed (floatDList DList)
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


int main ()
{

    floatDList vdlList1, vdlList2, vdlList3;
    funcfloatDListInit (&vdlList1);
    funcfloatDListInit (&vdlList2);
    funcfloatDListInit (&vdlList3);

    printf ("creating list1:\n");
    funcfloatDListCreateFIFO (&vdlList1, 5);
    printf ("\n\n");

    printf ("Displaying list:\n");
    funcfloatDListDisplay (vdlList1);
    printf ("\n\n");

    printf ("create list2:\n");
    funcfloatDListCreateFIFO (&vdlList2, 5);
    printf ("\n\n");

    printf ("Displaying list:\n");
    funcfloatDListDisplay (vdlList2);
    printf ("\n\n");



    vdlList3 = funcfloatDListSymmetricDifference (vdlList1, vdlList2);
    printf ("Displaying list:\n");
    funcfloatDListDisplay (vdlList3);
    printf ("\n\n");



    return 0;
}