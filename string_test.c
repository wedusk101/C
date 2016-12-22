#include <stdio.h>
#define SIZE 4096

int main()
{
	char input[SIZE];
	printf("Please enter a string.\n");
	fgets(input, SIZE, stdin);
	printf("The string you entered is :\n%s", input);
	return 0;
}