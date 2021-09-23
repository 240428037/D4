class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),mid;
        int low=0,high = n-1;
        if (nums[0] != 0) return 0;
        while (low <= high){
            mid = (low + high)>>1;
            if (nums[mid] != mid && nums[mid-1] == mid-1) return mid;
            else if (nums[mid] > mid) high = mid - 1;
            else low = mid + 1;
        }
        return high+1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++)
            ans ^= nums[i];
        for(int i = 0; i <= nums.size(); i ++)
            ans ^= i;
        return ans;
    }   
};

int missingNumber(int* nums, int numsSize) {
    // 对于有序数组, 大小为i的数应当处于下标为i的位置上, 如果不在, 说明在该数字之前发生了错位
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] != mid) { right = mid; }
        else { left = mid + 1;}
    }
    // 如果从0 ~ n - 1都不缺值, 则缺少的是n
    return left == numsSize - 1 && nums[left] == left ? left + 1 : left;
}



//有序数组-首选二分
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //缺失的是最左边元素
        if(nums.empty()){
            return 0;
        }
        // if(nums[0]!=0){
        //     return 0;
        // }

        //开始二分
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==mid){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return left;//找左边界
    }
};

//异或
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret=0;
        for(int i=0;i<nums.size();i++){
            ret^=nums[i];
        }    
        for(int i=0;i<=nums.size();i++){
            ret^=i;
        }
        return ret;
    }
};


class Solution {
public:
    string minNumber(vector<int>& nums) {
        string res;

        sort(nums.begin(), nums.end(), cmp);

        for (int &num : nums)
            res += to_string(num);              //逐个转换成字符串并拼接
        
        return res;
    }

    static bool cmp(int &x, int &y)             //比较函数
    {
        return to_string(x) + to_string(y) < to_string(y) + to_string(x);
    }
};

class Solution {
public:
    static bool cmp(int&x,int&y){
        return to_string(x)+to_string(y)<to_string(y)+to_string(x);
    }
    string minNumber(vector<int>& nums) {
        string ret;
        sort(nums.begin(),nums.end(),cmp);
        for(auto i:nums){
            ret+=to_string(i);
        }
        return ret;
    }
};


//子数组-连续
//2 3 4 5
//4
class Solution {
public:
    int maxLength(vector<int>&nums) {
        map<int,int>map;
        int ret=1;
        int tmp=0;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]!=0){
                tmp=max(tmp,map[nums[i]]);
            }
            ret=max(ret,i-tmp+1);
            map[nums[i]]=i+1;
        }
        return ret;
    }
};


//子数组-连续
//2 3 4 5
//4
class Solution {
public:
    int maxLength(vector<int>&nums) {
        map<int,int>map;
        int ret=1;
        int tmp=0;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]!=0){
                tmp=max(tmp,map[nums[i]]);
            }
            ret=max(ret,i-tmp+1);
            map[nums[i]]=i+1;
        }
        return ret;
    }
};

//测试用例
//子数组是连续的
//解题思路
//
class Solution {
public:
    int maxLength(vector<int>& nums) {
        unordered_map<int,int>map;
        int maxsize=0;
        int cursize=0;
        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])==0){
                map[nums[i]]=i;
                cursize++;
            }else if(map.count(nums[i])>0){
                //[2,2,3,4,8,99,3]
                //预期输出5
                //实际输出4
                i=map[nums[i]];//?-记录上一次出现重复的值的index
                map.clear();
                cursize=0;
            }
            if(cursize>maxsize){
                maxsize=cursize;
            }
        }
        return maxsize;
    }
};