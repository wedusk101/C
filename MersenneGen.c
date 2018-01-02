/*The following code generates Mersenne Prime numbers. The user inputs the number 
of Mersenne Primes to display.A Mersenne prime is of the form M = (2^N) - 1 where
M is a prime number and N is a positive integer and is prime. Please note that due to the 
very nature of Mersenne Primes, which are exceedingly rare, this program is very
slow for anything beyond very small input sizes.The program will also fail once it
exceeds the precision of the long integer format. Handling large numbers like
Mersenne Primes require special methods not implemented here. The code can be made
significantly more efficient using a few techniques. For example, the prime generator
used here can be replaced by something like the Sieve of Eratosthenes or the Sieve of Atkin.
Finally, multithreading the program can result in much better performance.*/

#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int isPrime(long int);
int isMersenne(long int);

int main()
{
	unsigned long int num = 0, i = 2, count = 0;
	printf("How many Mersenne Primes would you like to generate?\n");
	scanf("%lu", &num);
	printf("The list is:\n");
	while(count != num) 
	{
		if(isPrime(i) && isMersenne(i))
		{
			printf("%lu\n", i);
			count++;
		}
		i++;
	}
	return 0;
} // end

int isPrime(long int n) // checks if a number is prime or not
{
	unsigned long int i = 0;
	if(n <= 1 || n == 4)
		return FALSE;
	else
		for(i = 2; i < sqrt(n); i++)
		{
			if(n % i == 0)
				return FALSE;
		}
	return TRUE;
}

int isMersenne(long int m) // generates Mersenne Primes
{
	unsigned long int var = 0, exp = 1;
    while(exp <= log2(m + 1)) // M = (2^exp) - 1 => exp = log2(M + 1)
    {
        var = (unsigned long int)pow(2,exp);
        if(var == (m + 1)) // follows from the definition of a Mersenne prime
			return TRUE;
        exp++;
    }
    return FALSE;
}