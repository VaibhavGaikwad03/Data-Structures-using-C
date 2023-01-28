#include"Custom_Header.h"

void levelOrderTraversal(struct node *pRoot)
{
    int iCounter = 0;
    struct node *pPtr = NULL;
    struct Qnode *pQueue = NULL;

    if(pRoot == NULL)
        return;

    enQueue(&pQueue, pRoot);

    while(!isQueueEmpty(pQueue))
    {
        pPtr = deQueue(&pQueue);
        printf("%d ", pPtr->iData);

        if(pPtr->pLeft != NULL)
            enQueue(&pQueue, pPtr->pLeft);

        if(pPtr->pRight != NULL)  
            enQueue(&pQueue, pPtr->pRight);  
    }
}

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

int main(void)
{
    struct node *pRoot = NULL;

    insertBST(&pRoot, 50);
    insertBST(&pRoot, 30);
    insertBST(&pRoot, 75);
    insertBST(&pRoot, 20);
    insertBST(&pRoot, 35);
    insertBST(&pRoot, 80);
    insertBST(&pRoot, 32);

    levelOrderTraversal(pRoot);

    return 0;
}