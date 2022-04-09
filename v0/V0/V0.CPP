#include<stdio.h>

int main()
{
	char a[]="3+4";

	int x=a[0]-'0';
	int y=a[2]-'0';
	int z=x+y;
	printf("z=%d\n",z);

	return 0;
}