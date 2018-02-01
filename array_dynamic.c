#include <stdio.h>
#include <stdlib.h>

int* createArray(int);
void display(int*, int);

int main()
{
	int len = 0, *arr = NULL;
	printf("How many elements would you like to have on your list?\n");
	scanf("%d", &len);
	arr = createArray(len);
	printf("The elements you have entered are ");
	display(arr, len);
	free(arr);
	return 0;
}

int* createArray(int length)
{
	int i = 0, *list = NULL;
	list = malloc(length * sizeof(int));
	printf("Please enter the elements.\n");
	for(i = 0; i < length; i++)
		scanf("%d", (list + i));
	return list;
}

void display(int *list, int size)
{
	int i = 0;
	for(i = 0; i < size; i++)
		printf("%d ", *(list + i));
	printf(".\n");
}
