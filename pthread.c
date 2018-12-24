#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile long int sum = 0;
pthread_mutex_t sumLock;

void threadAddOne()
{
	int i = 0;
	long int localSumOne = 0;
	for(i = 1; i < 500000000; i++)
		localSumOne += i;
	pthread_mutex_lock(&sumLock);
	sum += localSumOne;
	pthread_mutex_unlock(&sumLock);
}

void threadAddTwo()
{
	int i = 0;
	long int localSumTwo = 0;
	for(i = 1; i < 500000000; i++)
		localSumTwo += i;
	pthread_mutex_lock(&sumLock);
	sum += localSumTwo;
	pthread_mutex_unlock(&sumLock);
	
}

int main()
{
	pthread_t one, two;
	pthread_mutex_init(&sumLock, NULL);
	pthread_create(&one, NULL, (void*)&threadAddOne, NULL);
	pthread_create(&two, NULL, (void*)&threadAddTwo, NULL);
	
	pthread_join(one, NULL);
	pthread_join(two, NULL);
	
	printf("%ld\n", sum);
	
	pthread_mutex_destroy(&sumLock);
	return 0;
}