#include<stdio.h>

int binarySearch(int *,int,int); // function for binary search
	
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
	pos = binarySearch(list, size, key);
	if (pos == -1)
		printf("Search for the key %d failed!\n",key);
	else
		printf("Key %d was found in position %d.\n", key, pos + 1);
	return 0;
}

int binarySearch(int *arr, int len, int key) // returns -1 if the search fails
{
	int lower = 0, upper = len - 1, mid = 0;
	mid = (lower + upper)/2;
	while(lower <= upper)
	{
		if(key < arr[mid] && arr[mid] != key)
			upper = mid - 1;
		else
			lower = mid + 1;
		mid = (lower + upper)/2;
	}
	if(arr[mid] == key)
		return mid;
	else return -1;	
}
	
