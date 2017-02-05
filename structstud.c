#include <stdio.h>
#include <string.h>

struct student
{
	int roll, phys_marks, math_marks, chem_marks, total;
	char name[30];
};

int main()
{
	int i = 0, j = 0;
	struct student stu[30], tmp;
	for(i = 0; i < 3; i++)
	{
		printf("STUDENT %d ----->\n", (i+1));
		printf("Please enter the roll number of the student.\n");
		scanf("%d", &stu[i].roll);
		setbuf(stdin, NULL); // removes pending newline from the buffer
		printf("Please enter the name of the student.\n");
		fgets(stu[i].name, 30, stdin);
		strtok(stu[i].name, "\n"); // removes pending newline from the buffer
		printf("Please enter the marks in Physics.\n");
		scanf("%d", &stu[i].phys_marks);
		printf("Please enter the marks in Chemistry.\n");
		scanf("%d", &stu[i].chem_marks);
		printf("Please enter the marks in Mathematics.\n");
		scanf("%d", &stu[i].math_marks);
		stu[i].total = stu[i].phys_marks + stu[i].chem_marks + stu[i].math_marks;		
	}
	printf("\n");
	for(i = 0; i < 3; i++) // sorts the structures in descending order according to the total marks
	{
		for( j = i + 1; j < 3; j++)
		{
			if(stu[i].total < stu[j].total)
			{
				tmp = stu[i];
				stu[i] = stu[j];
				stu[j] = tmp;
			}
			else
				continue;
		}
	}
	printf("The list of the students is as follows:\n");
	printf("\n");
	for(i = 0; i < 3; i++) // displays the result
	{
		printf("Roll Number      : %d\n", stu[i].roll);
		printf("Name             : %s\n", stu[i].name);
		printf("Physics Marks    : %d\n", stu[i].phys_marks);
		printf("Chemistry Marks  : %d\n", stu[i].chem_marks);
		printf("Mathematics Marks: %d\n", stu[i].math_marks);
		printf("Aggregate Marks  : %d\n", stu[i].total);
		printf("\n");
	}
	printf("Thank you.\n");
	return 0;
}
