#include <bits/stdc++.h>
using namespace std;


unordered_map<int , bool>leftCol;
unordered_map<int , bool>udiag;
unordered_map<int , bool>ldiag;
 
   bool isValid(int row, int col){

    
    if(leftCol[row]) return false;

    if(udiag[row-col])return false;

    if(ldiag[row+col]) return false;

    return true;
}

void storeAns(vector<vector<string>> &res , vector<vector<char>> &str, int n ){
    vector<string> tempstrarr;
    for(int i = 0; i<n; i++){
        string tempstr = "";
        for(int j = 0; j<n ; j++){
            tempstr.push_back(str[i][j]);
        }

        tempstrarr.push_back(tempstr);
    }

    res.push_back(tempstrarr);
}

   void recursionCall(int n, vector<vector<char> > &str, vector<vector<string>> &res, int col ){

    if(col >= n){
        storeAns(res , str , n);
        return;
    }


    for(int i = 0; i < n; i++){
        if(isValid(i , col)){
            str[i][col] = 'Q';
            leftCol[i] = true;
            ldiag[i+col] = true;
            udiag[i-col] = true;
            recursionCall(n ,str , res , col+1);
            str[i][col] = '.';
            leftCol[i] = false;
            ldiag[i+col] = false;
            udiag[i-col] = false;
        }
    }

}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res ;
    vector<vector<char> > str(n, vector<char>(n,'.'));

    recursionCall(n , str ,res ,0);

    

    return res;
    }

int main(){
    solveNQueens(4);
}