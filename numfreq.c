#include <stdio.h>

int main()
{
	int input = 0, i = 0, digit = 0, freq[10] = {0}; // intializes the array to zero
	printf("Please enter a number.\n");
	scanf("%d", &input);
	while(input > 0)
	{
		digit = input % 10; // extracts the digits
		freq[digit]++; // increments the count for the extracted digit in the frequency array
		input = input / 10;
	}
	for(i = 0; i < 10; i++)
	{
		if(freq[i]!=0) // ignores empty indices
			printf("%d is present %d times.\n", i, freq[i]);
	}
	return 0;
}