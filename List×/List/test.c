#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"


int main()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPrint(pList);
	return 0;
} 