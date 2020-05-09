// This piece of code implements a basic memory allocator utilizing the arena design pattern
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

const size_t SIZE_1G = 1073741824;
const size_t SIZE_2G = 2147483648;
const size_t SIZE_4G = 4294967296;

size_t POOL_SIZE = 4294967296; // copy the value from the relevant constant here

struct Node
{
	int value;
	struct Node *next;
};

typedef struct Node NODE;	

static size_t offset = 0;

void* allocate(char *arena, size_t req_size)
{
	if(offset + req_size <= POOL_SIZE)
	{
		void *ptr = &arena[offset];
		offset += req_size;
		memset(ptr, 0, req_size);
		return ptr;
	}
	return NULL;
}

int main()
{	
	char *arena = malloc(POOL_SIZE);	
	memset(arena, 0, POOL_SIZE);
	int *numList = allocate(arena, sizeof(int) * SIZE);
	
	if(numList != NULL)
	{
		for(size_t i = 0; i < SIZE; i++)
			numList[i] = 2 * i;
	
		for(size_t i = 0; i < SIZE; i++)
			printf("%d ", numList[i]);
		printf("\n\n");
	}
	
	float *floatList = allocate(arena, sizeof(float) * SIZE);
	
	if(floatList != NULL)
	{
		for(size_t i = 0; i < SIZE; i++)
			floatList[i] = 0.2f * i;
	
		for(size_t i = 0; i < SIZE; i++)
			printf("%f ", floatList[i]);
		printf("\n\n");
	}
	
	NODE *nptr = allocate(arena, sizeof(NODE) * SIZE); // allocate a list of NODE objects
	
	if(nptr != NULL)
	{
		for(size_t i = 0; i < SIZE; i++)
		{
			nptr[i].value = 3 * i;
			nptr[i].next = NULL;
		}
	
		for(size_t i = 0; i < SIZE; i++)
			printf("%d ", nptr[i].value);
		printf("\n");
	}
	
	
	printf("Enter 'q' to quit...\n");
	for(char input = ' '; input != 'q';)
		scanf("%c", &input);
	
	free(arena);
}
	