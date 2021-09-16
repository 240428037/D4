class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(auto i:str){
            if(st.empty()){
                st.push(i);
            }else{
                if((i==')'&&st.top()=='(')
                  ||(i==']'&&st.top()=='[')
                  ||(i=='}'&&st.top()=='{')
                  ){
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }
        return st.empty();
    }
};


class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(auto i:str){
            //为空直接压栈
            if(st.empty()){
                st.push(i);
            //不为空则需要判断栈顶元素
            }else{
                //匹配则出栈
                //||分隔-满足一个条件就ok
                if((i==')'&&st.top()=='(')
                ||(i=='}'&&st.top()=='{')
                ||(i==']'&&st.top()=='[')){
                    st.pop();
                //不匹配则压栈
                }else{
                    st.push(i);
                }
            }
        }
        //为空-说明匹配-return true
        //不为空-说明不匹配-return false
        return st.empty();
    }
};


//双栈实现队列
class Solution
{
public:
    void push(int node) {
        st1.push(node);
    }
    int pop() {
        //st2为空-将st1中的数据全部拿过来
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        //st2不为空
        int ret=st2.top();
        st2.pop();
        return ret;
    }
private:
    stack<int> st1;//st1用来入队-辅助栈
    stack<int> st2;//st2用来出队
};

//双栈实现队列
class Solution
{
public:
    void push(int node) {
        st1.push(node);
    }
    int pop() {
        //st2为空-将st1中的数据全部拿过来
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        //st2不为空
        int ret=st2.top();
        st2.pop();
        return ret;
    }
private:
    stack<int> st1;//st1用来入队-辅助栈
    stack<int> st2;//st2用来出队
};



//解题思路
//双栈实现
//一个数据栈一个辅助栈
//辅助栈用来处理min
class Solution {
public:
    //st1&&st2
    void push(int value) {
        st1.push(value);
        if(st2.empty()||value<=st2.top()){
            st2.push(value);
        }
    }
    //st1&&st2
    void pop() {
        if(st2.top()==st1.top()){
            st2.pop();
        }
        st1.pop();
    }
    //st1
    int top() {
        return st1.top();
    }
    //st2
    int min() {
        return st2.top();
    }
private:
    stack<int>st1;//数据栈
    stack<int>st2;//辅助栈-min
};



class Solution {
public:
    void push(int value) {
        st1.push(value);
        if(st2.empty()||value<=st2.top()){
            st2.push(value);
        }
    }
    void pop() {
        if(st2.top()==st1.top()){
            st2.pop();
        }
        st1.pop();
    }
    int top() {
        return st1.top();
    }
    int min() {
        return st2.top();
    }
private:
    stack<int>st1;//all
    stack<int>st2;//min
};


class MyStack {
public:
    queue<int>q1;
    queue<int>q2;//辅助栈
    MyStack(){}
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    int pop() {
        int ret=q1.front();
        q1.pop();
        return ret;
    }
    int top() {
        int ret=q1.front();
        return ret;
    }
    bool empty() {
        return q1.empty();
    }
};


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int>st;
        int i=0;
        for(auto&e:pushV){
            st.push(e);
            while(!st.empty()&&st.top()==popV[i]){
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
//解题思路
//从尾到头
//stack先进后出
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>v;
        stack<ListNode*>st;
        ListNode*cur=head;
        while(cur){
            st.push(cur);
            cur=cur->next;
        }
        while(!st.empty()){
            cur=st.top();
            st.pop();
            v.push_back(cur->val);
        }
        return v;
    }
};


class Parenthesis {
public:
    bool chkParenthesis(string str, int n) {
        stack<char>st;
        for(auto i:str){
            if(st.empty()){
                st.push(i);
            }else{
                if(i==')'&&st.top()=='('){
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }
        return st.empty();
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        vector<string> strs;
        string res = "", tmp = "";
        while(getline(is, tmp, '/')) {
            if(tmp == "" || tmp == ".")
                continue;
            else if(tmp == ".." && !strs.empty())
                strs.pop_back();
            else if(tmp != "..")
                strs.push_back(tmp);
        }
        for(string str:strs) 
            res +=  "/" + str;
        if(res.empty())
            return "/";
        return res;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> strs;
        strs.reserve(20);
        string curr;
        while (getline(ss, curr, '/'))
        {
            if (curr != "." && curr != "")
            {
                if (curr != "..")
                {
                    strs.push_back(curr);
                }
                else if (!strs.empty())
                {
                    strs.pop_back();
                }
            }
        }

        if (!strs.empty())
        {
            string res = "";
            for (string str : strs)
            {
                res.append("/");
                res.append(str);
            }
            return res;
        }
        else
        {
            // 为空，直接返回 "/"
            return "/";
        }
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string dir;
        for (auto c : path) {
            // 以 / 为分隔符
            if (c == '/') {
                // 切换上一集目录
                if (dir == ".." && !st.empty()) {
                    st.pop();
                } 
                // 上一个 '/' 到 下一个 '/'
                else if (dir != ".." && dir != "." && !dir.empty()) {
                    st.push(dir);
                }
                dir.clear();
            } else {
                dir += c;
            }
        }

        // 遍历栈
        string result;
        while (!st.empty()) {
            string s = st.top();
            st.pop();
            result = "/" + s + result;
        }
        if(result.empty()) result = "/";
        return result;
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string dir;
        for (auto c : path) {
            if (c == '/') {
                if (dir == ".." && !st.empty()) {
                    st.pop();
                } else if (dir != ".." && dir != "." && !dir.empty()) {
                    st.push(dir);
                }
                dir.clear();
            } else {
                dir += c;
            }
        }
        string res;
        while (!st.empty()) {
            auto t = st.top();
            st.pop();
            res += string(t.rbegin(), t.rend()) + "/";
        }
        reverse(res.begin(), res.end());
        if (res.empty()) res = "/";
        return res;
    }
};



class Solution {
public:
    string simplifyPath(string path) {
        path+="/";
        stack<string>st;
        string str;
        for(auto i:path){
            //
            if(i=='/'){
                //
                if(str==".."&&!st.empty()){
                    st.pop();
                //
                }else if(str!=".."&&str!="."&&!str.empty()){
                    st.push(str);
                }
                str.clear();
            }else{
                str+=i;
            }
        }
        string ret;
        while(!st.empty()){
            string s=st.top();
            st.pop();
            ret="/"+s+ret;
        }
        if(ret.empty()){
            ret="/";
        }
        return ret;
    }
};