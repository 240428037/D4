#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//27.移除元素
//双指针
//上下各一个
//定义两个指针src dest src先走 dest再走
//如果src指向的数==val src++ dest不动
//如果src指向的数!=val 此时把这个数放进dest 然后src++ dest++
//最后新的数组的下标就是dest
int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dest = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dest] = nums[src];
			src++;
			dest++;
		}
		else
		{
			src++;
		}
	}
	return dest;
}



//26. 删除有序数组中的重复项
//双指针
//在同一行
//因为是有序数组 所以数组元素是从小到大排列的 所以这个数一旦被跳过就不会再出现
//prev=0 cur=1 dst=0
//如果prev cur指向的元素不同
//就把prev指向的元素放到dst中 然后prev++ cur++ dst++
//如果prev cur指向元素相同
//就prev++ cur++
//注意while的循环控制条件是cur<numsSize 
//出了while循环以后 此时cur已经越界
//prev指向的这个值还没有放入dst中
//要nums[dst]=nums[prev]
//因为最后要返回新数组的个数 所以还要dst++
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int prev = 0;
	int cur = 1;
	int dst = 0;
	while (cur < numsSize)
	{
		if (nums[prev] != nums[cur])
		{
			nums[dst] = nums[prev];
			prev++;
			cur++;
			dst++;
		}
		else
		{
			prev++;
			cur++;
		}
	}
	nums[dst] = nums[prev];
	prev++;
	dst++;
	return dst;
}



//88. 合并两个有序数组
//双指针
//开辟一个新的数组tmp 使用完再free
//tmp nums1 nums2对应下标分别为i i1 i2
//用while控制循环 只要两个数组有一个走到头 就退出循环
//while循环内
//如果nums1[i1]<nums2[i2]
//就把小的那个数放到临时数组tmp中
//然后i1++ i++
//退出while循环以后 必然有一个数组走完了 而另外一个数组还没有走完
//不去管那个数组走完 写两个if判断就好
//当两个数组中的数据都放到tmp以后
//用memcpy把tmp中的数据放到nums1中 然后free掉tmp

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int*tmp = (int*)malloc(sizeof(int)*(m + n));
	int i = 0;
	int i1 = 0;
	int i2 = 0;
	while (i1 < m && i2 < n)
	{
		if (nums1[i1] < nums2[i2])
		{
			tmp[i] = nums1[i1];
			i++;
			i1++;
		}
		else
		{
			tmp[i] = nums2[i2];
			i++;
			i2++;
		}
	}
	while (i1 < m)
	{
		tmp[i] = nums1[i1];
		i++;
		i1++;
	}
	while (i2 < n)
	{
		tmp[i] = nums2[i2];
		i++;
		i2++;
	}
	memcpy(nums1, tmp, sizeof(int)*(m + n));
	free(tmp);
}


//189. 旋转数组
//[1234567] k=3
//[1234] [567]
//[4321] [765]
//[4321765]
//[5671234]

void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	//k有可能大于数组的大小
	k %= numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}



//989. 数组形式的整数加法
//

