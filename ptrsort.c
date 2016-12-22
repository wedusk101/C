#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *list, i = 0, j = 0, size = 0 , tmp; // declares an integer type pointer
	printf("How many elements do you want in your list?\n");
	scanf("%d", &size);
	list = (int *)malloc(size * sizeof(int)); // dynamically allocates memory for the array
	printf("Please enter the numbers.\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", list + i);
	}
	printf("The list you entered is ");
	for( i = 0; i < size; i++)
	{
		printf("%d ", *(list + i));
	}
	printf(".\n");
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(*(list + i) > *(list + j)) // sorts the elements
			{
				tmp = *(list + i);
				*(list + i) = *(list + j);
				*(list + j) = tmp;
			}
			else
				continue;
		}
	}
	printf("The list sorted in ascending order is ");
	for(i = 0; i < size; i++)
	{
		printf("%d ", *(list + i));
	}
	printf(".\n");
	free(list);
	return 0;
	
}
