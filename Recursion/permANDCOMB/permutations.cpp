#include <bits/stdc++.h>
using namespace std;

void validArrangement(vector<vector<int>>&res ,vector<int>& nums ,int j ){
        if(j  >= nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = j; i < nums.size(); i++){

            swap(nums[i] , nums[j]);
            validArrangement(res , nums , j+1 );
            swap(nums[i] , nums[j]);
        }
    }


    vector<vector<int>> allPermut(vector<int>& nums) {
        vector<vector<int>> res;
        

        validArrangement(res ,nums , 0);

        

        return res;

    }
 
int main(){
    
}