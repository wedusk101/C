/*The following code implements the insertion sort and binary search for the purpose of performing their asymptotic analyses. A list of 500 elements is populated using random
numbers. Then, the list is sorted using insertion sort in its best, worst, and average cases. In the best case the list is already sorted. In the average case the elements
are randomly distributed, and finally, for the worst case, the list is sorted in descending order. The unsorted and the sorted lists are written out to two text files.
After this, an index is chosen randomly from the list of numbers using which we perform binary search. The number of comparisons performed is recorded for all the operations.*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int binSearch(int*, int, int, int*);

int main()
{
	FILE *fp;
	int list[500], i = 0, j = 0, pivot = 0, count = 0, index = 0;
	srand(time(NULL));
	fp = fopen("Average.txt", "w");
	if(fp == NULL)
	{
		perror("Error opening file.\n");
		exit(EXIT_FAILURE); 
	}
	for(i = 0; i < 500; i++)
		list[i] = rand() % 1000; // generates 500 random numbers between 0 and 999
	for(i = 0; i < 500; i++)
		fprintf(fp, "%d ", list[i]); // writes the unsorted list to a file
	fclose(fp);
	for(i = 1; i < 500; i++)	// average case  of sorting the list in ascending order using insertion sort
	{
		pivot = list[i];
		j = i - 1;
		while(j >= 0 && list[j] > pivot)
		{
			list[j + 1] = list[j];
			j--;
			++count;
		}
		list[j + 1] = pivot;
	}
	fp = fopen("Output.txt", "w");
	if(fp == NULL)
	{
		perror("Error opening file.\n");
		exit(EXIT_FAILURE); 
	}
	for(i = 0; i < 500; i++)
		fprintf(fp, "%d ", list[i]); // writes the sorted list to a file
	printf("The number of comparisons for 500 elements in the average case of insertion sort was %d.\n", count);
	count = 0;
	for(i = 1; i < 500; i++)	// best case when the list is already sorted
	{
		pivot = list[i];
		j = i - 1;
		while(j >= 0 && list[j] > pivot)
		{
			list[j + 1] = list[j];
			j--;
		}
		++count;
		list[j + 1] = pivot;
	}
	printf("The number of comparisons performed for 500 elements in the best case of insertion sort was %d.\n", count);
	for(i = 1; i < 500; i++)	// sorting the list in descending order
	{
		pivot = list[i];
		j = i - 1;
		while(j >= 0 && list[j] < pivot)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = pivot;
	}
	/*printf("The numbers in the array are "); // to optionally display the sorted list 
	for(i = 0; i < 500; i++)
		printf("%d ", list[i]);*/
	count = 0;
	for(i = 1; i < 500; i++)	// worst case when the list is sorted in descending order
	{
		pivot = list[i];
		j = i - 1;
		while(j >= 0 && list[j] > pivot)
		{
			++count;
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = pivot;
	}
	printf("The number of comparisons performed for 500 elements in the worst case of insertion sort was %d.\n", count);
	count = 0;
	index = rand() % 500; // randomly chosen index for binary search key
	printf("The chosen index is %d which has a value of %d.\n", index, list[index]);
	printf("The key was found at position %d.\n", binSearch(list, 500, list[index], &count) + 1);
	printf("The number of comparisons performed in binary search was %d.\n", count);
	fclose(fp); // close file
	return 0;
} // end

int binSearch(int *arr, int len, int key, int* count) // returns -1 if the search fails
{
	int lower = 0, upper = len - 1, mid = 0;
	mid = (lower + upper)/2; // this is a bug
	while(lower <= upper)
	{
		++(*count);
		if(arr[mid] == key)
			return mid;
		if(key < arr[mid])
			upper = mid - 1;
		else
			lower = mid + 1;
		mid = (lower + upper)/2;
	}
	return -1;	
}