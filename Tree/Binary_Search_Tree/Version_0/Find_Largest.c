#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

int findLargestBST(struct node *pRoot)
{
    while(pRoot->pRight != NULL)
        pRoot = pRoot->pRight;
    
    return pRoot->iData;
}