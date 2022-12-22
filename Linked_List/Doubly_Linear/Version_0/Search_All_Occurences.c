#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
    struct node *pPrev;
};

void insertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        pNewNode->pPrev = NULL;
        *ppHead = pNewNode;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        { 
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
        pNewNode->pPrev = pTemp;
    }
}

int searchAllOcc(struct node *pHead, int iKey)
{
    int iCountOcc = 0;

    while(pHead != NULL)
    {   
        if(pHead->iData == iKey)
        {
            iCountOcc++;
        }
        pHead = pHead->pNext;   
    }
    return iCountOcc;
}

int main()
{
    int iRet = 0;
    struct node * pFirst = NULL;

    insertLast(&pFirst, 10);
    insertLast(&pFirst, 20);
    insertLast(&pFirst, 30);
    insertLast(&pFirst, 40);
    insertLast(&pFirst, 50);
    insertLast(&pFirst, 30);
    insertLast(&pFirst, 50);

    iRet = searchAllOcc(pFirst, 30);

    printf("%d occured %d times\n", 30, iRet);

    return 0;
}