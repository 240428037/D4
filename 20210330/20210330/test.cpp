#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

int main()
{
	Seqlist list;
	SeqlistInit(&list);
	ElemType item;
	int select = 1;
	while (select)
	{
		printf("******************************************\n");
		printf("*    1.push_back      2.push_front       *\n");
		printf("*    3.show_list      4.quit_sysytem     *\n");
		printf("******************************************\n");
		printf("��ѡ��:>\n");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����)");
			while (scanf("%d",&item),item != -1)
			{
				SeqlistPushBack(&list, item);
			}
			break;
		case 2:
			printf("������Ҫ���������(��-1����)");
			while (scanf("%d", &item), item != -1)
			{
				SeqlistPushFront(&list, item);
			}
			break;
		case 3:
			SeqlistShow(&list);
			break;
		case 4:
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}
	system("pasue");
	return 0;
}