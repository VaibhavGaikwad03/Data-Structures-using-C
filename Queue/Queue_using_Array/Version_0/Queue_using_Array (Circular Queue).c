#include<stdio.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define MAX 5

int g_iRear = -1;
int g_iFront = 0;

BOOL isQueueFull(void)
{
    if((g_iFront == 0 && g_iRear == MAX -1) || (g_iRear == g_iFront -1 && g_iRear != -1))
        return TRUE;
    return FALSE;
}

BOOL isQueueEmpty(void)
{
    if(g_iRear == -1)
        return TRUE;
    return FALSE;
}

void display(const int *pQueue)
{
    int iCounter = g_iFront;

    if(isQueueEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    if(g_iFront > g_iRear)                              //circular
    {
        for(; iCounter <= MAX - 1; iCounter++)
            printf("%d ", pQueue[iCounter]);
        iCounter = 0; 
    }
    for(; iCounter <= g_iRear; iCounter++)
        printf("%d ", pQueue[iCounter]);
    printf("\n");
}   

void enQueue(int *pQueue, int iNo)
{
    if(isQueueFull())
    {
        printf("Queue is full.\n");
        return;
    }

    //surely g_iFront is not 0 (jevha if madhe jaychi condition yeil tevha)

    if(g_iRear == MAX -1)                               //circular
        g_iRear = 0;
    else                                                //normal
        g_iRear++;
    pQueue[g_iRear] = iNo;
}

int deQueue(int *pQueue)
{
    int iDelData = 0;

    if(isQueueEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    iDelData = pQueue[g_iFront];

    if(g_iRear == g_iFront)                             //only one element
    {
        g_iRear = -1;
        g_iFront = 0;
    }
    else if(g_iFront == MAX -1)                         //circular
        g_iFront = 0;
    else                                                //normal
        g_iFront++;
    
    return iDelData;
}


int main(void)
{
    int Queue[MAX];

    enQueue(Queue, 10);
    enQueue(Queue, 20);
    enQueue(Queue, 30);
    enQueue(Queue, 40);
    enQueue(Queue, 50);

    display(Queue);

    deQueue(Queue);
    display(Queue);
    deQueue(Queue);
    display(Queue);
    deQueue(Queue);
    display(Queue);
    deQueue(Queue);
    display(Queue);
    deQueue(Queue);  

    return 0;   
}