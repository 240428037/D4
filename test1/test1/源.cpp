#include<iostream>
using namespace std;
struct ListNode{
	int val;
	struct ListNode*next;
	ListNode(int x) :val(x), next(nullptr){}
};
ListNode* reverselist(ListNode*head){
	if (head == nullptr || head->next == nullptr){
		return head;
	}
	ListNode*newhead = nullptr;
	ListNode*cur = head;
	while (cur){
		ListNode*next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
void test(){
	ListNode*p1 = new ListNode(-1);
	ListNode*p2 = new ListNode(-1);
	ListNode*p3 = new ListNode(2);
	p1->next = p2;
	p2->next = p3;
	ListNode*ret = reverselist(p1);
	while (ret){
		cout << ret->val << " ";
		ret = ret->next;
	}
}
int main(){
	test();
	return 0;
}