#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//27.�Ƴ�Ԫ��
//˫ָ��
//���¸�һ��
//��������ָ��src dest src���� dest����
//���srcָ�����==val src++ dest����
//���srcָ�����!=val ��ʱ��������Ž�dest Ȼ��src++ dest++
//����µ�������±����dest
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



//26. ɾ�����������е��ظ���
//˫ָ��
//��ͬһ��
//��Ϊ���������� ��������Ԫ���Ǵ�С�������е� ���������һ���������Ͳ����ٳ���
//prev=0 cur=1 dst=0
//���prev curָ���Ԫ�ز�ͬ
//�Ͱ�prevָ���Ԫ�طŵ�dst�� Ȼ��prev++ cur++ dst++
//���prev curָ��Ԫ����ͬ
//��prev++ cur++
//ע��while��ѭ������������cur<numsSize 
//����whileѭ���Ժ� ��ʱcur�Ѿ�Խ��
//prevָ������ֵ��û�з���dst��
//Ҫnums[dst]=nums[prev]
//��Ϊ���Ҫ����������ĸ��� ���Ի�Ҫdst++
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



//88. �ϲ�������������
//˫ָ��
//����һ���µ�����tmp ʹ������free
//tmp nums1 nums2��Ӧ�±�ֱ�Ϊi i1 i2
//��while����ѭ�� ֻҪ����������һ���ߵ�ͷ ���˳�ѭ��
//whileѭ����
//���nums1[i1]<nums2[i2]
//�Ͱ�С���Ǹ����ŵ���ʱ����tmp��
//Ȼ��i1++ i++
//�˳�whileѭ���Ժ� ��Ȼ��һ������������ ������һ�����黹û������
//��ȥ���Ǹ��������� д����if�жϾͺ�
//�����������е����ݶ��ŵ�tmp�Ժ�
//��memcpy��tmp�е����ݷŵ�nums1�� Ȼ��free��tmp

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


//189. ��ת����
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
	//k�п��ܴ�������Ĵ�С
	k %= numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);
}



//989. ������ʽ�������ӷ�
//

