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

int countNodes(struct node *pHead, struct node *pTail)
{
    int iCount = 0;

    if(pHead == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCount;
}

void display(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Data from the linked list : \n");
    do
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    printf("\n");
}

void insertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
        return;

    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;           
    }
    else
    {
        pNewNode->pNext = *ppHead;      
        (*ppHead)->pPrev = pNewNode;   
        *ppHead = pNewNode;
    }       
    (*ppHead)->pPrev = *ppTail;        
    (*ppTail)->pNext = *ppHead;        
}

void insertLast(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
        return;

    pNewNode->iData = iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;             
        *ppTail = pNewNode;           
    }
    else
    {
        pNewNode->pPrev = *ppTail;
        (*ppTail)->pNext = pNewNode;
        *ppTail = pNewNode;
    }
    (*ppHead)->pPrev = *ppTail;        
    (*ppTail)->pNext = *ppHead;
}

void insertAtPosition(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = countNodes(*ppHead, *ppTail);

    if(iPos < 1 || iPos > iCount + 1)
        return;

    if(iPos == 1)
        insertFirst(ppHead, ppTail, iNo);
    else if(iPos == iCount + 1)
        insertLast(ppHead, ppTail, iNo);
    else
    {
        pTemp = *ppHead;
        pNewNode = (struct node*)malloc(sizeof(struct node));
        pNewNode->iData = iNo;

        for(i = 1; i < iPos - 1; i++)
        {
            pTemp = pTemp->pNext;
        }
        pNewNode->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pNewNode;
        pTemp->pNext = pNewNode;
        pNewNode->pPrev = pTemp;
    }
}

int deleteFirst(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;

    if(*ppHead == NULL)
        return -1;

    iDelData = (*ppHead)->iData;

    if(*ppHead == *ppTail)
    {
        free(*ppHead);
        *ppHead = *ppTail = NULL;
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        free((*ppTail)->pNext);

        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int deleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData = 0;

    if(*ppHead == NULL)
        return -1;

    if(*ppHead == *ppTail)
    {
        iDelData = (*ppTail)->iData;
        free(*ppTail);
        *ppHead = *ppTail = NULL;
    }
    else
    {
        *ppTail = (*ppTail)->pPrev;
        iDelData = (*ppTail)->pNext->iData;
        free((*ppTail)->pNext);
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
    }
    return iDelData;
}

int deleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
    int iCount = 0, i = 0, iDelData = 0;
    struct node *pTemp = NULL;

    iCount = countNodes(*ppHead, *ppTail);

    if(iPos < 1 || iPos > iCount)
        return -1;

    if(iPos == 1)
        return deleteFirst(ppHead, ppTail);

    else if(iPos == iCount)
        return deleteLast(ppHead, ppTail);

    else
    {
        pTemp = *ppHead;

        for(i = 1; i < iPos; i++)
        {
            pTemp = pTemp->pNext;
        }

        iDelData = pTemp->iData;
        pTemp->pPrev->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pTemp->pPrev;

        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        free(pTemp);
        pTemp = NULL;

        return iDelData;
    }
}

int searchFirstOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountPos = 0;

    if(pHead == NULL)
    {
        return iCountPos;
    }

    do
    {
        iCountPos++;
        if(pHead->iData == iKey)
            break;
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);  

    if(pHead == pTail->pNext)
        iCountPos = 0;
    
    return iCountPos;
}

int searchLastOccurrence(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountPos = 0, iRetPos = 0;

    if(pHead == NULL)
        return iRetPos;

    do
    {   
        iCountPos++;
        if(pHead->iData == iKey)
            iRetPos = iCountPos;
        
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iRetPos;
}

int searchAllOccurrences(struct node *pHead, struct node *pTail, int iKey)
{
    int iCountOcc = 0;

    if(pHead == NULL)
        return iCountOcc;
    
    do
    {
        if(pHead->iData == iKey)
            iCountOcc++;

        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCountOcc;
}

void concatList(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2)
{
    if(*ppHead2 == NULL)
        return;

    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;

        return;
    }

    (*ppTail1)->pNext = *ppHead2;
    (*ppHead2)->pPrev = *ppTail1;
    *ppTail1 = *ppTail2;
    (*ppHead1)->pPrev = *ppTail1;
    (*ppTail1)->pNext = *ppHead1;

    *ppHead2 = *ppTail2 = NULL;
}

void concatAtPosition(struct node **ppHead1, struct node **ppTail1, struct node **ppHead2, struct node **ppTail2, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp = NULL;

    iCount = countNodes(*ppHead1, *ppTail1);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Position is invalid\n");
        return;
    }

    if(ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        concatList(ppHead2, ppTail2, ppHead1, ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = *ppTail2 = NULL;

        return;
    }

    if(iPos == iCount + 1)
    {
        concatList(ppHead1, ppTail1, ppHead2, ppTail2);
        return;
    }

    pTemp = *ppHead1;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }

    (*ppTail2)->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = *ppTail2;
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;

    *ppHead2 = *ppTail2 = NULL;
}

void physicalReverse(struct node **ppHead, struct node **ppTail)
{
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    if(*ppHead == NULL)
        return;

    do
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pPrev;
        pCurrent->pPrev = pNext;
        pCurrent = pNext;
    }while(pCurrent != *ppHead);

    *ppHead = *ppTail;
    *ppTail = pCurrent;
}

void reverseDisplay(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("|%d|->", pTail->iData);
        pTail = pTail->pPrev;
    }while(pTail != pHead->pPrev);
    printf("\n");
}

void deleteAll(struct node **ppHead, struct node **ppTail)
{
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
        return;

    pTemp = *ppHead;
    (*ppTail)->pNext = NULL;

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
    int iChoice = 0, iChoiceIn = 0, iCheckData = 0, iData = 0, iCount = 0, iPos = 0, iDeletedData = 0;
    int iOccurrence = 0, iPosition;
    BOOL bFlag = FALSE;
    
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;

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
                                        insertFirst(&pFirst, &pLast, iData);
                                        display(pFirst, pLast);
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
                                        insertLast(&pFirst, &pLast, iData);
                                        display(pFirst, pLast);
                                    } 
                                    else
                                    {
                                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                                    }
                                break;

                                case 3:
                                    printf("Enter the Position : \n");
                                    scanf("%d", &iPos);
                                    iCount = countNodes(pFirst, pLast);
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
                                            insertAtPosition(&pFirst, &pLast, iData, iPos);
                                            display(pFirst, pLast);
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
                                        iDeletedData = deleteFirst(&pFirst, &pLast);
                                        display(pFirst, pLast);
                                        if(iDeletedData != -1)
                                            printf("Deleted data is : %d\n", iDeletedData);
                                    break;

                                    case 2:
                                        iDeletedData = deleteLast(&pFirst, &pLast);
                                        display(pFirst, pLast);
                                        if(iDeletedData != -1)
                                            printf("Deleted data is : %d\n", iDeletedData);
                                    break;

                                    case 3:
                                        if(pFirst != NULL)
                                        {
                                            printf("Enter the position : \n");
                                            scanf("%d", &iPos);
                                            iCount = countNodes(pFirst, pLast);
                                            if(iPos < 1 || iPos > iCount)
                                            {
                                                printf("\nERROR: Position is invalid.\n");
                                            }
                                            else
                                            {
                                                iDeletedData = deleteAtPosition(&pFirst, &pLast, iPos);
                                                display(pFirst, pLast);
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
                                            iOccurrence = searchFirstOccurrence(pFirst, pLast, iData);

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
                                            iOccurrence = searchLastOccurrence(pFirst, pLast, iData);

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
                                            iOccurrence = searchAllOccurrences(pFirst, pLast, iData);

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
                                        physicalReverse(&pFirst, &pLast);
                                        display(pFirst, pLast);
                                    break;

                                    case 2:
                                        reverseDisplay(pFirst, pLast);
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
                    iCount = countNodes(pFirst, pLast);
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
                                                        insertFirst(&pFirst1, &pLast1, iData);
                                                        display(pFirst1, pLast1);
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
                                                        insertLast(&pFirst1, &pLast1, iData);
                                                        display(pFirst1, pLast1);
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
                                                    iCount = countNodes(pFirst1, pLast1);
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
                                                            insertAtPosition(&pFirst1, &pLast1, iData, iPos);
                                                            display(pFirst1, pLast1);
                                                        }
                                                        else
                                                        {
                                                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                                        }
                                                    }
                                                break;

                                                case 4:
                                                    if(pFirst1 == NULL)
                                                    {
                                                        printf("\nList is empty.\n");
                                                    }
                                                    else
                                                    {
                                                        printf("Enter the position : \n");
                                                        scanf("%d", &iPos);
                                                        iCount = countNodes(pFirst1, pLast1);
                                                        if(iPos < 1 || iPos > iCount)
                                                        {
                                                            printf("\nERROR: Position is invalid.\n");
                                                        }
                                                        else
                                                        {
                                                            iDeletedData = deleteAtPosition(&pFirst1, &pLast1, iPos);
                                                            display(pFirst1, pLast1);
                                                            printf("Deleted data is : %d\n", iDeletedData);
                                                        }
                                                    }
                                                break;

                                                case 5:
                                                    concatList(&pFirst, &pLast, &pFirst1, &pLast1);
                                                    display(pFirst, pLast);
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
                                    iCount = countNodes(pFirst, pLast);
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
                                                            insertFirst(&pFirst1, &pLast1, iData);
                                                            display(pFirst1, pLast1);
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
                                                            insertLast(&pFirst1, &pLast1, iData);
                                                            display(pFirst1, pLast1);
                                                        } 
                                                        else
                                                        {
                                                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                                        }
                                                    break;

                                                    case 3:
                                                        printf("Enter the Position : \n");
                                                        scanf("%d", &iPosition);
                                                        iCount = countNodes(pFirst1, pLast1);
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
                                                                insertAtPosition(&pFirst1, &pLast1, iData, iPosition);
                                                                display(pFirst1, pLast1);
                                                            }
                                                            else
                                                            {
                                                                printf("\nPlease enter only integer values. Non-integer values will cause errors in the program.\n");
                                                            }
                                                        }
                                                    break;

                                                    case 4:
                                                        if(pFirst1 == NULL)
                                                        {
                                                            printf("\nList is empty.\n");
                                                        }
                                                        else
                                                        {
                                                            printf("Enter the position : \n");
                                                            scanf("%d", &iPosition);
                                                            iCount = countNodes(pFirst1, pLast1);
                                                            if(iPosition < 1 || iPosition > iCount)
                                                            {
                                                                printf("\nERROR: Position is invalid.\n");
                                                            }
                                                            else
                                                            {
                                                                iDeletedData = deleteAtPosition(&pFirst1, &pLast1, iPosition);
                                                                display(pFirst1, pLast1);
                                                                printf("Deleted data is : %d\n", iDeletedData);
                                                            }
                                                        }
                                                    break;

                                                    case 5:
                                                        concatAtPosition(&pFirst, &pLast, &pFirst1, &pLast1, iPos);
                                                        display(pFirst, pLast);
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
                    deleteAll(&pFirst, &pLast);
                    pFirst = NULL;
                    pLast = NULL;
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