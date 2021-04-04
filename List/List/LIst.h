#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDatatype;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDatatype data;
}ListNode;

//void ListInit(ListNode** pphead);
ListNode* ListInit();
ListNode* BuyListNode(LTDatatype x);
void ListPrint(ListNode* phead);

ListNode* ListFind(ListNode* phead,LTDatatype x);//遍历
void ListDestroy(ListNode** pphead);//销毁
void ListClear(ListNode* phead);//清理所有数据结点 保留头结点 可以继续使用


void ListPushBack(ListNode* phead, LTDatatype x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDatatype x);
void ListPopFront(ListNode* phead);
//在pos前面插入x
void ListInsert(ListNode* pos,LTDatatype x);
void ListErase(ListNode* pos);