#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        long long sum=0;
        vector<int>v;
        v.resize(3*n);
        for(int i=0;i<3*n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            sum+=v[v.size()-(2*(i+1))];
        }
        cout<<sum<<endl;
    }
    return 0;
}


//解题思路
//动态规划
class Solution {
public:
    int getmax(int a,int b){
        return a>b?a:b;
    }
    int maxsumofSubarray(vector<int>&nums) {
        int sum=nums[0];
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=getmax(sum+nums[i],nums[i]);
            if(sum>=max){
                max=sum;
            }
        }
        return max;
    }
};


/**
* struct TreeNode {
*    int val;
*    struct TreeNode *left;
*    struct TreeNode *right;
* };
*/
//解题思路
//层序遍历分层打印-queue
//二叉树非递归-stack
//上层节点出队列的时候带下层节点入队列
//循环控制条件while(!q.empty())
//for循环-循环控制条件levelsize
//后序非递归的思路类似于层序遍历
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>>vv;
        if(root==nullptr){
            return vv;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++){
                TreeNode*cur=q.front();
                v.push_back(cur->val);
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            vv.push_back(v);
        }
        return vv;
    }
};