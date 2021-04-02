#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur!=NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

SListNode* BuySListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("ÉêÇë½áµãÊ§°Ü\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead==NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//ÕÒÎ²
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}