class Solution {
public:
	int StrToInt(string str) {
		if (str.empty()){
			return 0;
		}
		int flag = 1;
		if (str[0] == '+'){
			flag = 1;
			str[0] = '0';
		}
		if (str[0] == '-'){
			flag = -1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i < str.size(); i++){
			if (str[i]<'0' || str[i]>'9'){
				sum = 0;
				break;
			}
			sum = sum * 10 + (str[i] - '0');
		}
		return flag*sum;
	}
};



class Solution {
public:
	bool Ischar(int ch){
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')){
			return true;
		}
		else{
			return false;
		}
	}
	string reverseOnlyLetters(string s) {
		int begin = 0, end = s.size() - 1;
		while (begin < end){
			while (begin < end&&!Ischar(s[begin])){
				begin++;
			}
			while (begin < end&&!Ischar(s[end])){
				end--;
			}
			swap(s[begin], s[end]);
			begin++;
			end--;
		}
		return s;
	}
};