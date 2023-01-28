#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

int countNonLeafNodes(struct node *pRoot)
{
    static int iCount = 0;

    if(pRoot != NULL)
    {
        if(pRoot->pLeft != NULL || pRoot->pRight != NULL)
            iCount++;
        
        countNonLeafNodes(pRoot->pLeft);
        countNonLeafNodes(pRoot->pRight);
    }
    return iCount;
}