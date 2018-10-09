/*The following code recursively generates all permutations(including duplicates) of the digits input by the user. Due to the nature of the problem of generating permutations,
this program is exceedingly slow for all but the smallest of input sizes.*/

#include <stdio.h>
#include <limits.h>
#include <time.h>

void permute(int*, int, int);
void swap(int*, int*);
void displayList(int*, int);

int main()
{
	int i = 0, len = 0;
	clock_t start, stop;
	float diff = 0.0;
	printf("How many digits would you like to input?\n");
	scanf("%d", &len);
	int list[len];
	printf("Please enter the digits.\n");
	for(i = 0; i < len; i++)
		scanf("%d", &list[i]);
	printf("The permutations are as follows:\n");
	start = clock();
	permute(list, 0, len - 1);
	stop = clock();
	diff = ((float)stop - (float)start)/CLOCKS_PER_SEC;
	printf("Time taken to compute the permutations was %f seconds.\n", diff);
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