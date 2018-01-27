/*The following code prints a half-circle.*/
#include <stdio.h>
#include <math.h>

int main() 
{
	int i = 0, j = 0, count = 0, samples = 0; 
	printf("Please enter the sample size.\n");
	scanf("%d", &samples); // samples = diameter
	for(i = 0; i < samples; i++) // y - axis
	{
		for(j = 0; j < samples; j++) // x - axis
		{
			if(pow((j - samples/(float)2),2) + pow((i - samples/(float)2),2)  <= (samples * samples)/(float)4) // x^2 + y^2 <= radius^2
				printf("*");
		}
		printf("\n");
	}
	return 0;
}