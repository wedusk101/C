#include <stdio.h>

int main()
{
	int i = 0, j = 0, row = 0, column = 0;
	printf("Please enter the order m x n of the matrix. \n");
	scanf("%d", &row);
	scanf("%d", &column);
	int mat[row][column];
	int trans[column][row];
	printf("Please enter the elements of the matrix. \n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			scanf("%d", &mat[i][j]);
		}
		
	}
	printf("The matrix you entered is: \n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
		
	}
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			trans[i][j] = mat[j][i];
		}			
	}
	printf("The transpose of the matrix you entered is: \n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%d ", trans[i][j]);
		}
		printf("\n");
		
	}
	return 0;
}