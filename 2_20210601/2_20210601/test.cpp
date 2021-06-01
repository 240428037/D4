struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode*sorthead = head, *cur = head->next;
	sorthead->next = NULL;
	while (cur)
	{
		struct ListNode*next = cur->next;
		//头插
		if (cur->val <= sorthead->val)
		{
			cur->next = sorthead;
			sorthead = cur;
		}
		else
		{
			struct ListNode*sortprev = sorthead, *sortcur = sorthead->next;
			//中间插
			while (sortcur)
			{
				if (cur->val <= sortcur->val)
				{
					sortprev->next = cur;
					cur->next = sortcur;
					break;
				}
				else
				{
					sortprev = sortcur;
					sortcur = sortcur->next;
				}
			}
			//尾插
			if (sortcur == NULL)
			{
				sortprev->next = cur;
				cur->next = NULL;
			}
		}
		cur = next;
	}
	return sorthead;
}





class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode*sorthead = head;
		ListNode*cur = head->next;
		sorthead->next = nullptr;//置空-防止链表成环
		while (cur != nullptr){
			ListNode*next = cur->next;
			//头插
			//1
			//2->
			if (cur->val <= sorthead->val){
				cur->next = sorthead;
				sorthead = cur;
			}
			else{
				ListNode*sortprev = sorthead;
				ListNode*sortcur = sorthead->next;
				//中间插
				while (sortcur){
					//3
					//2->4
					if (cur->val <= sortcur->val){
						sortprev->next = cur;
						cur->next = sortcur;
						break;//跳出第二个while循环-迭代后再次进入第一个while循环
					}
					//4
					//2->3->5
					else{
						sortprev = sortcur;
						sortcur = sortcur->next;
					}
				}
				//尾插
				if (sortcur == nullptr){
					sortprev->next = cur;
					cur->next = nullptr;//置空-防止链表成环
				}
			}
			cur = next;//迭代
		}
		return sorthead;
	}
};