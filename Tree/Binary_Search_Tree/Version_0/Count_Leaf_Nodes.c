#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

int countLeafNodes(struct node *pRoot)
{
    static int iCount = 0;

    if(pRoot != NULL)
    {
        if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
            iCount++;

        countLeafNodes(pRoot->pLeft);
        countLeafNodes(pRoot->pRight);
    }
    return iCount;
}