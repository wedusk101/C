#include <stdio.h>

int recSum(int);

int main()
{
	int term = 0;
	printf("For how many consecutive natural numbers would you like to calculate the sum?\n");
	scanf("%d", &term);
	printf("The sum is %d.\n", recSum(term));
}

int recSum(int n)
{
	if(n > 0)
		return n + recSum(n - 1);
}