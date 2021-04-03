#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


void test()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);

	SListPrint(pList);

	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);

	SListPrint(pList);

	SListPopFront(&pList);

	SListPrint(pList);
	
	SListNode* ret = SListFind(pList, 2);
	if (ret)
	{
		ret->data = 10;
	}
	SListPrint(pList);
}



int main()
{
	test();
	return 0;
}