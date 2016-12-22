#include<stdio.h>
#include<math.h>

int main()
{
	  
	int m, t=0, p=1, flag=0;
    	printf("Enter a prime number. \n");
	scanf("%d",&m);
    	while(p <= m)
    	{
        	t=(int)pow(2,p);
        	if(t==(m+1))
        	{
            	printf("Number is a Mersenne Prime. \n");
            	flag=1;
            	break;
        	}
        p++;
    	}
    	if(flag!=1)
    	{
        	printf("Number is not a Mersenne Prime. \n");
    	}
	return 0;
}
