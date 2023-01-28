#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

void insertBST(struct node **ppRoot, int iNo)
{
    struct node *pPtr = NULL;
    struct node *pParent = NULL;

    pPtr = *ppRoot;

    while(pPtr != NULL)
    {
        pParent = pPtr;

        if(iNo < pPtr->iData)
            pPtr = pPtr->pLeft;
        
        else if(iNo > pPtr->iData)
            pPtr = pPtr->pRight;

        else
        {
            printf("Duplicate Data\n");
            return;
        }
    }

    pPtr = (struct node *)malloc(sizeof(struct node));

    if(pPtr == NULL)
    {
        printf("Memory allocation FALIED\n");
        return;
    }

    pPtr->iData = iNo;
    pPtr->pLeft = pPtr->pRight = NULL;

    if(pParent == NULL)
        *ppRoot = pPtr;
    
    else if(iNo < pParent->iData)
        pParent->pLeft = pPtr;
    
    else
        pParent->pRight = pPtr;
}