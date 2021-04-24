#define _CRT_SECURE_NO_WARNINGS 1

void Swap(int*p1, int*p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//����ָ�뷨-hoare
int PartSort(int*a, int begin, int end)
{
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		while (begin < end&&a[end] >= key)
			end--;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}
void QuickSort(int*a, int begin, int end)
{
	if (begin >= end)
		return;
	int keyindex = PartSort(a, begin, end);
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
}
//�ڿӷ�-DigPitMethod
int PartSort2(int*a, int begin, int end)
{
	int key = a[end];
	while (begin < end)
	{
		//�Ҵ�
		while (begin < end&&a[begin] = < key)
			begin++;
		a[end] = a[begin];//�ҵ����ӵ��ұߵĿ���ȥ��ͬʱbegin�γ��µĿ�
		while (begin < end&&a[end] >= key)
			end--;
		a[begin] = a[end];//�ҵ�С�ӵ���ߵĿ���ȥ��ͬʱend�γ��µĿ�
	}
	a[begin] = key;
	return begin;
}


//ǰ��ָ�뷨
int PrevCurMethod(int*a, int begin, int end)
{
	int prev = begin - 1, cur = begin;
	int key = a[end];
	while (cur < end)//����key��λ�þͽ�����
	{
		if (a[cur] < key&&prev++ != cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}
	prev++;
	Swap(&a[prev], &a[end]);
	return prev;
}

//����ȡ�з�ѡkey -�������������������O(logN)
int GetMidIndesx(int*a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	//begin mid
	if (a[begin]<a[mid])
	{
		if (a[mid]<a[end])
			return mid;
		else if (a[mid]>a[end])
			return end;
		else
			return begin;
	}
	//mid begin
	else
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return end;
		else
			return mid;
	}
}


//ǰ��ָ�뷨
int PrevCurMethod(int*a, int begin, int end)
{
	int midindex = GetMidIndesx(a, begin, end);
	Swap(&a[midindex], &a[end]);

	int prev = begin - 1, cur = begin;
	int key = a[end];
	while (cur < end)//����key��λ�þͽ�����
	{
		if (a[cur] < key&&prev++ != cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}
	prev++;
	Swap(&a[prev], &a[end]);
	return prev;
}



//���ŵݹ�ת�ǵݹ� -�ݹ��������ջ�����32λ��ջ8M����2G
void QuickSortNonR(int*a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (StackEmpty!=0)
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int keyindex = PrevCurMethod(a, left, end);
		//[left,keyindex-1] keyindex [keyindex+1,right]
		if (left<keyindex-1)
		{
			StackPush(&st, left);
			StackPush(&st, right);
		}
		if (keyindex+1<right)
		{
			StackPush(&st, keyindex+1);
			StackPush(&st, left);
		}
	}
	StackDestory(&st);
}



void _MergeSort(int*a, int begin, int end, int*tmp)
{
	//��ֹ����
	if (begin>=end)
		return;
	//�Ȼ���
	int mid = (begin + end) >> 1;

	//[begin,mid],[mid+1,end]����
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	//[begin,mid],[mid+1,end]����
	//�鲢������������
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1<=end1&&begin2<=end2)
	{
		if (a[begin1]<a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}
void MergeSort(int*a, int n)
{
	int*tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}




void CountSort(int*a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n;i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* CountArr = (int*)malloc(sizeof(int)*range);
	memset(CountArr, 0, sizeof(int)*range);
	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
		CountArr[a[i] - min]++;
	//���ݴ�����������
	int j = 0;
	for (int i = 0; i < range;i++)
	{
		while (CountArr[i]--)
		{
			a[j++] = i + min;
		}
	}
}