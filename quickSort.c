/*The following program implements the Quicksort algorithm using the Lomuto partitioning scheme.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void quickSort(int*, int, int);
int findPivot(int*, int, int);

int main()
{
	srand(time(NULL));
	FILE *fp;
	int i = 0, list[SIZE], j = 0, key = 0, count = 0, index = 0;
	fp = fopen("Input.txt", "w");
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
	int counter = low, partition = low - 1, pivot = high, tmp = 0;
	printf("The chosen pivot is index %d.\n", pivot);
	while(counter <= high - 1)
	{
		if(list[counter] <= list[pivot])
		{
			partition++;
			tmp = list[partition];
			list[partition] = list[counter];
			list[counter] = tmp;
		}
		counter++;
	}
	tmp = list[partition + 1]; // the counter has reached the penultimate element of the array
	list[partition + 1] = list[counter];
	list[counter] = tmp;
	return partition + 1;
}	