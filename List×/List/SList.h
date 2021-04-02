#define _CRT_SECURE_NO_WARNINGS 1

#pragma  once
#include <stdio.h>
#include <stdlib.h>


typedef int SListDataType;

//½áµã
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;

}SLTNode;

void SListPrint(SListNode* pphead);
SListNode* BuySListNode(SListDataType x);

void SListPushBack(SListNode** phead, SListDataType x);
void SListPopBack(SListNode* phead);

void SListPushFront(SListNode* phead, SListDataType x);
void SListPopFront(SListNode* phead);



