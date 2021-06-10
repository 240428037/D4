class Solution {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};

class Solution {
public:
	//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)){
			//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
			if (i + k < s.size()){
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//如果剩余字符少于 k 个，则将剩余字符全部反转。
			reverse(s.begin() + i, s.begin() + s.size());
		}
		return s;
	}
};


class Solution {
public:
	//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)){
			//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
			if (i + k < s.size()){
				reverse(s.begin() + i, s.begin() + i + k);
				continue;
			}
			//如果剩余字符少于 k 个，则将剩余字符全部反转。
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