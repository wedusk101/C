/*The following code implements a Binary Search Tree (BST) with a few of its basic operations.*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// #define DEBUG 1 // uncomment for memory debug mode

int allocCount = 0;

struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;
};

typedef struct treeNode *NODEPTR;

int countNodeBST(NODEPTR); 											// counts the number of nodes in the tree
void insertNodeBST(NODEPTR*, int); 									// inserts a node into the tree
void deleteNodeBST(NODEPTR*, NODEPTR*, NODEPTR*, int, int*); 		// deletes a node from the tree
int countLeafBST(NODEPTR); 											// counts the number of leaf nodes in the tree
int calcHeightBST(NODEPTR); 										// calculates the height of the tree
NODEPTR createTree(int); 											// creates a new binary search tree
void displayInorderBST(NODEPTR);								    // displays the inorder traversal of the tree
void displayPreorderBST(NODEPTR);									// displays the preorder traversal of the tree
void displayPostorderBST(NODEPTR); 									// displays the post order traversal of the tree
int searchBST(NODEPTR, NODEPTR*, NODEPTR*, int, int*); 				// searches the tree for a particular element and returns a pointer to the node and its parent
void initTree(NODEPTR*); 											// initializes the tree
int max(int, int);                  							    // returns the greater of two values
int getNodeDepth(NODEPTR, int);                           			// returns the depth of a given node in the BST
void delRoot(NODEPTR*);												// deletes the root of the tree
void displayBST(NODEPTR);											// displays the BST
void mirrorBST(NODEPTR*);											// mirror the BST
void displayNodesAtDepth(NODEPTR, int, int);						// displays all nodes at a given depth
void displayLevelOrderBST(NODEPTR);										// displays the level order traversal of the BST
void delBST(NODEPTR*);                                           	// deletes a BST
void swapNodes(NODEPTR*, NODEPTR*);									// swaps two nodes of the tree

int main()
{
	NODEPTR root, index, parentIndex;
	initTree(&root);
	int choice = 0, x = 0, child = 0;
	printf("This program implements a binary search tree with the following basic operations.\n");
	do
	{
		printf("\n----------- MENU -------------\n");
        printf("\n 1.  Create a binary search tree.\n");
		printf("\n 2.  Insert an element into the binary search tree.\n");
		printf("\n 3.  Delete an element from the binary search tree.\n");
		printf("\n 4.  Count the nodes in the binary search tree.\n");
		printf("\n 5.  Count the leaf nodes in the binary search tree.\n");
		printf("\n 6.  Find out the height of the binary search tree.\n");
		printf("\n 7.  Display the inorder traversal of the binary search tree.\n");
		printf("\n 8.  Display the preorder traversal of the binary search tree.\n");
		printf("\n 9.  Display the postorder traversal of the binary search tree.\n");
		printf("\n 10. Search for an element in the binary search tree.\n");
		printf("\n 11. Get the depth of a node with a particular value in the binary search tree.\n");
		printf("\n 12. Delete the root of the tree.\n");
		printf("\n 13. Display the level order traversal of the binary search tree.\n");
		printf("\n 14. Laterally invert the binary search tree. This will break the BST and will require reinverting it to be restored.\n");
		// printf("\n 15. Display the binary search tree.\n");
		printf("\n 0.  EXIT \n");
        printf("\n------------------------------\n");
        printf("\nPlease enter your choice : ");
        scanf("%d",&choice);
		switch(choice)
		{	case 1: 	printf("\nPlease enter the first element of the tree.\n");
						scanf("%d",&x);
						root = createTree(x);
						printf("Element inserted. Tree created successfully.\n");
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif
						break;
			
			case 2: 	printf("Please enter the element to insert.\n");
						scanf("%d",&x);
						insertNodeBST(&root, x);
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif
						break;
					
			case 3: 	printf("Please enter the element to delete.\n");
						scanf("%d",&x);
						index = parentIndex = NULL;
						child = 0;
						deleteNodeBST(&root, &index, &parentIndex, x, &child); // this function is dependent on searchBST() and delRoot()
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif
						break;
						
			case 4:		printf("The number of nodes in the tree is %d.\n", countNodeBST(root));
						break; 
						
			case 5:		printf("The number of leaf nodes in the tree is %d.\n", countLeafBST(root));
						break;
						
			case 6:		printf("The height of the tree is %d.\n", calcHeightBST(root));
						break; 
						
			case 7:		if(root == NULL)
						{
							printf("Tree is empty!\n");
							break;
						}
						displayInorderBST(root);
						
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif						
						break;
						
			case 8:		if(root == NULL)
						{
							printf("Tree is empty!\n");
							break;
						}
						displayPreorderBST(root);
						
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif						
						break;
						
			case 9:		if(root == NULL)
						{
							printf("Tree is empty!\n");
							break;
						}
						displayPostorderBST(root);
						
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif						
						break;
						
			case 10:	printf("Please enter the element you want to search for.\n");
						scanf("%d",&x);
						child = 0;
						index = parentIndex = NULL;
						if(searchBST(root, &index, &parentIndex, x, &child) == TRUE) 
							printf("Element found! Parent is %d.", parentIndex->data);
						else
							printf("Element not found.\n");
						break;
						
			case 11:	printf("Please enter the element you want the depth of.\n");
						scanf("%d",&x);
						child = 0;
						index = parentIndex = NULL;
						if(searchBST(root, &index, &parentIndex, x, &child) == TRUE) 
							printf("Depth of the element is %d.", getNodeDepth(root, x));
						else
							printf("Element not found.\n");
						break;
			
			case 12:	if(root == NULL)
						{
							printf("Empty tree. Operation aborted.\n");
							break;
						}
						delRoot(&root);
						printf("Root deleted successfully.\n");
						
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif
						break;
						
			case 13:	displayLevelOrderBST(root);
						
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif
						
						break;
						
			case 14:	mirrorBST(&root);
						printf("Tree mirrored successfully.\n");
						break;
						
			// case 15:	displayBST(root);
						// break;
			
			case 0:		delBST(&root);
						printf("Thank you.\n");
						#ifdef DEBUG
							printf("\nTotal number of memory allocations: %d\n", allocCount);
						#endif
						break;
					
			default:	printf("\nInvalid choice. Try again.\n");
		}
	}while(choice != 0);
	delBST(&root); // cleanup
	
	#ifdef DEBUG
		printf("\nTotal number of memory allocations: %d\n", allocCount);
	#endif
						
	return 0;
} // end

void initTree(NODEPTR* proot)
{
	*proot = NULL;
}

NODEPTR createTree(int val) // creates a tree with the user input value as the root
{
	NODEPTR tmp;
	tmp = malloc(sizeof(struct treeNode));
	if(tmp == NULL)
	{
		perror("Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}
	allocCount++;
	tmp->data = val;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void insertNodeBST(NODEPTR* proot, int val) // recursively inserts an element into the tree
{
	if(*proot == NULL)
	{
		*proot = createTree(val);
		printf("Element inserted successfully.\n");
		return;
	}
	if(val < (*proot)->data)
		insertNodeBST(&((*proot)->left), val);
	else if(val > (*proot)->data)
		insertNodeBST(&((*proot)->right), val);
	else
	{
		printf("Operation failed! Element already exists.\n");
		return;
	}
}

void swapNodes(NODEPTR* pa, NODEPTR* pb)
{
	NODEPTR tmp = *pb;
	*pb = *pa;
	*pa = tmp;	
}

void mirrorBST(NODEPTR* proot)
{
	if(*proot == NULL)
		return;
		
	NODEPTR parent = *proot;
	swapNodes(&(parent->left), &(parent->right));
			
	mirrorBST(&(parent->left));
	mirrorBST(&(parent->right));	
}

/*
void displayBST(root)
{
	
}
*/

void displayLevelOrderBST(NODEPTR root)
{
	int maxDepth = calcHeightBST(root);
	for(int i = 0; i <= maxDepth; i++)
		displayNodesAtDepth(root, 0, i);
}

void displayNodesAtDepth(NODEPTR root, int currentDepth, int maxDepth)
{
	if(root == NULL)
		return;
		
	if(currentDepth == maxDepth)
	{
		printf("%d ", root->data);
		return;
	}
	displayNodesAtDepth(root->left, currentDepth + 1, maxDepth);
	displayNodesAtDepth(root->right, currentDepth + 1, maxDepth);
}		

void displayInorderBST(NODEPTR root) // recursively displays the inorder traversal of the tree
{
	if(root != NULL)
	{
		displayInorderBST(root->left);
		printf("%d ", root->data);
		displayInorderBST(root->right);
	}
}

int countNodeBST(NODEPTR root) // recursively counts the number of nodes in the tree
{
	if(root	!=	NULL)
		return 1 + countNodeBST(root->left) + countNodeBST(root->right);
	else
		return 0;
}

int getNodeDepth(NODEPTR root, int val) // recursively calculates the depth of a given node in the tree
{
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	if(root->data == val)
		return 0;
	else if (val < (root->data))
		return 1 + getNodeDepth(root->left, val);
	else
		return 1 + getNodeDepth(root->right, val);
}

void displayPreorderBST(NODEPTR root) // recursively displays the preorder traversal of the tree
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		displayPreorderBST(root->left);
		displayPreorderBST(root->right);
	}
}

void displayPostorderBST(NODEPTR root) // recursively displays the postorder traversal of the tree
{
	if(root != NULL)
	{
		displayPostorderBST(root->left);
		displayPostorderBST(root->right);
		printf("%d ", root->data);
	}
}

int countLeafBST(NODEPTR root) // recursively counts the leaf nodes in the tree
{
	if(root == NULL)
		return 0;
	if(root != NULL)
	{
		if(root->left == NULL && root->right == NULL)
			return 1;
		else
			return countLeafBST(root->left) + countLeafBST(root->right);		
	}
}

int searchBST(NODEPTR root, NODEPTR* index, NODEPTR* parentIndex, int val, int* child) // recursively searches the tree for an element
{
	NODEPTR tmp = root; // backs up the pointer to the root into a temporary pointer
	if(root == NULL)
		return FALSE;
	if((root->data) == val)
	{
		if(*parentIndex == NULL)
			*parentIndex = root;
			
		*index = root;		// returns a pointer to the found element
		return TRUE;
	}
	if(val < (root->data))
	{
		if(root->left == NULL)
			return FALSE;
		*parentIndex = root; // backs up the pointer to the parent of the current node
		root = root->left;
		if((root->data) == val) // checks if the left child is the required element
		{
			*index = root;
			root = tmp;
			*child = -1; // -1 for left child
			return TRUE;
		}
		searchBST(root, index, parentIndex, val, child);
	}
	else
	{
		if(root->right == NULL)
			return FALSE;
		*parentIndex = root; // backs up the pointer to the parent of the current node
		root = root->right;
		if((root->data) == val)	// checks if the right child is the required element
		{
			*index = root;
			root = tmp;
			*child = 1; 	// 1 for right child
			return TRUE;
		}
		searchBST(root, index, parentIndex, val, child);
	}
}

int calcHeightBST(NODEPTR root) // recursively calculates the height of the tree
{
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	else
		return max(calcHeightBST(root->left), calcHeightBST(root->right)) + 1;	
}

int max(int x, int y)
{
	if(x > y)
		return x;
	else
		return y;
}

void deleteNodeBST(NODEPTR* proot, NODEPTR* index, NODEPTR* parentIndex, int val, int* child) // deletes a node with specific value
{
	if(proot == NULL)
	{
		printf("Empty tree. Operation aborted.\n");
		return;
	}
	if(searchBST(*proot, index, parentIndex, val, child) == FALSE) // search for the element fails 
	{
		printf("Element not found! Operation failed.\n");
		return;
	}
	else if((*index)->left != NULL && (*index)->right == NULL)	// the node to be deleted has only left child
	{
		if(*child == 1)
			(*parentIndex)->right = (*index)->left; // connects the right child of the parent to the left child of the node to be deleted
		if(*child == -1)
			(*parentIndex)->left = (*index)->left;	// connects the left child of the parent to the left child of the node to be deleted
		delRoot(index);
		return;
	}
	else if((*index)->left == NULL && (*index)->right != NULL)	// the node to be deleted has only right child
	{
		if(*child == 1)
			(*parentIndex)->right = (*index)->right; // connects the right child of the parent to the left child of the node to be deleted
		if(*child == -1)
			(*parentIndex)->left = (*index)->right;	// connects the left child of the parent to the left child of the node to be deleted
		delRoot(index);
		return;
	}
	else if((*index)->left == NULL && (*index)->right == NULL && (*parentIndex) == NULL) // the node to be deleted is the only node in the tree
	{
		*proot = NULL;
		delRoot(index);
		return;
	}
	else if(*index == *proot) // if the node to be deleted is the root of the tree
	{
		delRoot(index); // deletes the root of the tree
		*proot = *index; // restores the original pointer to the root of the tree
		return;		
	}
	else
	{
		if((*index)->left == NULL && (*index)->right == NULL) // the node to be deleted has no children
		{
			if(*child == -1)
				(*parentIndex)->left = NULL; // sets the left child of the parent of the element to be deleted to NULL
			if(*child == 1)
				(*parentIndex)->right = NULL; // sets the right child of the parent of the element to be deleted to NULL
		}
		if((*index)->left != NULL && (*index)->right != NULL)	// the node to be deleted has both children
		{
			if(*child == -1)
			{
				delRoot(index);
				(*parentIndex)->left = *index;	// sets the left child of the parent to the element that has replaced the deleted element
				return;
			}
			if(*child == 1)
			{
				delRoot(index);
				(*parentIndex)->right = *index;	// sets the right child of the parent to the element that has replaced the deleted element
				return;
			}
		}
	}
}

void delRoot(NODEPTR* proot) // deletes the root node of the tree
{
	NODEPTR toDel, parent, tmp;
	if((*proot)->left == NULL && (*proot)->right == NULL) // root has no child
	{
		free(*proot);
		allocCount--;
		*proot = NULL;
		printf("Element deleted successfully.\n");
		return;
	}
	if((*proot)->left != NULL && (*proot)->right == NULL) // root has only left child
	{
		toDel = *proot;
		*proot = (*proot)->left;
		free(toDel);
		allocCount--;
		toDel = NULL;
		printf("Element deleted successfully.\n");
		return;
	}
	if(((*proot)->right != NULL && (*proot)->left == NULL) || ((*proot)->right != NULL && (*proot)->left != NULL)) // root has only right child or both children
	{
		toDel = *proot; 			// backs up the pointer to the node to be deleted
		*proot = (*proot)->right;	// traverses to the right child of the node to be deleted
		parent = toDel;				// holds the pointer to the parent of the current node
		if(((*proot)->left == NULL && (*proot)->right == NULL) || ((*proot)->left == NULL && (*proot)->right != NULL)) // the right child has no children or only has right child
		{
			(*proot)->left = toDel->left;
			free(toDel);
			allocCount--;
			toDel = NULL;
			printf("Element deleted successfully.\n");
			return;
		}
		while((*proot)->left != NULL) // the right child has left child or both children
		{
			parent = *proot;
			*proot = (*proot)->left;
		}
		toDel->data = (*proot)->data;
		tmp = parent->left; 		// traverses to the left of the right child of the node to be deleted
		if(tmp->left == NULL && tmp->right != NULL)
			parent->left = tmp->right;
		else
			parent->left = NULL; 	// sets the left child of the parent to NULL
		free(*proot);
		allocCount--;
		*proot = toDel;
		toDel = NULL;
		printf("Element deleted successfully.\n");
		return;
	}
}

void delBST(NODEPTR *proot)
{
	if (*proot == NULL)
		return;
	if((*proot)->left == NULL && (*proot)->right == NULL)
	{
		free(*proot);
		allocCount--;
		*proot = NULL;
		return;
	}
	else
	{
		delBST(&(*proot)->right);
		delBST(&(*proot)->left);
	}
}	