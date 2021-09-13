//解题思路
//前序中序重建二叉树
//前序-根左右
//中序-左根右
//前序需要下标
//中序需要区间
//先重建根节点
//然后递归重建左右子树
//递归-终止条件-inbegin>inend
//递归终止条件为>-while和if的区间控制条件为<=-不要漏掉=
//子函数rebuild的参数prei需要传引用-前置++
class Solution {
public:
    TreeNode*rebuild(vector<int>pre,vector<int>in,int&prei,int inbegin,int inend){
        if(inbegin>inend){
            return nullptr;
        }
        TreeNode* root=new TreeNode(pre[prei]);
        //划分中序区间
        int rooti=inbegin;
        //<=
        while(rooti<=inend){
            if(pre[prei]==in[rooti]){
                break;
            }
            rooti++;
        }
        //[inbegin,rooti-1]-rooti-[rooti+1,inend]
        //重建左子树
        //<=
        if(inbegin<=rooti-1){
            root->left=rebuild(pre,in,++prei,inbegin,rooti-1);
        }else{
            root->left=nullptr;
        }
        //重建右子树
        //<=
        if(rooti+1<=inend){
            root->right=rebuild(pre,in,++prei,rooti+1,inend);
        }else{
            root->right=nullptr;
        }
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int>pre,vector<int>in) {
        int prei=0;
        int inbegin=0;
        int inend=in.size()-1;//-1!!!
        return rebuild(pre,in,prei,inbegin,inend);
    }
};


// struct TreeNode{
//     int val;
//     struct TreeNode*left;
//     struct TreeNode*right;
// };
//层序遍历用队列
//先插节点循环控制条件为while(!q.emoty())
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>>vv;
        //段错误处理
        if(root==nullptr){
            return vv;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int levelsize=q.size();
            while(levelsize--){
                TreeNode*cur=q.front();
                q.pop();
                v.push_back(cur->val);
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



/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
//解题思路
//在层序遍历分层打印的基础上
//引入levelcount
//levelcount%2==0-reverse
class Solution {
public:
    vector<vector<int> > Print(TreeNode*root) {
        vector<vector<int>>vv;
        if(root==nullptr){
            return vv;
        }
        queue<TreeNode*>q;
        q.push(root);
        int levelcount=0;
        while(!q.empty()){
            levelcount++;
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
            if(levelcount%2==0){
                reverse(v.begin(),v.end());
            }
            vv.push_back(v);
        }
        return vv;
    }
};


//解题思路
//递归-返回值为节点-开辟子函数
//递归-终止条件
class Solution {
public:
    TreeNode*common(TreeNode* root, int l1, int l2){
        //特殊处理-段错误
        if(root==nullptr){
            return nullptr;
        }
        //终止条件
        if(root->val==l1||root->val==l2){
            return root;
        }
        TreeNode*leftnode=common(root->left,l1,l2);
        TreeNode*rightnode=common(root->right,l1,l2);
        //l1l2左右子树都不在
        if(leftnode==nullptr&&rightnode==nullptr){
            return nullptr;
        }
        //pq都在右子树
        if(leftnode==nullptr){
            return rightnode;
        }
        //pq都在左子树
        if(rightnode==nullptr){
            return leftnode;
        }
        return root;//pq一左一右
    }
    int lowestCommonAncestor(TreeNode* root, int l1, int l2) {
        return common(root,l1,l2)->val;
    }
};