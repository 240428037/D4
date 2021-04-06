int missingNumber(int* nums, int numsSize){
	int x = 0;
	int i = 0;
	for (i = 0; i < numsSize; i++)
	{
		x = x^nums[i];
	}
	for (i = 0; i < numsSize + 1; i++)
	{
		x = x^i;
	}
	return x;
}


int* singleNumber(int* nums, int numsSize, int* returnSize)
{
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	//找出ret的第m位为1的位
	int m = 0;
	while (m < 32)
	{
		if (ret & (1 << m))
			break;
		else
			m++;
	}
	//分离
	int x1 = 0, x2 = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] & (1 << m))
		{
			x1 ^= nums[i];
		}
		else
		{
			x2 ^= nums[i];
		}
	}
	int* retarr = (int*)malloc(sizeof(int)* 2);
	retarr[0] = x1;
	retarr[1] = x2;
	*returnSize = 2;
	return retarr;
}


int* singleNumber(int* nums, int numsSize, int* returnSize)
{
	
	// 遍历一次数组得到abXOR;
	int abXOR = 0;
	for (int i = 0; i < numsSize; i++)
	{
		abXOR = abXOR^nums[i];
	}
	// 通过移位运算获得掩码
	int mask = 1;
	for (int i = 0; i < 32; i++){
		if ((mask & abXOR) == mask)
		{
			break;
		}
		else
		{
			mask = mask << 1;
		}
	}
	// 掩码位为1则与a累计异或，否则与b累计异或
	int a = 0;
	int b = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if ((nums[i] & mask) == mask)
		{
			a = a ^ nums[i];
		}
		else
		{
			b = b ^ nums[i];
		}
	}
	int *ret = (int *)calloc(*returnSize, sizeof(int));
	ret[0] = a;
	ret[1] = b;
	*returnSize = 2;
	return ret;
}



int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int mask = 0;
	int i;
	for (i = 0; i < numsSize; i++)
	{
		mask ^= nums[i];
	}
	mask = mask & (-1 * mask);
	int m1 = 0, m2 = 0;
	for (i = 0; i < numsSize; i++)
	{
		if ((nums[i] & mask) == 0)
		{
			m1 ^= nums[i];
		}
		else
		{
			m2 ^= nums[i];
		}
	}
	int *a = (int *)malloc(2 * sizeof(int));
	a[0] = m1;
	a[1] = m2;
	*returnSize = 2;
	return a;
}


void FindNumber(int[] numbers, int len, int &A, int &B)
{
	//不足两个元素
	if (len < 2)
	{
		return;
	}
	int XorRes = 0;
	for (int i = 0; i < len; i++)
	{
		XorRes ^= numbers[i];
	}
	//此时，XorRes=A^B(A!=B),所以说，AB至少有一位异或的位为1
	int id = 0;
	//int型数据，最多有效位为31位
	for (int i = 0; i < 31; i++)
	{
		//找到那个1
		if (XorRes&(1 << i))
		{
			id = i;
			break;
		}
	}
	id = 1 << id;
	for (int i = 0; i < len; i++)
	{
		if (numbers[i] & id)
		{
			*A ^= numbers[i];
		}
		else
		{
			*B ^= numbers[i];
		}
	}
}