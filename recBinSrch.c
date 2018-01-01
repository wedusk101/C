#include<stdio.h>

int binarySearch(int*, int, int, int); // function for binary search
	
int main(void)
{
	int i = 0, size = 0, key = 0, pos = 0;	
	printf("How many elements would you like to add to your list?\n");
	scanf("%d",&size);
	int list[size];
	printf("Please enter the elements.\n");
	for(i = 0; i < size; i++)
		scanf("%d", &list[i]);
	printf("The elements in the list are ");
	for(i = 0; i < size ; i++)
		printf("%d ",list[i]);
	printf("\n");
	printf("\nEnter the key value to search for:\n");
	scanf("%d",&key);
	pos = binarySearch(list, 0, size - 1, key);
	if (pos == -1)
		printf("Search for the key %d failed!\n",key);
	else
		printf("Key %d was found in position %d.\n", key, pos + 1);
	return 0;
}

int binarySearch(int *arr, int lower, int upper, int key) // returns -1 if the search fails
{
	int mid = (lower + upper)/2; // overflow bug
	while(lower != upper)
	{
		if(arr[mid] == key)
			return mid;
		else if(key < arr[mid])
			return binarySearch(arr, lower, mid, key);
		else
			return binarySearch(arr, mid + 1, upper, key);
	}
	return -1;	
}