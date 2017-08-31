#include <stdio.h>
#include <limits.h>

void maxList(int*, int, int);
int max = INT_MIN;
int min = INT_MAX;

#define SIZE 4

int main()
{
	int i = 0, list[SIZE];
	printf("Please enter the elements.\n");
	for(i = 0; i < SIZE; i++)
		scanf("%d", &list[i]);
	maxList(list, 0, SIZE - 1);
	printf("The greatest number in the list is %d and the smallest number is %d.\n", max, min);
	return 0;
}

void maxList(int *list, int low, int high) // recursively returns the greatest and smallest number 
{
	int mid;
	mid = low + (high - low)/2;
	if(low == high)
	{
		if(list[low] > max)
			max = list[low];
		if(list[low] < min)
			min = list[low];
		return;
	}
	else
	{
		maxList(list, low, mid);
		maxList(list, mid + 1, high);
	}
}