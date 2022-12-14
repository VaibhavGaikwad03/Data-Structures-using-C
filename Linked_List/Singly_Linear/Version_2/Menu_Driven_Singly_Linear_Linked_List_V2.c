#include<stdio.h>
#include<malloc.h>

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
        printf("\nList is empty.\n");
        return;
    }

    printf("\nData from the linked list : \n");

    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

void insertFirst(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

void insertLast(struct node ** ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
    }
}

void insertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    int i = 0, iCount = 0;

    iCount = countNodes(*ppHead);

    if(iPos < 1 || iPos > iCount + 1)
        return;

    if(iPos == 1)
    {   
        insertFirst(ppHead, iNo);
        return;
    }
    
    pTemp = *ppHead;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}

int deleteFirst(struct node **ppHead)
{
    int iDel = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    iDel = pTemp->iData;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDel;
}

int deleteLast(struct node **ppHead)
{
    int iDel = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    if((*ppHead)->pNext == NULL)
    {
        iDel = (*ppHead)->iData;
        free(*ppHead);
        *ppHead = NULL;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        iDel = pTemp->pNext->iData;
        free(pTemp->pNext);
        pTemp->pNext = NULL;
    }

    return iDel;
}

int deleteAtPosition(struct node **ppHead, int iPos)
{
    int i = 0, iDelData = 0, iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = countNodes(*ppHead);

    if(iPos < 1 || iPos > iCount)
    {
        return -1;
    }

    if(iPos == 1)
    {
        return deleteFirst(ppHead);
    }

    pTemp1 = *ppHead;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = pTemp1->pNext;
    pTemp1->pNext = pTemp2->pNext;
    iDelData = pTemp2->iData;
    pTemp2->pNext = NULL;
    free(pTemp2);
    pTemp2 = NULL;

    return iDelData;
}

int searchFirstOccurrence(struct node *pHead, int iKey)
{
    int iCountPos = 0;

    while(pHead != NULL)
    {   
        iCountPos++;
        if(pHead->iData == iKey)
        {
            break;
        }
        pHead = pHead->pNext;
    }
    
    if(pHead == NULL)
    {
        iCountPos = 0;
    }
    
    return iCountPos;
}

int searchLastOccurrence(struct node *pHead, int iKey)
{
    int iCountPos = 0, iReturnPos = 0;

    while(pHead != NULL)
    {   
        iCountPos++;
        if(pHead->iData == iKey)
        {
            iReturnPos = iCountPos;
        }
        pHead = pHead->pNext;
    }
    return iReturnPos;
}

int searchAllOccurrences(struct node *pHead, int iKey)
{
    int iCountOcc = 0;

    while(pHead != NULL)
    {   
        if(pHead->iData == iKey)
        {
            iCountOcc++;
        }
        pHead = pHead->pNext;   
    }
    return iCountOcc;
}

void concatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if(*ppHead2 == NULL)
    {
        return;
    }
    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }
    
    pTemp = *ppHead1;

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;
}

void concatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = countNodes(*ppHead1);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Position is Invalid\n");
        return;
    }    

    if(*ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        concatList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }

    pTemp1 = *ppHead1;

    for(int i = 1; i < iPos - 1; i++)
    {
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = pTemp1 = pTemp2 = NULL;
}

void physicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = *ppHead;
    struct node * pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    *ppHead = pPrev;
}

void reverseDisplay(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("Linked List is empty!!\n");
        return;
    }

    physicalReverse(&pHead);
    display(pHead);
    physicalReverse(&pHead);
}

void deleteAll(struct node **ppHead)
{
    struct node *pTemp = *ppHead;

    while(pTemp != NULL)
    {
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp);
        pTemp = *ppHead;
    }
}

int main()
{
    int iChoice = 0, iData = 0, iPos = 0, iCount = 0, iCheckData = 0, iDeletedData = 0, iOccurrence = 0, iPosition = 0;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    while(1)
    {
        out:
        fflush(stdin);
        printf("\nHello, Welcome...\nPlease choose from the below options : \n\n");
        printf("1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Delete First\n5. Delete Last\n6. Delete At Position\n7. Search First Occurrence\n8. Search Last Occurrence\n9. Search All Occurrences\n10. Count Nodes\n11. Concat List\n12. Concat At Position\n13. Physical Reverse\n14. Reverse Display\n15. Exit\n");
        printf(">_");
        iCheckData = scanf("%d", &iChoice);

        if(iCheckData != 0)
        {
            switch(iChoice)
            {
                case 1:
                    printf("Enter the data : \n");
                    iCheckData = scanf("%d", &iData);
                    if(iCheckData != 0)
                    {
                        insertFirst(&pFirst, iData);
                        display(pFirst);
                    }
                    else
                    {
                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                    }
                break;

                case 2:
                    printf("Enter the data : \n");
                    iCheckData = scanf("%d", &iData);
                    if(iCheckData != 0)
                    {
                        insertLast(&pFirst, iData);
                        display(pFirst);
                    } 
                    else
                    {
                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                    }
                break;

                case 3:
                    printf("Enter the Position : \n");
                    scanf("%d", &iPos);
                    iCount = countNodes(pFirst);
                    if(iPos < 1 || iPos > iCount + 1)
                    {
                        printf("\nERROR: Position is invalid.\n");
                    }
                    else
                    {
                        printf("Enter the data : \n");
                        iCheckData = scanf("%d", &iData);
                        if(iCheckData != 0)
                        {
                            insertAtPosition(&pFirst, iData, iPos);
                            display(pFirst);
                        }
                        else
                        {
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                        }
                    }
                break;

                case 4:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {
                        iDeletedData = deleteFirst(&pFirst);
                        display(pFirst);
                        printf("Deleted data is : %d\n", iDeletedData);
                    }
                break;

                case 5:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {
                        iDeletedData = deleteLast(&pFirst);
                        display(pFirst);
                        printf("Deleted data is : %d\n", iDeletedData);
                    }
                break;

                case 6:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {
                        printf("Enter the position : \n");
                        scanf("%d", &iPos);
                        iCount = countNodes(pFirst);
                        if(iPos < 1 || iPos > iCount)
                        {
                            printf("\nERROR: Position is invalid.\n");
                        }
                        else
                        {
                            iDeletedData = deleteAtPosition(&pFirst, iPos);
                            display(pFirst);
                            printf("Deleted data is : %d\n", iDeletedData);
                        }
                    }
                break;

                case 7:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {   
                        printf("\nPlease enter the data that you would like to search for :\n");
                        iCheckData = scanf("%d", &iData);

                        if(iCheckData != 0)
                        {
                            iOccurrence = searchFirstOccurrence(pFirst, iData);

                            if(iOccurrence != 0)
                            {   
                                printf("\nFirst occurrence of %d is at position %d.\n", iData, iOccurrence);
                            }
                            else
                            {
                                printf("\n%d not found.\n", iData);
                            }
                        }
                        else
                        {
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n"); 
                        }
                    }
                break;

                case 8:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {   
                        printf("\nPlease enter the data that you would like to search for :\n");
                        iCheckData = scanf("%d", &iData);

                        if(iCheckData != 0)
                        {
                            iOccurrence = searchLastOccurrence(pFirst, iData);

                            if(iOccurrence != 0)
                            {   
                                printf("\nLast occurrence of %d is at position %d\n", iData, iOccurrence);
                            }
                            else
                            {
                                printf("\n%d not found.\n", iData);
                            }
                        }
                        else
                        {
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n"); 
                        }
                    }
                break;

                case 9:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {   
                        printf("\nPlease enter the data that you would like to search for :\n");
                        iCheckData = scanf("%d", &iData);

                        if(iCheckData != 0)
                        {
                            iOccurrence = searchAllOccurrences(pFirst, iData);

                            printf("\n%d Occurred %d times\n", iData, iOccurrence);
                        }
                        else
                        {
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n"); 
                        }
                    }
                break;

                case 10:
                    iCount = countNodes(pFirst);
                    printf("\nCount of nodes is : %d\n", iCount);
                break;

                case 11:
                    while(1)
                    {   
                        fflush(stdin);
                        printf("\n1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Delete At Position\n5. Back\n");
                        printf(">_");
                        iCheckData = scanf("%d", &iChoice);

                        if(iCheckData != 0)
                        {
                            switch(iChoice)
                            {
                                case 1:
                                    printf("Enter the data : \n");
                                    iCheckData = scanf("%d", &iData);
                                    if(iCheckData != 0)
                                    {
                                        insertFirst(&pSecond, iData);
                                        display(pSecond);
                                    }
                                    else
                                    {
                                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                    }
                                break;

                                case 2:
                                    printf("Enter the data : \n");
                                    iCheckData = scanf("%d", &iData);
                                    if(iCheckData != 0)
                                    {
                                        insertLast(&pSecond, iData);
                                        display(pSecond);
                                    } 
                                    else
                                    {
                                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                    }
                                break;

                                case 3:
                                    iPos = 0;
                                    printf("Enter the Position : \n");
                                    scanf("%d", &iPos);
                                    iCount = countNodes(pSecond);
                                    if(iPos < 1 || iPos > iCount + 1)
                                    {
                                        printf("\nERROR: Position is invalid.\n");
                                    }
                                    else
                                    {
                                        printf("Enter the data : \n");
                                        iCheckData = scanf("%d", &iData);
                                        if(iCheckData != 0)
                                        {
                                            insertAtPosition(&pSecond, iData, iPos);
                                            display(pSecond);
                                        }
                                        else
                                        {
                                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                        }
                                    }
                                break;

                                case 4:
                                    if(pSecond == NULL)
                                    {
                                        printf("\nList is empty.\n");
                                    }
                                    else
                                    {
                                        printf("Enter the position : \n");
                                        scanf("%d", &iPos);
                                        iCount = countNodes(pSecond);
                                        if(iPos < 1 || iPos > iCount)
                                        {
                                            printf("\nERROR: Position is invalid.\n");
                                        }
                                        else
                                        {
                                            iDeletedData = deleteAtPosition(&pSecond, iPos);
                                            display(pSecond);
                                            printf("Deleted data is : %d\n", iDeletedData);
                                        }
                                    }
                                break;

                                case 5:
                                    concatList(&pFirst, &pSecond);
                                    display(pFirst);
                                    goto out;
                                break;

                                default:
                                    printf("\nERROR: Invalid option selected.\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                        }  
                    }
                break;

                case 12:
                    iCount = countNodes(pFirst);
                    printf("Enter the Position : \n");
                    scanf("%d", &iPos);

                    if(iPos < 1 || iPos > iCount + 1)
                    {
                        printf("\nERROR: Position is invalid.\n");
                    }
                    else
                    {
                        while(1)
                        {
                            fflush(stdin);
                            printf("\n1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Delete At Position\n5. Back\n");
                            printf(">_");
                            iCheckData = scanf("%d", &iChoice);

                            if(iCheckData != 0)
                            {
                                switch(iChoice)
                                {
                                    case 1:
                                        printf("Enter the data : \n");
                                        iCheckData = scanf("%d", &iData);
                                        if(iCheckData != 0)
                                        {
                                            insertFirst(&pSecond, iData);
                                            display(pSecond);
                                        }
                                        else
                                        {
                                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                        }
                                    break;

                                    case 2:
                                        printf("Enter the data : \n");
                                        iCheckData = scanf("%d", &iData);
                                        if(iCheckData != 0)
                                        {
                                            insertLast(&pSecond, iData);
                                            display(pSecond);
                                        } 
                                        else
                                        {
                                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                        }
                                    break;

                                    case 3:
                                        printf("Enter the Position : \n");
                                        scanf("%d", &iPosition);
                                        iCount = countNodes(pSecond);
                                        if(iPosition < 1 || iPosition > iCount + 1)
                                        {
                                            printf("\nERROR: Position is invalid.\n");
                                        }
                                        else
                                        {
                                            printf("Enter the data : \n");
                                            iCheckData = scanf("%d", &iData);
                                            if(iCheckData != 0)
                                            {
                                                insertAtPosition(&pSecond, iData, iPosition);
                                                display(pSecond);
                                            }
                                            else
                                            {
                                                printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                            }
                                        }
                                    break;

                                    case 4:
                                        if(pSecond == NULL)
                                        {
                                            printf("\nList is empty.\n");
                                        }
                                        else
                                        {
                                            printf("Enter the position : \n");
                                            scanf("%d", &iPosition);
                                            iCount = countNodes(pSecond);
                                            if(iPosition < 1 || iPosition > iCount)
                                            {
                                                printf("\nERROR: Position is invalid.\n");
                                            }
                                            else
                                            {
                                                iDeletedData = deleteAtPosition(&pSecond, iPosition);
                                                display(pSecond);
                                                printf("Deleted data is : %d\n", iDeletedData);
                                            }
                                        }
                                    break;

                                    case 5:
                                        concatAtPosition(&pFirst, &pSecond, iPos);
                                        display(pFirst);
                                        goto out;
                                    break;

                                    default:
                                        printf("\nERROR: Invalid option selected.\n");
                                    break;
                                }
                            }
                            else
                            {
                                printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                            }  
                        }
                    }
                break;

                case 13:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {
                        physicalReverse(&pFirst);
                        display(pFirst);
                    }
                break;

                case 14:
                    if(pFirst == NULL)
                    {
                        printf("\nList is empty.\n");
                    }
                    else
                    {
                        reverseDisplay(pFirst);
                    }
                break;

                case 15:
                    deleteAll(&pFirst);
                    pFirst = NULL;
                    printf("\nThank You for using our application !\n");
                    exit(0);
                break;

                default:
                    printf("\nERROR: Invalid option selected.\n");
                break;
            }
        }
        else
        {
            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
        }
    }
    return 0;
}