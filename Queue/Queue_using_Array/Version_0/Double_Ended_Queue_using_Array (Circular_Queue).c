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

    //surely g_iFront is not 0

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

void enQueueAtFront(int *pQueue, int iNo)               //mage ja value tak
{
    if(isQueueFull())
    {
        printf("Queue is full.\n");
        return;
    }

    if(g_iFront == 0)//circular                                
    {
        g_iFront = MAX - 1;                             //initially iFront = 0 asnar mg iFront la MAX - 1 la taka
        g_iRear = MAX - 1;                              //iRear la pn MAX - 1 la gheun ja chukun iRear = -1 rahila tr display krtana queue is empty yeil
    }
    else                                                //normal
        g_iFront--;

    pQueue[g_iFront] = iNo;
}

int deQueueFromRear(int *pQueue)                        //value kadh mg mage ja
{
    int iDelData = 0;

    if(isQueueEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }

    iDelData = pQueue[g_iRear];

    if(g_iRear == g_iFront)                             //iRear ani iFront ekach index la astil tr queue madhe ekch element asnar
    {
        g_iFront = 0;
        g_iRear = -1;
    }

    else if(g_iFront > g_iRear && g_iRear == 0)         //iFront jar iRear peksha motha asel ani iRear = 0 asel tr iRear la MAX - 1 la taka
        g_iRear = MAX - 1;                              //karan queue circular ahe

    else
        g_iRear--;

    return iDelData;
}

int main(void)
{
    int Queue[MAX];

    enQueueAtFront(Queue, 10);
    enQueueAtFront(Queue, 20);
    enQueueAtFront(Queue, 30);
    enQueue(Queue, 5);
    enQueue(Queue, 3);
    enQueue(Queue, 1);

    display(Queue);

    printf("%d\n", deQueueFromRear(Queue));
    printf("%d\n", deQueue(Queue));
    printf("%d\n", deQueue(Queue));
    // printf("%d\n", deQueueFromRear(Queue));
    // printf("%d\n", deQueueFromRear(Queue));
    // printf("%d\n", deQueueFromRear(Queue));
    // printf("%d\n", deQueueFromRear(Queue));
    
    display(Queue); 


    return 0;   
}