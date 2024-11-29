#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &mat , int path ,int row , int col , int &ans){
    
    if(row == mat.size()) return  path;

    int left = minPathSum(mat , path+mat[row][col] , row+1 , col , ans);
    int right = minPathSum(mat , path+mat[row][col] , row+1 , col+1 , ans);

    ans = min(left , right);

    return ans;
}

int main(){
    
}


