#include<stdio.h>

#define TRUE 1
#define FALSE 0

int isPrime(int);

int main()
{
	int num = 0;
	printf("Please enter a number.\n");
	scanf("%d", &num);
	if(isPrime(num))
		printf("Prime number.\n");
	else
		printf("Not a prime number.\n");
	return 0;
}

int isPrime(int n)
{
	int i = 0;
	if(n <= 1)
		return FALSE;
	else
		for(i = 2; i < n / 2; i++)
		{
			if(n % i == 0)
				return FALSE;
		}
	return TRUE;
}