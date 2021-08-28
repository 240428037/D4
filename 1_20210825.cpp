//测试用例
//需要满足 index1 小于index2
//解题思路
//使用map-key存值value存下标
//遍历数组使用find去找-找到插入-找不到把当前元素存入map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,int>map;//key存值value存下标
        for(int i=0;i<nums.size();i++){
            auto it=map.find(target-nums[i]);
            if(it!=map.end()){
                //返回的数组中需要满足前一个元素的下标小于后一个元素的下标
                v.push_back(it->second+1);//先放进map-下标小-先插入
                v.push_back(i+1);
                return v;
            }
            map[nums[i]]++;
        }
        return v;
    }
};


//测试用例
//需要满足 index1 小于index2
//解题思路
//使用map-key存值value存下标
//遍历数组使用find去找-找到插入-找不到把当前元素存入map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,int>map;//key存值value存下标
        for(int i=0;i<nums.size();i++){
            auto it=map.find(target-nums[i]);
            if(it!=map.end()){
                //返回的数组中需要满足前一个元素的下标小于后一个元素的下标
                v.push_back(it->second+1);//先放进map-下标小-先插入
                v.push_back(i+1);
                return v;
            }
            map[nums[i]]=i;
        }
        return v;
    }
};


class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        // 数组的值——数组的index
        unordered_map<int, int> value_index;
        int maxSize = 0;
        int curSize = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (value_index.count(arr[i]) == 0) {
                value_index[arr[i]] = i;
                curSize++;
            }
            else if (value_index.count(arr[i]) > 0){
                // 记录上一次出现重复的值的 index
                i = value_index[arr[i]];
                value_index.clear();

                curSize = 0;
            }

            if (maxSize < curSize) {
                maxSize = curSize;
            }
        }

        return maxSize;
    }
};


//测试用例
//子数组是连续的
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
            if(maxsize<cursize){
                maxsize=cursize;
            }
        }
        return maxsize;
    }
};


