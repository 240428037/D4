// struct TreeNode{
//     int val;
//     struct TreeNode*left;
//     struct TreeNode*right;
// };
class Solution {
public:
    vector<int> preorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        while(!st.empty()||cur){
            while(cur){
                st.push(cur);
                v.push_back(cur->val);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            cur=cur->right;
        }
        return v;
    }
    vector<int> inorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        while(!st.empty()||cur){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            v.push_back(cur->val);
            cur=cur->right;
        }
        return v;
    }
    vector<int> postorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*cur=st.top();
            st.pop();
            v.push_back(cur->val);
            if(cur->left){
                st.push(cur->left);
            }
            if(cur->right){
                st.push(cur->right);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>>vv;
        vv.push_back(preorder(root));
        vv.push_back(inorder(root));
        vv.push_back(postorder(root));
        return vv;
    }
};



// struct TreeNode{
//     int val;
//     struct TreeNode*left;
//     struct TreeNode*right;
// };

//前中后序非递归遍历
//前序中序-while(!st.empty()||cur)
//左路节点先入栈-出栈的时候带右路节点入栈
//后序-while(!st.empty())
class Solution {
public:
    //前序非递归
    //根左右
    vector<int>preorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        while(!st.empty()||cur){
            while(cur){
                v.push_back(cur->val);//
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            cur=cur->right;
        }
        return v;
    }
    //中序非递归
    //左跟右
    vector<int>inorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode*cur=root;
        while(!st.empty()||cur){
            while(cur){
                st.push(cur);
                cur=cur->left;
            }
            cur=st.top();
            st.pop();
            v.push_back(cur->val);//
            cur=cur->right;
        }
        return v;
    }
    //后序非递归
    //左右根
    vector<int>postorder(TreeNode*root){
        vector<int>v;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*cur=st.top();
            st.pop();
            v.push_back(cur->val);
            //
            if(cur->left){
                st.push(cur->left);
            }
            if(cur->right){
                st.push(cur->right);
            }
        }
        //st压栈:左 右
        //st出栈:右 左
        //v:根 右 左
        //reverse v:左 右 根
        reverse(v.begin(),v.end());
        return v;
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>>vv;
        vv.push_back(preorder(root));
        vv.push_back(inorder(root));
        vv.push_back(postorder(root));
        return vv;
    }
};