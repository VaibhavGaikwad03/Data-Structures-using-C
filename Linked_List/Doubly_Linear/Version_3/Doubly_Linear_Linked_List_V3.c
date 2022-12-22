#include<stdio.h>
#include<stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct node
{
    int iData;
    struct node *pNext;
    struct node *pPrev;
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
        printf("List is empty.\n");
        return;
    }

    printf("Data from the linked list : \n");

    printf("NULL<->");
    while(pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

void insertFirst(struct node ** ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    pNewNode->pNext = *ppHead;
    if(*ppHead != NULL)
        (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
}

void insertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        pNewNode->pPrev = NULL;
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
        pNewNode->pPrev = pTemp;
    }
}

void insertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    int i = 0, iCount = 0;
    iCount = countNodes(*ppHead);
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    if(iPos < 1 || iPos > iCount + 1)
    {
        return;
    }

    if(iPos == 1)
    {
        insertFirst(ppHead, iNo);
        return;
    }


    pTemp = *ppHead;

    pNewNode = malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    pNewNode->pPrev = NULL;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }
    
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
    if(pNewNode->pNext != NULL)
        pNewNode->pNext->pPrev = pNewNode;
    pNewNode->pPrev = pTemp;
}

int deleteFirst(struct node **ppHead)
{
    int iDelData = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    pTemp = *ppHead;
    iDelData = pTemp->iData;
    *ppHead = (*ppHead)->pNext;
    if(pTemp->pNext != NULL)
        (*ppHead)->pPrev = NULL;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int deleteLast(struct node **ppHead)
{
    int iDelData = 0;

    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    if((*ppHead)->pNext == NULL)
    {
        iDelData = (*ppHead)->iData;
        free(*ppHead);
        *ppHead = NULL;

        return iDelData;
    }

    pTemp = *ppHead;

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    
    iDelData = pTemp->iData;
    pTemp->pPrev->pNext = NULL;
    pTemp->pPrev = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}

int deleteAtPosition(struct node **ppHead, int iPos)
{
    int i = 0, iCount = 0, iDelData = 0;
    iCount = countNodes(*ppHead);
    struct node *pTemp = NULL;

    if(iPos < 1 || iPos > iCount)
    {
        return -1;
    }

    if(iPos == 1)
    {
        return deleteFirst(ppHead);
    }

    pTemp = *ppHead;

    for(i = 1; i < iPos; i++)
    {
        pTemp = pTemp->pNext;
    }
    iDelData = pTemp->iData;
    pTemp->pPrev->pNext = pTemp->pNext;
    if(pTemp->pNext != NULL)
        pTemp->pNext->pPrev = pTemp->pPrev;
    pTemp->pNext = NULL;
    pTemp->pPrev = NULL;
    free(pTemp);
    pTemp = NULL;

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
    (*ppHead2)->pPrev = pTemp;
    *ppHead2 = NULL;
}

void concatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = countNodes(*ppHead1);

    if(iPos < 1 || iPos > iCount + 1)
        return;

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

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    if(pTemp1->pNext != NULL)
        pTemp1->pNext->pPrev = pTemp2;
    pTemp1->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp1; 

    *ppHead2 = pTemp1 = pTemp2 = NULL;
}

void physicalReverse(struct node **ppHead)
{
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pPrev;
        pCurrent->pPrev = pNext;
        pCurrent = pNext;
    }

    pCurrent = *ppHead;

    while(pCurrent->pPrev != NULL)
    {
        pCurrent = pCurrent->pPrev;
    }
    *ppHead = pCurrent;
}

void reverseDisplay(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while(pHead->pNext != NULL)
    {
        pHead = pHead->pNext;
    }

    printf("NULL<->");
    while(pHead != NULL)
    {
        printf("|%d|<->", pHead->iData);
        pHead = pHead->pPrev;
    }
    printf("NULL\n");
}

void deleteAll(struct node **ppHead)
{
    struct node *pTemp = *ppHead;

    while(pTemp != NULL)
    {
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
        pTemp = *ppHead;
    }
    *ppHead = pTemp = NULL;
}

int main()
{
    int iChoice = 0, iChoiceIn = 0, iCheckData = 0, iData = 0, iCount = 0, iPos = 0, iDeletedData = 0;
    int iOccurrence = 0, iPosition;
    BOOL bFlag = FALSE;
    struct node *pFirst = NULL; 
    struct node *pSecond = NULL;

    while(1)
    {
        fflush(stdin);
        printf("\nHello, Welcome...\nPlease choose from the below options : \n\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Reverse\n5. Count\n6. Concat\n7. Exit\n");
        printf(">_");
        iCheckData = scanf("%d", &iChoice);

        if(iCheckData != 0)
        {
            switch(iChoice)
            {
                case 1:
                    bFlag = TRUE;
                    while(bFlag)
                    {
                        fflush(stdin);
                        printf("\nPlease choose from the below options : \n\n");
                        printf("1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Back\n");
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
                                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
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
                                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
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
                                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                                        }
                                    }
                                break;

                                case 4:
                                    bFlag = FALSE;
                                break;

                                default:
                                    printf("\nERROR: Invalid option selected.\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                        }
                    }
                        
                break;

                case 2:
                    if(pFirst != NULL)
                    {
                        bFlag = TRUE;
                        while(bFlag)
                        {
                            fflush(stdin);
                            printf("\nPlease choose from the below options : \n\n");
                            printf("1. Delete First\n2. Delete Last\n3. Delete At Position\n4. Back\n");
                            printf(">_");
                            iCheckData = scanf("%d", &iChoice);

                            if(iCheckData != 0)
                            {
                                switch(iChoice)
                                {
                                    case 1:
                                        iDeletedData = deleteFirst(&pFirst);
                                        display(pFirst);
                                        if(iDeletedData != -1)
                                            printf("Deleted data is : %d\n", iDeletedData);
                                    break;

                                    case 2:
                                        iDeletedData = deleteLast(&pFirst);
                                        display(pFirst);
                                        if(iDeletedData != -1)
                                            printf("Deleted data is : %d\n", iDeletedData);
                                    break;

                                    case 3:
                                        if(pFirst != NULL)
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
                                                if(iDeletedData != -1)
                                                    printf("Deleted data is : %d\n", iDeletedData);
                                            }
                                        }
                                        else
                                        {
                                            printf("\nList is empty.\n");
                                        }
                                    break;

                                    case 4:
                                        bFlag = FALSE;
                                    break;

                                    default:
                                        printf("\nERROR: Invalid option selected.\n");
                                    break;
                                }
                            }
                            else
                            {
                                printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nList is empty.\n");
                    }
                break;

                case 3:
                    if(pFirst != NULL)
                    {
                        bFlag = TRUE;
                        while(bFlag)
                        {
                            fflush(stdin);
                            printf("\nPlease choose from the below options : \n\n");
                            printf("1. Search First Occurrence\n2. Search Last Occurrence\n3. Search All Occurrences\n4. Back\n");
                            printf(">_");
                            iCheckData = scanf("%d", &iChoice);

                            if(iCheckData != 0)
                            {
                                switch(iChoice)
                                {
                                    case 1:
                                        printf("Please enter the data that you would like to search for :\n");
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
                                    break;

                                    case 2:
                                        printf("Please enter the data that you would like to search for :\n");
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
                                    break;

                                    case 3:
                                        printf("Please enter the data that you would like to search for :\n");
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
                                    break;

                                    case 4:
                                        bFlag = FALSE;
                                    break;

                                    default:
                                        printf("\nERROR: Invalid option selected.\n");
                                    break;
                                }
                            }
                            else
                            {
                                printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nList is empty.\n");
                    }
                break;

                case 4:
                    if(pFirst != NULL)
                    {
                        bFlag = TRUE;
                        while(bFlag)
                        {
                            fflush(stdin);
                            printf("\nPlease choose from the below options : \n\n");
                            printf("1. Physical Reverse\n2. Display Reverse\n3. Back\n");
                            printf(">_");
                            iCheckData = scanf("%d", &iChoice);

                            if(iCheckData != 0)
                            {
                                switch(iChoice)
                                {
                                    case 1:
                                        physicalReverse(&pFirst);
                                        display(pFirst);
                                    break;

                                    case 2:
                                        reverseDisplay(pFirst);
                                    break;

                                    case 3:
                                        bFlag = FALSE;
                                    break;

                                    default:
                                        printf("\nERROR: Invalid option selected.\n");
                                    break;
                                }
                            }
                            else
                            {
                                printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nList is empty.\n");
                    }
                break;

                case 5:
                    iCount = countNodes(pFirst);
                    printf("\nCount of nodes is : %d\n", iCount);
                break;

                case 6:
                    bFlag = TRUE;
                    while(bFlag)
                    {   
                        fflush(stdin);
                        printf("\nPlease choose from the below options :\n");
                        printf("\n1. Concat List\n2. Concat At Position\n3. Back\n");
                        printf(">_");
                        iCheckData = scanf("%d", &iChoice);

                        if(iCheckData != 0)
                        {
                            switch(iChoice)
                            {
                                case 1:
                                    bFlag = TRUE;
                                    while(bFlag)
                                    {
                                        fflush(stdin);
                                        printf("\nPlease choose from the below options :\n");
                                        printf("\n1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Delete At Position\n5. Concat & Back\n");
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
                                                    bFlag = FALSE;
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
                                    bFlag = TRUE;
                                break;

                                case 2:
                                    iCount = countNodes(pFirst);
                                    printf("Enter the Position : \n");
                                    scanf("%d", &iPos);

                                    if(iPos < 1 || iPos > iCount + 1)
                                    {
                                        printf("\nERROR: Position is invalid.\n");
                                    }
                                    else
                                    {
                                        bFlag = TRUE;
                                        while(bFlag)
                                        {
                                            fflush(stdin);
                                            printf("\n1. Insert First\n2. Insert Last\n3. Insert At Position\n4. Delete At Position\n5. Concat & Back\n");
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
                                                        bFlag = FALSE;
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
                                        bFlag = TRUE;
                                    }
                                break;

                                case 3:
                                    bFlag = FALSE;
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

                case 7:
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
            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
        }

    }
    return 0;
}