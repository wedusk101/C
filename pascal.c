/*
The following code prints N lines of the Pascal's triangle where N is taken as input
from the user. The program calculates the binomial coefficients to generate the triangle
using the formula n!/(k! * (n - k)!).The function fact() calculates the factorials
of the numbers which are then used for computing the binomial coefficients.
*/

#include <stdio.h>
int fact(int);

int main()
{
	int i = 0, j = 0, k = 0, line = 0;
	printf("How many lines of the Pascal's triangle would you like to see?\n");
	scanf("%d", &line);
	printf("\n");
	line = line - 1;
	for(i = 1; i <= line; i++)
	{
		printf(" ");
	}
	printf("1\n");
	for(i = 1; i <= line; i++)
	{
		for( j = 1; j <= line - i; j++)
		{
			printf(" ");
		}
		for(k = 0; k <= i; k++)
		{
			printf("%d", (int)(fact(i)/(fact(k) * fact(i - k)))); // generates the binomial coefficients
			printf(" ");
		}
		printf("\n");
			
	}
	return 0;
}

int fact(int n) // calculates the factorials of the numbers
{
	int i = 0, result = 1;
	for(i = 1; i <= n; i++)
	{
		result = result * i;
	}
	return result;
}