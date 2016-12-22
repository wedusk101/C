/* 
This program tests command line arguments that are passed to main during runtime. The arguments 
argc and argv represent the argument count and the argument vectors respectively. The first argument 
i.e. argv[0] is the name of the program. Therefore argc is at least 1. argv[1] is the second argument,
argv[2] is the third argument and so on. char *argv[] is a pointer to an array of string arguments.
The function atoi() type casts argv[1] to integer for use within the program. The program adds integers
and calculates their mean. The argument passed is the number of integers to be added.
*/ 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) // takes command line arguments 
{
	int *list, i = 0, sum = 0, size = 0;
	size = atoi(argv[1]); // type casts the string argument to integer
	float mean;
	list = malloc(size * sizeof(int)); // dynamically allocates the array
	printf("Please enter the desired integers.\n");
	for(i = 0; i < size; i++)
	{
		scanf("%d", (list + i)); // user inputs the integers
	}
	printf("The integers entered are ");
	for(i = 0; i < size; i++)
	{
		printf("%d ", *(list + i));
	}
	printf(".\n");	
	for(i = 0; i < size; i++)
	{
		sum = sum + *(list + i);
	}
	mean = (float)sum / (float)size; // calculates the mean of the integers
	printf("The mean of the numbers is %5.2f.\n", mean);
	free(list);
	return 0;
}