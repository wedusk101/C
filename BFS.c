/*The following code implements the breadth-first search(BFS) graph traversal technique using an adjacency list data structure.*/
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
	for(i = 0; i < size; i++)
	{	
		bak = list[i]; // backs up the pointer to the list
		while(list[i] != NULL)
		{
			printf("%c ", list[i]->nodeID);
			list[i] = list[i]->next;
		}
		printf("\n");
		list[i] = bak; // restores the backed up pointer
	}
}

int findNode(GPTR* list, int size, char frontier) // finds the index of a node in the adjacency list
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
	int i = frontier, out = 0;
	enqueue(&head, &tail, list[i]->nodeID);
	list[i]->discovered = 1; // marks the vertex as discovered to avoid duplicates
	while(!isEmpty(head))
	{
		out = dequeue(&head); // result of the traversal
		i = findNode(list, size, out); // finds out the index of the visited node in the adjacency list
		if(list[i]->visited != 1) // ignores vertices already visited
			printf("%c ", out);
		list[i]->visited = 1; // marks the vertex as visited
		bak = list[i]; 
		while(list[i] != NULL)
		{
			if(list[i]->visited != 1 && list[i]->discovered != 1)
			{
				enqueue(&head, &tail, list[i]->nodeID);
				list[i]->discovered = 1; // marks adjacent vertices as discovered
			}
			list[i] = list[i]->next;
		}
		list[i] = bak; 
	}	
}