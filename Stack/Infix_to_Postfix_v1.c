#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define MAX 50

long g_Stack[MAX];
int g_iTop = -1;

int IsEmpty(void)
{
    if(g_iTop == -1)
        return 1;
    return 0;
}

int IsFull(void)
{
    if(g_iTop == MAX - 1)
        return 1;
    return 0;
}

int IsSpace(char chSymbol)
{
    if(chSymbol == ' ' || chSymbol == '\t')
        return 1;
    return 0;
}

int IsOperator(char chSymbol)
{
    switch(chSymbol)
    {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void Push(long lNo)
{
    if(IsFull())
    {
        printf("Stack overflow\n");
        return;
    }
    g_Stack[++g_iTop] = lNo;
}

long Pop(void)
{
    if(IsEmpty())
        return -1;
    return g_Stack[g_iTop--];
}

void InfixToPostfix(const char *pInfix, char *pPostfix)
{
    int iRet;
    char chChar;
    int iCounter1;
    int iCounter2 = 0;

    for(iCounter1 = 0; pInfix[iCounter1] != '\0'; iCounter1++)
    {
        if(IsSpace(pInfix[iCounter1]))
            continue;

        if(pInfix[iCounter1] == '(')
            Push(pInfix[iCounter1]);

        else if(pInfix[iCounter1] == ')')
        {
            while((chChar = Pop()) != '(')
            pPostfix[iCounter2++] = chChar;
        }
        else if((iRet = IsOperator(pInfix[iCounter1])) != 0) // operator
        {
            while(g_iTop != -1 && IsOperator(g_Stack[g_iTop]) >= iRet)
                pPostfix[iCounter2++] = Pop();

            Push(pInfix[iCounter1]);
        }
        else // operand
        {
            pPostfix[iCounter2++] = '[';
            while(pInfix[iCounter1] >= '0' && pInfix[iCounter1] <= '9')
            pPostfix[iCounter2++] = pInfix[iCounter1++];
            pPostfix[iCounter2++] = ']';

            iCounter1--;
        }
    }

    while(g_iTop != -1)
        pPostfix[iCounter2++] = Pop();

    pPostfix[iCounter2] = '\0';
}

long PostfixEvaluation(const char *pPostfix)
{
    int iCounter1;
    int iCounter2;
    int iNo1;
    int iNo2;
    int iAns;
    char pTemp[10] = {0};

    for(iCounter1 = 0; pPostfix[iCounter1] != '\0'; iCounter1++)
    {
        if(pPostfix[iCounter1] == '[')
        {
            for(iCounter2 = 0; pPostfix[++iCounter1] != ']'; iCounter2++)
                pTemp[iCounter2] = pPostfix[iCounter1];

            pTemp[iCounter2] = '\0';

            iCounter2 = atoi(pTemp);
            Push(iCounter2);
        }
        else
        {
            iNo2 = Pop();
            iNo1 = Pop();

            switch(pPostfix[iCounter1])
            {
                case '^':
                    iAns = pow(iNo1, iNo2);
                    break;

                case '*':
                    iAns = iNo1 * iNo2;
                    break;

                case '/':
                    iAns = iNo1 / iNo2;
                    break;

                case '%':
                    iAns = iNo1 % iNo2;
                    break;

                case '+':
                    iAns = iNo1 + iNo2;
                    break;

                case '-':
                iAns = iNo1 - iNo2;
            }
            Push(iAns);
        }
    }
    return Pop();
}

int main(void)
{
    long lResult;
    char Infix[MAX];
    char Postfix[MAX];

    puts("Enter arithmetic expression:");
    gets(Infix);

    InfixToPostfix(Infix, Postfix);
    printf("\nPostfix expression is : %s\n", Postfix);

    lResult = PostfixEvaluation(Postfix);
    printf("\nResult is %ld\n", lResult);

    return 0;
}