//#define _CRT_SECURE_NO_WARNINGS 1

//����˼·��
//I like beijing\0
//�Ƚ������ַ�������
//gnijieb ekil I\0
//Ȼ�����ҵ�ÿ�����ʶ�ÿ����������
//beijing like I\0
#include<iostream>
#include<string>
#include<aigorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	//�Ƚ������ַ�������
	reverse(s.begin(), s.end());
	//��������ָ��start end�����ҵ�ÿ�����ʣ���Ϊ����֮���Կո�ָ�
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		//������϶��Ѿ��ҵ���һ�����ʻ��ߵ����ַ���ĩβ���Ե��ʽ�������
		reverse(start, end);
		//�жϺ��滹û�е��ʣ��еĻ�start����Ϊend+1,û��start=end;
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
}