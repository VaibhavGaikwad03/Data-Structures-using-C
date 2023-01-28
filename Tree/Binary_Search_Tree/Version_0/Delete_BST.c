#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

void deleteNode(struct node **ppRoot, int iNo)
{
    struct node *pPtr = NULL;
    struct node *pParent = NULL;
    struct node *pSuccessor = NULL;
    struct node *pParentSuccessor = NULL;
    struct node *pChild = NULL;

    //searching data to be deleted

    pPtr = *ppRoot;

    while(pPtr != NULL)
    {
        if(pPtr->iData == iNo)
            break;
        
        pParent = pPtr;
        if(iNo < pPtr->iData)
            pPtr = pPtr->pLeft;

        else
            pPtr = pPtr->pRight;
    }

    if(pPtr == NULL)
        return;

    //for both childs scenario
    if(pPtr->pLeft != NULL && pPtr->pRight == NULL)
    {
        pParentSuccessor = pPtr;
        pSuccessor = pPtr->pRight;      //one's right

        while(pSuccessor->pLeft != NULL)    //complete left
        {
            pParentSuccessor = pSuccessor;
            pSuccessor = pSuccessor->pLeft;
        }//found inorder successor

        pPtr->iData = pSuccessor->iData;

        pPtr = pSuccessor;
        pParent = pParentSuccessor;
    }

    //one child scenario

    if(pPtr->pLeft != NULL)
        pChild = pPtr->pLeft;

    else
        pChild = pPtr->pRight;              //handles no child scenario also

    if(pParent == NULL)
        *ppRoot = pChild;
    
    else if(pPtr == pParent->pLeft)
        pParent->pLeft = pChild;
    
    else
        pParent->pRight = pChild;

    free(pPtr);
}