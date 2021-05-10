class Solution {
public:
	int StrToInt(string str) {
		if (str.empty()){
			return 0;
		}
		int flag = 1;
		if (str[0] == '-'){
			flag = -1;
			str[0] = '0';
		}
		if (str[0] == '+'){
			flag = 1;
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
		return sum*flag;
	}
};




class Solution {
public:
	bool Ischar(char ch){
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')){
			return true;
		}
		else{
			return false;
		}
	}
	string reverseOnlyLetters(string S) {
		int begin = 0, end = S.size() - 1;
		while (begin < end){
			while (begin < end&&!(Ischar(S[begin]))){
				begin++;
			}
			while (begin < end&&!(Ischar(S[end]))){
				end--;
			}
			swap(S[begin], S[end]);
			begin++;
			end--;
		}
		return S;
	}
};




class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };
		for (int i = 0; i < s.size(); i++){
			count[s[i]] += 1;
		}
		for (int i = 0; i < s.size(); i++){
			if (1 == count[s[i]]){
				return i;
			}
		}
		return -1;
	}
};





class Solution {
public:
	int firstUniqChar(string s) {
		// int count[256]={0};
		// for(int i=0;i<s.size();i++){
		//     count[s[i]]+=1;
		// }
		// for(int i=0;i<s.size();i++){
		//     if(1==count[s[i]]){
		//         return i;
		//     }
		// }
		// return -1;
		int count[26] = { 0 };
		for (auto ch : s){
			count[ch - 'a']++;
		}
		for (int i = 0; i < s.size(); i++){
			if (1 == count[s[i] - 'a']){
				return i;
			}
		}
		return -1;
	}
};