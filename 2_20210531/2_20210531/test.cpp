/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode*curA = headA, *curB = headB;
		int la = 0, lb = 0;
		while (curA){
			la++;
			curA = curA->next;
		}
		while (curB){
			lb++;
			curB = curB->next;
		}
		ListNode*longlist = headA, *shortlist = headB;
		if (la<lb){
			longlist = headB;
			shortlist = headA;
		}
		int gap = abs(la - lb);
		while (gap--){
			longlist = longlist->next;
		}
		while (longlist){
			if (longlist == shortlist){
				return longlist;
			}
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
		return nullptr;
	}
};













class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode*curA = headA, *curB = headB;
		int la = 0, lb = 0;
		while (curA != nullptr){
			la++;
			curA = curA->next;
		}
		while (curB != nullptr){
			lb++;
			curB = curB->next;
		}
		ListNode*longlist = headA, *shortlist = headB;
		if (la < lb){
			longlist = headB;
			shortlist = headB;
		}
		int gap = abs(la - lb);
		while (gap--){
			longlist = longlist->next;
		}
		while (longlist){
			if (longlist == shortlist){
				return longlist;
			}
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
		return nullptr;
	}
};





class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode*curA = headA, *curB = headB;
		int la = 0, lb = 0;
		while (curA){
			la++;
			curA = curA->next;
		}
		while (curB){
			lb++;
			curB = curB->next;
		}
		ListNode*longlist = headA, *shortlist = headB;
		if (la < lb){
			longlist = headB;
			shortlist = headA;
		}
		int gap = abs(la - lb);
		while (gap--){
			longlist = longlist->next;
		}
		while (longlist){
			if (longlist == shortlist){
				return longlist;
			}
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
		return nullptr;
	}
};