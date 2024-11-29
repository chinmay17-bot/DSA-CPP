#include <bits/stdc++.h>
using namespace std;



//very complex do watch vod (recursion marathon)
 
int square(vector<vector<char>>& matrix , int i , int j,int row ,int col , int &maxi){
    if(j >= col || i >= row) return 0;

        int right = square(matrix , i , j+1 ,row , col,maxi);
        int diag = square(matrix , i+1 , j+1,row , col ,maxi);
        int down = square(matrix , i+1 , j,row , col ,maxi);

        if(matrix[i][j] == '1'){

            int ans = 1 + min(right , min(diag , down));

            maxi = max(ans , maxi);
            return ans;  
        }
        else {
            return 0;
        }

}

int main(){
    
}