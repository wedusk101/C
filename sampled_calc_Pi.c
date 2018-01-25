/*The following code calculates the approximate value of Pi using a sampling method. It is very similar to the Monte Carlo method for 
calculating Pi but doesn't use stochastic sampling. The sample size is set to 100000 (tested on GCC 5.4.0) which prevents overflow errors.*/ 
#include <stdio.h>
#include <time.h>

int main() 
{
	unsigned long int i = 0, j = 0, count = 0, samples = 0; // the value of samples controls the precision of the approximation
	long double pi = 0.0;
	clock_t start, stop;
	printf("Please enter the sample size (MAX 100,000).\n");
	scanf("%lu", &samples);
	start = clock();
	for(i = 0; i < samples; i++) // y - axis
	{
		for(j = 0; j < samples; j++) // x - axis
		{
			if(j * j + i * i <= samples * samples) // x^2 + y^2 <= r^2 where r is the radius 
				count++;
		}
	}
	pi = (4 * count)/(long double)(samples * samples);
	stop = clock();
	printf("Sample size is %lu.\n", samples);
	printf("Approximate value of Pi is %Lf.\n", pi);
	printf("Time taken is %f seconds.\n", ((float)stop - (float)start)/CLOCKS_PER_SEC);
	return 0;
}