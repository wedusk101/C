#include <stdio.h>

int main()
{
	int num_array[5], i = 0, tmp = 0;
	printf("Please enter five numbers.\n");
	for(i = 0; i < 5; i++) // Takes user input
	{
		scanf("%d", &num_array[i]);
	}
	printf("The list is : \n");
	for(i = 0; i < 5; i++) // Displays the list
	{
		printf("%d \n", num_array[i]);
	}
	for(i = 0; i < 5; i++) // Finds out the greatest number in the list and moves it to the last index
	{
		if(num_array[i] > num_array[i+1])
		{
			tmp = num_array[i+1];
			num_array[i+1] = num_array[i];
			num_array[i] = tmp;
		}
		else
			continue;
		
	}
	for(i = 0; i < 5; i++) // Finds out the smallest number in the list and moves it to the first index
	{
		if(num_array[i] < num_array[i+1])
			continue;
		else
		{
			tmp = num_array[i+1];
			num_array[i+1] = num_array[i];
			num_array[i] = tmp;
		}
		
		
	}
	printf("The greatest number in the list is %d. \n", num_array[4]);
	printf("The smallest number in the list is %d. \n", num_array[0]);
	return 0;
}
