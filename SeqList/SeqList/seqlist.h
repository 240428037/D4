#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//静态顺序表设计（固定大小）（不实现）
//#define N 10

//动态顺序表设计（大小可变）
typedef int SLDataType;

//STL:顺序表-vector
typedef struct SeqList
{
	SLDataType* a;//指向动态开辟的数组
	int size;//有效数据个数
	int capacity;//容量
}SL,SeqList;

void SeqListInit(SL* ps);//初始化
void SeqListPrint(SL* ps);//打印
void SeqListCheckCapacity(SL* ps);//增容
void SeqListDestory(SL* ps);//销毁
int SeqListFind(SL* ps, SLDataType x);//查找

//尾插尾删 头插头删
void SeqListPushBack(SL* ps, SLDataType x);//尾插
void SeqListPopBack(SL* ps);//尾删
void SeqListPushFront(SL* ps, SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删


//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);//在pos位置插入x
void SeqListErase(SL* ps, int pos);//删除pos位置的值


