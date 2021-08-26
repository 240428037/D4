
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x):
val(x),
next(nullptr)
{}
};
//解题思路
//1.迭代-三指针翻转
//while n3
//if n3
//return n1
//2.头插
//newhead
//cur
//while(cur)-next

ListNode* ReverseList(ListNode* head) {
	/*//1.迭代
	ListNode*n1=nullptr;
	ListNode*n2=head;
	ListNode*n3=head->next;
	while(n2){
	n2->next=n1;
	n1=n2;
	n2=n3;
	if(n3){
	n3=n3->next;
	}
	}
	return n1;
	*/
	//2.头插
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

int main(){
	ListNode cur = { 2, 5, 4, 3 };



}