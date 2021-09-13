class Solution {
public:
    //位运算,利用^的性质
    //相同为0，相异为1
    //1.两个相同的数字^结果为0
    //2.0和任何数字^结果仍为那个数
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        //遍历数组，用val=0和每一个元素^，val=num1^num2;
        int val=0;
        for(auto e:array){
            val^=e;
        }
        //val二进制位中的1要么是num1的要么是num2的
        //用i标记val的二进制位从右往左哪一位第一次出现1找到break
        int i=0;
        for(;i<32;i++){
            if(val&(1<<i)){
                break;
            }
        }
        //为1的第i要么是num1的要么是num2的
        //分组异或
        int num1=0;
        int num2=0;
        for(auto e:array){
            if(e&(1<<i)){
                num1^=e;
            }else{
                num2^=e;
            }
        }
        //处理小的在前大的在后这个条件
        int val1=num1>num2?num2:num1;
        int val2=num1>num2?num1:num2;
        vector<int>v;
        v.push_back(val1);
        v.push_back(val2);
        return v;
    }
};


#include<iostream>
using namespace std;
class A{
publicL:
    virtual ~A(){cout<<"~A()"<<endl;}
}
class B:public A{
public:
    ~B(){cout<<"~B()"<<endl;}
}
int main(){
    A*p=new B;
    delete p;
    return 0;
}


//解题思路
//左右指针
class Solution {
public:
    string solve(string str) {
        int left=0;
        int right=str.size()-1;
        while(left<right){
            swap(str[left++],str[right--]);
        }
        return str;
    }
};


//解题思路
//先翻转整个字符串-再逐个翻转每个单词
class Solution {
public:
    string ReverseSentence(string str) {
        //先翻转整个字符串
        reverse(str.begin(),str.end());
        auto left=str.begin();
        while(left!=str.end()){
            auto right=left;
            while(right!=str.end()&&*right!=' '){
                right++;
            }
            //逐个翻转单词
            reverse(left,right);
            //迭代
            if(right!=str.end()){
                left=right+1;
            }else{
                left=right;
            }
        }
        return str;
    }
};


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    reverse(str.begin(),str.end());
    auto left=str.begin();
    while(left!=str.end()){
        auto right=left;
        while(right!=str.end()&&*right!=' '){
            right++;
        }
        reverse(left,right);
        if(right!=str.end()){
            left=right+1;
        }else{
            left=right;
        }
    }
    cout<<str<<endl;
    return 0;
}




//翻转单词序列-接口型
//先翻转整个字符串-再双指针逐个翻转每个单词
//双指针-迭代器
class Solution {
public:
    string ReverseSentence(string str) {
        //先翻转整个字符串
        reverse(str.begin(),str.end());
        auto left=str.begin();
        while(left!=str.end()){
            auto right=left;
            while(right!=str.end()&&*right!=' '){
                right++;
            }
            //再逐个翻转单词
            reverse(left,right);
            //迭代
            if(right!=str.end()){
                left=right+1;
            }else{
                left=right;
            }
        }
        return str;
    }
};

//翻转单词序列-ACM模式
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    //
    reverse(str.begin(),str.end());
    auto left=str.begin();
    while(left!=str.end()){
        auto right=left;
        while(right!=str.end()&&*right!=' '){
            right++;
        }
        reverse(left,right);
        if(right!=str.end()){
            left=right+1;
        }else{
            left=right;
        }
    }
    //
    cout<<str<<endl;
    return 0;
}






##


//翻转字符串
//双指针翻转-左右指针
class Solution {
public:
    string solve(string str) {
        int left=0;
        int right=str.size()-1;
        while(left<right){
            swap(str[left++],str[right--]);
        }
        return str;
    }
};

//翻转单词序列-接口型
//先翻转整个字符串-再双指针逐个翻转每个单词
//双指针-迭代器
class Solution {
public:
    string ReverseSentence(string str) {
        //先翻转整个字符串
        reverse(str.begin(),str.end());
        auto left=str.begin();
        while(left!=str.end()){
            auto right=left;
            while(right!=str.end()&&*right!=' '){
                right++;
            }
            //再逐个翻转单词
            reverse(left,right);
            //迭代
            if(right!=str.end()){
                left=right+1;
            }else{
                left=right;
            }
        }
        return str;
    }
};

//翻转单词序列-ACM模式
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    //
    reverse(str.begin(),str.end());
    auto left=str.begin();
    while(left!=str.end()){
        auto right=left;
        while(right!=str.end()&&*right!=' '){
            right++;
        }
        reverse(left,right);
        if(right!=str.end()){
            left=right+1;
        }else{
            left=right;
        }
    }
    //
    cout<<str<<endl;
    return 0;
}



//翻转字符串
class Solution {
public:
    string solve(string str) {
        int left=0;
        int right=str.size()-1;
        while(left<right){
            swap(str[left++],str[right--]);
        }
        return str;
    }
};
class Solution {
public:
    string solve(string str) {
        reverse(str.begin(),str.end());
        return str;
    }
};



//翻转单词序列-接口型
//先翻转整个字符串-再双指针逐个翻转每个单词
//双指针-迭代器
class Solution {
public:
    string ReverseSentence(string str) {
        //先翻转整个字符串
        reverse(str.begin(),str.end());
        auto left=str.begin();
        while(left!=str.end()){
            auto right=left;
            while(right!=str.end()&&*right!=' '){
                right++;
            }
            //再逐个翻转单词
            reverse(left,right);
            //迭代
            if(right!=str.end()){
                left=right+1;
            }else{
                left=right;
            }
        }
        return str;
    }
};

//翻转单词序列-ACM模式
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    //
    reverse(str.begin(),str.end());
    auto left=str.begin();
    while(left!=str.end()){
        auto right=left;
        while(right!=str.end()&&*right!=' '){
            right++;
        }
        reverse(left,right);
        if(right!=str.end()){
            left=right+1;
        }else{
            left=right;
        }
    }
    //
    cout<<str<<endl;
    return 0;
}