#include <stdio.h>

struct time 
{
	int hrs, mins, sec;	
};

int main()
{
	int sum_hrs = 0, sum_mins = 0, sum_sec = 0, sec_carry = 0, min_carry = 0;
	struct time t1, t2;
	printf("Please enter the time in Hours, Minutes, Seconds.\n");
	printf("Hours:\n");
	scanf("%d", &t1.hrs);
	printf("Minutes:\n");
	scanf("%d", &t1.mins);
	printf("Seconds:\n");
	scanf("%d", &t1.sec);
	printf("Please enter the time interval you want to add.\n");
	printf("Hours:\n");
	scanf("%d", &t2.hrs);
	printf("Minutes:\n");
	scanf("%d", &t2.mins);
	printf("Seconds:\n");
	scanf("%d", &t2.sec);
	sum_sec = (t1.sec + t2.sec) % 60; // Calculates total seconds
	sec_carry = (t1.sec + t2.sec) / 60; // Calculates seconds that are carried to minutes
	sum_mins = ((t1.mins + t2.mins) + sec_carry) % 60; // Calculates total minutes
	min_carry = ((t1.mins + t2.mins) + sec_carry) / 60; // Calculates minutes that are carried to hours
	sum_hrs = (t1.hrs + t2.hrs) + min_carry; // Calculates total hours
	printf("The time is %d Hours:%d Minutes:%d Seconds\n", sum_hrs, sum_mins, sum_sec);
	return 0;
}
