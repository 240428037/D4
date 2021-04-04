#define _CRT_SECURE_NO_WARNINGS 1
#include "LIst.h"


void TestList1()
{
	//ListNode* phead = NULL;
	//ListInit(&phead);

	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);//1 2 3 4
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);//1 2
	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint(phead);//4 3 2 1 1 2
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);//2 1 1 2
	ListDestroy(&phead);
}

void TestList2()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);//1 2 3 4
	ListNode* pos = ListFind(phead, 3);
	pos->data = 300;
	ListInsert(pos, 30);
	ListPrint(phead);//1 2 30 300 4
	ListErase(pos);
	ListPrint(phead);//1 2 30 4
	ListDestroy(&phead);
}
int main()
{
	TestList1();
	//TestList2();
	return 0;
}