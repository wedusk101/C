#include <stdio.h>
#include <stdlib.h>

void primMST(int**, int*, int, int*);

int main()
{
	int size = 0, i = 0, j = 0, **mat = NULL, edgeCount = 0, minCost = 0, *mst = NULL;
	printf("How many nodes does the graph contain?\n");
	scanf("%d", &size);
	//printf("How many edges does the graph contain?\n");
	//scanf("%d", &edgeCount);
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
	int min = 999, i = 0, j = 0, minVertex = 0, k = 0, bak = 0, degree = 0;
	for(i = 0; i < num; i++)
	{
		degree = 0;
		min = 999; // resets the variable for the minimum weight edge
		for(j = 0; j < num; j++) // counts the degree of each vertex
		{
			if(arr[i][j] != 0 && arr[i][j] != 999)
			{
				bak = j;
				degree++;
			}
		}
		if(degree == 1) // handles pendant vertices
		{
			visited[i] = visited[bak] = 1; // adds the vertex to the MST
			printf("%d - %d ---> %d\n", i, bak, arr[i][bak]);
			*weight += arr[i][bak];
			continue;
		}
		if(visited[i] == 1)
		{
			for(j = 0; j < num; j++)
			{
				if(arr[i][j] != 0 && arr[i][j] != 999 && arr[i][j] < min && visited[j] != 1)
				{
					min = arr[i][j];
					minVertex = j;
				}
			}
			bak = min;
			min = 999;
			for(j = 0; j < num; j++)
			{
				if(arr[i][j] != 0 && arr[i][j] != 999 && arr[i][j] < min)
				{
					min = arr[i][j];
					minVertex = j;
				}
			}
			if(bak < min)
			{
				visited[minVertex] = 1;
				printf("%d - %d ---> %d\n", i, minVertex, bak);
				*weight += min; // updates total minimum weight of the tree
				continue;
			}
			else
				continue;
		}
		for(j = 0; j < num; j++)
		{			
			if(arr[i][j] != 0 && arr[i][j] != 999 && arr[i][j] < min && !(visited[i] == 1 && visited[j] == 1))
			{
				min = arr[i][j];
				minVertex = j;
			}
		}
		/*bak = min;
		for(k = 0; k < num; k++)
		{
			if(arr[minVertex][k] != 0 && arr[minVertex][k] != 999 && visited[k] != 1 && arr[minVertex][k] < bak)
			{
				min = arr[minVertex][k];
				minVertex = k;
			}
		}*/
		if(min != 999) // work around for the last iteration bug
		{
			visited[i] = visited[minVertex] = 1;
			printf("%d - %d ---> %d\n", i, minVertex, min);
			*weight += min; // updates total minimum weight of the tree
		}
	}	
}	