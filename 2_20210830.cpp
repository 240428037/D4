class Solution {
public:
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        vector<int>v;
        if(operators.empty()){
            return v;
        }
        for(auto opt:operators){
            if(opt[0]==1){
                put(opt[1],opt[2],k);
            }
            if(opt[0]==2){
                get(opt[1],v);
            }
        }
        return v;
    }
private:
    unordered_map<int,int>hash;
    list<int>list;
    void put(int key,int value,int k){
        if(list.size()==k){
            int delkey=list.back();
            list.pop_back();
            hash.erase(delkey);
        }
        hash[key]=value;
        list.push_front(key);
    }
    void get(int key,vector<int>&v){
        auto it=hash.find(key);
        if(it==hash.end()){
            v.push_back(-1);
        }else{
            v.push_back(it->second);
            list.remove(it->first);
            list.push_front(it->first);
        }
    }
};



class LRUCache {
public:
    LRUCache(int capacity)
    :k(capacity)
    {}


    int get(int key) {
        auto it=hash.find(key);
        if(it==hash.end()){
            return -1;
        }else{
            list.remove(it->first);
            list.push_front(it->first);
            return it->second;
        }
    }
    
    void put(int key, int value) {
        if(list.size()==k){
            int delkey=list.back();
            list.pop_back();
            hash.erase(delkey);
        }
        hash[key]=value;
        list.push_front(key);
    }
private:
    unordered_map<int,int>hash;
    list<int>list;
    int k;
};


//解题思路
//1.用nums前k个元素建k个数的大堆-priority_queue默认建大堆
//2.用nums剩下的元素依次和堆顶元素比较
//如果比堆顶元素小则交换-先弹出再压入
//3.将q中的元素放到vector中返回
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int>nums, int k) {
        vector<int>v;
        //防止段错误
        if(k==0){
            return v;
        }
        priority_queue<int>q;
        //用nums前k个元素建k个数的大堆-priority_queue默认建大堆
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        //用nums剩下的元素依次和堆顶元素比较
        //如果比堆顶元素小则交换-先弹出再压入
        for(int i=k;i<nums.size();i++){
            if(nums[i]<q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        //将q中的元素放到vector中返回
        for(int i=0;i<k;i++){
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};