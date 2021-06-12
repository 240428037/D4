class Solution {
public:
	int maxdepth(TreeNode* root){
		if (root == nullptr){
			return 0;
		}
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		return leftdepth > rightdepth ? leftdepth + 1 : rightdepth + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr){
			return true;
		}
		int leftdepth = maxdepth(root->left);
		int rightdepth = maxdepth(root->right);
		return abs(leftdepth - rightdepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
	}
};