#include <stdio.h>

int main()
{
	int i = 0, j = 0, k = 0, l = 9;
	for(i = 5; i >= 1; i--)
	{
		for(j = 0; j < 5 - i; j++)
		{
			printf(" ");
		}
		for(k = l; k >= 1; k--)
		{
			printf("*");
		}
		printf("\n");
		l-=2;
	}
	return 0;
}
