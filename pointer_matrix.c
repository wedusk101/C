#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int, int);
void inputMatrix(int**, int, int);
void displayMatrix(int**, int, int);

int main()
{
	int **mat, row = 0, col = 0;
	printf("Please enter the number of rows you want in your matrix.\n");
	scanf("%d", &row);
	printf("Please enter the number of columns you want in your matrix.\n");
	scanf("%d", &col);
	mat = createMatrix(row, col); // saves the returned pointer
	printf("Please enter the elements of the matrix.\n");
	inputMatrix(mat, row, col); 
	printf("The maxtrix you have entered is : \n");
	displayMatrix(mat, row, col);	
}

int** createMatrix(int r, int c)
{
	int i = 0, **pmat;
	pmat = malloc(r * sizeof(int*));// allocates memory for the array of pointers
	for(i = 0; i < r; i++)
	{
		*(pmat + i) = (int *)malloc(c * sizeof(int));	// allocates memory for the arrays of integers	
	}
	return pmat;	
}

void inputMatrix(int **mt, int r, int c) // takes user input
{
	int i = 0, j = 0;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			scanf("%d", *(mt + i) + j);  
		}	
	}
	
}

void displayMatrix(int** mt, int r, int c) // displays the matrix
{
	int i = 0, j = 0;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("%d ", *(*(mt + i) + j));
		}
		printf("\n");
	}
	
}