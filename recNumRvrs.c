#include <stdio.h>
#include <math.h>

int recNumRvrs(int, int);
void countDigits(int, int*);

int main()
{
	int input = 0, digits = 0;
	printf("Please enter a positive integer.\n");
	scanf("%d", &input);
	countDigits(input, &digits);
	printf("The reverse of %d is %d.\n", input, recNumRvrs(input, digits));
	return 0;
}

void countDigits(int num, int *count)
{
	for(;num != 0; num /= 10)
		(*count)++;
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