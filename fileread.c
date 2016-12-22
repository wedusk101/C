#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char ch, filename[50];
	int c = 0, n = 0;
	printf("Please enter the name of the file you wish to open.\n");
	fgets(filename, 50, stdin);
	fp = fopen("Hello.txt", "r"); // Opens file in read mode
	if(fp == NULL)
	{
		perror("Error opening file.\n");
		exit(EXIT_FAILURE); // Displays error in case the program fails to open the file
	}
	printf("The contents of the file are:\n");
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n') // Counts the number of lines
		{
			n++;
		}
		printf("%c", ch);
		c++; // Counts the number of characters
	}
	fclose(fp);
	printf("\n");
	printf("The number of characters in the file is %d and the number of lines is %d .\n", c, n);
	return 0;	
}