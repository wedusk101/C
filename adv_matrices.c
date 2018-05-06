/* Checks whether a matrix is upper triangular, lower triangular, identity,
diagonal or tridiagonal. Should be updated for more efficient algorithms. */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int** createMatrix(int, int);          // prototype to allocate space for matrix
void inputMatrix(int **, int, int);    // prototype to populate matrix 
void displayMatrix(int **, int, int); // prototype to display elements of the matrix 
int isUpperTriangular(int **, int); // prototype to check whether the matrix is upper triangular
int isLowerTriangular(int **, int); // prototype to check whether the matrix is lower triangular
int isIdentity(int**, int);     // prototype to check whether the matrix is identity 
int isDiagonal(int**, int);     // prototype to check whether the matrix is diagonal 
int isTridiagonal(int**, int);  // prototype to check whether the matrix is tridiagonal 
void delMatrix(int**, int); // deallocates memory

#define TRUE 1
#define FALSE 0

int main()
{
	int **mat, size;
	printf("Please enter the order for a 2D square matrix.\n");
	scanf("%d",&size);
	mat = createMatrix(size, size);	
    printf("Please enter the elements for the matrix.\n");
	inputMatrix(mat, size, size);	
    printf("The matrix you have entered is:\n\n");
	displayMatrix(mat, size, size);
	printf("\n\n");
	
	if(isUpperTriangular(mat, size))
		printf("The matrix is an Upper Triangular matrix.\n");
	else
		printf("The matrix is not an Upper Triangular matrix.\n");
	
	if(isLowerTriangular(mat, size))
		printf("The matrix is a Lower Triangular matrix.\n");
    else
    	printf("The matrix is not a Lower Triangular matrix.\n");
	
	if(isIdentity(mat, size))
		printf("The matrix is an Identity matrix.\n");
    else
    	printf("The matrix is not an Identity matrix.\n");
	
	if(isDiagonal(mat, size))
		printf("The matrix is a Diagonal matrix.\n");
    else
    	printf("The matrix is not a Diagonal matrix.\n"); 
	
    if(isTriDiagonal(mat, size))
		printf("The matrix is a Tridiagonal matrix.\n");
    else
    	printf("The matrix is not a Tridiagonal matrix.\n");
	printf("\n\n");
	delMatrix(mat, size); // memory is deallocated 
	return 0;
} // end of main

int** createMatrix(int row, int col) // dynamically allocates memory for the matrix
{
    int **p, i = 0;
    p = (int**)malloc(row * sizeof(int*));
    for(i = 0; i < row; i++)
    {
		*(p + i) = (int*)malloc(col * sizeof(int)); // allocates memory for each element          
    }    
    return p;
}

void inputMatrix(int **arr, int x, int y) // takes user input for the matrix
{
	int i = 0, j = 0;
    for(i = 0; i < x; i++)
    {
		for(j = 0; j < y; j++)
        {
			scanf("%d", *(arr + i) + j);
        }
    }
}      

void displayMatrix(int **arr, int x, int y) // displays the matrix
{
	int i = 0, j = 0;
    for(i = 0; i < x; i++)
    {
		for(j = 0; j < y; j++)
        {
			printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int isUpperTriangular(int **arr, int order)
{
	int i = 0, j = 0;
    for(i = 0; i < order; i++)
    {
		for(j = 0; j < order; j++)
        {
			if(i > j)
			{
				if(arr[i][j] == 0)
					return TRUE;
				else
					return FALSE;
			}
		}
    }
}
   
int isLowerTriangular(int **arr, int order)
{
    int i = 0, j = 0;
    for(i = 0; i < order; i++)
    {
		for(j = 0; j < order; j++)
        {
			if(i < j)
			{
				if(arr[i][j] == 0)
					return TRUE;
				else
					return FALSE;
			}
		}
    }
}

int isIdentity(int **arr, int order) // this function is dependent on isDiagonal()
{	int i = 0, j = 0, count = 0;
	for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++)
		{
			if(i == j && arr[i][j] == 1)
				count++; // counts the number of ones in the principal diagonal
		}
    }
	if(isDiagonal(arr, order) && count == order) // checks if the matrix is diagonal 
		return TRUE;
	else
		return FALSE;
}
 
int isDiagonal(int **arr, int order) 
{
	int i = 0, j = 0;
    for(i = 0; i < order; i++)
	{
		for(j = 0; j < order; j++)
		{
			if(i != j)
			{
				if (arr[i][j] == 0)
					return TRUE;
				else
					return FALSE;
			}
    
        }
	}
}

int isTriDiagonal(int **arr, int order) 
{
    int i = 0, j = 0, count = 0, zeros = 0;
    for(i = 0; i < order; i++)
    {
		for(j = 0; j < order; j++)
        {
			if(abs(i - j) > 1 && arr[i][j] == 0)
				count++; // counts the total number of zeros above and below the tridiagonals
		}
    }
	for(i = 0; i < order; i++)
    {
		for(j = 0; j < order; j++)
        {
			if(arr[i][j] == 0) // counts the total number of zeros
				zeros++;
        }
    }
	if(count == zeros) // checks whether the total number of zeros matches the number for a tridiagonal matrix of said order
		return TRUE;
	else 
		return FALSE;
}

void delMatrix(int **arr, int order)
{
	int i = 0;
	for(i = 0; i < order; i++)
		free(arr[i]);
	free(arr);
}