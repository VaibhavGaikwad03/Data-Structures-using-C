#include"customheader.h"

//insertBTS
//deleteBST
//searchBST
//countNodes
//countLeafNodes
//countNonLeafNodes
//heightOfTree
//findSmallest
//findLargest

void preorder(struct node *pRoot)
{
    if(pRoot == NULL)
        return;

    printf("%d ", pRoot->iData);
    preorder(pRoot->pLeft);
    preorder(pRoot->pRight);
}

void inorder(struct node *pRoot)
{
    if(pRoot == NULL)
        return;

    inorder(pRoot->pLeft);
    printf("%d ", pRoot->iData);
    inorder(pRoot->pRight);
}

void postorder(struct node *pRoot)
{
    if(pRoot == NULL)
        return;

    postorder(pRoot->pLeft);
    postorder(pRoot->pRight);
    printf("%d ", pRoot->iData);

}

void levelOrderTraversal(struct node *pRoot)
{
    int iCounter = 0;
    struct node *pPtr = NULL;
    struct Qnode *pQueue = NULL;

    if(pRoot == NULL)
        return;

    enQueue(&pQueue, pRoot);

    while(!isQueueEmpty(pQueue))
    {
        pPtr = deQueue(&pQueue);
        printf("%d ", pPtr->iData);

        if(pPtr->pLeft != NULL)
            enQueue(&pQueue, pPtr->pLeft);

        if(pPtr->pRight != NULL)  
            enQueue(&pQueue, pPtr->pRight);  
    }
}

void insertBST(struct node **ppRoot, int iNo)
{
    struct node *pPtr = NULL;
    struct node *pParent = NULL;

    pPtr = *ppRoot;

    while(pPtr != NULL)
    {
        pParent = pPtr;

        if(iNo < pPtr->iData)
            pPtr = pPtr->pLeft;
        
        else if(iNo > pPtr->iData)
            pPtr = pPtr->pRight;

        else
        {
            printf("\nDuplicate Data.\n");
            return;
        }
    }

    pPtr = (struct node *)malloc(sizeof(struct node));

    if(pPtr == NULL)
    {
        printf("\nMemory allocation FAILED\n");
        return;
    }

    pPtr->iData = iNo;
    pPtr->pLeft = pPtr->pRight = NULL;

    if(pParent == NULL)
        *ppRoot = pPtr;
    
    else if(iNo < pParent->iData)
        pParent->pLeft = pPtr;
    
    else
        pParent->pRight = pPtr;
}

void deleteNodeBST(struct node **ppRoot, int iNo)
{
    struct node *pPtr = NULL;
    struct node *pParent = NULL;
    struct node *pSuccessor = NULL;
    struct node *pParentSuccessor = NULL;
    struct node *pChild = NULL;

    //searching data to be deleted

    pPtr = *ppRoot;

    while(pPtr != NULL)
    {
        if(pPtr->iData == iNo)
            break;
        
        pParent = pPtr;
        if(iNo < pPtr->iData)
            pPtr = pPtr->pLeft;

        else
            pPtr = pPtr->pRight;
    }

    if(pPtr == NULL)
    {
        printf("\nThe data to be deleted could not be found.\n");
        return;
    }

    //for both childs scenario
    if(pPtr->pLeft != NULL && pPtr->pRight == NULL)
    {
        pParentSuccessor = pPtr;
        pSuccessor = pPtr->pRight;      //once right

        while(pSuccessor->pLeft != NULL)    //complete left
        {
            pParentSuccessor = pSuccessor;
            pSuccessor = pSuccessor->pLeft;
        }//found inorder successor

        pPtr->iData = pSuccessor->iData;

        pPtr = pSuccessor;
        pParent = pParentSuccessor;
    }

    //one child scenario

    if(pPtr->pLeft != NULL)
        pChild = pPtr->pLeft;

    else
        pChild = pPtr->pRight;              //handles no child scenario also

    if(pParent == NULL)
        *ppRoot = pChild;
    
    else if(pPtr == pParent->pLeft)
        pParent->pLeft = pChild;
    
    else
        pParent->pRight = pChild;

    free(pPtr);
}

struct node * searchBST(struct node *pRoot, int iKey)
{
    if(pRoot == NULL)
        return NULL;

    if(iKey < pRoot->iData)
        return searchBST(pRoot->pLeft, iKey);
    else if(iKey > pRoot->iData)
        return searchBST(pRoot->pRight, iKey);
    else
        return pRoot;
}

void countNodes(struct node *pRoot, int *piCount)
{
    if(pRoot != NULL)
    {
        ++(*piCount);
        countNodes(pRoot->pLeft, piCount);
        countNodes(pRoot->pRight, piCount);
    }
}

void countLeafNodes(struct node *pRoot, int *piCount)
{
    if(pRoot != NULL)
    {
        if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
            ++(*piCount);

        countLeafNodes(pRoot->pLeft, piCount);
        countLeafNodes(pRoot->pRight, piCount);
    }
}

void countNonLeafNodes(struct node *pRoot, int *piCount)
{
    if(pRoot != NULL)
    {
        if(pRoot->pLeft != NULL || pRoot->pRight != NULL)
            ++(*piCount);
        
        countNonLeafNodes(pRoot->pLeft, piCount);
        countNonLeafNodes(pRoot->pRight, piCount);
    }
}

int heightOfTree(struct node *pRoot)
{
    int iLeftHeight = 0, iRightHeight = 0;

    if(pRoot == NULL)
        return 0;

    iLeftHeight = heightOfTree(pRoot->pLeft);
    iRightHeight = heightOfTree(pRoot->pRight);

    if(iLeftHeight > iRightHeight)
        return 1 + iLeftHeight;
    return 1 + iRightHeight;
}

int findSmallestBST(struct node *pRoot)
{
    while(pRoot->pLeft != NULL)
        pRoot = pRoot->pLeft;

    return pRoot->iData;
}

int findLargestBST(struct node *pRoot)
{
    while(pRoot->pRight != NULL)
        pRoot = pRoot->pRight;
    
    return pRoot->iData;
}

int main(void)
{
    BOOL bFlag = TRUE;
    struct node *pRet = NULL;
    struct node *pRoot = NULL;
    int iChoice = 0, iCheckData = 0, iData = 0, iRet = 0, iCount = 0;

    printf("\nHello, Welcome...");
    while(1)
    {
        fflush(stdin);
        printf("\nPlease choose from the below options,\n");
        printf("\n1. Insert Node\n2. Delete Node\n3. Search\n4. Traverse\n5. Count Nodes\n6. Count Leaf Nodes\n7. Count Non Leaf Nodes\n8. Find Smallest\n9. Find Largest\n10. Find Height of the Tree\n11. Exit\n>_");
        iCheckData = scanf("%d", &iChoice);

        if(iCheckData)
        {
            switch(iChoice)
            {
                case 1:

                    printf("\nEnter the data : \n");
                    iCheckData = scanf("%d", &iData);
                    if(iCheckData)
                    {
                        insertBST(&pRoot, iData);
                        if(pRoot != NULL)
                        {
                            printf("\nData from the tree is : \n");
                            inorder(pRoot);
                        }
                        else
                            printf("\nTree is empty.\n");
                        printf("\n");
                    }
                    else
                        printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                    break;

                case 2:

                    if(pRoot != NULL)
                    {
                        printf("\nEnter the data to delete : \n");
                        iCheckData = scanf("%d", &iData);
                        
                        if(iCheckData)
                        {
                            deleteNodeBST(&pRoot, iData);
                            printf("\nData from the tree is : \n");
                            inorder(pRoot);
                            printf("\n");
                        }
                        else
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                    }
                    else
                        printf("\nTree is empty.\n");
                    break;

                case 3:

                    if(pRoot != NULL)
                    {
                        printf("\nEnter the data to search : \n");
                        iCheckData = scanf("%d", &iData);

                        if(iCheckData)
                        {
                            pRet = searchBST(pRoot, iData);
                            if(pRet != NULL)
                                printf("\nWe have found the data you requested.\n");
                            else
                                printf("\nWe have not found the data you requested.\n");
                        }
                        else
                            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");
                    }
                    else
                        printf("\nTree is empty.\n");
                    break;

                case 4:
                    bFlag = TRUE;
                    while(bFlag)
                    {
                        printf("\n1. Breadth first search\n2. Depth first search\n3. Back\n>_");
                        iCheckData = scanf("%d", &iChoice);

                        if(iCheckData != 0)
                        {
                            switch(iChoice)
                            {
                                case 1:

                                    if(pRoot != NULL)
                                    {
                                        printf("\nIn level order traversal : \n");
                                        levelOrderTraversal(pRoot);
                                        printf("\n");
                                    }
                                    else
                                        printf("\nTree is empty.\n");

                                    break;

                                case 2:
                                    bFlag = TRUE;
                                    while(bFlag)
                                    {
                                        printf("\n1. Preorder\n2. Inorder\n3. Postorder\n4. Back\n>_");
                                        iCheckData = scanf("%d", &iChoice);

                                        if(iCheckData != 0)
                                        {
                                            switch(iChoice)
                                            {
                                                case 1:

                                                    if(pRoot != NULL)
                                                    {
                                                        printf("\nData in preorder traversal : \n");
                                                        preorder(pRoot);
                                                        printf("\n");
                                                    }
                                                    else
                                                        printf("\nTree is empty.\n");

                                                    break;

                                                case 2:

                                                    if(pRoot != NULL)
                                                    {
                                                        printf("\nData in inorder traversal : \n");
                                                        inorder(pRoot);
                                                        printf("\n");
                                                    }
                                                    else
                                                        printf("\nTree is empty.\n");

                                                    break;

                                                case 3:

                                                    if(pRoot != NULL)
                                                    {
                                                        printf("\nData in postorder traversal : \n");
                                                        postorder(pRoot);
                                                        printf("\n");
                                                    }
                                                    else
                                                        printf("\nTree is empty.\n");

                                                    break;

                                                case 4:

                                                    bFlag = FALSE;

                                                    break;

                                                default:
                                                    printf("\nInvalid option selected.\n"); 

                                            }
                                        }
                                    }
                                    bFlag = TRUE;

                                    break;

                                case 3:

                                    bFlag = FALSE;

                                    break;

                                default:
                                    printf("\nInvalid option selected.\n");
                            }
                        }
                    }

                    break;

                case 5:

                    iCount = 0;
                    countNodes(pRoot, &iCount);
                    printf("\nCount of nodes is : %d\n", iCount);
                    break;

                case 6:

                    iCount = 0;
                    countLeafNodes(pRoot, &iCount);
                    printf("\nCount of leaf nodes is : %d\n", iCount);

                    break;

                case 7:

                    iCount = 0;
                    countNonLeafNodes(pRoot, &iCount);
                    printf("\nCount of non leaf nodes is : %d\n", iCount);

                    break;

                case 8:

                    iRet = findSmallestBST(pRoot);
                    printf("\nSmallest number is : %d\n", iRet);

                    break;

                case 9:

                    iRet = findLargestBST(pRoot);
                    printf("\nLargest number is : %d\n", iRet);

                    break;

                case 10:

                    iRet = heightOfTree(pRoot);
                    printf("\nHeight of the tree is : %d\n", iRet);

                    break;

                case 11:
                    
                    printf("\nThank You for using our application !\n");
                    exit(0);

                    break;

                default:
                    printf("\nInvalid option selected.\n");
                    
            }
        }
        else
            printf("\nPlease enter only integer values. Non-integer values will cause errors in the program !\n");

    }

    return 0;
}