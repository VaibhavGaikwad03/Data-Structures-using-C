#include<stdio.h>
#include<malloc.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define MAX 3

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

BOOL isFull(struct node *pHead)
{
    if(MAX == countNodes(pHead))
        return TRUE;
    return FALSE;
}

BOOL isEmpty(struct node *pHead)
{
    if(pHead == NULL)
        return TRUE;
    return FALSE;
}

void display(struct node *pHead)
{
    if(isEmpty(pHead))
    {
        printf("\nStack is empty !\n");
        return;
    }

    printf("\nData from the stack : \n");

    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

void push(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;

    if(isFull(*ppHead))
    {
        printf("\nStack Overflow !\n");
        return;
    }

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

int pop(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(isEmpty(*ppHead))
    {
        return -1;
    }
    
    iDelData = (*ppHead)->iData;

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int main(void)
{
    BOOL bFlag = TRUE;
    int iChoice = 0, iNo = 0, iRet = 0;
    struct node *pStack = NULL;

    while(bFlag)
    {
        fflush(stdin);
        printf("\nHello, Welcome...\nChoose from the below options :\n");
        printf("\n1. Push\n2. Pop\n3. Count Nodes\n4. Exit\n>_");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the data : \n");
                scanf("%d", &iNo);
                push(&pStack, iNo);
                display(pStack);   
                break;

            case 2:
                iRet = pop(&pStack);
                if(iRet != -1)
                    printf("\nPopped data is : %d\n", iRet);
                display(pStack);
                break;

            case 3:
                iRet = countNodes(pStack);
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