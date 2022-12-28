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

void display(const int *pQueue, int iRear, int iFront)
{
    int iCounter = iFront;

    if(isQueueEmpty(iRear))
    {
        printf("Queue is empty.\n");
        return;
    }

    if(iFront > iRear)                             
    {
        for(; iCounter <= MAX - 1; iCounter++)
            printf("%d ", pQueue[iCounter]);
        iCounter = 0; 
    }
    for(; iCounter <= iRear; iCounter++)
        printf("%d ", pQueue[iCounter]);
    printf("\n");
}   

void enQueue(int *pQueue, int *iRear, int iFront,int iNo)
{
    if(isQueueFull(*iRear, iFront))
    {
        printf("Queue is full.\n");
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
        printf("Queue is empty.\n");
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
    int iRear = -1, iFront = 0;

    enQueue(Queue, &iRear, iFront,10);
    enQueue(Queue, &iRear, iFront,20);
    enQueue(Queue, &iRear, iFront,30);
    enQueue(Queue, &iRear, iFront,40);
    enQueue(Queue, &iRear, iFront,50);

    display(Queue, iRear, iFront);

    printf("%d\n", deQueue(Queue, &iRear, &iFront));
    display(Queue, iRear, iFront);
    printf("%d\n", deQueue(Queue, &iRear, &iFront));
    display(Queue, iRear, iFront);
    printf("%d\n", deQueue(Queue, &iRear, &iFront));
    display(Queue, iRear, iFront);
    printf("%d\n", deQueue(Queue, &iRear, &iFront));
    display(Queue, iRear, iFront);
    printf("%d\n", deQueue(Queue, &iRear, &iFront));
    display(Queue, iRear, iFront);
    // deQueue(Queue, &iRear, &iFront);
    // display(Queue, iRear, iFront);
    // deQueue(Queue, &iRear, &iFront);
    // display(Queue, iRear, iFront);
    // deQueue(Queue, &iRear, &iFront);
    // display(Queue, iRear, iFront);
    // deQueue(Queue, &iRear, &iFront);  

    return 0;   
}