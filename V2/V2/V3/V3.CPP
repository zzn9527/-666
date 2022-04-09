#include<stdio.h>
#include<string.h>

int main()
{
	char a[]="2*2/4*1/1*2*3/2";

	int x=a[0]-'0';
	for(int i=1;i<strlen(a);i++)
	{
		if(a[i]=='*')
		{
			int y=a[i+1]-'0';
			x=x*y;
			i++;
		}
		else if(a[i]=='/')
		{
			int y=a[i+1]-'0';
			x=x/y;
			i++;
		}
	}
	printf("x=%d\n",x);

	return 0;
}