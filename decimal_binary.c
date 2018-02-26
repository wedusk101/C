/* The following code converts a positive decimal number up to 1023 to its binary equivalent form. I'm certain there are better ways to do
this than my method.First the number of digits in the binary number are counted. The most common problem for this conversion
is the truncation of the left most zeros. The order of conversion dictates the way in which the digits of the binary form are 
displayed. As such the left most zeros are lost unless care is taken to address the problem.I decided not to use arrays or bitwise
operators in this case.The reversed number checked for the number of zeros lost due to truncation.Then the 
number is multiplied by the power of ten corresponding to the number of lost zeros.Finally this number is reversed
again and displayed as the result.*/

#include <stdio.h>
#include <math.h>

int main()
{
	int input = 0, rem = 0, counter_digit = 0, msb_zero = 0, reverse = 0, counter_second = 0, result = 0, tmp = 0;
	printf("Please enter a positive integer. \n");
	scanf("%d", &input);
	while(input != 0) //Generates the binary digits in reverse order and counts the number of digits in the desired binary number.
	{
		rem = input % 2;
		input = input / 2;
		counter_digit++;	
		reverse = (reverse * 10) + rem;
	}
	tmp = reverse;
	while(reverse != 0) //Counts the digits of the reversed binary number
	{
		reverse = reverse / 10;
		counter_second++;
	}
	msb_zero = counter_digit - counter_second; // This is the number of zeros lost due to truncation of left most zeros.
	while(tmp != 0) // Reverses the previous number 
	{
		rem = tmp % 10;
		tmp = tmp / 10;
		result = (result * 10) + rem;
	}
	result = (int) result * pow(10,msb_zero); // Adds the lost zeros to obtain the result 	
	printf("The binary representation is %d.", result);
	return 0;
}