#include <stdio.h>
int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d", a, b, c);//a=-1,b=-1,c=255
	return 0;
}


#include <stdio.h>
int main()
{
	char a = -128;
	printf("%u\n", a);//4294967168
	return 0;
}


#include <stdio.h>
int main()
{
	char a = 128;
	printf("%u\n", a);//4294967168
	return 0;
}

#include<stdio.h>
int main()
{
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);//-10
	return 0;
}

#include<stdio.h>
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);//ËÀÑ­»·
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));//255
	return 0;
}

#include <stdio.h>
unsigned char i = 0;
int main()
{
	for (i = 0; i <= 255; i++)
	{
		printf("hello world\n");//ËÀÑ­»·
	}
	return 0;
}