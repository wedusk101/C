/*The following code generates Mersenne Prime numbers. The user inputs the number 
of Mersenne Primes to display.A Mersenne prime is of the form M = (2^N) - 1 where
M is a prime number and N is a positive integer. Please note that due to the 
very nature of Mersenne Primes, which are exceedingly rare, this program is very
slow for anything beyond very small input sizes.The program can be made significantly
more efficient using a few techniques. For example, the prime generator used here
can be replaced by something like the Sieve of Eratosthenes or the Sieve of Atkin.
The function isMersenne() can also be made faster by limiting the number of iterations.
Finally, multithreading the program can result in much better performance.*/

#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int isPrime(int);
int isMersenne(int);

int main()
{
	int num = 0, i = 0, count = 0;
	printf("How many Mersenne Primes would you like to generate?\n");
	scanf("%d", &num);
	printf("The list is:\n");
	while(1) 
	{
		if(isPrime(i) && isMersenne(i))
		{
			printf("%d\n", i);
			count++;
		}
		if(count == num)
			break;
		i++;
	}
} // end

int isPrime(int n) // checks if a number is prime or not
{
	int i = 0;
	if(n <= 1)
		return FALSE;
	else
		for(i = 2; i < n / 2; i++)
		{
			if(n % i == 0)
				return FALSE;
		}
	return TRUE;
}

int isMersenne(int m) // generates Mersenne Primes
{
	int var = 0, exp = 1;
    while(exp < m) // the number of iterations here can be reduced using logarithms
    {
        var = (int)pow(2,exp);
        if(var == (m + 1))
			return TRUE;
        exp++;
    }
    return FALSE;
}
