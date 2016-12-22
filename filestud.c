/*
This program takes as input details like marks, name and roll number for several students
and writes them to a text file "Info.txt". The details are taken as data members to a structure
which is then copied to the file.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int roll, phys_marks, math_marks, chem_marks; // Structure for student info
	char name[30];
};

int main()
{
	FILE *fp;
	char ch;
	int i = 0, j = 0, total[30];
	struct student stu[30];
	fp = fopen("Info.txt", "w"); // Creates file and sets file pointer to write mode
	if(fp == NULL)
	{
		perror("Error opening file.\n");
		exit(EXIT_FAILURE); // Displays error in case the program fails to open the file
	}
	for(i = 0; i < 3; i++)
	{
		printf("STUDENT %d ----->\n", (i+1));
		fprintf(fp, "STUDENT %d ----->", (i+1));
		fprintf(fp, "\n\n");
		printf("Please enter the roll number of the student.\n");
		fscanf(stdin, "%d", &stu[i].roll);
		setbuf(stdin, NULL); // removes pending newline from the buffer
		fprintf(fp, "Roll Number        : %d", stu[i].roll);
		fprintf(fp, "\n");
		printf("Please enter the name of the student.\n");
		fgets(stu[i].name, 30, stdin);
		strtok(stu[i].name, "\n"); // removes pending newline from the buffer
		fprintf(fp, "Name               : %s", stu[i].name);
		printf("Please enter the marks in Physics.\n");
		fprintf(fp, "\n");
		fscanf(stdin, "%d", &stu[i].phys_marks);
		fprintf(fp, "Physics Marks      : %d", stu[i].phys_marks);
		fprintf(fp, "\n");
		printf("Please enter the marks in Chemistry.\n");
		fscanf(stdin, "%d", &stu[i].chem_marks);
		fprintf(fp, "Chemistry Marks    : %d", stu[i].chem_marks);
		fprintf(fp, "\n"); // Prints newline into the file
		printf("Please enter the marks in Mathematics.\n");
		fscanf(stdin, "%d", &stu[i].math_marks);
		fprintf(fp, "Mathematics Marks  : %d", stu[i].math_marks);
		fprintf(fp, "\n");
		total[i] = stu[i].phys_marks + stu[i].chem_marks + stu[i].math_marks;
		fprintf(fp, "Aggregate Marks    : %d\n", total[i]);
		fprintf(fp, "\n\n");
	}
	fclose(fp); // Closes the file pointer
	return 0;
}