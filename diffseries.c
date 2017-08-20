// 1 + 2 + 4 + 7 + 11 +...
#include <stdio.h>

int main()
{
	int sum = 0, range = 0, i = 0, j = 0, term = 1;
	printf("Please enter the number of terms to calculate.\n");
	scanf("%d", &range);
	for(i = 1; j < range; i++, j++)
	{
		sum = sum + term;
		printf("%d ", term);
		term = term + i;
	}
	printf("\nThe sum is %d.\n", sum);
	return 0;
}