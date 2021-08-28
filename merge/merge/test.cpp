#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr)
	{}
};

ListNode* mergelist(ListNode* head1, ListNode* head2) {
	if (head1 == nullptr || head2 == nullptr){
		return head1 == nullptr ? head2 : head1;
	}
	//定义头尾节点
	ListNode*head = nullptr;
	ListNode*tail = nullptr;
	//初始化
	if (head1->val<head2->val){
		head = tail = head1;
		head1 = head1->next;
	}
	else{
		head = tail = head2;
		head2 = head2->next;
	}
	//开始合并
	while (head1&&head2){
		if (head1->val<head2->val){
			tail->next = head1;
			head1 = head1->next;
		}
		else{
			tail->next = head2;
			head2 = head2->next;
		}
		tail = tail->next;
	}
	//处理另外一个没有完成合并的链表
	while (head1){
		tail->next = head1;
		head1 = head1->next;
		tail = tail->next;
	}
	while (head2){
		tail->next = head2;
		head2 = head2->next;
		tail = tail->next;
	}
	return head;
}

ListNode* sortlist(ListNode*head){
	vector<int>v;
	ListNode*cur = head;
	while (cur){
		v.push_back(cur->val);
		cur = cur->next;
	}
	cur = head;
	sort(v.begin(), v.end());
	for (int i = 0; i<v.size(); i++){
		cur->val = v[i];
		cur = cur->next;
	}
	return head;
}

void test(){
	ListNode*p1 = new ListNode(3);
	ListNode*p2 = new ListNode(1);
	ListNode*p3 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	ListNode*x1 = new ListNode(2);
	ListNode*x2 = new ListNode(4);
	ListNode*x3 = new ListNode(6);
	x1->next = x2;
	x2->next = x3;
	ListNode*head = mergelist(p1, x1);
	ListNode*newhead = sortlist(head);
	ListNode*cur = newhead;
	while (cur){
		cout << cur->val << " ";
		cur = cur->next;
	}
}

int main(){
	test();
	return 0;
}