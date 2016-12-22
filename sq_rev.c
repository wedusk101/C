#include<stdio.h>
int reverse(int);

int main()
{
	int num = 0, first_reverse = 0, second_reverse = 0, first_square = 0, second_square = 0; 
	for(num = 10; num <= 100; num++)
	{
		first_square = num * num;
		first_reverse = reverse(num);
		second_square = first_reverse * first_reverse;
		if(reverse(first_square) == second_square && num % 10 != 0)
		{
			printf("%d \n", num);
		}
		else
			continue;
	}	
	return 0;
}

int reverse(int n)
{
	int sum = 0, rem = 0;
	while( n != 0)
	{
		rem = n % 10;
		sum = (sum * 10) + rem;
		n = n / 10;
	}
	return sum;
}