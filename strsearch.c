#include <stdio.h>
#include <string.h>

#define SIZE 140

int naiveMatch(char*, char*);

int main()
{
	int result = 0;
	char needle[10], haystack[SIZE];
	printf("Please enter the text.\n");
	fgets(haystack, SIZE, stdin);
	strtok(haystack, "\n");
	printf("Please enter the pattern to search for.\n");
	fgets(needle, 10, stdin);
	strtok(needle, "\n");
	result = naiveMatch(needle, haystack);
	if(result == -1)
		printf("The given pattern was not found in the given text.\n");
	else
		printf("Pattern found at position %d of the text.\n", result + 1);
	return 0;	
}

int naiveMatch(char* pattern, char* text)
{
	int i = 0, j = 0, patlen = 0, texlen = 0, count = 0;
	patlen = strlen(pattern);
	texlen = strlen(text);
	for(j = 0; j <= patlen && i <= texlen; j++, i++)
	{
		printf("loop\n");
		if(count == patlen)
			return i - patlen;
		if(text[i] == pattern[j])
			count++;
		else
		{
			j = -1;
			count = 0;
		}
	}
	return -1;	
}