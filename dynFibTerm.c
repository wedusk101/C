/*The following code generates the nth Fibonacci term using dynamic programming.
Compared to the naive recursive solution, which runs in O(2^n), this approach runs
in linear time.Over here, an array is used to save the intermediate results of the 
recursive calls.This process is called memoization.Using this technique, overlapping
sub-problems are saved for future reuse.Some other problems where dynamic programming
is used include solving the Traveling Salesman Problem(TSP) and finding out the all-pairs
shortest paths for a given graph, as in the Floyd-Warshall algorithm.*/

#include <stdio.h>
#include <time.h>

unsigned long int fibonacci(int, unsigned long int*);

int main()
{
	int term = 0, i = 0;
	clock_t start, stop;
	float diff;
	printf("This program prints the nth term of the Fibonacci sequence.\n");
	printf("Please enter the term to display.\n");
	scanf("%d", &term);
	unsigned long int memo[term + 1];
	for(i = 0; i < term + 1; i++)
		memo[i] = 0;
	start = clock();
	printf("Required term is %lu.\n", fibonacci(term, memo));
	stop = clock();
	diff = ((float)stop - (float)start)/CLOCKS_PER_SEC;
	printf("Time taken is %f seconds.\n", diff);	
	return 0;
}

unsigned long int fibonacci(int n, unsigned long int *bak)
{
	if(bak[n] != 0)
		return bak[n];
	if(n == 1 || n == 2)
		return 1;
	else
		bak[n] = fibonacci(n-1, bak) + fibonacci(n-2, bak);
	return bak[n];
}