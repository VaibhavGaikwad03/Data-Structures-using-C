#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void display(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Data from the linked list : \n");
    do
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
}

void insertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        return;
    }

    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;             //new node becomes first
        *ppTail = pNewNode;             //new node becomes last
        (*ppTail)->pNext = *ppHead;     //circular effect

        return;
    }

    pNewNode->pNext = *ppHead;          //first node becomes second
    *ppHead = pNewNode;                 //second node becomes first
    (*ppTail)->pNext = *ppHead;         //circular effect
}

int main()
{

    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    insertFirst(&pFirst, &pLast, 30);
    insertFirst(&pFirst, &pLast, 20);
    insertFirst(&pFirst, &pLast, 10);

    display(pFirst, pLast);

    return 0;
}