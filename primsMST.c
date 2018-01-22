/*The following code implements the Prim-Jarnik-Dijkstra algorithm for generating a Minimum Spanning Tree (MST) from a given graph.*/ 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct edge
{
	int src;
	int dst;
	int weight;
	int visited;
};

typedef struct edge EDGE;

void primMST(EDGE*, int, int, int*, int*);

int main()
{
	int size = 0, nodeCount = 0, i = 0, minCost = 0, *node = NULL;
	printf("How many edges does the graph contain?\n");
	scanf("%d", &size);
	printf("How many nodes does the graph contain?\n");
	scanf("%d", &nodeCount);
	EDGE MST[size];
	node = malloc(nodeCount * sizeof(int));
	printf("Please enter the details of the graph in the following order:\n");
	printf("Source Node Number -> Destination Node Number -> Edge weight between the two nodes.\n");
	printf("Please note that nodes are numbered 0 through (n - 1) consecutively, where n is the number of nodes.\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &MST[i].src);
		scanf("%d", &MST[i].dst);
		scanf("%d", &MST[i].weight);
		MST[i].visited = 0;	// initialize the set of edges in the MST	
	}
	for(i = 0; i < nodeCount; i++)
		node[i] = 0; // initalize visited vertex set
	primMST(MST, size, nodeCount, node, &minCost);
	printf("\nThe total weight of the resultant MST is %d.\n", minCost);
	return 0;
}

void primMST(EDGE *list, int len, int numNode, int *node, int *cost)
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
	node[list[0].src] = 1;
	for(i = 0; numEdge != numNode - 1; i++) // check asymptotic complexity
	{
		if(i > len || i > numNode)	// prevents the index from going out of bounds
			i = 0;
		/*if((node[list[i].src] == 0 && node[list[i].dst] == 0) || (node[list[i].src] == 1 && node[list[i].dst] == 1 && list[i].visited == 0) || list[i].src == list[i].dst)
		{
			printf("Line 73 - Skipped %d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
			continue; // excludes disconnected edges and self loops and prevents cycles
		}*/
		if(node[list[i].src] == 1 && node[list[i].dst] == 0  && list[i].visited == 0)
		{
			printf("Line 78 - Entered with - %d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
			for(j = 0; j < len; j++)
			{
				if(list[j].src == list[i].dst && !((node[list[j].src] == 0 && node[list[j].dst] == 0) || (node[list[j].src] == 1 && node[list[j].dst] == 1 && list[j].visited == 0) || list[j].src == list[j].dst) && list[j].visited == 0 && list[j].weight <= list[i].weight)
				{
					list[j].visited = 1;
					node[list[j].src] = 1;
					node[list[j].dst] = 1;
					numEdge++;
					*cost += list[j].weight;
					printf("Line 88 - %d - %d ---> %d\n", list[j].src, list[j].dst, list[j].weight);
				}
				if(list[j].dst == list[i].dst && !((node[list[j].src] == 0 && node[list[j].dst] == 0) || (node[list[j].src] == 1 && node[list[j].dst] == 1 && list[j].visited == 0) || list[j].src == list[j].dst) && list[j].visited == 0 && list[j].weight <= list[i].weight)
				{
					list[j].visited = 1;
					node[list[j].src] = 1;
					node[list[j].dst] = 1;
					numEdge++;
					*cost += list[j].weight;
					printf("Line 97 - %d - %d ---> %d\n", list[j].src, list[j].dst, list[j].weight);
				}
				printf("Line 99 - Skipped %d - %d ---> %d\n", list[j].src, list[j].dst, list[j].weight);
			}
			if(!(node[list[i].src] == 1 && node[list[i].dst] == 1) && list[i].visited == 0)
			{
				list[i].visited = 1;
				node[list[i].src] = 1;
				node[list[i].dst] = 1;
				numEdge++;
				*cost += list[i].weight;
				printf("Line 108 - %d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
			}
		}
		if(node[list[i].src] == 0 && node[list[i].dst] == 1  && list[i].visited == 0)
		{
			printf("Line 113 - Entered with - %d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
			for(j = 0; j < len; j++)
			{
				if(list[j].src == list[i].src && !((node[list[j].src] == 0 && node[list[j].dst] == 0) || (node[list[j].src] == 1 && node[list[j].dst] == 1 && list[j].visited == 0) || list[j].src == list[j].dst) && list[j].visited == 0 && list[j].weight <= list[i].weight)
				{
					list[j].visited = 1;
					node[list[j].src] = 1;
					node[list[j].dst] = 1;
					numEdge++;
					*cost += list[j].weight;
					printf("Line 123 - %d - %d ---> %d\n", list[j].src, list[j].dst, list[j].weight);
				}
				if(list[j].dst == list[i].src && !((node[list[j].src] == 0 && node[list[j].dst] == 0) || (node[list[j].src] == 1 && node[list[j].dst] == 1 && list[j].visited == 0) || list[j].src == list[j].dst) && list[j].visited == 0 && list[j].weight <= list[i].weight)
				{
					list[j].visited = 1;
					node[list[j].src] = 1;
					node[list[j].dst] = 1;
					numEdge++;
					*cost += list[j].weight;
					printf("Line 132 - %d - %d ---> %d\n", list[j].src, list[j].dst, list[j].weight);
				}
				printf("Line 134 - Skipped %d - %d ---> %d\n", list[j].src, list[j].dst, list[j].weight);
			}
			if(!(node[list[i].src] == 1 && node[list[i].dst] == 1) && list[i].visited == 0)
			{
				list[i].visited = 1;
				node[list[i].src] = 1;
				node[list[i].dst] = 1;
				numEdge++;
				*cost += list[i].weight;
				printf("Line 143 - %d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
			}
		}
		//printf("Line 144 - Skipped all\n");
		/*if((node[list[i].src] == 0 && node[list[i].dst] == 0) || (node[list[i].src] == 1 && node[list[i].dst] == 1 && list[i].visited == 0) || list[i].src == list[i].dst)
		{
			printf("Line 73 - Skipped %d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
			continue; // excludes disconnected edges and self loops and prevents cycles
		}*/
	}
	printf("The MST is:\n\n");
	for(i = 0; i < len; i++)
		if(list[i].visited == 1)
			printf("%d - %d ---> %d\n", list[i].src, list[i].dst, list[i].weight);
}	