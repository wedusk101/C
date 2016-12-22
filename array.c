#include <stdio.h>

int main()
{
	int num_array[5], i = 0;
	printf("Please enter five numbers.\n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &num_array[i]);
	}
	printf("The list is : \n");
	for(i = 0; i < 5; i++)
	{
		printf("%d \n", num_array[i]);
	}
	return 0;
}
