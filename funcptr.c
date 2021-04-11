/*Sample code to demonstrate the use of function pointers (callbacks) in C.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *listPtr;
	int size;
} List;	

int sum(int a, int b)
{
	return a + b;
}

int fmadd(int a, int b, int c)
{
	return a * b + c;
}

List* genRandList(int len)
{
	List *arr = (List*)malloc(sizeof(List));
	arr->size = len;
	arr->listPtr = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; ++i)
		arr->listPtr[i] = rand();
	
	return arr;
}

int operateSum(int (*sum) (int, int), int x, int y)
{
	return sum(x, y);
}

int operateFMA(int (*fmadd) (int, int, int), int x, int y, int z)
{
	return fmadd(x, y, z);
}

List* operateRandList(List* (*genRandList) (int), int size)
{
	return genRandList(size);
}

int main(int argc, char **argv)
{
	int a = 0, b = 0, c = 0, len = 0;
	
	printf("Please enter two integers to add.\n");
	scanf("%d%d", &a, &b);
	int s = operateSum(sum, a, b);
	printf("The sum is %d.\n", s);
	
	printf("Please enter three integers for fused multiply add.\n");
	scanf("%d%d%d", &a, &b, &c);
	int fma = operateFMA(fmadd, a, b, c);
	printf("The result of the fused multiply add operation is %d.\n", fma);
	
	printf("Please enter the length of the required list of random numbers.\n");
	scanf("%d", &len);
	List *arr = operateRandList(genRandList, len);	
	printf("The list of random numbers is:\n");
	for (int i = 0; i < arr->size; ++i)
		printf("%d\n", arr->listPtr[i]);
		
	free(arr->listPtr);
	free(arr);
	return 0;
}
	