class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto e : nums){
			ret ^= e;
		}
		return ret;
	}
};



class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int val = 0;
		for (auto&e : nums){
			val ^= e;
		}
		int i = 0;
		for (; i < 32; i++){
			if (val&(1 << i)){
				break;
			}
		}
		int num1 = 0;
		int num2 = 0;
		for (auto&e : nums){
			if (e&(1 << i)){
				num1 ^= e;
			}
			else{
				num2 ^= e;
			}
		}
		vector<int>v;
		v.push_back(num1);
		v.push_back(num2);
		return v;
	}
};



class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int count[32] = { 0 };
		for (auto&e : nums){
			for (int i = 0; i < 32; i++){
				if (e&(1 << i)){
					count[i]++;
				}
			}
		}
		int ret = 0;
		for (int i = 0; i < 32; i++){
			if (count[i] % 3 == 1){
				ret |= (1 << i);
			}
		}
		return ret;
	}
};


class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret(numRows);
		for (int i = 0; i < numRows; ++i) {
			ret[i].resize(i + 1);
			ret[i][0] = ret[i][i] = 1;
			for (int j = 1; j < i; ++j) {
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
			}
		}
		return ret;
	}
};
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>vv;
		vv.resize(numRows);
		for (int i = 0; i < numRows; i++){
			vv[i].resize(i + 1);
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}
		for (int i = 0; i < vv.size(); i++){
			for (int j = 0; j < vv[i].size(); j++){
				if (vv[i][j] != 1){
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				}
			}
		}
		return vv;
	}
};


class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		vector<int> res;
		int n = num.size();
		for (int i = n - 1; i >= 0; --i) {
			int sum = num[i] + k % 10;
			k /= 10;
			if (sum >= 10) {
				k++;
				sum -= 10;
			}
			res.push_back(sum);
		}
		for (; k > 0; k /= 10) {
			res.push_back(k % 10);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};