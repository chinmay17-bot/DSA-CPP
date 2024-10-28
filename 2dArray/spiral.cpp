#include <bits/stdc++.h>
using namespace std;

void printSpiral(vector<vector<int>> &mat){
    vector<int> ans;

    int top = 0;
    int left = 0;

    int bottom = mat.size()-1;
    int right = mat[0].size()-1;

    while (top <= bottom && left <= right)
    {

        //to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;

        //to bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }

        right--;
        
        //to left
        if(top <= bottom){
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }

            bottom--;   
        }

        //to top
        if(left <= right){
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }

            left++;
            
        }
                
    }

    for(auto it: ans){
        cout << it << " ";
    }
    
}
 
int main(){
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printSpiral(mat);
}