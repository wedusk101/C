/*The following program implements Floyd-Warshall algorithm for generating the set of all-pairs shortest paths
for a given graph.*/
#include <stdio.h>
#include <stdlib.h>

void floyd(int**, int);
void delMat(int**, int);

int main()
{
	int size = 0, i = 0, j = 0, **mat = NULL;
	printf("How many nodes does the graph contain?\n");
	scanf("%d", &size);
	mat = (int**)malloc(size * sizeof(int*));
	for(i = 0; i < size; i++)
		mat[i] = malloc(size * sizeof(int));
	printf("Please enter the values for the distance matrix of the directed graph. Enter 999 for infinity.\n");
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++)
			scanf("%d", &mat[i][j]);
	printf("The entered matrix is : \n");
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
			printf("%d  ", mat[i][j]);
		printf("\n");
	}
	floyd(mat, size);
	printf("The resultant all-pairs shortest-paths matrix is : \n");
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
			printf("%d  ", mat[i][j]);
		printf("\n");
	}
	delMat(mat);
	return 0;		
}

void delMat(int **arr, int order)
{
	int i = 0;
	for(i = 0; i < order; i++)
		free(arr[i]);
	free(arr);
}

void floyd(int **dist, int num)
{
	int i = 0, j = 0, k = 0;
	for(k = 0; k < num; k++)
		for(i = 0; i < num; i++)
			for(j = 0; j < num; j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
}