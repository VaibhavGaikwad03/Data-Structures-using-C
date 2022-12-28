//Queue using array (circular queue) without using global variables.

#include<stdio.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define MAX 5


BOOL isQueueFull(int iRear, int iFront)
{
    if((iFront == 0 && iRear == MAX -1) || (iRear == iFront -1 && iRear != -1))
        return TRUE;
    return FALSE;
}

BOOL isQueueEmpty(int iRear)
{
    if(iRear == -1)
        return TRUE;
    return FALSE;
}

int countNodes(const int *pQueue, int iRear, int iFront)
{
    int iCount = 0;

    if(isQueueEmpty(iRear))
    {
        return iCount;
    }

    if(iFront > iRear)                             
    {
        for(; iFront <= MAX - 1; iFront++)
            iCount++;
        iFront = 0; 
    }
    for(; iFront <= iRear; iFront++)
        iCount++;

    return iCount;
}

void display(const int *pQueue, int iRear, int iFront)
{
    if(isQueueEmpty(iRear))
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nData from the Queue : \n");
    if(iFront > iRear)                             
    {
        for(; iFront <= MAX - 1; iFront++)
            printf("\n%d ", pQueue[iFront]);
        iFront = 0; 
    }
    for(; iFront <= iRear; iFront++)
        printf("%d ", pQueue[iFront]);
    printf("\n");
}   

void enQueue(int *pQueue, int *iRear, int iFront,int iNo)
{
    if(isQueueFull(*iRear, iFront))
    {
        printf("\nQueue is full.\n");
        return;
    }


    if(*iRear == MAX -1)                               
        *iRear = 0;
    else                                              
        (*iRear)++;
    pQueue[*iRear] = iNo;
}

int deQueue(int *pQueue, int *iRear, int *iFront)
{
    int iDelData = 0;

    if(isQueueEmpty(*iRear))
    {
        return -1;
    }
    iDelData = pQueue[*iFront];

    if(*iRear == *iFront)
    {
        *iRear = -1;
        *iFront = 0;
    }
    else if(*iFront == MAX -1)                         
        *iFront = 0;

    else                                               
        ++(*iFront);
    
    return iDelData;
}


int main(void)
{
    int Queue[MAX];
    BOOL bFlag = TRUE;
    int iRear = -1, iFront = 0, iChoice = 0, iNo = 0, iRet = 0;


    while(bFlag)
    {
        fflush(stdin);
        printf("\nHello, Welcome...\nChoose from the below options :\n");
        printf("\n1. EnQueue\n2. DeQueue\n3. Count Nodes\n4. Exit\n>_");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
            
                if(isQueueFull(iRear, iFront))
                    printf("\nQueue is full.\n");
                else
                {
                    printf("Enter the data : \n");
                    scanf("%d", &iNo);
                    enQueue(Queue, &iRear, iFront, iNo);
                    display(Queue, iRear, iFront);
                }   
                break;

            case 2:

                iRet = deQueue(Queue, &iRear, &iFront);
                if(iRet != -1)
                    printf("\nDeleted data is : %d\n", iRet);
                display(Queue, iRear, iFront);
                break;

            case 3:

                iRet = countNodes(Queue, iRear, iFront);
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