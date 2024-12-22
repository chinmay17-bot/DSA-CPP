#include <bits/stdc++.h>
using namespace std;
 
void validArrangement(vector<vector<int>>&res ,vector<int>& nums ,int j ){
        if(j  >= nums.size()){
            res.push_back(nums);
            return;
        }
        

        map<int , bool>mp;
        for(int i = j; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()) continue;

            mp[nums[i]] = true;
            swap(nums[i] , nums[j]);
            validArrangement(res , nums , j+1 );
            swap(nums[i] , nums[j]);
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        

        validArrangement(res ,nums , 0);

        // vector<vector<int>> ans (res.begin() , res.end());

        return res;

    }

int main(){
    
}