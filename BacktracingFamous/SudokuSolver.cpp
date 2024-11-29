#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board , char num, int row, int col){
    
    //3*3 matrix Rule
    for(int i = 0; i < board.size(); i++){
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num) return false;
    }


    //Row rule
    for (int i = 0; i < board.size(); i++)
    {
        if(board[row][i] == num) return false;


    }

    

    //Col rule
    for (int i = 0; i < board.size(); i++)
    {
        if(board[i][col] == num) return false;
    }

    
    return true;
}

bool recursiveCall(vector<vector<char>> &board ){

    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){

            //find where we have to add data
            if(board[i][j] == '.'){


                //now loop for what number we can put
                for(char k = '1'; k <= '9'; k++){


                    if(isSafe(board , k , i , j) == true){

                        //set current value to see
                        board[i][j] = k;

                        //bool for if that number is possible for further solution 
                        bool canSolve = recursiveCall(board);
                        if(canSolve == true){
                            return true;
                        }

                        //backtracking to prev state that it was not possible for
                        else{
                            board[i][j] = '.';
                        }
                    }
                }


                //if no number was possilbe to put then
                return false;

            }
        }
    }

    //as complete iteration is done for the sub problem
    return true;
}
 
void sudokuSolver(vector<vector<char>> &board){
    recursiveCall(board);
}

int main(){
    
}