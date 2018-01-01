/*The following code recursively reverses a given string.*/
#include <stdio.h>
#include <string.h>

void recStrRvrs(char*, int);

int main()
{
	int len = 0;
	char input[30];
	printf("Please enter a string.\n");
	fgets(input, 30, stdin);
	len = strlen(input) - 1;
	printf("The reversed string is:\n");
	recStrRvrs(input, len);
	printf("\n");
	return 0;
}

void recStrRvrs(char *str, int num)
{
	if(num >= 0)
	{
		printf("%c", str[num]);
		recStrRvrs(str, num - 1);
	}
}