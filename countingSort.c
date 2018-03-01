/*The following code implements the counting sort algorithm for a given list of positive integers.*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int* countingSort(int* list, int);

int main()
{
	int i = 0, max = 0, list[SIZE];
	int* result;
	printf("Please enter the numbers (>= 0).\n");
	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &list[i]);
		if(list[i] > max)
			max = list[i];
	}
	result = countingSort(list, max);
	printf("The sorted list is:\n");
	for(i = 1; i <= SIZE; i++)
	{
		if(result[i] >= 0 && result[i] <= max)
			printf("%d ", result[i]);
	}
	printf("\n");
	free(result);
}

int* countingSort(int* list, int max)
{
	int *output, i = 0, freq[max + 1];
	output = malloc(SIZE * sizeof(int));
	for(i = 0; i < max + 1; i++)
		freq[i] = 0;  // initialize frequency array
	for(i = 0; i < SIZE; i++) // calculates frequency of each number
		freq[list[i]]++;
	for(i = 1; i < max + 1; i++) // calculates the cumulative frequency of the numbers
		freq[i] = freq[i] + freq[i-1];
	for(i = SIZE - 1; i >= 0; i--)
	{
		output[freq[list[i]]] = list[i];
		freq[list[i]]--;
	}
	return output;
}