class Solution {
public:
    void merge(int nums1[], int m, int nums2[], int n) {
        int pos=m+n-1;
        m--;
        n--;
        while(m>=0&&n>=0){
            if(nums1[m]>nums2[n]){
                nums1[pos--]=nums1[m--];
            }else{
                nums1[pos--]=nums2[n--];
            }
        }
        while(n>=0){
            nums1[pos--]=nums2[n--];
        }
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprofit=0;
        for(auto i:prices){
            maxprofit=max(maxprofit,i-minprice);
            minprice=min(minprice,i);
        }
        return maxprofit;
    }
};



class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> nums) {
        int result=nums[0];
        int times=1;
        for(int i=1;i<nums.size();i++){
            if(times!=0){
                if(nums[i]==result){
                    times++;
                }else{
                    times--;
                }
            }else{
                result=nums[i];
                times=1;
            }
        }
        int count=0;
        for(auto i:nums){
            if(result==i){
                count++;
            }
        }
        return count>nums.size()/2?result:0;
    }
};

NC73数组中出现次数超过一半的数字https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=190&&tqId=35371&rp=1&ru=/ta/job-code-high-rd&qru=/ta/job-code-high-rd/question-ranking

//数组中出现次数超过一半的数字
//众数非众数/守阵地
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> nums) {
        int result=nums[0];
        int times=1;
        //不能用范围for-i从1开始
        for(int i=1;i<nums.size();i++){
            if(times==0){
                result=nums[i];
                times=1;
            }else{
                if(nums[i]==result){
                    times++;
                }else{
                    times--;
                }
            }
        }
        int count=0;
        for(auto i:nums){
            if(result==i){
                count++;
            }
        }
        return count>nums.size()/2?result:0;
    }
};


class Solution {
public:
    int getmax(int a,int b){
        return a>b?a:b;
    }
    int FindGreatestSumOfSubArray(vector<int>nums) {
        int sum=nums[0];
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=getmax(sum+nums[i],nums[i]);
            if(sum>max){
                max=sum;
            }
        }
        return max;
    }
};




#include<iostream>
#include<vector>
using namespace std;
int getmax(int a,int b){
    return a>b?a:b;
}
int main(){
    int size;
    cin>>size;
    vector<int>nums(size);
    for(int i=0;i<size;i++){
        cin>>nums[i];
    }
    int sum=nums[0];
    int max=nums[0];
    for(int i=0;i<size;i++){
        sum=getmax(sum+nums[i],nums[i]);
        if(sum>max){
            max=sum;
        }
    }
    cout<<max<<endl;
    return 0;
}


//解题思路
//原地旋转不能使用额外数组
//1.先按层下上翻转
//2.再翻对角线翻转
class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        //两个两层for循环
        //1.按层上下翻转
        //for1-按层-i<n/2;
        //for2-j<n;
        //(i,j)-(n-1-i,j);
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(mat[i][j],mat[n-1-i][j]);
            }
        }
        //2.按对角线翻转
        //for1-i<n
        //for2-j<i
        //(i,j)-(j,i)
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        return mat;
    }
};


//螺旋矩阵-顺时针打印矩阵
//顺时针旋转矩阵
class Solution {
public:
    //解题思路
    //左上角坐标(0,0)
    //右下标坐标(row-1,col-1)
    //先顺时针打印这个矩阵边上的元素
    //缩小矩阵
    //再次顺时针打印一直缩小到矩阵为空
    vector<int> spiralOrder(vector<vector<int> > &mat) {
        vector<int>v;
        int row=mat.size();
        int col=mat[0].size();
        int x1=0;
        int y1=0;
        int x2=row-1;
        int y2=col-1;
        //控制条件<=
        while(x1<=x2&&y1<=y2){
            //从左往右
            for(int j=y1;j<=y2;j++){
                v.push_back(mat[x1][j]);
            }
            //从上往下-上面是<=这里就是<-不然会重复打印
            for(int i=x1+1;i<x2;i++){
                v.push_back(mat[i][y2]);
            }
            //从右往左
            for(int j=y2;j>=y1&&x1<x2;j--){
                v.push_back(mat[x2][j]);
            }
            //从下往上-上面是>=这里就是>
            for(int i=x2-1;i>x1&&y1<y2;i--){
                v.push_back(mat[i][y1]);
            }
            x1++;
            x2--;
            y1++;
            y2--;
        }
        return v;
    }
};