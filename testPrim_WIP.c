#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct edge
{
	int src;
	int dst;
	int weight;
	int srcFlag;
	int dstFlag;
	int visited;
};

typedef struct edge EDGE;

void primMST(EDGE*, int, int, int*);

int main()
{
	int size = 0, nodeCount = 0, i = 0, minCost = 0;
	printf("How many edges does the graph contain?\n");
	scanf("%d", &size);
	printf("How many nodes does the graph contain?\n");
	scanf("%d", &nodeCount);
	EDGE MST[size];
	printf("Please enter the details of the graph in the following order:\n");
	printf("Source Node Number -> Destination Node Number -> Edge weight between the two nodes.\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &MST[i].src);
		scanf("%d", &MST[i].dst);
		scanf("%d", &MST[i].weight);
		MST[i].srcFlag = 0;
		MST[i].dstFlag = 0;
		MST[i].visited = 0;	// initialize the tree	
	}
	primMST(MST, size, nodeCount, &minCost);
	printf("\nThe total weight of the resultant MST is %d.\n", minCost);
	return 0;
}

void primMST(EDGE *list, int len, int numNode, int *cost)
{
	int i = 0, j = 0, numEdge = 0;
	EDGE tmp;
	for(i = 0; i < len; i++) // sorts the structures in ascending order according to the weights
	{
		for( j = i + 1; j < len + 1; j++)
		{
			if(list[i].weight > list[j].weight)
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
	printf("The edges in ascending order are:\n\n");
	for(i = 0; i < len; i++) 
		printf("%d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
	printf("\n\n");
	list[0].srcFlag = 1;
	for(i = 0; numEdge != numNode - 1; i++) // check asymptotic complexity
	{
		if(i > len)
			i = 0;
		//printf("Inner :  Src - %d Dst - %d srcFlag - %d  dstFlag - %d \n", list[i].src, list[i].dst, list[i].srcFlag, list[i].dstFlag);
		//printf("%d\n", i);
		if(list[i].srcFlag == 1 && list[i].dstFlag == 1)
			continue;
		if(list[i].srcFlag == 1 && list[i].dstFlag == 0)
		{
			list[i].dstFlag = 1;
			list[i].visited = 1;
			//printf("Src - %d Dst - %d srcFlag - %d  dstFlag - %d \n", list[i].src, list[i].dst, list[i].srcFlag, list[i].dstFlag);
			for(j = 0; j < len; j++)
			{
				if(list[j].src == list[i].dst)
					list[j].srcFlag = 1;
				if(list[j].dst == list[i].dst)
					list[j].dstFlag = 1;
			}
			numEdge++;
			*cost += list[i].weight;
		}
		if(list[i].srcFlag == 0 && list[i].dstFlag == 1)
		{
			list[i].srcFlag = 1;
			list[i].visited = 1;
			//printf("Src - %d Dst - %d srcFlag - %d  dstFlag - %d \n", list[i].src, list[i].dst, list[i].srcFlag, list[i].dstFlag);
			for(j = 0; j < len; j++)
			{
				if(list[j].src == list[i].src)
					list[j].srcFlag = 1;
				if(list[j].src == list[i].dst)
					list[j].dstFlag = 1;
			}
			numEdge++;
			*cost += list[i].weight;
		}
		//printf("Outer :  Src - %d Dst - %d srcFlag - %d  dstFlag - %d \n", list[i].src, list[i].dst, list[i].srcFlag, list[i].dstFlag);		
	}
	printf("The MST is:\n\n");
	for(i = 0; i < len; i++)
		if(list[i].visited == 1)
			printf("%d - %d ---> %d  srcFlag - %d  dstFlag - %d \n", list[i].src, list[i].dst, list[i].weight, list[i].srcFlag, list[i].dstFlag);
}	