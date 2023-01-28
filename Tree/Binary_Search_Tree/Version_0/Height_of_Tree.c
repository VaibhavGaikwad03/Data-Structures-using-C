#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *pLeft;
    int iData;
    struct node *pRight;
};

int heightOfTree(struct node *pRoot)
{
    int iLeftHeight = 0, iRightHeight = 0;

    if(pRoot == NULL)
        return 0;

    iLeftHeight = heightOfTree(pRoot->pLeft);
    iRightHeight = heightOfTree(pRoot->pRight);

    if(iLeftHeight > iRightHeight)
        return 1 + iLeftHeight;
    return 1 + iRightHeight;
}