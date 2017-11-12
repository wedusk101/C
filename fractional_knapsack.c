#include <stdio.h>

#define SIZE 7

struct decision
{
	float benefit;
	float cost;
	float utility;
};

typedef struct decision Choice;

int main()
{
	int i = 0, j = 0, min = 0;
	Choice opt[SIZE], tmp;
	float capacity = 0.0, total = 0.0, profit = 0.0, lim = 0.0;
	printf("Please enter the max capacity.\n");
	scanf("%f", &capacity);
	printf("Please enter the cost values associated with the items.\n");
	for(i = 0; i < SIZE; i++)
		scanf("%f", &opt[i].cost);
	printf("Please enter the utility values associated with the items.\n");
	for(i = 0; i < SIZE; i++)
		scanf("%f", &opt[i].utility);
	printf("The utility-cost ratios associated with the items are as follows:\n");
	for(i = 0; i < SIZE; i++)
	{
		opt[i].benefit = opt[i].utility /(float)opt[i].cost;
		printf("%4.2f ", opt[i].benefit);
	}
	printf("\n");
	for(i = 0; i < SIZE - 1; i++) 
	{
		min = i;
		for(j = i + 1; j < SIZE; j++)
		{
			if(opt[j].benefit > opt[min].benefit)
				min = j;
		}
		tmp = opt[i];
		opt[i] = opt[min];
		opt[min] = tmp;
	}
	printf("The utility-cost ratios sorted in non-decreasing order are as follows:\n");
	for(i = 0; i < SIZE; i++)
		printf("%4.2f ", opt[i].benefit);
	printf("\n");
	i = 0;
	printf("The items in the knapsack have the following costs:\n"); 
	while(total <= capacity)
	{
		if(opt[i].cost > capacity - total)
			break;
		total = total + opt[i].cost;
		profit = profit + opt[i].utility;
		printf("%4.2f ", opt[i].cost);
		i++;
	}
	if(total < capacity)
	{
		lim = ((capacity - total)/opt[i].cost);
		printf("%4.2f ", lim);
		profit += lim * opt[i].utility;
	}
	printf("\n");
	printf("The net profit is %4.2f.\n", profit);	
	return 0;
}