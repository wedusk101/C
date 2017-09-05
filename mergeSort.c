#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void mergeSort(int*, int, int);
void merge(int*, int, int, int);

int main()
{
	FILE *fp;
	srand(time(NULL));
	int i = 0, list[SIZE], j = 0;
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
	mergeSort(list, 0, SIZE - 1); // average case
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

void mergeSort(int *list, int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high)/2;
		mergeSort(list, low, mid);
		mergeSort(list, mid + 1, high);
		merge(list, low, mid, high);
	}
}

void merge(int *list, int low, int mid, int high)
{
	int i = 0, j = 0, k = low;
	int firstLen = mid - low + 1;
	int secondLen = high - mid;
	int first[firstLen], second[secondLen];
	for(i = low, j = 0; j < firstLen; j++)
		first[j] = list[i++];  // copying into first auxiliary array
	for(i = mid + 1, j = 0; j < secondLen; j++)
		second[j] = list[i++]; // copying into second auxiliary array
	i = 0, j = 0;
	while(i < firstLen && j < secondLen)
	{
		if(first[i] <= second[j])
			list[k++] = first[i++];
		else
			list[k++] = second[j++];
	}
	while(i < firstLen)
		list[k++] = first[i++];
	while(j < secondLen)
		list[k++] = second[j++];
}