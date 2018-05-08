/*The following program implements the representation of a polynomial using linked lists.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coeff;
	int exp;
	struct node *next;
};

typedef struct node* NODEPTR;

void initList(NODEPTR*);
void insertEndList(NODEPTR*, NODEPTR*); 
void displayPolynomial(NODEPTR);
void delList(NODEPTR*); // free allocated memory

int main()
{
	NODEPTR list, secondlist, lastNode;
	initList(&list);
	printf("\nPlease enter the terms of the polynomial in the following format:\n");
	printf("(a_n * x ^ n) + (a_n-1 * x ^ n-1) + ... + (a_1 * x) + a_0\n");
	printf("\nWhere a_n to a_0 represent the coefficients in descending order \nand ^ n, ^ n-1 and so on represent the exponents in descending order.\n\n");
	insertEndList(&list, &lastNode);
	printf("The polynomial is ");
	displayPolynomial(list);
	delList(&list);
	printf(" .\n");
}

void initList(NODEPTR *plist)
{
	*plist = NULL;
}

void insertEndList(NODEPTR *plist, NODEPTR *lastNode)
{
	NODEPTR newNode, tmp;
    int cf = 0, ex = 0;
    char ch;
	tmp = *plist;
    do
	{
		printf("Please enter the coefficient.\n");
        scanf("%d", &cf);
		printf("Please enter the exponent.\n");
        scanf("%d", &ex);
        newNode = malloc(sizeof(struct node));
        newNode->coeff = cf;
		newNode->exp = ex;
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

void displayPolynomial(NODEPTR plist)
{
	while(plist != NULL)
	{
		if(plist->exp == 0)
		{
			printf("%d", plist->coeff);
			return;
		}
		if(plist->next == NULL && plist->coeff == 0)
		{
			printf("0");
			return;
		}
		if(plist->next == NULL)
		{
			printf("%dx^%d", plist->coeff, plist->exp);
			return;
		}
		if(plist->coeff != 0 && (plist->exp != 0 && plist->exp != 1))
		{
			printf("%dx^%d + ", plist->coeff, plist->exp);
		}
		if(plist->coeff == 1)
		{
			printf("x^%d + ", plist->exp);
		}
		if(plist->coeff != 0 && plist->exp == 1)
		{
			printf("%dx + ", plist->coeff);
		}
		plist = plist->next;
	}
}

void delList(NODEPTR *plist)
{
	NODEPTR delNode;
	while(*plist != NULL)
	{
		delNode = *plist;
		*plist = (*plist)->next;
		free(delNode);
	}
}