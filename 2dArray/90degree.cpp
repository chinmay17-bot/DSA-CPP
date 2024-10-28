#include <bits/stdc++.h>
using namespace std;
 
void rotate(vector<vector<int>> &mat , int n, int m){
    //BRUTE FORCE
    //BUT WE NEED TO OPTIMISE IT USING CONSTANT SPACE (IN PLACE)

    /*
    int ans[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";   
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans[j][n-1-i] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";   
    }
    
    */


   //OPTIMAL SOLUTION

   //TRANSPOSE THEN REVERSE EACH ROW SIMPLE

    int i = 0;

    while(i < n-1){
        int j = i+1;
        while(j < m){
            swap(mat[i][j] , mat[j][i]);
            j++;
        }

        i++;
    }
    i = 0;
    int end = n;

    while (i < end)
    {   
        int strtcol = 0; 
        int endcol = m-1;
        while(strtcol <= endcol){
            swap(mat[i][strtcol] , mat[i][endcol]);
            strtcol++;
            endcol--;
        }
        i++;
    }
    
}

int main(){
    vector<vector<int>> mat = {{0,1,2,0},{3,4,5,2},{1,3,1,5},{2,7,1,3}};
    

    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";   
    }
    rotate(mat , n , m);

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";   
    }
}