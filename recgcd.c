#include <stdio.h>
int gcd(int, int);

int main()
{
	int first_number = 0, second_number = 0;
	printf("This program prints the Greatest Common Divisor of two numbers using Euclid's algorithm.\n");
	printf("Please enter two numbers such that the first number is less than the second number.\n");
	scanf("%d", &first_number);
	scanf("%d", &second_number);
	printf("The GCD of %d and %d is %d.", first_number, second_number, gcd(first_number, second_number));
	return 0;
}

int gcd(int first, int second)
{
	int rem = 0, tmp = 0;
	while(first > 0)
	{
		rem = second % first;
		if(rem == 0)
		{
			return first;
			break;
		}
		else
		{
			tmp = first;
			first = rem;
			second = tmp;
			gcd(first, second);
		}
	}
	return first;	
}

	
