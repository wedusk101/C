/*The following code is work in progess and implements a point quad tree with a few of its basic operations.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct point
{
	float x;
	float y;
	char name[10];
};

struct treeNode
{
	struct point coo;
	struct treeNode *nw;
	struct treeNode *ne;
	struct treeNode *se;
	struct treeNode *sw;
};

typedef struct treeNode *NODEPTR;

void initTree(NODEPTR*); 																	// initiliazes the tree
int searchPQT(NODEPTR, NODEPTR*, NODEPTR*, float, float, int*);								// searches for a point in the quadtree and returns a pointer to it and its parent
void relDirection(NODEPTR, NODEPTR*, NODEPTR*, float, float, float, float, int*); 			// returns the relative direction between a source and a destination
void insertNodePQT(NODEPTR*, NODEPTR*, NODEPTR*, char*, float, float, int*);				// inserts a point into the quad tree
void displayTree(NODEPTR);																	// displays all the points in the tree
float calcDistance(float, float, float, float);												// calculates the Euclidean distance between two points
int countNodePQT(NODEPTR);																	// returns the total number of nodes in a tree
int countLeafPQT(NODEPTR);																	// returns the total number of leaf nodes in a tree
void naiveNN(NODEPTR, NODEPTR*, float*, float, float);										// naive implementation of nearest neighbor search for a given point
//NODEPTR copyPQT(NODEPTR);																	// creates a copy of a tree which can be during the deletion of a point
// delete a point																			// deletes a point from the tree by reinserting its children recursively
//distance radius search																	// searches for points in a given radius from a given point
// modify a point																			/* Updates the coordinates of a particular point while preserving the quadtree structure.This can be done by deleting a chosen point and reinserting the new point.*/

int main()
{
	NODEPTR center, index, parentIndex;
	center = NULL;
	initTree(&center);
	index = parentIndex = NULL;
	int choice = 0, child = 0; // child ----> 1 = NE, 2 = NW, 3 = SW, 4 = SE
	float key_x = 0, key_y = 0, key_x2, key_y2, minDist = 0;
	char inputName[10];
	printf("This program implements a point quad tree with the following basic operations.\n");
	do
	{
		printf("\n----------- MENU -------------\n");
        printf("\n 1. Insert a point into the point quad tree.\n");
		printf("\n 2. Search for a point in the tree.\n");
		printf("\n 3. Display the contents of the point quad tree.\n");
		printf("\n 4. Calculate the Euclidean distance between two points in the tree.\n");
		printf("\n 5. Find out the relative direction between two points in the tree.\n");
		printf("\n 6. Count the number of nodes in the tree.\n");
		printf("\n 7. Count the number of leaf nodes in the tree.\n");
		printf("\n 8. Find the nearest neighbor of a given point.\n");
		printf("\n 0. EXIT \n");
        printf("\n------------------------------\n");
        printf("\nPlease enter your choice : ");
        scanf("%d",&choice);
		switch(choice)
		{	case 1: 	printf("\nPlease enter the point as x-y coordinate tuple.\n");
						scanf("%f",&key_x);
						scanf("%f",&key_y);
						printf("Please enter a name for the point. No two points should have the same name.\n");
						setbuf(stdin, NULL);	// removes pending newline from the buffer from the last input
						fgets(inputName, 10, stdin);
						strtok(inputName, "\n");	// removes pending newline from the buffer after the string input
						index = parentIndex = NULL;
						child = 0;
						insertNodePQT(&center, &index, &parentIndex, inputName, key_x, key_y, &child);
						break;
			
			case 2:		printf("Please enter the point to search for.\n");
						scanf("%f",&key_x);
						scanf("%f",&key_y);
						index = parentIndex = NULL;
						child = 0;
						if(key_x == 0 && key_y == 0)
						{
							printf("Point found!\n");
							printf("The point is the origin O(0,0).\n");
							break;
						}
						else if(searchPQT(center, &index, &parentIndex, key_x, key_y, &child) == TRUE)
						{
							printf("Point found!\n");
							printf("The point is %s(%4.2f,%4.2f).\n", index->coo.name, index->coo.x, index->coo.y);
							printf("Its parent node is %s(%4.2f,%4.2f).\n", parentIndex->coo.name, parentIndex->coo.x, parentIndex->coo.y);
						}
						else
							printf("Point not found.\n");
						break;
					
			case 3:		printf("The points in the plane are:\n");
						displayTree(center);
						break;
						
			case 4:		printf("Please enter the first point.\n");
						scanf("%f",&key_x);
						scanf("%f",&key_y);
						printf("Please enter the second point.\n");
						scanf("%f",&key_x2);
						scanf("%f",&key_y2);
						index = parentIndex = NULL;
						child = 0;
						if(searchPQT(center, &index, &parentIndex, key_x, key_y, &child) == TRUE	&& searchPQT(center, &index, &parentIndex, key_x2, key_y2, &child) == TRUE)
							printf("The distance between the two points is %4.2f units.", calcDistance(key_x, key_y, key_x2, key_y2));
						else
							printf("One or both points is/are not in the tree. Operation aborted.\n");							
						break;
						
			case 5:		printf("Please enter the coordinates of the source point.\n");
						scanf("%f",&key_x);
						scanf("%f",&key_y);
						printf("Please enter the coordinates of the destination point.\n");
						scanf("%f",&key_x2);
						scanf("%f",&key_y2);
						relDirection(center, &index, &parentIndex, key_x, key_y, key_x2, key_y2, &child);
						break;
						
			case 6:		printf("The number of nodes in the tree is %d.\n", countNodePQT(center));
						break;
						
			case 7:		printf("The number of leaf nodes in the tree is %d.\n", countLeafPQT(center));
						break;
						
			case 8:		printf("Please enter the coordinates of the point.\n");
						scanf("%f",&key_x);
						scanf("%f",&key_y);
						index = parentIndex = NULL;
						child = 0;
						minDist = 1000000; // start with a large radius of search using a big number
						if(searchPQT(center, &index, &parentIndex, key_x, key_y, &child) == FALSE)
						{
							printf("Point not found.\n");
							break;
						}						
						index = NULL;
						naiveNN(center, &index, &minDist, key_x, key_y);
						printf("The nearest neighbor is %s(%4.2f,%4.2f) at a distance of %4.2f units.\n", index->coo.name, index->coo.x, index->coo.y, minDist);
						break;
						
			case 0:		printf("Thank you.\n");
						break;
					
			default:	printf("\nInvalid choice. Try again.\n");
		}
	}while(choice != 0);
} // end

void insertNodePQT(NODEPTR *proot, NODEPTR* index, NODEPTR* parentIndex, char* pname, float valx, float valy, int* child) // recursively inserts a point into the tree
{
	NODEPTR tmp;
	tmp = malloc(sizeof(struct treeNode));
	tmp->coo.x = valx;
	tmp->coo.y = valy;
	strncpy(tmp->coo.name, pname, 10);
	tmp->nw = tmp->ne = tmp->se = tmp->sw = NULL;
	if(searchPQT(*proot, index, parentIndex, valx, valy, child) != TRUE)
	{
		if(*proot == NULL)
		{
			*proot = tmp;
			printf("Point inserted succesfully.\n");
			return;
		}
		if(valx == (*proot)->coo.x) // handles multiple points on an axis with the same x coordinate
		{
			if(valy > (*proot)->coo.y)
			{
				if((*proot)->nw == NULL)
				{
					insertNodePQT(&(*proot)->nw, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				if((*proot)->ne == NULL)
				{
					insertNodePQT(&(*proot)->ne, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				printf("Error occured! Point could not be inserted. Try inserting some other point first."); // this condition needs to be handled somehow
				return;			
			}
			else if(valy < (*proot)->coo.y)
			{
				if((*proot)->sw != NULL)
				{
					insertNodePQT(&(*proot)->sw, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				if((*proot)->se != NULL)
				{
					insertNodePQT(&(*proot)->se, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				printf("Error occured! Point could not be inserted. Try inserting some other point first."); // this condition needs to be handled somehow
				return;
			}
		}
		else if(valy == (*proot)->coo.y)	// handles multiple points on an axis with the same Y coordinate
		{
			if(valx > (*proot)->coo.x)
			{
				if((*proot)->ne != NULL)
				{
					insertNodePQT(&(*proot)->ne, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				if((*proot)->se != NULL)
				{
					insertNodePQT(&(*proot)->ne, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				printf("Error occured! Point could not be inserted. Try inserting some other point first.");
				return; 				
			}
			else if(valx < (*proot)->coo.x)
			{
				if((*proot)->nw != NULL)
				{
					insertNodePQT(&(*proot)->nw, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				if((*proot)->sw != NULL)
				{
					insertNodePQT(&(*proot)->sw, index, parentIndex, &(*pname), valx, valy, child);
					return;
				}
				printf("Error occured! Point could not be inserted. Try inserting some other point first.");
				return;
			}
		}
		else if(valx > (*proot)->coo.x)
		{
			if(valy > (*proot)->coo.y)
				insertNodePQT(&(*proot)->ne, index, parentIndex, &(*pname), valx, valy, child);
			else if(valy < (*proot)->coo.y)
				insertNodePQT(&(*proot)->se, index, parentIndex, &(*pname), valx, valy, child);			
		}
		else if(valx < (*proot)->coo.x)
		{
			if(valy > (*proot)->coo.y)
				insertNodePQT(&(*proot)->nw, index, parentIndex, &(*pname), valx, valy, child);
			else if(valy < (*proot)->coo.y)
				insertNodePQT(&(*proot)->sw, index, parentIndex, &(*pname), valx, valy, child);
		}
	}
	else
		printf("Operation failed! Point already exists.\n");
}

void initTree(NODEPTR* proot) // initiliazes the tree with (0,0) as the origin
{
	*proot = malloc(sizeof(struct treeNode));
	(*proot)->coo.x = 0;
	(*proot)->coo.y = 0;
	strncpy((*proot)->coo.name, "O", 10);
	(*proot)->nw = NULL;
	(*proot)->ne = NULL;
	(*proot)->se = NULL;
	(*proot)->sw = NULL;	
}

void displayTree(NODEPTR root) // recursively displays the contents of the tree
{
	if(root != NULL)
	{
		printf("%s(%4.2f,%4.2f) ", root->coo.name, root->coo.x, root->coo.y);
		displayTree(root->nw);
		displayTree(root->ne);
		displayTree(root->se);
		displayTree(root->sw);
	}
}

int searchPQT(NODEPTR root, NODEPTR* index, NODEPTR* parentIndex, float valx, float valy, int* child) // recursively searches the tree for a point
{
	NODEPTR tmp;	// used as a backup pointer
	if(root == NULL)
		return FALSE;
	if((root->coo.x) == valx && (root->coo.y) == valy)	// condition for successful search
	{
		*index = root;	// returns a pointer to the found element
		return TRUE;
	}
	if(valx > (root->coo.x))
	{
		if(valy > (root->coo.y))
		{
			if(root->ne == NULL)
				return FALSE;
			else
			{	
				tmp = root; // backs up the pointer to the root of the tree
				root = root->ne; // traverses to the NE branch of the tree
			}
			if((root->coo.x) == valx && (root->coo.y) == valy) // checks if the search succeeds
			{
				*index = root;	// returns a pointer to the node being searched for in case of a successful search
				root = tmp;
				*parentIndex = root; // returns a pointer to the parent node of the point being searched for
				*child = 1; // NE quadrant
				return TRUE;
			}
			
		}
		if(valy < (root->coo.y))
		{
			if(root->se == NULL)
				return FALSE;
			else
			{	
				tmp = root;
				root = root->se;
			}
			if((root->coo.x) == valx && (root->coo.y) == valy)
			{
				*index = root;
				root = tmp;
				*parentIndex = root;
				*child = 4; // SE quadrant
				return TRUE;
			}
			
		}
	}
	if(valx < (root->coo.x))
	{
		if(valy > (root->coo.y))
		{
			if(root->nw == NULL)
				return FALSE;
			else
			{
				tmp = root;
				root = root->nw;
			}
			if((root->coo.x) == valx && (root->coo.y) == valy)
			{
				*index = root;
				root = tmp;
				*parentIndex = root;
				*child = 2; // NW quadrant
				return TRUE;
			}
			
		}
		if(valy < (root->coo.y))
		{
			if(root->sw == NULL)
				return FALSE;
			else
			{	
				tmp = root;
				root = root->sw;
			}
			if((root->coo.x) == valx && (root->coo.y) == valy)
			{
				*index = root;
				root = tmp;
				*parentIndex = root;
				*child = 3; // SW quadrant
				return TRUE;
			}
			
		}
	}
	if(valx > (root->coo.x)) 
	{
		if(valy > (root->coo.y))
		{
			*parentIndex = root; // returns a pointer to the parent of the node
			searchPQT(root->ne, index, parentIndex, valx, valy, child);
		}
		else if(valy < (root->coo.y))
		{	
			*parentIndex = root;
			searchPQT(root->se, index, parentIndex, valx, valy, child);
		}
	}
	else if(valx < (root->coo.x))
	{
		if(valy > (root->coo.y))
		{
			*parentIndex = root;
			searchPQT(root->nw, index, parentIndex, valx, valy, child);
		}
		else if(valy < (root->coo.y))
		{
			*parentIndex = root;
			searchPQT(root->sw, index, parentIndex, valx, valy, child);
		}
	}
}

float calcDistance(float valx1, float valy1, float valx2, float valy2)
{
	return sqrt(pow(valx1 - valx2, 2) + pow(valy1 - valy2, 2));
}

void relDirection(NODEPTR root, NODEPTR* index, NODEPTR* parentIndex, float valx1, float valy1, float valx2, float valy2, int* child)
{
	if(searchPQT(root, index, parentIndex, valx1, valy1, child) == TRUE	&& searchPQT(root, index, parentIndex, valx2, valy2, child) == TRUE) // checks if the points are present in the tree
	{
		if(valx2 > valx1)
		{
			if(valy2 > valy1)
			{
				printf("The destination lies to the north-east of the source.\n");
				return;
			}
			else if(valy2 < valy1)
			{
				printf("The destination lies to the south-east of the source.\n");
				return;
			}
		}
		if(valx2 < valx1)
		{
			if(valy2 > valy1)
			{
				printf("The destination lies to the north-west of the source.\n");
				return;
			}
			else if(valy2 < valy1)
			{
				printf("The destination lies to the south-west of the source.\n");
				return;
			}
		}
		if(valx1 == valx2)
		{
			if(valy2 > valy1)
			{
				printf("The destination lies to the north of the source.\n");
				return;
			}
			else if(valy2 < valy1)
			{
				printf("The destination lies to the south of the source.\n");
				return;
			}			
		}
		if(valy1 == valy2)
		{
			if(valx2 > valx1)
			{
				printf("The destination lies to the east of the source.\n");
				return;
			}
			else if(valy2 < valy1)
			{
				printf("The destination lies to the west of the source.\n");
				return;
			}
		}
	}
	else
		printf("One or both points is/are not in the tree.Operation aborted.\n");
}

int countNodePQT(NODEPTR root) // recursively counts the number of nodes in the tree
{
	if(root	!=	NULL)
		return 1 + countNodePQT(root->nw) + countNodePQT(root->ne) + countNodePQT(root->se) + countNodePQT(root->sw);
	else
		return 0;
}

int countLeafPQT(NODEPTR root) // recursively counts the leaf nodes in the tree
{
	if(root == NULL)
		return 0;
	if(root != NULL)
	{
		if(root->nw == NULL && root->ne == NULL && root->se == NULL && root->sw == NULL)
			return 1;
		else
			return countLeafPQT(root->nw) + countLeafPQT(root->ne) + countLeafPQT(root->se)	+ countLeafPQT(root->sw);	
	}
}

void naiveNN(NODEPTR root, NODEPTR* index, float* nearestDist, float valx, float valy) // recursively finds the nearest neighbor for a given point
{
	float dist = 0;
	if(root != NULL)
	{
		if(root->coo.x != valx && root->coo.y != valy) // excludes the user given point from the calculations for nearest neighbor
		{
			dist = calcDistance(valx, valy, root->coo.x, root->coo.y);	// this function doesn't work yet for points on the same axis
			if(dist < (*nearestDist))
			{		
				*nearestDist = dist;
				*index = root;
			}
		}
		naiveNN(root->nw, index, nearestDist, valx, valy);
		naiveNN(root->ne, index, nearestDist, valx, valy);
		naiveNN(root->se, index, nearestDist, valx, valy);
		naiveNN(root->sw, index, nearestDist, valx, valy);		
	}
}