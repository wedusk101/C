#include <stdio.h>

int main()
{
	int i = 0, j = 0, k = 0, l = 1;
	for(i = 1; i <= 5; i++)
	{
		for(j = 5-i; j > 0; j--)
		{
			printf(" ");
		}
		for(k = 1; k <= l; k++)
		{
			printf("*");
		}
		printf("\n");
		l+=2;
	}
	return 0;
}
