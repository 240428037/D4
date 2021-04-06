#define _CRT_SECURE_NO_WARNINGS 1

#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

typedef int	QDataType;

typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	struct QueueNode* _front;
	struct QueueNode* _back;
}Queue;


// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}
// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_back==NULL)
	{
		q->_back = q->_front = newnode;
	}
	else
	{
		q->_back->_next = newnode;
		//1 2
		//3
		q->_back=newnode;
	}

}
// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next==NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;

	}
	else
	{
		QueueNode* tmp = q->_front->_next;
		free(q->_front);
		q->_front = tmp;
	}
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);

	return q->_back->_data;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
	return n;


}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = NULL;
	}
}


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	//printf("%d ", QueueFront(&q));
	//QueuePop(&q);
	//printf("%d ", QueueFront(&q));
	//QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}