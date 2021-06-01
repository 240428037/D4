class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		ListNode*prev = nullptr, *cur = head;
		while (cur != nullptr){
			if (cur->val != val){
				prev = cur;
				cur = cur->next;
			}
			else{
				if (cur == head){
					head = cur->next;
					cur = head;
				}
				else{
					prev->next = cur->next;
					cur = prev->next;
				}
			}
		}
		return head;
	}
};


class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int>st;
		vector<int>v;
		while (head != nullptr){
			st.push(head->val);
			head = head->next;//µü´ú
		}
		while (!st.empty()){
			v.push_back(st.top());
			st.pop();
		}
		return v;
	}
};



class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode*slow = head, *fast = head;
		while (fast&&fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};