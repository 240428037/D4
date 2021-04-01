#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

//≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s); 
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);
}

int main()
{
	TestSeqList1();
	return 0;
}