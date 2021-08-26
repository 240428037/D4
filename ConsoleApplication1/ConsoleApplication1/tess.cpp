ListNode* reverselist(ListNode* head){
	if (head == nullptr || head->next == nullptr){
		return head;
	}
	ListNode* n1 = nullptr;
	ListNode* n2 = head;
	ListNode* n3 = head->next;
	while (n2){
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3){
			n3 = n3->next;
		}
	}
	return n1;
}
ListNode*mergelist(ListNode*l1, ListNode*l2){
	if (l1 == nullptr || l2 == nullptr){
		return l1 == nullptr ? l2 : l1;
	}
	ListNode*head = nullptr;
	ListNode*tail = nullptr;
	if (l1->val < l2->val){
		head = tail = l1;
		l1 = l1->next;
	}
	else{
		head = tail = l2;
		l2 = l2->next;
	}
	while (l1&&l2){
		if (l1->val < l2->val){
			tail->next = l1;
			l1 = l1->next;
		}
		else{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	while (l1){
		tail->next = l1;
		l1 = l1->next;
		tail = tail->next;
	}
	while (l2){
		tail->next = l2;
		l2 = l2->next;
		tail = tail->next;
	}
	return head;
}
