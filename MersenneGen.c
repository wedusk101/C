/*The following code generates Mersenne Prime numbers using trial division method. 
The user inputs the number of Mersenne Primes to display.A Mersenne prime is of 
the form M = (2^N) - 1 where M is a prime number and N is a positive integer and 
is prime. Please note that due to the very nature of Mersenne Primes, which are 
exceedingly rare, this program is very slow for anything beyond very small input 
sizes.The program will also fail once it exceeds the precision of the long integer
format. Handling large numbers like Mersenne Primes require special methods not 
implemented here. The code can be made significantly more efficient using a few 
techniques. For example, the prime generator used here can be replaced by something
like the Sieve of Eratosthenes. Finally, multithreading the program can result in 
much better performance. A different approach altogether, like the Lucas–Lehmer 
primality test, is obviously a different scenario altogether.*/

#include<stdio.h>
#include<math.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

int isPrime(long long);
int isMersenne(long long);

int main()
{
	long long num = 0, i = 3, count = 0;
	printf("How many Mersenne Primes would you like to generate?\n");
	scanf("%lld", &num);
	printf("The list is:\n");
	while(count != num) 
	{
		if(isPrime(i) && isMersenne(i))
		{
			printf("%lld\n", i);
			count++;
		}
		i += 2;
	}
	return 0;
} // end

int isPrime(long long n) // checks if a number is prime or not
{
	long long i = 0;
	if(n <= 1)
		return FALSE;
	else
		for(i = 2; i * i <= n; i++)
		{
			if(n % i == 0)
				return FALSE;
		}
	return TRUE;
}

int isMersenne(long long m) // generates Mersenne Primes
{
	long long var = 0, exp = 1;
    while(var <= (m + 1)) // M = (2^exp) - 1 => 2<<exp = (M + 1)
    {
        var = 2<<exp;
        if(var == (m + 1)) // follows from the definition of a Mersenne prime
			return TRUE;
        exp++;
    }
    return FALSE;
}