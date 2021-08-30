// class Solution {
// public:
//     ListNode* ReverseList(ListNode* head) {
//         ListNode*cur=head;
//         ListNode*newhead=nullptr;
//         while(cur){
//             ListNode*next=cur->next;
//             cur->next=newhead;
//             newhead=cur;
//             cur=next;
//         }
//         return newhead;
//     }
// };

// class Solution {
// public:
//     ListNode* ReverseList(ListNode* head) {
//         ListNode*prev=nullptr;
//         ListNode*cur=head;
//         ListNode*next=head->next;
//         while(cur){
//             cur->next=prev;
//             prev=cur;
//             cur=next;
//             if(next){
//                 next=next->next;
//             }
//         }
//         return prev;
//     }
// };


#include<iostream>
using namespace std;
struct ListNode{
	int val;
	struct ListNode*next;
	ListNode(int x) :val(x), next(nullptr){}
};
ListNode*reverselist(ListNode*head){
	ListNode*cur = head;
	ListNode*newhead = nullptr;
	while (cur){
		ListNode*next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
void test(){
	ListNode*p1 = new ListNode(1);
	ListNode*p2 = new ListNode(2);
	ListNode*p3 = new ListNode(3);
	p1->next = p2;
	p2->next = p3;
	ListNode*newhead = reverselist(p1);
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