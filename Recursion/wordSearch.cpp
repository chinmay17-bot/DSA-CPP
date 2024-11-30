#include <bits/stdc++.h>
using namespace std;


bool solve(vector<vector<char>>& board ,int row , int col , string& word , int index){
       
       //this shows that we found our word
       if(index == word.size()) return true;
       //this for base cases
       //we check for visited by same data structure by marking it % as it is not in the input 
       if(row >= board.size() || col >= board[0].size() || board[row][col] != word[index] || row < 0 || col < 0){
           return false;
       }
       char revert = board[row][col];
       board[row][col] ='%';


       // 4 directions to move 
       bool up = solve(board , row-1 , col , word , index+1);
       bool right = solve(board , row , col+1 , word , index+1);
       bool down = solve(board , row+1 , col , word , index+1);
       bool left = solve(board , row , col-1 , word , index+1);

       //backtrack
       board[row][col] = revert;

       
       return (up || down || right || left);
   }

bool exist(vector<vector<char>>& board, string word) {

    //we do a loop to check for all cells as word can be anywhere 
    for(int i= 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(solve(board , i , j , word , 0)){
                return true;
            }
        }
    }
    return false;
}
 
int main(){
    
}