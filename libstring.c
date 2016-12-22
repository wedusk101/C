/*
The following program tests implementations of strlen(), strcmp(), strcpy(), strrev() and strcat(). I'm certain the code could be 
much better, but for now this is what I could manage, given the time contraints. Please note that the functions are not fully compliant
with ANSI/ISO standards, as I didn't put in security checks for the user input. I plan on doing that later when I get the chance.
*/ 

#include <stdio.h>
#include <string.h> // For the strtok() function. Didn't feel like writing my own function for cleaning up the newline characters.
#include <stdlib.h>  // Don't know if there's a sign function, ended up using abs() for implementing it in a single line. Didn't write a separate function.
#define SIZE 200

int strlength(char[]);
int strcmpr(char[], char[]);
void strcopy(char[], char[]);
void strrevrs(char[]);
void strcncat(char[], char[]);

int main()
{	
 	int choice = 0, i = 0;
	char str_first[SIZE], str_second[SIZE];
    	printf("This program tests implementations of a few standard library string functions.\n");
    	printf("Please enter 1 to find out the length of a string.\n");
    	printf("Please enter 2 to compare two strings.\n");
    	printf("Please enter 3 to copy one string into another.\n");
    	printf("Please enter 4 to reverse a string.\n");
    	printf("Please enter 5 to append two strings.\n");
    	scanf("%d", &choice);
	setbuf(stdin, NULL); // Clears the input buffer after using scanf for removing the pending newline from pressing the return key. Could be compiler specific! Not sure.
	switch(choice)
	{	
                case 1:
			printf("Please enter a string.\n");
			fgets(str_first, SIZE, stdin);
			strtok(str_first, "\n"); // Removing the newline from the user input return key press
			printf("The string you entered is: %s.\n", str_first);
			printf("The length of the string is %d.\n", strlength(str_first));
                        break;			
                
		case 2:
			printf("Please enter two strings.\n");
                        fgets(str_first, SIZE, stdin);
			strtok(str_first, "\n");// Again removing the newline from the user input return key press
                        fgets(str_second, SIZE, stdin);
			strtok(str_second, "\n");
                    	printf("The first string you entered is: %s.\n", str_first);
                    	printf("The second string you entered is: %s.\n", str_second);
                        printf("%d\n", strcmpr(str_first, str_second));
                        break;

                case 3:
			printf("Please enter two strings.\n");
                        fgets(str_first, SIZE, stdin);
			strtok(str_first, "\n");
                        fgets(str_second, SIZE, stdin);
			strtok(str_second, "\n");
                        printf("The first string you entered is: %s.\n", str_first);
                        printf("The second string you entered is: %s.\n", str_second);
                        strcopy(str_first, str_second);
                        break;

                case 4:
			printf("Please enter a string.\n");
                        fgets(str_first, SIZE, stdin);
			strtok(str_first, "\n");
                        printf("The string you entered is: %s.\n", str_first);
                        strrevrs(str_first);
                        break;
                    
                case 5:
                        printf("Please enter two strings.\n");
                        fgets(str_first, SIZE, stdin);
			strtok(str_first, "\n");
                        fgets(str_second, SIZE, stdin);
			strtok(str_second, "\n");
                        printf("The first string you entered is: %s.\n", str_first);
                        printf("The second string you entered is: %s.\n", str_second);
                        strcncat(str_first, str_second);
                        break;
                    
                default:
                        printf("Wrong choice!\n");
                        break;
	}
        return 0; // End of main()
 }
 
 int strlength(char str1[]) // Calculates the length of the string
 {
    	int len = 0;
    	while(str1[len] != '\0')
    	{
        	len++;
    	}
    	return len;
 }
 
 int strcmpr(char str1[], char str2[]) // Compares the strings and returns -1, 0 or 1
 {                 
 	int i = 0, d = 0, len1 = 0, len2 = 0, len = 0;
	while(str1[len1] != '\0')
    	{
        	len1++;
    	}
	while(str2[len2] != '\0')
    	{
        	len2++;
    	}
	if(len1 < len2) // Finds out the longer string
		len = len2;
	else
		len = len1;
	while(i <= len) // Loops until the length of the longer string is reached
    	{      
		d = str1[i] - str2[i]; // Stores the difference between the ASCII values of the characters
		if(d < 0)
        	{
            		break;
        	}
        	else if(d > 0)
        	{
            		break;
        	}
		i++;
    	}
	if(d != 0)
		return (int)(d/abs(d)); // Basically the sign function of d. Returns 1 or -1
	else
		return 0;
}

void strcopy(char dest[], char src[]) // Copies source string to destination string including the NULL terminating character
{
     	int len = 0, i = 0;
     	while(src[len] != '\0') // Calculates the length of the destination string. This gives us the index from where to start copying the source string.
     	{
		len++;
     	}
        while(src[i] != '\0') // Copies the characters of the source string into the destination string
        {
        	dest[i] = src[i];
		i++;
     	}
	dest[len] = '\0'; // Adds the NULL terminating character
     	printf("The new string is %s.\n", dest);
}

void strrevrs(char str[]) // Reverses a string.Swaps the characters starting from the ends and traversing to the middle.
{
	int len = 0, i = 0, j = 0, tmp = 0, c = 0;
	while(str[len] != '\0') // Calculates the length of the string for using in the loop.
	{
		len++;
        }
	j = len - 1; // Starts from before the NULL terminating character as the endpoint.
	while(c < len/2) // Loops until the middle of the string is reached. For strings with odd number of characters, the middle character stays fixed.
	{
		tmp = str[i];
        	str[i] = str[j];
        	str[j] = tmp;
		i++;
		j--;
		c++; // Loop test condition update
     	}
        printf("The new string is %s.\n", str);
 }
 
 void strcncat(char dest[], char src[]) // Appends two strings and returns the joined string.
 {
	int len = 0, i = 0, j = 0, c = 0;
        while(dest[len] != '\0') // Calculates the length of the destination string
	{
		len++;
        }
	for(i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
		c++; // Calculates the length of the source string
	}
	dest[len + c] = '\0'; // Adds the NULL terminating character by adjusting the offset
	printf("The new string is %s.\n", dest);
 }
