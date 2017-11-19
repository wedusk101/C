#include <stdio.h>
#include <stdlib.h>

void primMST(int**, int*, int, int*);

int main()
{
	int size = 0, i = 0, j = 0, **mat = NULL, root = 0, minCost = 0, *mst = NULL;
	printf("How many nodes does the graph contain?\n");
	scanf("%d", &size);
	mat = (int**)malloc(size * sizeof(int*));
	mst = malloc(size * sizeof(int));
	for(i = 0; i < size; i++)
	{
		mat[i] = malloc(size * sizeof(int));
		mst[i] = 0; // initialize the minimum spanning tree set
	}
	printf("Please enter the values for the distance matrix of the graph. Enter 999 for infinity.\n");
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
	printf("\n\n");
	primMST(mat, mst, size, &minCost);
	printf("The total weight of the resultant MST is %d.\n", minCost);
	free(mat);
	free(mst);
	return 0;
}

void primMST(int **arr, int *visited, int num, int *weight)
{
	int min = 999, i = 0, j = 0, minVertex = 0;
	for(i = 0; i < num; i++)
	{
		min = 999; // resets the variable for the minimum weight edge
		visited[i] = 1; // adds the vertex to the MST
		for(j = 0; j < num; j++)
		{
			if(arr[i][j] != 0 && arr[i][j] != 999 && visited[j] != 1 && arr[i][j] < min)
			{
				min = arr[i][j];
				minVertex = j;
			}
		}
		if(min != 999) // work around for the last iteration bug
		{
			printf("%d - %d ---> %d\n", i, minVertex, min);
			*weight += min; // updates total minimum weight of the tree
		}
	}	
}	