/*The following code implements the insertion sort technique.*/
#include <stdio.h>
#include <stdlib.h>

void insSort(int *, int);
void display(int *, int);

int main()
{
	int size = 0, i = 0;
	printf("How many elements would to like to add to your list?\n");
	scanf("%d", &size);
	int list[size];
	printf("Please enter the elements.\n");
	for(i = 0; i < size; i++)
		scanf("%d", &list[i]);
	printf("The list you have entered is ");
	display(list, size);
	printf(".\n");
	printf("The sorted list with each iteration is as follows:\n");
	insSort(list, size);
	return 0;	
}

void insSort(int *list,int size)
{
	int i = 0, j = 0, pivot = 0;
	for(i = 1; i < size; i++)
	{
		pivot = list[i];
		j = i - 1;
		while(j >= 0 && list[j] > pivot)
		{
			list[j + 1] = list[j];
			j--;
			list[j + 1] = pivot;
		}
		display(list, size);
		printf("\n");
	}
}

void display(int *list, int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
		printf("%d ", list[i]);
}