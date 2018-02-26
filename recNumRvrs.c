#include <stdio.h>
#include <math.h>

int recNumRvrs(int);

int main()
{
	int input = 0;
	printf("Please enter a positive integer.\n");
	scanf("%d", &input);
	printf("The reverse of %d is %d.\n", input, recNumRvrs(input));
	return 0;
}

int recNumRvrs(int num)
{
	return num > 10 ? (num % 10) * pow(10, (int)log10(num)) + recNumRvrs(num / 10) : num;
}