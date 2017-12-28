#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

struct graphNode
{
	char nodeID;
	int visited;
	int discovered;
	struct graphNode *next;
};

typedef struct graphNode* GPTR;

void bfs(GPTR*, int, int);
GPTR createNode();
void displayList(GPTR*, int);
int findNode(GPTR*, int, char);

int main()
{
	int order = 0, i = 0, j = 0, rootIndex = 0;
	char root; // frontier of the search
	printf("Please enter the number of vertices in the graph.\n\n");
	scanf("%d", &order);
	GPTR adj[order];
	printf("Please enter the information for the adjacency list representation of the graph.\n\n");
	for(i = 0; i < order; i++)
	{
		printf("Please enter a character node ID for vertex %d.\n\n", i + 1);
		adj[i] = createNode();
	}
	printf("The created adjacency list is as follows:\n\n");
	displayList(adj, order);
	printf("Please enter the node ID of the frontier of the search.\n\n");
	scanf(" %c", &root);
	printf("Searching for node...\n\n");
	rootIndex = findNode(adj, order, root);	
	if(rootIndex == -1)
		printf("Node with given node ID not found in the graph. Operation aborted!\n\n");
	else
	{
		printf("Node found! The breadth first traversal is as follows:\n\n");
		bfs(adj, order, rootIndex);
		printf("\n");
	}
	return 0;	
}

GPTR createNode()
{
	GPTR newNode;
	char id, choice;
	newNode = malloc(sizeof(struct graphNode));
	newNode->visited = 0; // initialize the vertices
	newNode->discovered = 0;
	scanf(" %c", &id);
	newNode->nodeID = id;
	newNode->next = NULL;
	printf("Would you like to link more nodes to the current node? (Y/N)\n\n");
	scanf(" %c", &choice);
	if(choice == 'Y' || choice == 'y')
		newNode->next = createNode();
	return newNode;
}

void displayList(GPTR* list, int size)
{
	int i = 0;
	GPTR bak;
	bak = *list;
	for(i = 0; i < size; i++)
	{	
		bak = list[i];
		while(list[i] != NULL)
		{
			printf("%c ", list[i]->nodeID);
			list[i] = list[i]->next;
		}
		printf("\n");
		list[i] = bak;
	}
}

int findNode(GPTR* list, int size, char frontier)
{
	int i = 0;
	GPTR bak;
	for(i = 0; i < size; i++)
	{
		if(list[i] == NULL)
			break;
		if(list[i]->nodeID == frontier)
			return i;
	}
	return -1;
}

void bfs(GPTR* list, int size, int frontier)
{
	NODEPTR head, tail;
	head = tail = NULL;
	GPTR bak;
	int i = frontier;
	printf("Frontier : %d\n", i);
	enqueue(&head, &tail, i);
	while(!isEmpty(head))
	{
		printf("CHECK\n");
		bak = list[i];
		while(list[i] != NULL)
		{
			if(list[i]->visited != 1 && list[i]->discovered != 1)
			{
				enqueue(&head, &tail, i);
				list[i]->discovered = 1;
			}
			list[i] = list[i]->next;
		}
		list[i] = bak;
		i = dequeue(&head);
		printf("125 i = %d\n", i);
		list[i]->visited = 1;
		printf("%c ", list[i]->nodeID);
		list[i] = list[i]->next;
		i = findNode(list, size, list[i]->nodeID);
		printf("New Frontier : %d\n", i);
	}	
}