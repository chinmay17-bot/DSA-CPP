#include <bits/stdc++.h>
using namespace std;

bool bsOn2Darray(vector<vector<int>> &mat){
    //basic solution is take each row and do bs on that
    //t.f. O(N)+O(LogN)
    
    
    //
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()*matrix[0].size() - 1;
        int c = matrix[0].size();

        while(low <= high){

            int midi = (low+high) / 2;
            
            
            //MAIN LOGIC
            int mid = matrix[midi/c][midi%c];

            if(mid == target) return true;

            if(mid < target){
                low = (midi+1);
            }
            else{
                high = midi-1;
            }

        }

        return false;
    }
 
int main(){
    
}