#define _CRT_SECURE_NO_WARNINGS 1


//��������ʵ��ջ
typedef int QDataType;

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

void QueueInit(Queue* q);// ��ʼ������
void QueuePush(Queue* q, QDataType data);// ��β�����
void QueuePop(Queue* q);// ��ͷ������
QDataType QueueFront(Queue* q);// ��ȡ����ͷ��Ԫ��
QDataType QueueBack(Queue* q);// ��ȡ���ж�βԪ��
int QueueSize(Queue* q);// ��ȡ��������ЧԪ�ظ���
int QueueEmpty(Queue* q);// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
void QueueDestroy(Queue* q);// ���ٶ���

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
	if (q->_back == NULL)
	{
		q->_back = q->_front = newnode;
	}
	else
	{
		q->_back->_next = newnode;
		//1 2    3
		q->_back = newnode;
	}
}

// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
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
















typedef struct {
	Queue _q1;
	Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_q1);
	QueueInit(&st->_q2);

	return st;

}


/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->_q1))
	{
		QueuePush(&obj->_q1, x);
	}
	else
	{
		QueuePush(&obj->_q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* pemptyQ = &obj->_q1;
	Queue* pnoemptyQ = &obj->_q2;
	if (!QueueEmpty(&obj->_q1))
	{
		pemptyQ = &obj->_q2;
		pnoemptyQ = &obj->_q1;

	}
	while (QueueSize(pnoemptyQ)>1)
	{
		QueuePush(pemptyQ, QueueFront(pnoemptyQ));
		QueuePop(pnoemptyQ);
	}
	int top = QueueBack(pnoemptyQ);
	QueuePop(pnoemptyQ);
	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->_q1))
	{
		return QueueBack(&obj->_q1);
	}
	else
	{
		return QueueBack(&obj->_q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->_q1) && QueueEmpty(&obj->_q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->_q1);
	QueueDestroy(&obj->_q2);
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/



//����ջʵ�ֶ���
typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;//ջ��
	int _capacity;//����
}Stack;

void StackInit(Stack* ps);// ��ʼ��ջ
void StackPush(Stack* ps, STDataType data);// ��ջ
void StackPop(Stack* ps);// ��ջ
STDataType StackTop(Stack* ps);// ��ȡջ��Ԫ��
int StackSize(Stack* ps);// ��ȡջ����ЧԪ�ظ���
int StackEmpty(Stack* ps);// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
void StackDestroy(Stack* ps);// ����ջ

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

// ��ջ
void StackPop(Stack* ps)
{
	// assert(ps&&ps->_top > 0);
	//      if (ps->size == 0)
	//      {
	//          return;
	//      }
	if (ps->_top == 0)
		return;

	ps->_top--;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	//     if (ps->size == 0)
	//     {
	//          return (STDataType)0;
	//     }
	//     return ps->array[ps->size - 1];

	assert(ps);
	// if(ps->_top==0)
	// {
	//     return (STDataType)0;
	// }
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط�����(1)�������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}



















typedef struct {
	Stack _pushst;
	Stack _popst;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->_pushst);
	StackInit(&q->_popst);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->_pushst, x);

}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->_popst))
	{
		while (StackEmpty(&obj->_pushst))
		{
			StackPush(&obj->_popst, StackTop(&obj->_pushst));
			StackPop(&obj->_pushst);
		}
	}
	int front = StackTop(&obj->_popst);
	StackPop(&obj->_popst);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->_popst))
	{
		while (StackEmpty(&obj->_pushst))
		{
			StackPush(&obj->_popst, StackTop(&obj->_pushst));
			StackPop(&obj->_pushst);
		}
	}
	return StackTop(&obj->_popst);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->_pushst) && StackEmpty(&obj->_popst);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->_pushst);
	StackDestroy(&obj->_popst);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/
