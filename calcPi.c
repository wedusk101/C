/* The following code very crudely approximates Pi using Euler's Basel problem approach where,
(pi^2)/6 = 1/1^2 + 1/2^2 + 1/3^2 + 1/4^2 + 1/5^2...
The program runs as long as the absolute relative approximate error, epsilon, is above a pre-specified threshold.
*/

#include <stdio.h>
#include<math.h>

int main()
{
	int i = 1;
    float epsilon = 1.0, sum = 0.0, term_current = 0.0, term_previous = 0.0, pi = 0.0;
    while((fabs)(epsilon)>0.000001)
    {
       	term_current = 1/(float)pow(i,2);
       	sum = sum + term_current;
		pi = sqrt(6 * sum);
       	epsilon = pi - term_previous;
       	term_previous = pi;
       	i++;
   	}
	printf("The approximate value of Pi is %5.4f.\n", pi);
    return 0;
}