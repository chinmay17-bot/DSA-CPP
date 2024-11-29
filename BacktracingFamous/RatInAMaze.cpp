#include <bits/stdc++.h>
using namespace std;
 
bool validity(int srcx , int srcy , int destx , int desty , vector<vector<int>> &mat ,vector<vector<bool>> &visited){

        //For out of bounds   
        if(srcx < 0 || srcy < 0 || srcx > destx || srcy > desty){
            return false;
        }

        //if blocked
        if(mat[srcx][srcy] == 0){
            return false;
        }
        
        //if already
        if(visited[srcx][srcy] == true){
            return false;
        }
        
        return true;
    }
  
    
void pathFinder(vector<vector<int>> &mat , vector<vector<bool>> &visited , int srcx , int srcy , int destx , int desty , vector<string> &ans , string out){

    if(srcx == destx && srcy == desty){
        ans.push_back(out);
        return;
    }
    
    //to upper
    int nxtx = srcx-1;
    int nxty = srcy;
    
    if(validity(nxtx , nxty , destx , desty , mat , visited)){

        //Set visited for this call
        visited[nxtx][nxty] = true;
        pathFinder(mat , visited , nxtx , nxty , destx , desty , ans , out+"U");
        
        //reset visited for backtracing 
        visited[nxtx][nxty] = false;
    }
    
    //to right
    nxtx = srcx;
    nxty = srcy+1;
    
    if(validity(nxtx , nxty , destx , desty , mat , visited)){
        visited[nxtx][nxty] = true;
        pathFinder(mat , visited , nxtx , nxty , destx , desty , ans , out+"R");
        visited[nxtx][nxty] = false;
    }
    
    //to down
    nxtx = srcx+1;
    nxty = srcy;
    
    if(validity(nxtx , nxty , destx , desty , mat , visited)){
        visited[nxtx][nxty] = true;
        pathFinder(mat , visited , nxtx , nxty , destx , desty , ans , out+"D");
        visited[nxtx][nxty] = false;
    }
    
    //to left
    nxtx = srcx;
    nxty = srcy-1;
    
    if(validity(nxtx , nxty , destx , desty , mat , visited)){
        visited[nxtx][nxty] = true;
        pathFinder(mat , visited , nxtx , nxty , destx , desty , ans , out+"L");
        visited[nxtx][nxty] = false;
    }

    
}

vector<string> findPath(vector<vector<int>> &mat) {
   // code here
   
   int i = 0;
   int j = 0;
   int n = mat.size();
   vector<vector<bool>> visited( n , vector<bool>(n,0));
   

   //First position is already visited
   visited[0][0] = true;
   vector<string> ans;
   string out = "";
   
   int destx = n-1;
   int desty = n-1;
   
   if(mat[0][0] == 0) return ans;
   
   pathFinder(mat , visited , i , j , destx , desty , ans , out);
   
   return ans;
} 
int main(){

}