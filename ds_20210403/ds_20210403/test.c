#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//203. 移除链表元素
//要定义两个指针 因为如果只有一个指针cur 当cur->val==val的时候 没法删
//prev cur
//最开始 prev=NULL cur=head
//结束 prev=最后一个 cur=NULL
//所以while的循环控制条件是cur
//函数的返回值histruct ListNode* 所以最后返回的头结点head
//typedef struct ListNode Node

//进入while循环以后
//if cur->val==val
//else
//else的话 就是迭代 要两个指针一起往后走
//所以prev=cur; cur=cur->next;

//if里 如果相等 就要删
//prev->next=cur->next;
//再free掉cur就可以
//但是存在一个问题 如果head=val呢？
//所以要再分成两个判断
//if (cur==head)或者if(prev==NULL)
//head=cur->head 重新定义头结点
//free(cur); 删除
//cur=head; 把head再给cur


typedef struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val){
	Node* prev = NULL, *cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)//if(prev==NULL)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;//必须加上这一步 
				//如果最后一个数是val 程序要走到prev指向最后一个数时才算结束
				//这个时候 while的循环判断条件里的free是一个野指针
				//所以要把cur置为NULL 即cur=prev->next 
				//删除了val后 prev->next为NULL
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}



////vs调试OJ
//如何快速在VS构建OJ的测试用例
//struct ListNode {
//int val;
//struct ListNode *next;
// };
//
//
//typedef struct ListNode Node;
//struct ListNode* removeElements(struct ListNode* head, int val){
//	Node* prev = NULL, *cur = head;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			if (cur == head)//if(prev==NULL)
//			{
//				head = cur->next;
//				free(cur);
//				cur = head;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur = prev->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//
//
//int main()
//{
//	Node* n1 = (Node*)malloc(sizeof(Node));
//	n1->val = 6;
//	Node* n2 = (Node*)malloc(sizeof(Node));
//	n2->val = 6;
//	Node* n3 = (Node*)malloc(sizeof(Node));
//	n3->val=1;
//	Node* n4 = (Node*)malloc(sizeof(Node));
//	n4->val = 6;
//
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//
//	Node* head=removeElements(n1, 6);
//	return 0;
//}



//876. 链表的中间结点
//只能遍历这个链表一次 -双指针解决
//限时间复杂度
//快慢指针！！！！！slow fast	
//fast走两步 slow走一步
//fast走完 slow走一半
//1 2 3 4 5 奇数个 
//
//1 2 3 4 5 6 偶数个



//while的循环控制条件是&&还是||
//对于奇数 1 2 3 4 5
//fast为尾的时候找到 
//对于偶数 1 2 3 4
//fast为空的时候找到
//但是你在没有遍历之前不知道奇偶
//fast&& fast->next 所以是&&
typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL)
		return head;
	Node*slow = head;
	Node*fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}



//链表中倒数第k个结点
//输入一个链表，输出该链表中倒数第k个结点。

//段错误 -内存错误 数组越界 堆栈溢出
//k大于链表长度 此时链表为空
//对k要做判断 如果K大于链表长度
//返回空指针
//第一个循环 加两个判断条件

//快慢指针
//fast先走k步
//然后slow和fast再一起走
//当fast为空的时候 slow刚好走到倒数第k个

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	// write code here
	struct ListNode* slow = pListHead;
	struct ListNode* fast = pListHead;
	while (k--)
	{
		if (fast)
			fast = fast->next;
		else
			return NULL;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;

}




//21. 合并两个有序链表
//尾插 核心 取小结点下来尾插
//逆置-头插
//超出时间限制 -循环有问题 -死循环了

typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	Node* head = NULL, *tail = NULL;
	if (l1->val < l2->val)
	{
		head = tail = l1;
		l1 = l1->next;
	}

	else
	{
		head = tail = l2;
		l2 = l2->next;
	}


	//取小的尾插
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	if (l1)
		tail->next = l1;
	else
		tail->next = l2;

	return head;
}



//
//带哨兵位的头结点 不存储有效数据 方便我们去尾插
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	Node* head = NULL, *tail = NULL;
	if (l1->val < l2->val)
	{
		head = tail = l1;
		l1 = l1->next;
	}

	else
	{
		head = tail = l2;
		l2 = l2->next;
	}


	//取小的尾插
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	if (l1)
		tail->next = l1;
	else
		tail->next = l2;

	return head;
}