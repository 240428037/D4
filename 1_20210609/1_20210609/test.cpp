class Solution {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};

class Solution {
public:
	//����һ���ַ��� s ��һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת��
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)){
			//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
			if (i + k < s.size()){
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
			reverse(s.begin() + i, s.begin() + s.size());
		}
		return s;
	}
};


class Solution {
public:
	//����һ���ַ��� s ��һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת��
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)){
			//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
			if (i + k < s.size()){
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
			reverse(s.begin() + i, s.end());
		}
		return s;
	}
};



class Solution {
public:
	string reverseWords(string s) {
		int length = s.length();
		int i = 0;
		while (i < length) {
			int start = i;
			while (i < length && s[i] != ' ') {
				i++;
			}

			int left = start, right = i - 1;
			while (left < right) {
				swap(s[left], s[right]);
				left++;
				right--;
			}
			while (i < length && s[i] == ' ') {
				i++;
			}
		}
		return s;
	}
};



class Solution {
public:
	string reverseWords(string s) {
		int i = 0;
		for (; i < s.size();){
			int start = i;
			while (i < s.size() && s[i] != ' '){
				i++;
			}
			int begin = start, end = i - 1;
			while (begin < end){
				swap(s[begin], s[end]);
				begin++;
				end--;
			}
			while (i < s.size() && s[i] == ' '){
				i++;
			}
		}
		return s;
	}
};