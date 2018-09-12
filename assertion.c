#include <stdio.h>
#include <assert.h>

int main()
{
	int x = 0;
	printf("Please enter an even number.\n");
	scanf("%d", &x);
	assert(x % 2 == 0 && "ERROR: Input number is NOT prime. Program terminated."); // assert(condition && message) in case the assertion fails
	printf("Okay\n"); // assertion passes
	return 0;
}