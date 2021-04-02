#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��̬˳�����ƣ��̶���С������ʵ�֣�
//#define N 10

//��̬˳�����ƣ���С�ɱ䣩
typedef int SLDataType;

//STL:˳���-vector
typedef struct SeqList
{
	SLDataType* a;//ָ��̬���ٵ�����
	int size;//��Ч���ݸ���
	int capacity;//����
}SL,SeqList;

void SeqListInit(SL* ps);//��ʼ��
void SeqListPrint(SL* ps);//��ӡ
void SeqListCheckCapacity(SL* ps);//����
void SeqListDestory(SL* ps);//����
int SeqListFind(SL* ps, SLDataType x);//����

//β��βɾ ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDataType x);//β��
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ


//����λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);//��posλ�ò���x
void SeqListErase(SL* ps, int pos);//ɾ��posλ�õ�ֵ


