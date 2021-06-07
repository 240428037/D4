class Solution {
public:
	int getmax(int a, int b){
		return a > b ? a : b;
	}
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int max = nums[0];
		for (int i = 0; i < nums.size(); i++){
			sum = getmax(sum + nums[i], nums[i]);
			if (sum >= max){
				max = sum;
			}
		}
		return max;
	}
};