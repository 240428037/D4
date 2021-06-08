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
	string reverseOnlyLetters(string s) {
		int begin = 0, end = s.size() - 1;
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
		return s;
	}
};


class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };
		for (int i = 0; i < s.size(); i++){
			count[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++){
			if (count[s[i]] == 1){
				return i;
			}
		}
		return -1;
	}
};


class Solution {
public:
	int myAtoi(string s) {
		int sign = 1, tmp = 0, i = 0;

		while (s[i] == ' ')  ++i;              //1.忽略前导空格

		if (s[i] == '+' || s[i] == '-')        //2.确定正负号
			sign = (s[i++] == '-') ? -1 : 1;  //s[i]为+的话sign依旧为1，为-的话sign为-1

		while (s[i] >= '0' && s[i] <= '9')     //3.检查输入是否合法
		{
			if (tmp > INT_MAX / 10 || (tmp == INT_MAX / 10 && s[i] - '0' > 7))    //4.是否溢出
				return sign == 1 ? INT_MAX : INT_MIN;
			tmp = tmp * 10 + (s[i++] - '0');  //5.不加括号有溢出风险
		}
		return tmp * sign;
	}
};


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



class Solution {
public:
	int strToInt(string str) {
		if (str.empty()){
			return 0;
		}
		int i = 0;
		while (str[i] == ' '){
			i++;
		}
		int flag = 1;
		if (str[i] == '+'){
			flag = 1;
			i++;
		}
		else if (str[i] == '-'){
			flag = -1;
			i++;
		}
		long long sum = 0;
		while (str[i] >= '0'&&str[i] <= '9'){
			sum = sum * 10 + (str[i] - '0');
			if (sum > INT_MAX&&flag == 1){
				return INT_MAX;
			}
			else if (sum < INT_MIN&&flag == -1){
				return INT_MIN;
			}
			i++;
		}
		return sum*flag;
	}
};