#include<stdio.h>
#include<string.h>

int main()
{
	char a[]="2+2*3+2/2-1";
	char b[100];

	int c=-1;
	for(int i=0;i<100;i++)
	{
		if(a[i]=='*')
		{
			int x=b[c]-'0';
			int y=a[i+1]-'0';
			b[c]=x*y+'0';
			i++;
		}
		else if(a[i]=='/')
		{
			int x=b[c]-'0';
			int y=a[i+1]-'0';
			b[c]=x/y+'0';
			i++;
		}
		else b[++c]=a[i];
	}

	int z=b[0]-'0';
	for(i=1;i<100;i++)
	{
		if(b[i]=='+')
			z+=b[++i]-'0';
		else if(b[i]=='-')
			z-=b[++i]-'0';
	}

	printf("%d\n",z);

	return 0;
}