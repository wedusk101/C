#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	FILE *fp;
	int arr[20], i = 0;
	srand(time(NULL));
	fp = fopen("Data.txt", "w");
	if(fp == NULL)
	{
		perror("Error opening file.\n");
		exit(EXIT_FAILURE); 
	}
	for(i = 0; i < 20; i++)
	{
		arr[i] = rand() % 1000;
	}
	for(i = 0; i < 20; i++)
		fprintf(fp, "%d ", arr[i]);
	rewind(fp);
	while(fgetc(fp) != EOF)
		fscanf(fp, "%d", &arr[i]);
	printf("The numbers in the array are ");
	for(i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf(".\n");		
	fclose(fp);
	return 0;
}