#include<stdio.h>

#define TRUE 1
#define FALSE 0

int isPrime(int);

int main()
{
	int num = 0, count = 0, i = 0;
	printf("Please enter the upper bound.\n");
	scanf("%d", &num);
	for(i = 1; i <= num; i++)
	{
		if(isPrime(i))
			count++;
	}
	printf("The number of primes till %d is %d.\n", num, count);
}

int isPrime(int n)
{
	int i = 0;
	if(n <= 1 || n == 4)
		return FALSE;
	else
		for(i = 2; i < n / 2; i++)
		{
			if(n % i == 0)
				return FALSE;
		}
	return TRUE;
}