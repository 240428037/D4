#define _CRT_SECURE_NO_WARNINGS 1

#pragma  once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;
//结点

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pphead);//打印
SListNode* BuySListNode(SListDataType x);//动态申请一个结点
SListNode* SListFind(SListNode* phead, SListDataType x);//查找

void SListPushBack(SListNode** phead, SListDataType x);//尾插
void SListPopBack(SListNode** pphead);//尾删
void SListPushFront(SListNode** pphead, SListDataType x);//头插
void SListPopFront(SListNode** pphead);//头删

//单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SListDataType x);
//单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos);