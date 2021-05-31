class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr){
			return l2;
		}
		if (l2 == nullptr){
			return l1;
		}
		ListNode*head, *tail;
		head = tail = new ListNode;
		while (l1 != nullptr&&l2 != nullptr){
			if (l1->val < l2->val){
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}
			else{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		}
		while (l1 != nullptr){
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
		}
		while (l2 != nullptr){
			tail->next = l2;
			l2 = l2->next;
			tail = tail->next;
		}
		ListNode*ret = head->next;
		delete head;
		return ret;
	}
};



class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr){
			return l2;
		}
		if (l2 == nullptr){
			return l1;
		}
		ListNode*head, *tail;
		head = tail = new ListNode;
		while (l1 != nullptr&&l2 != nullptr){
			if (l1->val < l2->val){
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}
			else{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		}
		while (l1 != nullptr){
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
		}
		while (l2 != nullptr){
			tail->next = l2;
			l2 = l2->next;
			tail = tail->next;
		}
		ListNode*ret = head->next;
		delete head;
		return ret;
	}
};




class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr){
			return l2;
		}
		if (l2 == nullptr){
			return l1;
		}
		ListNode*head = nullptr, *tail = nullptr;
		if (l1->val < l2->val){
			head = tail = l1;
			l1 = l1->next;
		}
		else{
			head = tail = l2;
			l2 = l2->next;
		}
		while (l1 != nullptr&&l2 != nullptr){
			if (l1->val < l2->val){
				tail->next = l1;
				l1 = l1->next;
				tail = tail->next;
			}
			else{
				tail->next = l2;
				l2 = l2->next;
				tail = tail->next;
			}
		}
		while (l1 != nullptr){
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
		}
		while (l2 != nullptr){
			tail->next = l2;
			l2 = l2->next;
			tail = tail->next;
		}
		return head;
	}
};