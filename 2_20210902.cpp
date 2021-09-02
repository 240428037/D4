#include<iostream>
using namespace std;
struct ListNode{
    int val;
    struct ListNode*next;
    ListNode(int x):val(x),next(nullptr){}
};
ListNode*reverselist(ListNode*head){
        ListNode*cur=head;
        ListNode*newhead=nullptr;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        return newhead;
}
void test(){
    ListNode*p1=new ListNode(1);
    ListNode*p2=new ListNode(2);
    ListNode*p3=new ListNode(3);
    p1->next=p2;
    p2->next=p3;
    ListNode*newhead=reverselist(p1);
    ListNode*cur=newhead;
    while(cur){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
}
int main(){
    test();
    return 0;
}



// struct ListNode{
//     int val;
//     struct ListNode*next;
//     ListNode(int x):val(x),next(nullptr){}
// };

//头插
class Solution {
public:
    ListNode* ReverseList(ListNode*head) {
        ListNode*cur=head;
        ListNode*newhead=nullptr;
        while(cur){
            ListNode*next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        return newhead;
    }
};

// //迭代
// class Solution {
// public:
//     ListNode* ReverseList(ListNode*head) {
//         ListNode*prev=nullptr;
//         ListNode*cur=head;
//         ListNode*next=cur->next;
//         while(cur){
//             cur->next=prev;
//             prev=cur;
//             cur=next;
//             if(next){
//                 next=next->next;
//             }
//         }
//         return prev;
//     }
// };

// #include<iostream>
// using namespace std;
// ListNode*reverselist(ListNode*head){
//         ListNode*cur=head;
//         ListNode*newhead=nullptr;
//         while(cur){
//             ListNode*next=cur->next;
//             cur->next=newhead;
//             newhead=cur;
//             cur=next;
//         }
//         return newhead;
// }
// void test(){
//     ListNode*n1=new ListNode(1);
//     ListNode*n2=new ListNode(2);
//     ListNode*n3=new ListNode(3);
//     n1->next=n2;
//     n2->next=n3;
//     ListNode*newhead=reverselist(n1);
//     ListNode*cur=newhead;
//     while(cur){
//         cout<<cur->val<<endl;
//         cur=cur->next;
//     }
// }
// int main(){
//     test();
//     return 0;
// }


class LRUcache{
public:
    LRUcache(int capacity):k(capacity){}
    void put(int key,int value){
        if(list.size()==k){
            int delkey=list.back();
            list.pop_back();
            map.erase(delkey);
        }
        list.push_front(key);
        map[key]=value;
    }
    int get(int key){
        auto it=map.find(key);
        if(it!=map.end()){
            list.remove(it->first);
            list.push_front(it->first);
            return it->second;
        }else{
            return -1;
        }
    }
private:
    unordered_map<int,int>map;
    list<int>list;
    int k;
}




class Solution {
public:
    unordered_map<int,int>map;
    list<int>list;
    void put(int key,int value,int k){
        if(list.size()==k){
            int delkey=list.back();
            list.pop_back();
            map.erase(delkey);
        }
        list.push_front(key);
        map[key]=value;
        
    }
    int get(int key){
        auto it=map.find(key);
        if(it!=map.end()){
            list.remove(it->first);
            list.push_front(it->first);
            return it->second;
        }else{
            return -1;
        }
    }
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        vector<int>v;
        for(auto i:operators){
            if(i[0]==1){
                put(i[1],i[2],k);
            }
            if(i[0]==2){
                int val=get(i[1]);
                v.push_back(val);
            }
        }
        return v;
    }
};


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int>nums, int k) {
        vector<int>v;
        //特殊情况处理
        if(k==0){
            return v;
        }
        priority_queue<int>q;
        //先建k个数的大堆
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        //比较替换
        for(int i=k;i<nums.size();i++){
            if(nums[i]<q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        //cout
        while(!q.empty()){
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};