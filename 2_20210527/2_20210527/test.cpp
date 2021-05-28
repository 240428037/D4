class Solution {
public:
	void reverse(vector<int>&nums, int begin, int end){
		while (begin < end){
			swap(nums[begin], nums[end]);
			begin++;
			end--;
		}
	}
	void rotate(vector<int>& nums, int k) {
		//1234567 k=3 s=7
		//0 s-1-k=3
		//4321 567
		//s-k=4 s-1=6
		//4321 765
		//0 s-1
		//5671234
		k %= nums.size();
		reverse(nums, 0, nums.size() - 1 - k);
		reverse(nums, nums.size() - k, nums.size() - 1);
		reverse(nums, 0, nums.size() - 1);
	}
};