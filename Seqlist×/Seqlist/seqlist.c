#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

void SeqListInit(SL* ps)
{
	//一种初始化方式
	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;

	ps->a = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size;++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//void SeqListCheckCapacity(SL* ps)
//{
//	//如果满了需要增容
//	if (ps->size = ps->capacity)
//	{
//		ps->capacity *= 2;
//		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
//		if (ps->a == NULL)
//		{
//			printf("增容失败\n");
//			exit(-1);
//		}
//	}
//}

//尾插
void SeqListPushBack(struct SL* ps, SLDataType x)
{
	assert(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
////尾删
//void SeqListPopBack(struct SL* ps)
//{
//	assert(ps);
//	//ps->a[ps->size - 1] = 0;
//	ps->size--;
//}
////头插
//void SeqListPushFront(struct SL* ps, SLDataType x)
//{
//	assert(ps); 
//	int end = ps->size - 1;
//	while (end>=0)
//	{
//		ps->a[end + 1] = ps->a[end];
//		--end;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}
////头删
//void SeqListPopFront(struct SL* ps)
//{
//	assert(ps);
//	int start = 0;
//	while (start < ps->size-1)
//	{
//		ps->a[start] = ps->a[start + 1];
//		++start;
//	}
//
//}
////在pos位置插入x
//void SeqListInsert(struct SL* ps, int pos, SLDataType x)
//{}
////删除pos位置的值
//void SeqListErase(struct SL* ps, int pos)
//{}