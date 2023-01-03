#include<stdio.h>
#define MAX 10

void weightedGraph(void)
{
    int Data[MAX] = {0};
    int Graph[MAX][MAX] = {0};
    int iCnt1 = 0, iCnt2 = 0, iCnt3 = 0, iSize = 0, iNoVertices = 0, iVertex = 0, iWeight = 0;

    printf("How many vertices you want ?\n");
    scanf("%d", &iSize);

    if(iSize > 10)
        return;

    for(iCnt1 = 0; iCnt1 < iSize; iCnt1++)
    {
        printf("Enter %d data : ", iCnt1 + 1);
        scanf("%d", &Data[iCnt1]);
    }

    for(iCnt1 = 0; iCnt1 < iSize; iCnt1++)
    {
        printf("\nHow many adjacent vertices for %d ?\n", Data[iCnt1]);
        scanf("%d", &iNoVertices);

        for(iCnt2 = 0; iCnt2 < iNoVertices; iCnt2++)
        {
            printf("\nEnter %d vertex : ", iCnt2 + 1);
            scanf("%d", &iVertex);

            printf("Enter the weight of %d --> %d vertices : ", Data[iCnt1], iVertex);
            scanf("%d", &iWeight);

            for(iCnt3 = 0; iCnt3 < iSize; iCnt3++)
                if(Data[iCnt3] == iVertex)
                    Graph[iCnt1][iCnt3] = iWeight;
        }
    }

    printf("\nGraph is : \n");

    for(iCnt1 = 0; iCnt1 < iSize; iCnt1++)
    {
        printf("%d --> ", Data[iCnt1]);
        for(iCnt2 = 0; iCnt2 < iSize; iCnt2++)
            if(Graph[iCnt1][iCnt2] != 0)
                printf("%d(%d) ", Data[iCnt2], Graph[iCnt1][iCnt2]);
        printf("\n");
    }
}

int main(void)
{
    weightedGraph();

    return 0;
}