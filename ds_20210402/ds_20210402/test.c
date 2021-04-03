#define _CRT_SECURE_NO_WARNINGS 1



//206. ��ת����/��������
//1.�淽��
//��������ָ��n1 n2 n3
//NULL head head->next
//��ͼ�жϿ�ʼ���� ��ֹ���� ��ѭ������
//��ʼ���� ��ת�����Ժ���ԭ�����ϸļ�ͷ�� n1 n2 n3���ε�ָ��
//��ֹ����
//Ҫ��������
//��ֹǰһ�̺���ֹʱ
//����while��ѭ������������n2 != NULL
//ѭ������
//n2->next = n1; (�Ѿ���ת���������� n2ָ��n1)
//n1 n2 n3
//n1 = n2;
//n2 = n3;
//��2��ֵ��1
//��3��ֵ��2  ����⻭ͼ ����ָ��Ҫ������
//n2=n3Ҫ���ж�����
//��Ϊ���n3ָ��NULL�Ͳ��ܰѿ�ָ���n2

//����������ָ��
//����n2->nextָ��n1��  n2->next = n1;��ʱ��
//NUMM<-1 2 1��2֮���Ͽ� ������Ҫ������ָ��
//��n2��n1 
//n3��n2
//���ܲ��ϵ�����ȥ

struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode*n1 = NULL, *n2 = head, *n3 = head->next;
	while (n2)
	{
		//��ת
		n2->next = n1;
		//����
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}


//ͷ�巨
//Ҫ����һ���µ�����newhead
//��������ָ��cur next
//Ϊʲô����Ҫһ��next��
//��Ϊһ����curָ����Ǹ����µ�������ȥ��
//cur��cur����һ��Ԫ��cur->next��ʧȥ��ϵ��
//
//�����ٷ�֮ǰ Ҫ���� next=cur->next
//�ܹ���Ҫ��������newhead cur head
//����newhead�ʼ��ΪNULL
//curָ����ǵ�һ��Ԫ�� Ҳ����head
//��next=cur->nextҪ����ѭ���� ����Ҫ��ͷ��֮ǰ
//
//ѭ����ֹ��������cur=NULL��ʱ��
//
//ѭ����
//cur->next=newhead ��һ��curҪָ��NULL ����ÿ�θշ�������ֵҪָ���ϴε����һ��
//newhead=cur ��cur��newhead
//cur=next �������� Ϊ��ѭ��������
//
//
//��󷵻ص����Ѿ���ת���˵����� newhead���������ͷ
//����return newhead

//�����������Ҫȥ��עNULL ������Ok
//���headΪ�� cur��Ϊ�� whileѭ���ͽ���ȥ ��󷵻�newhead=NULL
//
//�����һ����� ȡ����ͷ��
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;

	while (cur)
	{
		struct ListNode* next = cur->next;
		//ͷ��
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}