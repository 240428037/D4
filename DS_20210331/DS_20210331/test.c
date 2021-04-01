#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}



//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}


//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1)*N;
//}



//long long Fibonacci_1(size_t N)
//{
//	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//}
//
////求出整个斐波那契数列
//long long	Fibonacci(size_t N)
//{
//	long long* fibarray = malloc(sizeof(long long)*(N+1));
//	fibarray[0] = 0;
//	if (N==0)
//	{
//		return fibarray;
//	}
//	fibarray[1] = 1;
//	//以空间换时间
//	int i = 0;
//	for (int i = 2; i <= N;++i)
//	{
//		fibarray[i] = fibarray[i - 1] + fibarray[i - 2];
//	}
//	return fibarray;
//}
//
//int main()
//{
//	printf("%d\n", Fibonacci(50));
//	return 0;
//}

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	int ret = 0;
	for (int i = 0; i < numsSize;++i)
	{
		ret = ret^nums[i];
	}
	//找出ret的第m位为1的位
	int m = 0;
	while (m<32)
	{
		if (ret ^ (1 << m))
			break;
		else
			++m;
	}
	//分离
	int x1 = 0;
	int x2 = 0;
	for (int i = 0; i < numsSize;++i)
	{
		if (nums[i] & (i << m))
		{
			x1 = x1^nums[i];
		}
		else
		{
			x2 = x2^nums[i];
		}
	}
	int* retarr = (int*)malloc(sizeof(int)* 2);
	retarr[0] = x1;
	retarr[1] = x2;
	*returnSize = 2;
	return retarr;
}