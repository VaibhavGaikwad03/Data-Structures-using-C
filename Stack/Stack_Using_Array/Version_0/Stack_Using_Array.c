#include<stdio.h>

#define MAX 5

typedef int BOOL;

#define TRUE 1
#define FALSE 0

BOOL isFull(int iTop)
{
    if(iTop == MAX - 1)
        return TRUE;
    return FALSE;
}

BOOL isEmpty(int iTop)
{
    if(iTop == -1)
        return TRUE;
    return FALSE;
}

void display(const int *pStack, int iTop)
{
    int i = 0;

    if(iTop == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for(i = 0; i <= iTop; i++)
    {
        printf("%d ", pStack[i]);
    }
    printf("\n");
}

void push(int *pStack, int *piTop, int iNo)
{
    if(isFull(*piTop))
    {
        printf("Stack Overflow\n");
        return;
    }

    pStack[++(*piTop)] = iNo;
}

int pop(int *pStack, int *piTop)
{
    if(isEmpty(*piTop))
    {
        printf("Stack is empty\n");
        return -1;
    }

    return pStack[(*piTop)--];
}

int main()
{
    int Stack[MAX] = {0};
    int iTop = -1, iRet = 0;

    push(Stack, &iTop, 10);
    push(Stack, &iTop, 20);
    push(Stack, &iTop, 30);
    push(Stack, &iTop, 40);

    display(Stack, iTop);

    pop(Stack, &iTop);

    display(Stack, iTop);

    pop(Stack, &iTop);
    pop(Stack, &iTop);
    pop(Stack, &iTop);
    

    display(Stack, iTop);

    return 0;
}