//统计字符串各个字符出现的次数
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string str;
    map<char,int>map;
    while(cin>>str){
        for(int i=0;i<str.size();i++){
            map[str[i]]++;
        }
        auto it=map.begin();
        while(it!=map.end()){
            cout<<it->first;
            cout<<it->second;
            it++;
        }
        map.clear();
    }
}



//测试用例
//[3,2,4],6
//[2,3]-下标
//解题思路
//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            auto it=map.find(target-nums[i]);
            if(it!=map.end()){
                v.push_back(it->second);
                v.push_back(i+1);
                return v;
            }
            map[nums[i]]=i+1;
        }
        return v;//return {};也ok
    }
};



//解题思路
class Solution {
public:
    int duplicate(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
            if(hash[nums[i]]>1){
                return nums[i];
            }
        }
        return -1;
    }
};


// 时间复杂度：O(nlogk)
// 空间复杂度：O(n)
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // first对应元素value second对应元素出现次数
        unordered_map<int,int>hashmap;
        vector<int> ret;

        // 记录元素出现次数
        for(int i:nums) hashmap[i]++;

        int maxtimes = 0;
        // 找到元素出现的最高频率次数
        for(auto i:hashmap) {
            if(i.second > maxtimes) maxtimes = i.second;
        }
            
        // 从最高往低走 依次输出
        while(k > 0){
            for(auto i:hashmap){
                if(i.second == maxtimes){
                    ret.push_back(i.first);
                    k--;
                } 
            }
            maxtimes--;
        }
        return ret;
    }
};