#include <stdio.h>

int main()
{
	int input_list[10];
	int i = 0, j = 0, tmp = 0;
	printf("Please enter ten integers. \n");
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &input_list[i]);
	}
	printf("The list you entered is ");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", input_list[i]);
	}
	printf(".\n");
	for(i = 0; i < 10; i++)
	{
		for(j = i + 1; j < 10; j++)
		{
			if(input_list[i] > input_list[j])
			{
				tmp = input_list[i];
				input_list[i] = input_list[j];
				input_list[j] = tmp;
			}
			else
				continue;
		}
	}
	printf("The list sorted in descending order is ");
	for(i = 9; i >= 0; i--)
	{
		printf("%d ", input_list[i]);
		
	}
	printf(".\n");
	return 0;
}
