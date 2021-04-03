#define _CRT_SECURE_NO_WARNINGS 1



//206. 反转链表/逆置链表
//1.逆方向
//定义三个指针n1 n2 n3
//NULL head head->next
//画图判断开始条件 终止条件 和循环条件
//开始条件 反转过来以后（在原基础上改箭头） n1 n2 n3依次的指向
//终止条件
//要画出两步
//终止前一刻和终止时
//所以while的循环控制条件是n2 != NULL
//循环条件
//n2->next = n1; (已经反转过来的链表 n2指向n1)
//n1 n2 n3
//n1 = n2;
//n2 = n3;
//把2的值给1
//把3的值给2  不理解画图 三个指针要往后走
//n2=n3要加判断条件
//因为如果n3指向NULL就不能把空指针给n2

//必须有三个指针
//否则当n2->next指向n1即  n2->next = n1;的时候
//NUMM<-1 2 1和2之间会断开 所以需要有三个指针
//把n2给n1 
//n3给n2
//才能不断的走下去

struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode*n1 = NULL, *n2 = head, *n3 = head->next;
	while (n2)
	{
		//反转
		n2->next = n1;
		//迭代
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}


//头插法
//要定义一个新的链表newhead
//定义两个指针cur next
//为什么还需要一个next呢
//因为一旦把cur指向的那个往新的链表里去放
//cur和cur的下一个元素cur->next就失去联系了
//
//所以再放之前 要定义 next=cur->next
//总共需要定义三个newhead cur head
//其中newhead最开始赋为NULL
//cur指向的是第一个元素 也就是head
//而next=cur->next要放在循环里 而且要在头插之前
//
//循环终止的条件是cur=NULL的时候
//
//循环体
//cur->next=newhead 第一次cur要指向NULL 后面每次刚放下来的值要指向上次的最后一个
//newhead=cur 把cur给newhead
//cur=next 老链表里 为了循环往下走
//
//
//最后返回的是已经反转好了的链表 newhead是新链表的头
//所以return newhead

//这种情况不需要去关注NULL 你带入就Ok
//如果head为空 cur就为空 while循环就进不去 最后返回newhead=NULL
//
//如果是一个结点 取下来头插
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;

	while (cur)
	{
		struct ListNode* next = cur->next;
		//头插
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}