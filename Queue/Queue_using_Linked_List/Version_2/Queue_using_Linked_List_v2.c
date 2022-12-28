#include<stdio.h>
#include<malloc.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define MAX 5

struct node
{
    int iData;
    struct node *pNext;
};

int countNodes(struct node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    return iCount;
}

void display(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nData from the Queue : \n");
    while(pHead != NULL)
    {
        printf("|%d|<-", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

BOOL isQueueFull(struct node *pHead)
{
    if(countNodes(pHead) == MAX)
        return TRUE;
    return FALSE;
}

BOOL isQueueEmpty(struct node *pHead)
{
    if(countNodes(pHead) == 0)
        return TRUE;
    return FALSE;
}

void enQueue(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(isQueueFull(*ppHead))                                //if queue is full
    {
        printf("\nQueue is full.\n");
        return;
    }

    if((*ppHead) == NULL)                                   //if queue is empty
    {
        *ppHead = pNewNode;
        pNewNode = NULL;

        return;
    }

    pTemp = *ppHead;                                        //if queue having at least one or more elements

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
}

int deQueue(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(isQueueEmpty(*ppHead))
    {
        return -1;
    }

    iDelData = (*ppHead)->iData;

    if((*ppHead)->pNext == NULL)
    {
        free(*ppHead);
        *ppHead = NULL;

        return iDelData;
    }

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int main()
{
    BOOL bFlag = TRUE;
    struct node *pQueue = NULL;
    int iChoice = 0, iNo = 0, iRet = 0;

    while(bFlag)
    {
        fflush(stdin);
        printf("\nHello, Welcome...\nChoose from the below options :\n");
        printf("\n1. EnQueue\n2. DeQueue\n3. Count Nodes\n4. Exit\n>_");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
            
                if(isQueueFull(pQueue))
                    printf("\nQueue is full.\n");
                else
                {
                    printf("Enter the data : \n");
                    scanf("%d", &iNo);
                    enQueue(&pQueue, iNo);
                    display(pQueue);
                }
                break;

            case 2:
                iRet = deQueue(&pQueue);
                if(iRet != -1)
                    printf("\nDeleted data is : %d\n", iRet);
                display(pQueue);
                break;

            case 3:
                iRet = countNodes(pQueue);
                printf("\nCount of nodes is : %d\n", iRet);
                break;

            case 4:
                bFlag = FALSE;
                printf("\nThank You for using our application...\n");
                break;

            default:
                printf("\nInvalid option selected.\n");
        }
    }
    return 0;
}