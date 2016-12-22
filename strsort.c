/*
The following code uses an array of pointers to take as input a list of strings from the user.
It then sorts the strings in alphabetical order and displays the list.
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	int i = 0, j = 0, size = 0;
	printf("How many names would you like to add to your list?\n");
	scanf("%d", &size); 
	setbuf(stdin, NULL); // removes pending newline left from pressing the return key
	char *list[size], tmp[20]; // declares an array of character pointers and a temporary character array for swapping
	printf("Please enter the names.\n");
	for(i = 0; i < size; i++)
	{
		list[i] = (char *)malloc(20 * sizeof(char)); // dynamically allocates memory for each string
		fgets(list[i], 20, stdin); // takes user input
		strtok(list[i], "\n"); // removes pending newline
	}
	printf("\n");
	printf("The list of names is:\n");
	for(i = 0; i < size; i++)
	{
		printf("%s\n", *(list + i));
	}
	printf("\n");
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(strcmp(list[i], list[j]) > 0) // compares the strings lexicographically
			{
				strcpy(tmp, list[i]);
				strcpy(list[i], list[j]);
				strcpy(list[j], tmp);
			}
			else
				continue;
		}
	}
	printf("\n");
	printf("The list sorted in alphabetical order is:\n");
	for(i = 0; i < size; i++)
	{
		printf("%s\n", *(list + i)); // displays the sorted list
	}
	return 0;
}
