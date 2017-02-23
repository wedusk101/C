/*The following code takes as input a two dimensional sparse matrix and
generates its compressed representation and transpose in COO (coordinate)
format.The original sparse matrix is then deleted and the compressed
representation is used to generate the transpose for the sparse matrix.*/

#include<stdio.h>
#include<stdlib.h>

int** createMatrix(int,int);        // prototype to allocate memory for a matrix 
void inputMatrix(int **,int,int);   // prototype to populate matrix 
void displayMatrix(int **,int,int); // prototype to display elements of the matrix 
int count(int **,int,int);          // prototype to count non-zero elements of a matrix 
int** sparse(int **, int,int);      // prototype to store a matrix in compressed form  
int** transposeSp(int **);          // prototype to transpose a sparse matrix 

int main(void)
{
	int row = 0, col = 0, i = 0;
	int **mat, **compr, **trans, nzc = 0; 
	printf("Please enter the order of the matrix (row and column):\n");
	scanf("%d%d",&row, &col);
	mat = createMatrix(row, col);		
	printf("Please enter the elements of the matrix:\n");
	inputMatrix(mat, row, col);		
	printf("The given matrix is:\n\n");
	displayMatrix(mat, row, col); // displays the original sparse matrix
	printf("\n");
	compr = sparse(mat, row, col);
	nzc = count(mat, row, col); // holds the number of non zero elements
	printf("Number of non-zero elements is %d.\n", nzc);
	free(mat); // memory for the original matrix is deallocated
	printf("\nCompressed representation in COO format:\n\n");
	displayMatrix(compr, nzc + 1, 3); // displays the compressed matrix
	trans = transposeSp(compr);
	printf("\nTranspose in COO format: \n\n");
	displayMatrix(trans, nzc + 1, 3);	// displays the transpose
	return 0;
}


int** createMatrix(int x, int y)
{
	int **p, i = 0;
    p = (int**)malloc(x * sizeof(int*));
    for(i = 0; i < x; i++)
    {
		p[i] = (int*)malloc(y * sizeof(int));          
    }    
    return p;
}

void inputMatrix(int **arr, int x, int y)
{
    int i = 0, j = 0;
    for(i = 0; i < x; i++)
    {
		for(j = 0; j < y; j++)
        {
			scanf("%d", (*(arr + i) + j));
        }
    }
}
 
void displayMatrix(int **arr, int x, int y)
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

int count(int **arr, int x, int y)
{
	int i = 0, j = 0, count = 0;
    for(i = 0; i < x; i++)
    {
		for(j = 0; j < y; j++)
        {
			if(arr[i][j] != 0)
            {
				++count;
            }
        }
    }
    return count;
}

int** sparse(int **arr, int x, int y) // creates the compressed matrix in COO format
{
	int i = 0, j = 0, k = 1, nnz = 0, **sprs;
    nnz = count(arr, x, y); // holds the number of non zero elements
    sprs = createMatrix(nnz + 1, 3); // allocates memory for the compresses matrix
    sprs[0][0] = x;
    sprs[0][1] = y;
    sprs[0][2] = nnz;
    for(i = 0; i < x; i++)
    {
		for(j = 0; j < y; j++)
        {
			if(arr[i][j] != 0)
            {
				sprs[k][0] = i;
                sprs[k][1] = j;
                sprs[k][2] = arr[i][j]; 
                ++k;                        
            }
        }
    }
    return sprs;
}           
   

int** transposeSp(int **arr) // uses the compressed matrix to create the transpose
{
    int i = 0, j = 0, row = arr[0][2] + 1, col = 3, k = 1, **trns;
	trns = createMatrix(row, col); // allocates memory for the transposed matrix
	trns[0][0] = arr[0][1];
	trns[0][1] = arr[0][0];
	trns[0][2] = arr[0][2];
	for(i = 0; i < arr[0][1]; i++) // arr[0][1] = number of columns in the original sparse matrix
    {
		for(j = 1; j < row; j++)
		{
			if(arr[j][1] == i)
			{
				trns[k][0] = i;
				trns[k][1] = arr[j][0];
				trns[k][2] = arr[j][2];
				++k;
			}
		}
	}
    return trns;
}
