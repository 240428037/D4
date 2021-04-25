//#define _CRT_SECURE_NO_WARNINGS 1

//解题思路：
//I like beijing\0
//先将整个字符串逆置
//gnijieb ekil I\0
//然后再找到每个单词对每个单词逆置
//beijing like I\0
#include<iostream>
#include<string>
#include<aigorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	//先将整个字符串逆置
	reverse(s.begin(), s.end());
	//定义两个指针start end用于找到每个单词，因为单词之间以空格分隔
	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		//到这里肯定已经找到了一个单词或者到达字符串末尾，对单词进行逆置
		reverse(start, end);
		//判断后面还没有单词，有的话start迭代为end+1,没有start=end;
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
}