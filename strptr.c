#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char *str; 
	int size, i = 0;
	printf("How many characters do you want in your string?\n");
	scanf("%d", &size); // user inputs size of array
	setbuf(stdin, NULL); // removes pending newline from buffer
	str = malloc((size + 1)* sizeof(char)); // dynamically allocates memory for the array
	printf("Please enter a string.\n");
	fgets(str, size + 1, stdin); // user inputs the characters
	strtok(str, "\n"); // removes pending newline from buffer
	printf("The string you entered is %s.\n", str);
	for(i = 0; i < size; i++)
	{
		if(isupper(*(str + i)))
			*(str + i) = tolower(*(str + i)); // converts uppercase characters to lowercase
	}
	printf("The new string is %s.", str);
	free(str);
	return 0;
	
}