#include<stdio.h>
int main()
{
	int num,sum=0,i;
	printf("enter the number");
	scanf("%d",&num);
	for(i=1;i<num;i++)
	{
		if(num%i==0)
		{
			sum+=i;
		}
	}
	if(sum==num)
	{
		printf("perfect number");
	}
	else
	{
		printf("not perfect");
	}
}