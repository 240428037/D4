#define _CRT_SECURE_NO_WARNINGS 1

#pragma  once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDataType;
//���

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* pphead);//��ӡ
SListNode* BuySListNode(SListDataType x);//��̬����һ�����
SListNode* SListFind(SListNode* phead, SListDataType x);//����

void SListPushBack(SListNode** phead, SListDataType x);//β��
void SListPopBack(SListNode** pphead);//βɾ
void SListPushFront(SListNode** pphead, SListDataType x);//ͷ��
void SListPopFront(SListNode** pphead);//ͷɾ

//��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SListDataType x);
//������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);