#define _CRT_SECURE_NO_WARNINGS 1
#include "LIst.h"

//void ListInit(ListNode** pphead)
//{
//	*pphead = BuyListNode(0);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

ListNode* BuyListNode(LTDatatype x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->data = x;
	return node;
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

ListNode* ListFind(ListNode* phead, LTDatatype x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListDestroy(ListNode** pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}

void ListClear(ListNode* phead)
{
	assert(phead);
	
	ListNode* cur = phead;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = NULL;
	}
	phead->next = phead;
	phead->prev = phead;
}


void ListPushBack(ListNode* phead, LTDatatype x)
{
	//assert(phead);
	//ListNode* tail = phead->prev;
	//ListNode* newnode = BuyListNode(x);
	////phead tail newnode
	//tail->next = newnode;
	//newnode->prev = tail;

	//phead->prev = newnode;
	//newnode->next = phead;
	ListInsert(phead, x);
}


void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);//删空后再删会报错 定位到该行 就知道是删多了
	////phead tailprev tail
	//ListNode* tail = phead->prev;
	//ListNode* tailprev = tail->prev;
	////phead tailprev tail
	//tailprev->next = phead;
	//phead->prev = tailprev;
	//free(tail);
	//tail = NULL;
	ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, LTDatatype x)
{
	//assert(phead);
	//ListNode* first = phead->next;
	//ListNode* newnode = BuyListNode(x);
	////phead newnode first 
	//
	//phead->next = newnode;
	//newnode->prev = phead;

	//newnode->next = first;
	//first->prev = newnode;
	ListInsert(phead->next, x);
}
void ListPopFront(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);
	////phead first second
	//ListNode* first = phead->next;
	//ListNode* second = first->next;
	////phead first second
	//phead->next = second;
	//second->prev = phead;
	//free(first);
	ListErase(phead->next);
}


void ListInsert(ListNode* pos, LTDatatype x)
{
	assert(pos);
	//posprev pos
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	//posprev newnode  pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	//posprev pos popnext
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}