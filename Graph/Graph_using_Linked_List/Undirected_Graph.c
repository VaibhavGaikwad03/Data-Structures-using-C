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
    struct vrtex *pAdjVertex;
    struct edge *pNextAdjEdge;
};

void undirectionalGraph(struct vertex **ppHead)
{
    int iVertex = 0, iNoVertices = 0, iCnt1 = 0, iAdjVertices = 0;
    struct vertex *pVertex = NULL;
    struct edge *pEdge = NULL;

    while(1)
    {
        pVertex = (struct vertex *)malloc(sizeof(struct vertex));
        printf("Enter vertex : ");
        scanf("%d", &iVertex);

        pVertex->iData = iVertex;
        pVertex->pNextVertex = NULL;
        pVertex->pAdjEdge = NULL;

        printf("How many adjacent vertices for %d ?", iVertex);
        scanf("%d", &iNoVertices);

        for(iCnt1 = 1; iCnt1 <= iNoVertices; iCnt1++)
        {
            pEdge = (struct edge *)malloc(sizeof(struct edge));

            if(pVertex->pAdjEdge == NULL)
                pVertex->pAdjEdge = &pEdge;
            else
                
            
            printf("Enter %d vertex : ", iCnt1);
            scanf("%d", &iAdjVertices);
        }
    }
}

int main(void)
{
    struct vertex *pHead = NULL;

    undirectionalGraph(&pHead);

    return 0;
}