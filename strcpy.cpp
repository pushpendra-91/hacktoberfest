#include<stdio.h>
int main()
{
	char a[10],b[10];
	printf("enter two string of same length");
	scanf("%s",a);
	int i=0;
	while(a[i]!=0)
	{
		b[i]=a[i];
		i++;
}
	printf("%s",b);
	
}
