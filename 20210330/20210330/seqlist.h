#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"

#define ElemType int

#define SEQLIST_DEFAULT_SIZE 8


//����˳���Ľṹ
typedef struct Seqlist
{
	ElemType* base;
	size_t capacity;
	size_t size;
}Seqlist;

//��������
void SeqlistInit(Seqlist *plist);
void SeqlistPushBack(Seqlist *plist, ElemType x);
void SeqlistShow(Seqlist *plist);
void SeqlistPushFront(Seqlist *plist, ElemType x);

//////////////////////////////////
//����ʵ��
bool IsFull(Seqlist *plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}
bool IsEmpty(Seqlist *plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}

void SeqlistInit(Seqlist *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType)*plist->capacity);
	plist->size = 0;
}
void SeqlistPushBack(Seqlist *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳���������%d����β������\n", x);
		return;
	}
	//plist->base[plist->size] = x;
	//plist->size++;
	plist->base[plist->size++] = x;
}

void SeqlistPushFront(Seqlist *plist, ElemType x)
{
	assert(plist != NULL);
	//����
	if (IsEmpty(plist))
	{
		printf("˳���������%d����ͷ������\n", x);
		return;
	}
	//ͷ��
	for (size_t i = plist->size; i > 0; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[0] = x;
	plist->size++;

	
}


void SeqlistShow(Seqlist *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; ++i)
		printf("%d ", plist->base[i]);
	//printf("\n");
}






#endif