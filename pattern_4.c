#include <stdio.h>

int main()
{
	int i = 0, j = 0, k = 0;
	for(i = 1; i <= 5; i++)
	{
		for(j = 5-i; j >= 0; j--)
		{
			printf(" ");
		}
		for(k = 1; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
