#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

struct graphNode
{
	char nodeID;
	int visited;
	struct graphNode *next;
};

typedef struct graphNode* GPTR;

void bfs(GPTR*, int);
GPTR createNode();
void displayList(GPTR*, int);

int main()
{
	int order = 0, i = 0, j = 0;
	char root;
	printf("Please enter the number of vertices in the graph.\n\n");
	scanf("%d", &order);
	GPTR adj[order];
	printf("Please enter the information for the adjacency list representation of the graph.\n\n");
	for(i = 0; i < order; i++)
		adj[i] = createNode();
	printf("The created adjacency list is as follows:\n\n");
	displayList(adj, order);
	return 0;	
}

GPTR createNode()
{
	GPTR newNode;
	char id, choice;
	newNode = malloc(sizeof(struct graphNode));
	newNode->visited = 0;
	printf("Please enter a character node ID for the vertex.\n\n");
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
	for(i = 0; i < size; i++)
	{
		while(list[i] != NULL)
		{
			printf("%c ", list[i]->nodeID);
			list[i] = list[i]->next;
		}
		printf("\n");
	}
}