/* The following code calculates the sine of an angle in radians using the Taylor series expansion
Sin x = x - x^3/3! + x^5/5! - x^7/7! ....
The program runs as long as the absolute relative approximate error, epsilon, is above a pre-specified threshold.
The factorial is calculated by a separate function which then returns the value to be used for calculating
the current term. */

#include <stdio.h>
#include<math.h>
int factorial(int);

int main()
{
	int i = 1, p = 0;
    	float x = 0.0, epsilon = 1.0, sinx = 0.0, term_current = 0.0, term_previous = 0.0;
    	printf("Enter the angle in radians. \n");
    	scanf("%f", &x);
    	while((fabs)(epsilon)>0.0001)
    	{
        	term_current = pow(x,i)/(float)factorial(i)*pow((-1),p);
        	sinx = sinx + term_current;
        	epsilon = term_current - term_previous;
        	term_previous = term_current;
        	p++;
        	i+=2;
    	}
    	printf("The sine of %f radians is %5.4f. \n", x, sinx);
    	return 0;
}

int factorial(int n)
{
    	int j = 1, fact = 1;
    	for(j = 1; j <= n; j++)
	{
            fact = fact * j;
        }
	return fact;
}
    
    
