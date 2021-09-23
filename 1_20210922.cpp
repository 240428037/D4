#include<iostream>
using namespace std;
int path(int m,int n){
    if(m==0||n==0){
        return 1;
    }
    return path(m-1,n)+path(m,n-1);
}
int main(){
    int row,col;
    while(cin>>row>>col){
        cout<<path(row,col)<<endl;
    }
    return 0;
}


//贪心+动规
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>>vv(row,vector<int>(col,0));
        vv[0][0]=board[0][0];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0&&j==0){
                    continue;
                }else if(i==0){
                    vv[i][j]=vv[i][j-1]+board[i][j];
                }else if(j==0){
                    vv[i][j]=vv[i-1][j]+board[i][j];
                }else{
                    vv[i][j]=max(vv[i-1][j],vv[i][j-1])+board[i][j];
                }
            }
        }
        return vv[row-1][col-1];
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>&board) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>>vv(row,vector<int>(col,0));
        vv[0][0]=board[0][0];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0&&j==0){
                    continue;
                }else if(i==0){
                    vv[i][j]=vv[i][j-1]+board[i][j];
                }else if(j==0){
                    vv[i][j]=vv[i-1][j]+board[i][j];
                }else{
                    vv[i][j]=min(vv[i-1][j],vv[i][j-1])+board[i][j];
                }
            }
        }
        return vv[row-1][col-1];
    }
};


//贪心+动规
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>>vv(row,vector<int>(col,0));
        vv[0][0]=board[0][0];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0&&j==0){
                    continue;
                }else if(i==0){
                    vv[i][j]=vv[i][j-1]+board[i][j];
                }else if(j==0){
                    vv[i][j]=vv[i-1][j]+board[i][j];
                }else{
                    vv[i][j]=max(vv[i-1][j],vv[i][j-1])+board[i][j];
                }
            }
        }
        return vv[row-1][col-1];
    }
};


class Board {
public:
    bool checkWon(vector<vector<int> > vv) {
        int row=vv.size();
        int col=vv[0].size();
        //行-行不变列变
        for(int i=0;i<row;i++){
            int sum=0;
            for(int j=0;j<col;j++){
                sum+=vv[i][j];
            }
            if(sum==col){
                return true;
            }
        }
        //列-列不变行变
        for(int i=0;i<col;i++){
            int sum=0;
            for(int j=0;j<row;j++){
                sum+=vv[j][i];
            }
            if(sum==row){
                return true;
            }
        }
        //正斜-从左上角到右下角
        int sum=0;
        for(int i=0;i<row;i++){
            sum+=vv[i][i];
            if(sum==row){
                return true;
            }
        }
        //副斜-从左下角到右上角
        sum=0;
        for(int i=0;i<row;i++){
            sum+=vv[i][col-1-i];
            if(sum==row){
                return true;
            }
        }
        return false;
    }
};


class Board {
public:
    bool checkWon(vector<vector<int>>board) {
        int row=board.size();
        int col=board[0].size();
        //行-行不变列变
        for(int i=0;i<row;i++){
            int sum=0;
            for(int j=0;j<col;j++){
                sum+=board[i][j];
            }
            if(sum==col){
                return true;
            }
        }
        //列-列不变行变
        for(int i=0;i<col;i++){
            int sum=0;
            for(int j=0;j<row;j++){
                sum+=board[j][i];
            }
            if(sum==row){
                return true;
            }
        }
        //正斜-左上角->右下角
        int sum=0;
        for(int i=0;i<row;i++){
            sum+=board[i][i];
            if(sum==row){
                return true;
            }
        }
        //副斜-左下角->右上角
        sum=0;
        for(int i=0;i<row;i++){
            sum+=board[i][col-1-i];
            if(sum==row){
                return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //从左下角开始找
        //(array.size()-1,0)
        int i=array.size()-1;
        int j=0;
        while(i>=0&&j<array[0].size()){
            if(array[i][j]<target){
                j++;
            }else if(array[i][j]>target){
                i--;
            }else if(array[i][j]==target){
                return true;
            }
        }
        return false;
    }
};