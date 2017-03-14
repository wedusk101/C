/*The following code implements the Towers of Hanoi using recursion.*/
#include <stdio.h>

void moveTower(int, char, char, char);

int main()
{
	int num = 0;
	char source = 'A', dest = 'B', temp = 'T';
	printf("This program generates the moves required for solving the Towers of Hanoi.\n");
	printf("Tower A is the source tower, B is the destination tower and T is the spare tower.\n");
	printf("How many disks would you like in your simulation?\n");
	scanf("%d", &num);
	printf("Commencing moves...\n");
	moveTower(num, source, dest, temp);
	printf("Moves completed.\n");
	return 0;
} // end

void moveTower(int height, char from, char to, char spare) // recursively calculates the required moves
{
	if(height == 1)
		printf("Moving disk %d from tower %c to tower %c.\n", height, from, to); // base case moves the disk from the source tower to the destination tower directly
	else
	{
		moveTower(height - 1, from, spare, to);
		printf("Moving disk %d from tower %c to tower %c.\n", height, from, to);// height contains the disk to be moved
		moveTower(height - 1, spare, to, from);
	}
}
