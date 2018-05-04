/*The following code implements the selection sort technique.*/
#include <stdio.h>
#include <stdlib.h>

void selSort(int* , int);

int main()
{
    int *list, size = 0, i = 0;
    printf("How many elements would you like on your list?\n");
    scanf("%d", &size);
    list = (int*)malloc(size * sizeof(int)); // dynamically allocates memory for the array
    printf("Please enter the elements.\n");
    for( i = 0; i < size; i++)
    {
		scanf("%d", list + i);
    }
    printf("The result of selection sort on your list is as follows: \n");
    selSort(list, size);
	free(list); // deallocates the memory 
    return 0;
}

void selSort(int *arr, int len) // sorts the list using the selection sort algorithm
{
	int i = 0, j = 0, k = 0, min = 0, tmp = 0;
    for( i = 0; i < len - 1; i++)
    {
		min = i;
        for(j = i + 1; j < len; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
		printf("Pass %d ---->\n\n", i + 1);
        for( k = 0; k < len; k++)
        {
			printf("%d ", arr[k]);
        }
        printf("\n\n");
    }
} // end

     
         
