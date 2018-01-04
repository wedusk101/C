/*The following code is a naive implementation to generate the nth Fibonacci term
using recursion.*/
#include <stdio.h>
#include <time.h>

unsigned long int fibonacci(int);

int main()
{
	int term = 0;
	clock_t start, stop;
	float diff;
	printf("This program prints the nth term of the Fibonacci sequence.\n");
	printf("Please enter the term to display.\n");
	scanf("%d", &term);
	start = clock();
	printf("Required term is %lu.\n", fibonacci(term));
	stop = clock();
	diff = ((float)stop - (float)start)/CLOCKS_PER_SEC;
	printf("Time taken is %f seconds.\n", diff);	
	return 0;
}

unsigned long int fibonacci(int n)
{
	if(n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}