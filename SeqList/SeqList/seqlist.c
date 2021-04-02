#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

void SeqListInit(SL* ps)
{
	assert(ps);
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
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
		if (ps->a == NULL)
		{
			printf("增容失败\n");
			exit(-1);
		}
	}
}

void SeqListDestory(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

int SeqListFind(SL* ps,SLDataType x)
{
	assert(ps);
	int i = 0; 
	for (int i = 0; i < ps->size;++i)
	{
		if (ps->a[i]==x)
		{
			return i;
		}
	}
	return -1;
}

//尾插
void SeqListPushBack(SL* ps, SLDataType x)
{
	//assert(ps);
	//SeqListCheckCapacity(ps);
	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);//接口复用
}

//尾删
void SeqListPopBack(SL* ps)
{
      //assert(ps);
      //ps->a[ps->size - 1] = 0;
      //ps->size--;
	  SeqListErase(ps,ps->size-1);//接口复用
}

//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
   //   assert(ps);
	  //SeqListCheckCapacity(ps);
   //   int end = ps->size - 1;
   //   while (end>=0)
   //   {
   //          ps->a[end + 1] = ps->a[end];
   //          --end;
   //   }
   //   ps->a[0] = x;
   //   ps->size++;
	SeqListInsert(ps,0,x);//接口复用
}

//头删
void SeqListPopFront(SL* ps)
{
	//assert(ps);
	//int start = 0;
	//while (start < ps->size - 1)
	//{
	//	ps->a[start] = ps->a[start + 1];
	//	++start;
	//}
	//ps->size--;
	SeqListErase(ps, 0);//接口复用
}


//在pos位置插入x
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos<=ps->size && pos>=0);

	SeqListCheckCapacity(ps);
	 
	int end  = ps->size - 1;
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

//删除pos位置的值
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	int start = pos;
	while (start<ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}