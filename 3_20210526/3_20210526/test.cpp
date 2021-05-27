class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//1.快慢指针找中间节点
		ListNode*slow = head, *fast = head;
		while (fast&&fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		//反转后半段链表
		ListNode*cur = slow;
		ListNode*newhead = nullptr;
		while (cur != nullptr){
			ListNode*next = cur->next;
			cur->next = newhead;
			newhead = cur;
			cur = next;
		}
		//判断回文
		//&&任意一个头节点走到空就结束
		while (newhead != nullptr&&head != nullptr){
			if (newhead->val != head->val){
				return false;
			}
			newhead = newhead->next;
			head = head->next;
		}
		return true;
	}
};



#include<iostream>
#include<vector>
using namespace std;
int row, col;
vector<vector<int>>vv;
vector<vector<int>>tmp;//临时路径
vector<vector<int>>ret;//最佳路径

void track(int i, int j){
	vv[i][j] = 1;//标记该点已经走过
	tmp.push_back({ i, j });
	//判断是否到达出口
	if (i == row - 1 && j == col - 1){
		//寻找最佳路径
		if (ret.empty() || ret.size() < tmp.size()){
			ret = tmp;
		}
	}
	//上
	if (i - 1 >= 0 && vv[i - 1][j] == 0){
		track(i - 1, j);
	}
	//下
	if (j + 1 < row&&vv[i][j + 1] == 0){
		track(i, j + 1);
	}//左
	if (j - 1 >= 0 && vv[i][j - 1] == 0){
		track(i, j - 1);
	}//右
	if (i + 1 <= col&&vv[i + 1][j] == 0){
		track(i + 1, j);
	}
	//回溯-恢复路径
	vv[i][j] = 0;
	tmp.pop_back();
}

int main(){
	while (cin >> row >> col){
		vv = vector<vector<int>>(row, vector<int>(col, 0));
		tmp.clear();
		ret.clear();
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				cin >> vv[i][j];
			}
		}
		track(0, 0);
		for (int i = 0; i < ret.size(); i++){
			cout << "(" << ret[i][0] << "," << ret[i][1] << ")" << endl;
		}
	}
	return 0;
}


#include<iostream>
#include<vector>
using namespace std;
int row, col;
vector<vector<int>>vv;
vector<vector<int>>tmp;//临时路径
vector<vector<int>>ret;//最佳路径

void track(int i, int j){
	vv[i][j] = 1;//标记该点已经走过
	tmp.push_back({ i, j });
	//判断是否到达出口
	if (i == row - 1 && j == col - 1){
		//寻找最佳路径
		if (ret.empty() || ret.size() < tmp.size()){
			ret = tmp;
		}
	}
	//上
	if (i - 1 >= 0 && vv[i - 1][j] == 0){
		track(i - 1, j);
	}
	//下
	if (i + 1 < row&&vv[i + 1][j] == 0){
		track(i + 1, j);
	}//左
	if (j - 1 >= 0 && vv[i][j - 1] == 0){
		track(i, j - 1);
	}//右
	if (j + 1 < col&&vv[i][j + 1] == 0){
		track(i, j + 1);
	}
	//回溯-恢复路径
	vv[i][j] = 0;
	tmp.pop_back();
}

int main(){
	while (cin >> row >> col){
		vv = vector<vector<int>>(row, vector<int>(col, 0));
		tmp.clear();
		ret.clear();
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				cin >> vv[i][j];
			}
		}
		track(0, 0);//从起始点(0,0)开始走
		//输出路径
		for (int i = 0; i < ret.size(); i++){
			cout << "(" << ret[i][0] << "," << ret[i][1] << ")" << endl;
		}
	}
	return 0;
}
