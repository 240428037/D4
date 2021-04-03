#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//203. �Ƴ�����Ԫ��
//Ҫ��������ָ�� ��Ϊ���ֻ��һ��ָ��cur ��cur->val==val��ʱ�� û��ɾ
//prev cur
//�ʼ prev=NULL cur=head
//���� prev=���һ�� cur=NULL
//����while��ѭ������������cur
//�����ķ���ֵhistruct ListNode* ������󷵻ص�ͷ���head
//typedef struct ListNode Node

//����whileѭ���Ժ�
//if cur->val==val
//else
//else�Ļ� ���ǵ��� Ҫ����ָ��һ��������
//����prev=cur; cur=cur->next;

//if�� ������ ��Ҫɾ
//prev->next=cur->next;
//��free��cur�Ϳ���
//���Ǵ���һ������ ���head=val�أ�
//����Ҫ�ٷֳ������ж�
//if (cur==head)����if(prev==NULL)
//head=cur->head ���¶���ͷ���
//free(cur); ɾ��
//cur=head; ��head�ٸ�cur


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
				cur = prev->next;//���������һ�� 
				//������һ������val ����Ҫ�ߵ�prevָ�����һ����ʱ�������
				//���ʱ�� while��ѭ���ж��������free��һ��Ұָ��
				//����Ҫ��cur��ΪNULL ��cur=prev->next 
				//ɾ����val�� prev->nextΪNULL
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



////vs����OJ
//��ο�����VS����OJ�Ĳ�������
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



//876. ������м���
//ֻ�ܱ����������һ�� -˫ָ����
//��ʱ�临�Ӷ�
//����ָ�룡��������slow fast	
//fast������ slow��һ��
//fast���� slow��һ��
//1 2 3 4 5 ������ 
//
//1 2 3 4 5 6 ż����



//while��ѭ������������&&����||
//�������� 1 2 3 4 5
//fastΪβ��ʱ���ҵ� 
//����ż�� 1 2 3 4
//fastΪ�յ�ʱ���ҵ�
//��������û�б���֮ǰ��֪����ż
//fast&& fast->next ������&&
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



//�����е�����k�����
//����һ����������������е�����k����㡣

//�δ��� -�ڴ���� ����Խ�� ��ջ���
//k���������� ��ʱ����Ϊ��
//��kҪ���ж� ���K����������
//���ؿ�ָ��
//��һ��ѭ�� �������ж�����

//����ָ��
//fast����k��
//Ȼ��slow��fast��һ����
//��fastΪ�յ�ʱ�� slow�պ��ߵ�������k��

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




//21. �ϲ�������������
//β�� ���� ȡС�������β��
//����-ͷ��
//����ʱ������ -ѭ�������� -��ѭ����

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


	//ȡС��β��
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
//���ڱ�λ��ͷ��� ���洢��Ч���� ��������ȥβ��
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


	//ȡС��β��
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