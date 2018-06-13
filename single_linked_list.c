/*The following code implements a single linked list along with a few of its basic functions.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
    struct node *next;
};

typedef struct node* NODEPTR;

void initList(NODEPTR*);	// initializes the linked list
void insertEndList(NODEPTR*, NODEPTR*); // inserts a node at the end of the linked list
void deleteEndList(NODEPTR*, NODEPTR*); // deletes the node at the end of the list
void insertNodePos(NODEPTR*, int, int, NODEPTR*); // inserts a node into a position of the user's choice
void insertFirst(NODEPTR*, int, NODEPTR*); // inserts a node at the beginning of the linked list
void deleteNodePos(NODEPTR*, int, NODEPTR*); // deletes the node present at a position of the user's choice
void insertAfter(NODEPTR*, int, int, NODEPTR*); // inserts a node after a particular position
void deleteFirst(NODEPTR*, NODEPTR*); // deletes the node at the beginning of the list
void deleteAfter(NODEPTR*, int, NODEPTR*); // deletes the element after a particular position
void deleteNodex(NODEPTR*, int, NODEPTR*); // deletes a specific node
void deleteAfterx(NODEPTR*, int, NODEPTR*); // deletes the node present after a specific value
void insertAfterx(NODEPTR*, int, int, NODEPTR*); // inserts a node after the node with a specific value
int countNode(NODEPTR); // counts the number of nodes in the linked list
void displayList(NODEPTR); // displays the elements present in each node
void concatList(NODEPTR*, NODEPTR*, NODEPTR*); // appends two linked lists
int searchx(NODEPTR, int); // searches the nodes of the linked list for a particular value
void revList(NODEPTR*, NODEPTR*); // reverses the linked list and displays it
NODEPTR copyList(NODEPTR); // creates a copy of a linked list and displays both the original and the copied list
void delList(NODEPTR*); // deletes a linked list

int main()
{
    NODEPTR list, secondlist, lastNode;
    int choice = 0, pos = 0, val = 0, element = 0;
    initList(&list); // lists are initialized
	initList(&secondlist);
	initList(&lastNode);
    do
	{
		printf("\n------Welcome! What would you like to do?--------\n\n");
		printf("1.  Insert at the end of the linked list.\n");
		printf("2.  Insert into a specific position.\n");
        printf("3.  Delete the node at a specific position.\n");
        printf("4.  Delete a node with a specific value.\n");
		printf("5.  Delete the node at the beginning of the list.\n");
        printf("6.  Count the number of nodes in the list.\n");
        printf("7.  Append one linked list to another list.\n");
		printf("8.  Search for a specific value in the list.\n");
        printf("9.  Display the list.\n");
		printf("10. Delete the node at the end of the list.\n");
		printf("11. Insert a node at the beginning of the list.\n");
		printf("12. Insert a node after a specific value.\n");
		printf("13. Delete a node after a specific value.\n");
		printf("14. Delete a node after a specific position.\n");
		printf("15. Insert a node after a specific position.\n");
		printf("16. Reverse the list.\n");
		printf("17. Create a copy of a linked list.\n");
		printf("18. Reinitialize the pointers to all the lists.\n");
		printf("0.  EXIT.\n\n");
        printf("--------------------------------------------------\n");
        scanf("%d", &choice);
        switch(choice)
        {
			case 1:
				insertEndList(&list, &lastNode);
                break;
            
			case 2:
				printf("Please enter the position.\n");
                scanf("%d", &pos);
                printf("Please enter the value.\n");
                scanf("%d", &val);
                insertNodePos(&list, pos, val, &lastNode);
                break;
            
			case 3:
				printf("Please enter the position of the node you would like to delete.\n");
                scanf("%d", &pos);
                deleteNodePos(&list, pos, &lastNode);
                break;
				
			case 4:
				printf("Please enter the value of the node which you would like to delete.\n");
				scanf("%d", &val);
				deleteNodex(&list, val, &lastNode);
				break;
					
			case 5:
				deleteFirst(&list, &lastNode);
                break;
            
			case 6:
				printf("Total nodes are %d.", countNode(list));
                break;
            
			case 7:
				delList(&list); // start with fresh pointers
				delList(&secondlist);
				concatList(&list, &secondlist, &lastNode);
                break;
           
			case 8:
				printf("Please enter the value you want to search for.\n");
                scanf("%d", &val);
				int keypos = searchx(list, val);				
                if(keypos == -1)
					printf("Element not found!\n");
				else
					printf("Element found at position %d.", keypos);
                break;
            
			case 9:
				displayList(list);
				break;
					
			case 10:
				deleteEndList(&list, &lastNode);
				break;
					
			case 11:
				printf("Please enter the value you would like to insert.\n");
				scanf("%d", &val);
				insertFirst(&list, val, &lastNode);
				break;
					
			case 12:
				printf("Please enter the value of the node.\n");
				scanf("%d", &val);
				printf("Please enter the element that you want to insert.\n");
				scanf("%d", &element);
				insertAfterx(&list, val, element, &lastNode);
				break;
					
			case 13:
				printf("Please enter the value.\n");
				scanf("%d", &val);
				deleteAfterx(&list, val, &lastNode);
				break;
					
			case 14:
				printf("Please enter the position.\n");
				scanf("%d", &pos);
				deleteAfter(&list, pos, &lastNode);
				break;
				
			case 15:
				printf("Please enter the position.\n");
				scanf("%d", &pos);
				pos = pos + 1;
				if(pos > countNode(list) + 1)
				{
					printf("Invalid Position! Operation aborted.\n");
					break;
				}
				printf("Please enter the value.\n");
				scanf("%d", &val);
				insertAfter(&list, pos, val, &lastNode);
				break;
				
			case 16:
				if(list == NULL)
				{
					printf("List is empty. First create a list. Operation aborted!\n");
					break;
				}
				revList(&list, &lastNode);
				displayList(list);
				break;
				
			case 17:
				if(list == NULL)
				{
					printf("List is empty. First create a list. Operation aborted!\n");
					break;
				}
				delList(&secondlist); // makes sure that we start with a fresh list as backup
				secondlist = copyList(list);
				displayList(secondlist);
				break;
				
			case 18:
				delList(&list); 
				delList(&secondlist);
				printf("Lists reinitialized successfully.\n");
				break;
				
			case 0:
				delList(&list); // clean up
				delList(&secondlist);
				break;
            
			default:
				printf("Invalid choice.\n");
        }
    }while(choice != 0);
	printf("Thank you.\n");
	return 0;                    
}

void initList(NODEPTR *plist)
{
	*plist = NULL;
}

void insertEndList(NODEPTR *plist, NODEPTR *lastNode)
{
	NODEPTR newNode, tmp;
    int x;
    char ch;
	tmp = *plist;
    do
	{
		printf("Please enter the value.\n");
        scanf("%d", &x);
        newNode = malloc(sizeof(struct node));
        newNode->info = x;
        newNode->next = NULL;
		if(*plist == NULL)
		{
			*plist = newNode;
			*lastNode = newNode;
		}
        else
			(*lastNode)->next = newNode;
		printf("Value inserted successfully.\n");
        printf("Do you wish to continue? (Y/N)\n");
        scanf(" %c", &ch);
        *lastNode = newNode;
    }while(ch == 'y' || ch == 'Y');
}

int countNode(NODEPTR plist)
{
	int count = 0;
	while(plist != NULL)
	{
		count++;
		plist = plist->next;
	}
	return count;	
}

void displayList(NODEPTR plist)
{
	printf("\n");
	if(plist == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	while(plist != NULL)
	{
		printf("%d ", plist->info);
		plist = plist->next;
	}
	printf("\n");
}

void insertNodePos(NODEPTR *plist, int pos, int val, NODEPTR *lastNode) 
{
	NODEPTR newNode, tmp;
	int count = 0;
	newNode = malloc(sizeof(struct node));
	if(pos == countNode(*plist) + 1)
	{
		tmp = *plist;
		newNode->info = val;
		newNode->next = NULL;
		while((*plist)->next != NULL)
		{
			*plist = (*plist)->next;
		}
		(*plist)->next = newNode;
		*lastNode = *plist;
		*plist = tmp;
		printf("Value inserted successfully.\n");
		return;
	}
	if(pos < 1 || pos > countNode(*plist) + 1)
	{
		printf("Invalid Position! Try again.\n");
		return;
	}
	if(pos == 1) 
		insertFirst(plist, val, lastNode);
	else
	{
		tmp = *plist;
		while(count != pos - 2)
		{
			tmp = tmp->next;
			++count;
		}
		newNode->info = val;
		newNode->next = tmp->next;
		tmp->next = newNode;
		printf("Value inserted successfully.\n");
	}		
}

void insertFirst(NODEPTR *plist, int val, NODEPTR *lastNode)
{
	NODEPTR newNode, tmp;
	newNode = malloc(sizeof(struct node));
	tmp = *plist;
	newNode->info = val;
	if((*plist) == NULL)
	{
		newNode->next = NULL;
		*plist = newNode;
		*lastNode = newNode;
		printf("Value inserted successfully.\n");
		return;
	}	
	newNode->next = *plist;
	*plist = newNode;
	printf("Value inserted successfully.\n");
}

void concatList(NODEPTR *firstlist, NODEPTR *secondlist, NODEPTR *lastNode)
{
	initList(firstlist);
	initList(secondlist);
	NODEPTR tmp;
	printf("FIRST LIST ----->\n");
	insertEndList(firstlist, lastNode);
	tmp = *firstlist;
	printf("SECOND LIST ---->\n");
	insertEndList(secondlist, lastNode);
	while((*firstlist)->next != NULL)
		*firstlist = (*firstlist)->next;
	(*firstlist)->next = *secondlist;
	*firstlist = tmp;
	printf("The appended list is :\n");
	displayList(*firstlist);
}

int searchx(NODEPTR plist, int key) // only valid for the first occurrence of a value
{
	int pos = 0;
	for(pos = 1; plist->next != NULL; pos++, plist = plist->next)
	{
		if(plist->info == key)
			return pos;
	}
	if(plist->info == key)
			return pos;
	return -1;	
}

void insertAfter(NODEPTR *plist, int pos, int val, NODEPTR *lastNode)
{
	insertNodePos(plist, pos, val, lastNode);	
}

void insertAfterx(NODEPTR *plist, int key, int element, NODEPTR *lastNode) // not valid for duplicate values in the list
{
	NODEPTR tmp = *plist, newNode;
	int pos = 1;
	newNode = malloc(sizeof(struct node));
	while((*plist)->next != NULL && (*plist)->info != key)
	{
		*plist = (*plist)->next;
		pos++;
	}
	if((*plist)->info == key)
	{
		*plist = tmp;
		printf("Element found at Position: %d\n", pos);
		insertNodePos(plist, pos + 1, element, lastNode);
		return;
	}
	else
		printf("Element not found! Try again.\n");
	*plist = tmp;
}

void deleteNodePos(NODEPTR *plist, int posNode, NODEPTR *lastNode)
{
	int pos = 1, count = countNode(*plist);
	NODEPTR bak, tp, delNode;
	bak = *plist;
	if(*plist == NULL)
	{
		printf("List is empty! Operation aborted.\n");
		return;
	}
	if(posNode < 1 || posNode > count)
	{
		printf("Invalid position! Try again.\n");
		return;
	}	
	if(posNode == 1)
	{
		delNode = *plist;
		bak = (*plist)->next;
		(*plist)->next = NULL;
		*plist = bak;
		printf("Node deleted successfully.\n");
		free(delNode);
		return;		
	}
	if(posNode == count)
	{
		while(pos != posNode - 1)
		{
			*plist = (*plist)->next;
			pos++;
		}
		delNode = (*plist)->next;
		(*plist)->next = NULL;
		*lastNode = *plist;
		*plist = bak;
		printf("Node deleted successfully.\n");
		free(delNode);
		return;
	}
	while(pos != posNode)
	{
		*plist = (*plist)->next;
		pos++;		
	}
	tp = *plist;
	delNode = tp;
	pos = 1;
	*plist = bak;
	while(pos != posNode - 1)
	{
		*plist = (*plist)->next;
		pos++;		
	}
	(*plist)->next = tp->next;
	*plist = bak;
	printf("Node deleted successfully.\n");
	free(delNode);	
}

void deleteFirst(NODEPTR *plist, NODEPTR *lastNode)
{
	deleteNodePos(plist, 1, lastNode);
}

void deleteEndList(NODEPTR *plist, NODEPTR *lastNode)
{
	int end;
	end = countNode(*plist);
	deleteNodePos(plist, end, lastNode);
}

void deleteAfter(NODEPTR *plist, int pos, NODEPTR *lastNode)
{
	deleteNodePos(plist, pos + 1, lastNode);
}

void deleteAfterx(NODEPTR *plist, int val, NODEPTR *lastNode) // not valid for duplicate values in the list
{
	int valpos = searchx(*plist, val);
	if(valpos == -1)
	{
		printf("Element not found!\n");
		return;
	}
	deleteNodePos(plist, valpos + 1, lastNode);
}

void deleteNodex(NODEPTR *plist, int val, NODEPTR *lastNode) // not valid for duplicate values in the list
{
	int valpos = searchx(*plist, val);
	if(valpos == -1)
	{
		printf("Element not found!\n");
		return;
	}
	deleteNodePos(plist, valpos, lastNode);
}

void delList(NODEPTR *plist)
{
	NODEPTR delNode;
	if(*plist == NULL)
		return;
	while((*plist)->next != NULL)
	{
		delNode = *plist;
		*plist = (*plist)->next;
		free(delNode);
	}
	free(*plist);
	*plist = NULL;
}

void revList(NODEPTR *plist, NODEPTR *lastNode)
{
	NODEPTR tp, fast, slow;
	fast = slow = *plist;
	tp = fast->next;
	fast = fast->next;
	slow->next = NULL;
	*lastNode = slow;	// updates the pointer to the last node
	while(fast->next != NULL)
	{
		fast = fast->next;
		tp->next = slow;
		slow = tp;
		tp = fast;
	}
	fast->next = tp;
	tp->next = slow;
	*plist = fast;
}

NODEPTR copyList(NODEPTR plist) // recursively creates a copy of the list
{
	NODEPTR newNode;
	newNode = malloc(sizeof(struct node));
	newNode->info = plist->info; 
	newNode->next = NULL;
	if(plist->next != NULL)
		newNode->next = copyList(plist->next); 
	return newNode;
}