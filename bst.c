/*The following code implements a binary search tree with a few of its basic operations.*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;
};

typedef struct treeNode *NODEPTR;

int countNodeBST(NODEPTR); 							// counts the number of nodes in the tree
void insertNodeBST(NODEPTR*, int); 					// inserts a node into the tree
void deleteNodeBST(NODEPTR*, NODEPTR*, int); 		// deletes a node from the tree
int countLeafBST(NODEPTR); 							// counts the number of leaf nodes in the tree
int calcHeightBST(NODEPTR); 						// calculates the height of the tree
NODEPTR createTree(int); 							// creates a new binary search tree
void displayInorderBST(NODEPTR);				    // displays the inorder traversal of the tree
void displayPreorderBST(NODEPTR);					// displays the preorder traversal of the tree
void displayPostorderBST(NODEPTR); 					// displays the post order traversal of the tree
int searchBST(NODEPTR, NODEPTR*, int); 				// searches the tree for a particular element
void initTree(NODEPTR*); 							// initializes the tree
int max(int, int);                  			    // returns the greater of two values
void delRoot(NODEPTR*);								// deletes the root of the tree

int main()
{
	NODEPTR root, index;
	initTree(&root);
	index = NULL;
	int choice = 0, x = 0;
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
		printf("\n 11. Delete the root of the tree.\n");
		printf("\n 0.  EXIT \n");
        printf("\n------------------------------\n");
        printf("\nPlease enter your choice : ");
        scanf("%d",&choice);
		switch(choice)
		{	case 1: 	printf("\nPlease enter the first element of the tree.\n");
						scanf("%d",&x);
						root = createTree(x);
						break;
			
			case 2: 	printf("Please enter the element to insert.\n");
						scanf("%d",&x);
						insertNodeBST(&root, x);
						break;
					
			case 3: 	printf("Please enter the element to delete.\n");
						scanf("%d",&x);
						deleteNodeBST(&root, &index, x);
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
						break;
						
			case 8:		if(root == NULL)
						{
							printf("Tree is empty!\n");
							break;
						}
						displayPreorderBST(root);
						break;
						
			case 9:		if(root == NULL)
						{
							printf("Tree is empty!\n");
							break;
						}
						displayPostorderBST(root);
						break;
						
			case 10:	printf("Please enter the element to search for.\n");
						scanf("%d",&x);
						if(searchBST(root, &index, x) == TRUE)
							printf("Element found!\n");
						else
							printf("Element not found.\n");
						break;
			
			case 11:	if(root == NULL)
						{
							printf("Empty tree. Operation aborted.\n");
							break;
						}
						delRoot(&root);
						printf("Root deleted successfuly.\n");
						break;
			
			case 0:		printf("Thank you.\n");
						break;
					
			default:	printf("\nInvalid choice. Try again.\n");
		}
	}while(choice != 0);
} // end

void initTree(NODEPTR* proot)
{
	*proot = NULL;
}

NODEPTR createTree(int val) // creates a tree with the user input value as the root
{
	NODEPTR tmp;
	tmp = malloc(sizeof(struct treeNode));
	tmp->data = val;
	tmp->left = tmp->right = NULL;
	printf("Element inserted. Tree created successfully.\n");
	return tmp;
}

void insertNodeBST(NODEPTR* proot, int val) // recursively inserts an element into the tree
{
	if(*proot == NULL)
	{
		*proot = createTree(val);
		printf("Element inserted succesfully.\n");
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
	if(root  != NULL)
		return 1 + countNodeBST(root->left) + countNodeBST(root->right);
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

int searchBST(NODEPTR root, NODEPTR* index, int val) // recursively searches the tree for an element
{
	if(root == NULL)
		return FALSE;
	if((root->data) == val)
	{
		*index = root;		// returns a pointer to the found element
		return TRUE;
	}
	if(val < (root->data))
		searchBST(root->left, index, val);
	else
		searchBST(root->right, index, val);		
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

void deleteNodeBST(NODEPTR* proot, NODEPTR* index, int val) // deletes a node with specific value
{
	if(proot == NULL)
	{
		printf("Empty tree. Operation aborted.\n");
		return;
	}
	if(searchBST(*proot, index, val) == FALSE) // searches for the element to be deleted and returns a pointer to it if found
	{
		printf("Element not found! Operation failed.\n");
		return;
	}
	else
	{
		delRoot(index); // deletes the found element
		return;
	}
}

void delRoot(NODEPTR* proot) // deletes the root node of the tree
{
	NODEPTR toDel, parent;
	if((*proot)->left == NULL && (*proot)->right == NULL) // root has no child
	{
		free(*proot);
		*proot = NULL;
		printf("Element deleted succesfully.\n");
		return;
	}
	if((*proot)->left != NULL && (*proot)->right == NULL) // root has only left child
	{
		toDel = *proot;
		*proot = (*proot)->left;
		free(toDel);
		toDel = NULL;
		printf("Element deleted succesfully.\n");
		return;
	}
	if(((*proot)->right != NULL && (*proot)->left == NULL) || ((*proot)->right != NULL && (*proot)->left != NULL)) // root has only right child or both children
	{
		toDel = *proot; 			// backs up the pointer to the node to be deleted
		*proot = (*proot)->right;	// traverses to the right child of the node to be deleted
		parent = toDel;				// holds the pointer to the parent of the current node
		if(((*proot)->left == NULL && (*proot)->right == NULL) || ((*proot)->left == NULL && (*proot)->right != NULL)) // the right child has no children or only has right child
		{
			toDel->data = (*proot)->data;
			parent->right = NULL;   // sets the right child of the parent to NULL
			free(*proot);
			*proot = toDel;
			printf("Element deleted succesfully.\n");
			return;
		}
		while((*proot)->left != NULL) // the right child has left child or both children
		{
			parent = *proot;
			*proot = (*proot)->left;
		}
		toDel->data = (*proot)->data;
		parent->left = NULL; 		// sets the left child of the parent to NULL
		free(*proot);
		*proot = toDel;
		toDel = NULL;
		printf("Element deleted succesfully.\n");
		return;
	}
}