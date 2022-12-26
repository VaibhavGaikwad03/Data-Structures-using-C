#include<stdio.h>
#include<malloc.h>
#define MAX 5
typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct node 
{
    int iData;
    struct node *pNext;
};

int countNode(struct node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    return iCount;
}

BOOL isFull(struct node *pHead)
{
    if(MAX == countNode(pHead))
        return TRUE;
    return FALSE;
}

int main()
{


    return 0;
}