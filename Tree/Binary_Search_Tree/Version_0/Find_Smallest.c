#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

int findSmallestBST(struct node *pRoot)
{
    while(pRoot->pLeft != NULL)
        pRoot = pRoot->pLeft;

    return pRoot->iData;
}