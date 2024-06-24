#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("enter the string:");
    scanf("%s",str);
    printf("%s",strrev(str));
    return 0;
}