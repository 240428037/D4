#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"
//≤‚ ‘
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);//1 2 3 4
	SeqListPopBack(&s);
	SeqListPrint(&s);//1 2 3
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);//-1 1 2 3
	SeqListPopFront(&s);
	SeqListPrint(&s);//1 2 3
	SeqListInsert(&s, 2, 2);
	SeqListPrint(&s);//1 2 2 3
	SeqListErase(&s, 2, 2);
	SeqListPrint(&s);//1 2 3 
	int pos = SeqListFind(&s, 2);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	SeqListPrint(&s);//1 3
	//SeqListDestory(&s);

}
int main()
{
	TestSeqList1();
	return 0;
}