#include <stdio.h>
int gcd(int, int);

int main()
{
	int first_number = 0, second_number = 0;
	printf("This program prints the Greatest Common Divisor of two numbers using Euclid's algorithm.\n");
	printf("Please enter two numbers.\n");
	scanf("%d", &first_number);
	scanf("%d", &second_number);
	printf("The GCD of %d and %d is %d.\n", first_number, second_number, gcd(first_number, second_number));
	return 0;
}

int gcd(int first, int second)
{
	if(first % second == 0)
		return second;
	else
		gcd(second, first % second); 
}

	
