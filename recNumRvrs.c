#include <stdio.h>
#include <math.h>

int recNumRvrs(int, int);
int countDigits(int);

int main()
{
	int input = 0, digits = 0;
	printf("Please enter a positive integer.\n");
	scanf("%d", &input);
	digits = countDigits(input);
	printf("The reverse of %d is %d.\n", input, recNumRvrs(input, digits));
	return 0;
}

int countDigits(int num)
{
	int count = 0;
	for(;num != 0; num /= 10)
		count++;
	return count;
}

int recNumRvrs(int num, int digits)
{
	int d = num % 10;
	num = num / 10;
	if(digits > 1)
		return (int)(d * pow(10, digits - 1) + recNumRvrs(num, digits - 1));
	else
		return d; 
}