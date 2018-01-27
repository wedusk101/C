/*The following code calculates the approximate value of Pi using Monte Carlo Sampling.*/ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() 
{
	srand(time(NULL));
	long long count = 0, max = 0, samples = 0, i = 0, x = 0, y  = 0; // the value of samples controls the precision of the approximation
	long double pi = 0.0;
	clock_t start, stop;
	printf("Please enter the sample size. Doubling the sample size quadruples the computation time.\n");
	scanf("%lld", &samples);
	max = samples * samples; // square of the radius = total number of samples
	start = clock();
	for(i = 0; i < max; i++) // sampling
	{	
		x = rand() % samples + 1;
		y = rand() % samples + 1;
			if(x * x + y * y <= max) // x^2 + y^2 <= r^2 where r is the radius
				count++;		
	}
	pi = (4 * count)/(long double)max;
	stop = clock();
	printf("Sample size is %lld.\n",samples);
	printf("Approximate value of Pi is %7.6Lf.\n", pi);
	printf("Time taken is %f seconds.\n",((float)stop - (float)start)/(float)CLOCKS_PER_SEC);
	return 0;
}