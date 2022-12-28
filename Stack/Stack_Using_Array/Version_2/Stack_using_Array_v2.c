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
        printf("\nStack is empty\n");
        return;
    }

    printf("\nData from the Stack : \n");

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
        printf("\nStack Overflow\n");
        return;
    }

    pStack[++(*piTop)] = iNo;
}

int pop(int *pStack, int *piTop)
{
    if(isEmpty(*piTop))
    {
        return -1;
    }

    return pStack[(*piTop)--];
}

int main()
{
    BOOL bFlag = TRUE;
    int Stack[MAX] = {0};
    int iTop = -1, iChoice = 0, iNo = 0, iRet = 0;
    
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
                push(Stack, &iTop, iNo);
                display(Stack, iTop);   
                break;

            case 2:

                iRet = pop(Stack, &iTop);
                if(iRet != -1)
                    printf("\nPopped data is : %d\n", iRet);
                display(Stack, iTop);
                break;

            case 3:

                printf("\nCount of nodes is : %d\n", iTop + 1);
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