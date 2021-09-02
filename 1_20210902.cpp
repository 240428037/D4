#include<iostream>
#include<vector>
using namespace std;


int row;
int col;
vector<vector<int>>vv;
vector<vector<int>>tmp;
vector<vector<int>>best;


void trace(int i,int j){
    vv[i][j]=1;
    tmp.push_back({i,j});
    if(i==row-1&&j==col-1){
        if(best.empty()||tmp.size()<best.size()){
            best=tmp;
        }
    }
    if(j+1<col&&vv[i][j+1]==0){
        trace(i,j+1);
    }
    if(j-1>=0&&vv[i][j-1]==0){
        trace(i,j-1);
    }
    if(i-1>=0&&vv[i-1][j]==0){
        trace(i-1,j);
    }
    if(i+1<row&&vv[i+1][j]==0){
        trace(i+1,j);
    }
    //回溯
    vv[i][j]=0;
    tmp.pop_back();
}


int main(){
    while(cin>>row>>col){
        vv=vector<vector<int>>(row,vector<int>(col,0));
        tmp.clear();
        best.clear();
        for(int i=0;i<vv.size();i++){
            for(int j=0;j<vv[0].size();j++){
                cin>>vv[i][j];
            }
        }
        trace(0,0);
        for(int i=0;i<best.size();i++){
            cout<<"("<<best[i][0]<<","<<best[i][1]<<")"<<endl;
        }
    }
    return 0;
}