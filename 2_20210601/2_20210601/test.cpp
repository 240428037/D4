struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode*sorthead = head, *cur = head->next;
	sorthead->next = NULL;
	while (cur)
	{
		struct ListNode*next = cur->next;
		//ͷ��
		if (cur->val <= sorthead->val)
		{
			cur->next = sorthead;
			sorthead = cur;
		}
		else
		{
			struct ListNode*sortprev = sorthead, *sortcur = sorthead->next;
			//�м��
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
			//β��
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
		sorthead->next = nullptr;//�ÿ�-��ֹ����ɻ�
		while (cur != nullptr){
			ListNode*next = cur->next;
			//ͷ��
			//1
			//2->
			if (cur->val <= sorthead->val){
				cur->next = sorthead;
				sorthead = cur;
			}
			else{
				ListNode*sortprev = sorthead;
				ListNode*sortcur = sorthead->next;
				//�м��
				while (sortcur){
					//3
					//2->4
					if (cur->val <= sortcur->val){
						sortprev->next = cur;
						cur->next = sortcur;
						break;//�����ڶ���whileѭ��-�������ٴν����һ��whileѭ��
					}
					//4
					//2->3->5
					else{
						sortprev = sortcur;
						sortcur = sortcur->next;
					}
				}
				//β��
				if (sortcur == nullptr){
					sortprev->next = cur;
					cur->next = nullptr;//�ÿ�-��ֹ����ɻ�
				}
			}
			cur = next;//����
		}
		return sorthead;
	}
};