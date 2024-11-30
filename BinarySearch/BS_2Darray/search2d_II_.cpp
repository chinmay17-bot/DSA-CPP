#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size()-1;

        int row = 0;
        int col = cols;
        while(row < rows && col >= 0){
            int ele = matrix[row][col];

            if(ele == target) return true;

            if(ele > target){
                col--;
            }

            else{
                row++;
            }
        }
        return false;
    }

int main(){
    
}