#include <bits/stdc++.h>
using namespace std;

void modrow(vector<vector<int>> &mat , int i ,int m){
    for(int k = 0; k < m; k++){
        if(mat[i][k] != 0){
            mat[i][k] = -1;
        }
    }
}

void modcol(vector<vector<int>> &mat , int j ,int n){
    for(int k = 0; k < n; k++){
        if(mat[k][j] != 0){
            mat[k][j] = -1;
        }
    }
}

void Zero(vector<vector<int>> &mat){

//BRUTE FORCE SOLUTION


/*
int n = mat.size();
int m = mat[0].size();
//BRUTE FORCE SOLUTION
for (int i = 0; i < n; i++)
{
    for(int j = 0;j < m; j++){
        if(mat[i][j] == 0){
            modrow(mat , i , m);
            modcol(mat , j, n);
        }
    }
}

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if(mat[i][j] == -1){
            mat[i][j] = 0;
        }
    }
    
}


*/

//BETTER SOLUTION

/*
int n = mat.size();
int m = mat[0].size();


vector<int> row;
vector<int> col;

for (int i = 0; i < n; i++)
{
    row.push_back(0);
}

for (int i = 0; i < m; i++)
{
    col.push_back(0);
}

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if(mat[i][j] == 0){
            row[i] = 1;
            col[j] = 1;
        }
    }
}

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if(row[i] == 1 || col[j] == 1){
            mat[i][j] = 0;
        }
    }
}




*/


    //OPTIMAL(BIT FUZZY)
    int n = mat.size();
    int m = mat[0].size();
    int col0 = 1; // Used to track for first col since 1st element is being used for 1st row


    //the column and row arrays are
    //int row = mat[..][0]
    //int col = mat[0][..]

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mat[i][j] == 0){
                mat[i][0] = 0;
                if(j != 0){
                    mat[0][j] = 0;
                }

                else{
                    col0 = 0; 
                }
            }
        }
            
    }


    for (int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++){
            if(mat[i][j] != 0){
                if(mat[0][j] == 0 || mat[i][0] == 0){
                    mat[i][j] = 0;
                }
            }
        }
    }
    

    //Atlast we covert if possible for temp row and temp col of the matrix
    if(mat[0][0] == 0){
        for(int i = 1; i < m; i++){
            mat[0][i] = 0;
        }
    }
    
    if(col0 == 0){
        for(int i = 0; i < n; i++){
            mat[i][0] = 0;
        }
    }
    

}

int main(){
    vector<vector<int>> mat = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }

        cout <<"\n";
    }
    
    Zero(mat);

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            cout << mat[i][j] << " ";
        }

        cout <<"\n";
    }
}