#include <stdio.h>

int main() // prints a crude hexagon
{
	int i = 0, j = 0;
	for(i = 0; i < 20; i++) // y - axis
	{
		for(j = 0; j < 20; j++) // x - axis
		{
			if(i <= 9 && i >= 1 && (2*j) + i <= 25 && (2*j) + i >= 9 && (2*j) - i + 1 >= 0 && (2*j) - i <= 15)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}