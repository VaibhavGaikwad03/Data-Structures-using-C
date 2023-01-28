#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

int countNodes(struct node *pRoot)
{
    static int iCount = 0;

    if(pRoot != NULL)
    {
        iCount++;
        countNodes(pRoot->pLeft);
        countNodes(pRoot->pRight);
    }
    return iCount;
}