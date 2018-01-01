/*The following code recursively generates all permutations(including duplicates) of the digits input by the user.
The macro "SIZE", limits the number of inputs given by the user. Due to the nature of the problem of generating permutations,
this program is exceedingly slow for all but the smallest of input sizes.*/

#include <stdio.h>
#include <limits.h>

#define SIZE 4

void permute(int*, int, int);
void swap(int*, int*);
void displayList(int*, int);

int main()
{
	int i = 0, list[SIZE];
	printf("Please enter the digits.\n");
	for(i = 0; i < SIZE; i++)
		scanf("%d", &list[i]);
	printf("The permutations are as follows:\n");
	permute(list, 0, SIZE - 1);
	return 0;
}

void permute(int *list, int low, int high) // recursively computes the permutations of the items in the list 
{
	int i = 0;
	if(low <= high)
	{
		for(i = low; i <= high; i++)
		{
			swap(&list[low], &list[i]);
			permute(list, low + 1, high);
			swap(&list[low], &list[i]);
		}
	}
	else
		displayList(list, high + 1);
}

void swap(int *a, int *b) // swaps two items 
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void displayList(int *list, int num) // displays the list
{
	int i = 0;
	for(i = 0; i < num; i++)
		printf("%d", list[i]);
	printf("\n");
}