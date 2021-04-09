#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void Heapsort(int* a, int n)
{
	//½¨¶Ñ
	for (int i = (n - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, n, i);
	}
	for (int i = 0; i < n;++i)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	int a[10] = { 27, 15, 19, 34, 65, 37, 25, 49, 49, 28, 18 };
	Heapsort(a);
	return 0;
}