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

void kruskalMST(EDGE*, int, int, int*);
int cycleCheck(EDGE*, int, int, int);
int returnSrc(EDGE*, int, int, int*);
int returnDst(EDGE*, int, int, int*);

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
	kruskalMST(MST, size, nodeCount, &minCost);
	printf("\nThe total weight of the resultant MST is %d.\n", minCost);
	return 0;
}

void kruskalMST(EDGE *list, int len, int numNode, int *cost)
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
	/*printf("The edges in ascending order are:\n\n");
	for(i = 0; i < len; i++) 
		printf("%d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
	printf("\n\n");*/
	list[0].srcFlag = 1;
	for(i = 0; numEdge != numNode - 1; i++) // check asymptotic complexity
	{
		if(list[i].srcFlag == 1 && list[i].dstFlag == 0)
		{
			list[i].dstFlag = 1;
			list[i].visited = 1;
			for(j = 0; j < len; j++)
			{
				if(list[i].dst == list[j].src)
					list[j].srcFlag = 1;
				if(list[i].dst == list[j].dst)
					list[j].dstFlag = 1;
			}
			numEdge++;
			*cost += list[i].weight;
		}
		if(list[i].srcFlag == 0 && list[i].dstFlag == 1)
		{
			list[i].srcFlag = 1;
			list[i].visited = 1;
			for(j = 0; j < len; j++)
			{
				if(list[i].src == list[j].src)
					list[j].srcFlag = 1;
				if(list[i].src == list[j].dst)
					list[j].dstFlag = 1;
			}
			numEdge++;
			*cost += list[i].weight;
		}
		if(list[i].srcFlag == 0 && list[i].dstFlag == 0)
		{
			list[i].srcFlag = 1;
			list[i].dstFlag = 1;
			list[i].visited = 1;
			for(j = 0; j < len; j++)
			{
				if(list[i].src == list[j].src)
					list[j].srcFlag = 1;
				if(list[i].src == list[j].dst)
					list[j].dstFlag = 1;
				if(list[i].dst == list[j].src)
					list[j].srcFlag = 1;
				if(list[i].dst == list[j].dst)
					list[j].dstFlag = 1;
			}
			numEdge++;
			*cost += list[i].weight;
		}
		if(list[i].srcFlag == 1 && list[i].dstFlag == 1 && list[i].visited == 0) // checks connectedness and detects cycles
		{
			if(cycleCheck(list, len, list[i].src, list[i].dst) == FALSE)
			{
				list[i].visited = 1;
				numEdge++;
				*cost += list[i].weight;
			}
		}
	}
	printf("The MST is:\n\n");
	for(i = 0; i < len; i++)
		if(list[i].visited == 1)
			printf("%d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
}

int returnNextSrc(EDGE *list, int num, int keyDst, int *index) // returns the next source vertex and its index given a destination vertex
{
	int i = 0;
	for(i = *index; i < num; i++)
	{
		if(list[i].dst == keyDst)
		{
			*index = i;
			return list[i].src;
		}
	}
	return -1;
}

int returnNextDst(EDGE *list, int num, int keySrc, int *index) // returns the next destination vertex and its index given a source vertex
{
	int i = 0;
	for(i = *index; i < num; i++)
	{
		if(list[i].src == keySrc)
		{
			*index = i;
			return list[i].dst;
		}
	}
	return -1;
}

int cycleCheck(EDGE *list, int num, int src, int dst) // checks if connecting the source and the destination vertices will create a cycle
{
	int i = 0, pos = 0;
	for(i = 0; i < num; i++)  // maybe use a dictionary function of some sort like key - value pair
	{
		if(list[i].src == src && list[i].dst == dst)
			continue;
		//if(list[i].src = src && list[i].dst == returnNextDst(list, num, )
			
			
	}
	return FALSE;
}