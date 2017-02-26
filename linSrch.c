/*The following code implements the basic linear search using 
a sentinel element that is inserted at the end of the list to 
enhance the efficiency of the program.*/

#include<stdio.h>

int linearSearch(int *,int,int); // function for linear search

int main(void)
{
	int i = 0, len = 0, key = 0, pos = 0;	
	printf("How many elements would you like on your list?\n");
	scanf("%d",&len);
	len += 1;
	int input[len];	
	printf("Please enter the elements.\n");
	for(i=0;i<len - 1;++i)
		scanf("%d",&input[i]);
	printf("The elements in the list are ");
	for(i = 0; i < len - 1 ; i++)
		printf("%d ", input[i]);
	printf("\n");
	printf("Enter the key value to search for:\n");
	scanf("%d",&key);
	input[len] = key; // inserts the key at the end of the array
	pos = linearSearch(input, len, key);	
	if (pos == -1)
		printf("Search for the key %d failed!\n",key);
	else
		printf("Key %d was found in position %d.\n", key, pos);
	return 0;
}

int linearSearch(int *arr, int size, int key) // returns -1 if the search fails
{
	int i = 0;
	for(i = 0; arr[i] != key; i++)
		; // loop without body gets the index of the key element
	if(i == size)
		return -1;
	else
		return i + 1;
}
	
