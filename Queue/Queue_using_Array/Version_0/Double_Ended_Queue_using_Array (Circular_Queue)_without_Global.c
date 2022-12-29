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

void enQueueAtFront(int *pQueue, int *iFront, int *iRear, int iNo)               //mage ja value tak
{
    if(isQueueFull(*iRear, *iFront))
    {
        printf("Queue is full.\n");
        return;
    }

    if(*iFront == 0)//circular                                
    {
        *iFront = MAX - 1;                                              //initially iFront = 0 asnar mg iFront la MAX - 1 la taka
        *iRear = MAX - 1;                                               //iRear la pn MAX - 1 la gheun ja chukun iRear = -1 rahila tr display krtana queue is empty yeil
    }
    else                                                                //normal
        --(*iFront);

    pQueue[*iFront] = iNo;
}

int deQueueFromRear(int *pQueue, int *iFront, int *iRear)               //value kadh mg mage ja
{
    int iDelData = 0;

    if(isQueueEmpty(*iRear))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    iDelData = pQueue[*iRear];

    if(*iRear == *iFront)                                               //iRear ani iFront ekach index la astil tr queue madhe ekch element asnar
    {
        *iFront = 0;
        *iRear = -1;
    }

    else if(*iFront > *iRear && *iRear == 0)                            //iFront jar iRear peksha motha asel ani iRear = 0 asel tr iRear la MAX - 1 la taka
        *iRear = MAX - 1;                                               //karan queue circular ahe

    else
        --(*iRear);

    return iDelData;
}

int main(void)
{
    int Queue[MAX];
    int iRear = -1, iFront = 0;

    enQueueAtFront(Queue, &iFront, &iRear, 10);
    enQueueAtFront(Queue, &iFront, &iRear, 20);
    enQueueAtFront(Queue, &iFront, &iRear, 30);
    enQueue(Queue, &iRear, iFront, 5);
    enQueue(Queue, &iRear, iFront, 3);
    enQueue(Queue, &iRear, iFront, 1);

    display(Queue, iRear, iFront);

    printf("%d\n", deQueueFromRear(Queue, &iFront, &iRear));
    printf("%d\n", deQueue(Queue, &iRear, &iFront));
    printf("%d\n", deQueue(Queue, &iRear, &iFront));
    // printf("%d\n", deQueueFromRear(Queue, &iFront, &iRear));
    // printf("%d\n", deQueueFromRear(Queue, &iFront, &iRear));
    // printf("%d\n", deQueueFromRear(Queue, &iFront, &iRear));
    // printf("%d\n", deQueueFromRear(Queue, &iFront, &iRear));
    
    display(Queue, iRear, iFront); 


    return 0;   
}