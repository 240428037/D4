class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()){
			return 0;
		}
		int dest = 0, src = 0;
		while (src < nums.size()){
			if (nums[src] != val){
				nums[dest] = nums[src];
				dest++;
				src++;
			}
			else{
				src++;
			}
		}
		return dest;
	}
};



class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()){
			return 0;
		}
		int left = 0, right = nums.size();
		while (left < right){
			if (nums[left] == val){
				nums[left] = nums[right - 1];
				right--;
			}
			else{
				left++;
			}
		}
		return left;
	}
};



class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		int dest = 0, prev = 0, cur = 1;
		while (cur < nums.size()){
			if (nums[prev] != nums[cur]){
				nums[dest] = nums[prev];
				dest++;
				prev++;
				cur++;
			}
			else{
				prev++;
				cur++;
			}
		}
		nums[dest] = nums[prev];
		dest++;
		return dest;
	}
};



class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//1.合并后排序
		// for(int i=0;i<n;i++){
		//     nums1[m+i]=nums2[i];
		// }
		// sort(nums1.begin(),nums1.end());
		//2.双指针遍历
		// int i1=0,i2=0,i3=0;
		// vector<int>nums3(m+n);
		// while(i1<m||i2<n){
		//     if(i1==m){
		//         nums3[i3++]=nums2[i2++];
		//     }
		//     else if(i2==n){
		//         nums3[i3++]=nums1[i1++];
		//     }
		//     else if(nums1[i1]<nums2[i2]){
		//         nums3[i3++]=nums1[i1++];
		//     }
		//     else{
		//         nums3[i3++]=nums2[i2++];
		//     }
		// }
		// for(int i=0;i<m+n;i++){
		//     nums1[i]=nums3[i];
		// }
		//3.逆向双指针
		int i1 = m - 1, i2 = n - 1, tail = m + n - 1;
		while (i1 >= 0 || i2 >= 0){
			if (i1 == -1){
				nums1[tail--] = nums2[i2--];
			}
			else if (i2 == -1){
				nums1[tail--] = nums1[i1--];
			}
			else if (nums1[i1] > nums2[i2]){
				nums1[tail--] = nums1[i1--];
			}
			else{
				nums1[tail--] = nums2[i2--];
			}
		}
	}
};