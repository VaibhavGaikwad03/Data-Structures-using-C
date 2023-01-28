#include<stdio.h>
#include<malloc.h>

struct vertex
{
    struct vertex *pNextVertex;
    int iData;
    struct edge *pAdjEdge;
};

struct edge 
{
    struct vertex *pAdjVertex;
    struct edge *pNextAdjEdge;
};

void DirectionalGraph(struct vertex **ppHead)
{
    int iVertex = 0, iNoAdjVertices = 0, iCnt1 = 0, iAdjVertex = 0;
    struct vertex *pNewVertex = NULL;
    struct edge *pNewEdge = NULL;
    struct vertex *pTempVertex = NULL;
    struct vertex *pTravelVertex = NULL;
    struct edge *pTravelEdge = NULL;

    printf("\nEnter vertex : ");
    scanf("%d", &iVertex);

    pNewVertex = (struct vertex *)malloc(sizeof(struct vertex));

    pNewVertex->pNextVertex = NULL;
    pNewVertex->iData = iVertex;
    pNewVertex->pAdjEdge = NULL;

    if(*ppHead == NULL)
        *ppHead = pNewVertex;

    pTravelVertex = *ppHead;

    while(pTravelVertex != NULL)
    {
        printf("\nHow many adjacent vertices for %d : ", pTravelVertex->iData);
        scanf("%d", &iNoAdjVertices);

        for(iCnt1 = 1; iCnt1 <= iNoAdjVertices; iCnt1++)
        {
            printf("Enter %d vertex : ", iCnt1);
            scanf("%d", &iAdjVertex);

            pNewEdge = (struct edge *)malloc(sizeof(struct edge));
            
            pNewEdge->pNextAdjEdge = NULL;

            pTempVertex = *ppHead;

            while(pTempVertex != NULL)
            {
                /*
                already adjacent vertex present
                asla tr new edge chya adjacent vertex
                madhe already present asnarya vertex cha address taka
                */

                if(iAdjVertex == pTempVertex->iData)       
                {
                    pNewEdge->pAdjVertex = pTempVertex;
                    break;
                }
                pTempVertex = pTempVertex->pNextVertex;
            }

            if(pTempVertex == NULL)       //navin vertex create karava lagel
            {
                pTempVertex = *ppHead;

                while(pTempVertex->pNextVertex != NULL)
                    pTempVertex = pTempVertex->pNextVertex;

                pNewEdge->pAdjVertex = (struct vertex *)malloc(sizeof(struct vertex));

                pNewEdge->pAdjVertex->iData = iAdjVertex;
                pNewEdge->pAdjVertex->pAdjEdge = NULL;
                pNewEdge->pAdjVertex->pNextVertex = NULL;

                pTempVertex->pNextVertex = pNewEdge->pAdjVertex;
            }

            if(iCnt1 == 1)      //first edge create zali asel tr vertex chya adjacent edge madhe navin edge taka
                pTravelVertex->pAdjEdge = pNewEdge;

            else 
            {
                /*
                jar other than first edge create zali tr 
                travel kara joparyant travel edge chya next
                adjacent edge madhe null yet nahi toparynt ani 
                mg travel edge chya next adjacent edge madhe 
                navin edge takun dya
                */

                pTravelEdge = pTravelVertex->pAdjEdge;

                while(pTravelEdge->pNextAdjEdge != NULL)
                    pTravelEdge = pTravelEdge->pNextAdjEdge;

                pTravelEdge->pNextAdjEdge = pNewEdge;
            }

            pNewEdge = pNewEdge->pNextAdjEdge;
        }
        pTravelVertex = pTravelVertex->pNextVertex;
    }

    pTravelVertex = *ppHead;

    printf("\nGraph is : \n");

    while(pTravelVertex != NULL)
    {
        pTravelEdge = pTravelVertex->pAdjEdge;

        printf("%d --> ", pTravelVertex->iData);

        while(pTravelEdge != NULL)
        {
            printf("%d ", pTravelEdge->pAdjVertex->iData);
            pTravelEdge = pTravelEdge->pNextAdjEdge;
        }
        printf("\n");
        pTravelVertex = pTravelVertex->pNextVertex;
    }
}

int main(void)
{
    struct vertex *pFirst = NULL;

    DirectionalGraph(&pFirst);

    return 0;
}