#include<stdio.h>
int main()
{
	int n,sum=0,rem;
	printf("enter the number");
	scanf("%d",&n);
	while(n>0)
	{
		rem=n%10;
		sum=sum+rem;
		n=n/10;
	}
	printf("%d",sum);
	return 0;
}