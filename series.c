#include <stdio.h>
#include <math.h>

int main()
{
	int input = 0, i = 0, sign = -1; 
	double sum = 1.0, term = 0.0;
	printf("This series prints the sum of the series 1 - 1/3 + 1/9 - 1/27  .... upto n terms. \n");
	printf("Enter the value of n.\n");
	scanf("%d", &input);
	for(i = 1; i < input; i++)
	{
		if(i % 2 != 0)
		{
			term = sign * (1/pow(3,i));
		}
		else
		{
			term = 1/(pow(3,i));
		}
		sum = sum + term ;
	}
	printf("The sum of the series till n is %2.4f. \n", sum);
	return 0;
}

