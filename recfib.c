#include <stdio.h>
int fibonacci(int);

int main()
{
	int term = 0, i = 0;
	printf("This program prints the terms of the Fibonacci sequence. \n");
	printf("Please enter the number of terms to display. \n");
	scanf("%d", &term);
	printf("The terms are 0 1 ");
	for(i = 0; i <= term - 3; i++)
	{
		printf("%d ", fibonacci(i));
	}
	printf(". \n");
	return 0;
}

int fibonacci(int n)
{
	int result = 1;
	if(n > 0)
	{
		result = fibonacci(n-1) + fibonacci(n-2);
	}
	return result;
}
