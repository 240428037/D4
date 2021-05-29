//#include <iostream>
//#include<vector>
//using namespace std;
//int main(){
//	vector<int>v1;
//	vector<int>v2(v1);
//	vector<int>v3(5, 1);
//	vector<int>v4(v3.begin(), v3.end());
//
//	//auto it = v3.begin();
//	//while (it != v3.end()){
//	//	cout << *it << " ";
//	//	it++;
//	//}
//	auto it = v3.begin();
//	while (it != v3.end()){
//		*it *= 2;
//		it++;
//		cout << *it << " ";
//		it++;
//	}
//}


class Solution {
public:
	int getmax(int a, int b){
		return a > b ? a : b;
	}
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int max = nums[0];
		for (int i = 0; i < nums.size(); i++){
			sum = getmax(sum + nums[i], nums[i]);
			if (sum >= max){
				max = sum;
			}
		}
		return max;
	}
};


class Solution {
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {
		vector<int>v;
		for (int i = num.size() - 1; i >= 0; i--){
			int sum = num[i] + k % 10;
			k /= 10;
			if (sum >= 10){
				k++;
				sum -= 10;
			}
			v.push_back(sum);
		}
		while (k > 0){
			v.push_back(k % 10);
			k /= 10;
		}
		reverse(v.begin(), v.end());
		return v;
	}
};


class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// // 1.对数组进行排序，如果那个数字存在那么那个数字一定在中间
		// // 最后再判断一下那个数字的出现次数是否超过数组长度的一半
		// if(nums.empty()){
		//     return 0;
		// }
		// sort(nums.begin(),nums.end());
		// int count=0;
		// int mid=nums.size()/2;
		// for(int i=0;i<nums.size();i++){
		//     if(nums[mid]==nums[i]){
		//         count++;
		//     }
		// }
		// return count>nums.size()/2?nums[mid]:0;

		//2.众数非众数
		if (nums.empty()){
			return 0;
		}
		int result = nums[0];
		int times = 1;
		for (int i = 0; i < nums.size(); i++){
			if (times == 0){
				result = nums[i];
				times = 1;
			}
			else{
				if (result == nums[i]){
					times++;
				}
				else{
					times--;
				}
			}
		}
		int count = 0;
		for (int i = 0; i<nums.size(); i++){
			if (result == nums[i]){
				count++;
			}
		}
		return count>nums.size() / 2 ? result : 0;
	}
};





class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// // 1.对数组进行排序，如果那个数字存在那么那个数字一定在中间
		// // 最后再判断一下那个数字的出现次数是否超过数组长度的一半
		// if(nums.empty()){
		//     return 0;
		// }
		// sort(nums.begin(),nums.end());
		// int count=0;
		// int mid=nums.size()/2;
		// for(int i=0;i<nums.size();i++){
		//     if(nums[mid]==nums[i]){
		//         count++;
		//     }
		// }
		// return count>nums.size()/2?nums[mid]:0;

		//2.众数非众数
		if (nums.empty()){
			return 0;
		}
		int result = nums[0];
		int times = 1;
		//i从1开始！！！！！！
		for (int i = 1; i < nums.size(); i++){
			if (times == 0){
				result = nums[i];
				times = 1;
			}
			else{
				if (result == nums[i]){
					times++;
				}
				else{
					times--;
				}
			}
		}
		int count = 0;
		for (int i = 0; i<nums.size(); i++){
			if (result == nums[i]){
				count++;
			}
		}
		return count>nums.size() / 2 ? result : 0;
	}
};


class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>vv(numRows);
		for (int i = 0; i < numRows; i++){
			vv[i].resize(i + 1);
			vv[i][0] = vv[i][i] = 1;
			for (int j = 1; j < i; j++){
				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
			}
		}
		return vv;
	}
};