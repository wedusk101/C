#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void quickSort(int*, int, int);
int findPivot(int*, int, int);

int main()
{
	FILE *fp;
	srand(time(NULL));
	int i = 0, list[SIZE], j = 0, key = 0, count = 0, index = 0;
	fp = fopen("Average.txt", "w");
	if(fp == NULL)
	{
		perror("Error opening file.\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < SIZE; i++)
	{		
		list[i]	= rand() % 100 + 1;
		fprintf(fp, "%d ", list[i]);
	}
	fclose(fp);
	for(i = 0; i < SIZE; i++) // display shuffled list
		printf("%d ", list[i]);
	printf("\n");
	quickSort(list, 0, SIZE - 1);
	fp = fopen("Output.txt", "w");
	if(fp == NULL)
	{
		perror("Error opening file.\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < SIZE; i++)
		fprintf(fp, "%d ", list[i]);
	fclose(fp);
	for(i = 0; i < SIZE; i++) // display sorted list
		printf("%d ", list[i]);
	printf("\n");
	return 0;	
}

void quickSort(int *list, int low, int high)
{
	int pivot = 0;
	if(low < high)
	{
		pivot = findPivot(list, low, high);
		quickSort(list, low, pivot - 1);
		quickSort(list, pivot + 1, high);
	}		
}

int findPivot(int *list, int low, int high)
{
	int right = 0, left = 0, pivot = 0, tmp = 0, len = high - low + 1;
	pivot = rand() % len; // high - low + 1 = SIZE of the array ---- used for randomly generating the pivot
	printf("The chosen pivot is index %d.\n", pivot);
	left = low;
	right = high;
	while(left + right < len)
	{
		if(list[left] > list[pivot] && list[right] < list[pivot])
		{
			if(left < right)
			{
				tmp = list[left];
				list[left] = list[right];
				list[right] = tmp;
			}
			if(left > right && left == pivot)
				return pivot;
			if(left == right)
			{
				tmp = list[pivot];
				list[left] = list[pivot];
				list[pivot] = tmp;
				pivot = left;
				return pivot;
			}				
		}
		left++;
		right--;
	}
	return pivot;
}	