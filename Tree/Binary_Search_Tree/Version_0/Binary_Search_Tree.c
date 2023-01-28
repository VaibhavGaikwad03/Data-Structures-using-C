#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

struct node * searchBST(struct node *pRoot, int iKey)
{
    if(pRoot == NULL)
        return NULL;

    if(iKey < pRoot->iData)
        return searchBST(pRoot->pLeft, iKey);
    else if(iKey > pRoot->iData)
        return searchBST(pRoot->pRight, iKey);
    else
        return pRoot;
}

void preorder(struct node *pRoot)
{
    if(pRoot == NULL)
        return;

    printf("%d ", pRoot->iData);
    preorder(pRoot->pLeft);
    preorder(pRoot->pRight);
}

void inorder(struct node *pRoot)
{
    if(pRoot == NULL)
        return;

    inorder(pRoot->pLeft);
    printf("%d ", pRoot->iData);
    inorder(pRoot->pRight);
}

void postorder(struct node *pRoot)
{
    if(pRoot == NULL)
        return;

    postorder(pRoot->pLeft);
    postorder(pRoot->pRight);
    printf("%d ", pRoot->iData);

}

void levelOrderTraversal(struct node *pRoot){}

int findSmallestBST(struct node *pRoot)
{
    while(pRoot->pLeft != NULL)
        pRoot = pRoot->pLeft;

    return pRoot->iData;
}

int findLargestBST(struct node *pRoot)
{
    while(pRoot->pRight != NULL)
        pRoot = pRoot->pRight;
    
    return pRoot->iData;
}

int countLeafNodes(struct node *pRoot)
{
    if (pRoot == NULL) 
    {
        return 0;
    }
    if (pRoot->pLeft == NULL && pRoot->pRight == NULL) 
    {
        return 1;
    }
  return countLeafNodes(pRoot->pLeft) + countLeafNodes(pRoot->pRight);
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
    insertBST(&pRoot, 40);
    insertBST(&pRoot, 20);
    insertBST(&pRoot, 22);
    insertBST(&pRoot, 53);
    insertBST(&pRoot, 10);

    preorder(pRoot);

    printf("\n");
    printf("%d\n", findSmallestBST(pRoot));
    printf("%d\n", findLargestBST(pRoot));
    printf("\n%d\n", countLeafNodes(pRoot));

    return 0;
}