/* This program accepts a string as input from the user and displays the frequency of each character.
Note that this is case sensitive. I have used an integer array to store the frequency of each character.
The frequency counter array is first initialized to zero. The characters are then type casted to their 
ASCII equivalent which is used as the index for their corresponding cell in the frequency counter array.
Finally the non empty indices of the counter array are implicitly casted back to their character equivalents
using fornat specifiers and displayed to the user along with their frequencies.*/

#include <stdio.h>
#include <string.h>

int main()
{
	char input[30];
	printf("Please enter a string.\n");
	fgets(input, 30, stdin);
	strtok(input, "\n"); // removes pending newline from the buffer
	for(i = 0; input[i] != '\0'; i++)
	{
		counter[(int)input[i]]++; // the characters are casted to their ASCII value and used as indices for the counter array
	}
	for( i = 0; i < 128; i++)
	{
		if(counter[i] != 0)
			printf("%c is present %d times.\n", i, counter[i]); // empty indices are ignored during display 
		else
			continue;
	}
	return 0;
}