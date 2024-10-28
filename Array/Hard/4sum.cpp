#include <bits/stdc++.h>
using namespace std;

void _4sum(vector<int> nums , int target){
    //BRUTE FORCE IS FORMING ALL QUADS


    //BETTER SOLUTION USING HASHSET OR HASHMAP CAN ALSO BE USED

    /*
    int i = 0;
    int j = i+1;
    int k = i+2;
    int n = nums.size();
    set<vector<int>> ans;
    for(i = 0; i < n; i ++){
        for(j = i+1; j < n; j++){
            set<long long> num;
            for(k = j+1; k < n; k++){
                long long sum = nums[i]+nums[j];
                sum+=nums[k];
                long long diff = target-(sum);
                if(num.find(diff) != num.end()){
                    vector<int> temp = {nums[i] , nums[j] , nums[k] , (int )diff};
                    sort(temp.begin() , temp.end());
                    ans.insert(temp);
                }
                num.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> res(ans.begin() , ans.end());
    */



   //OPTIMAL SOLUTION
   sort(nums.begin(), nums.end());
   int n = nums.size();
   set<vector<int>> ans;

   for (int i = 0; i < n; i++)
   {
    //TO AVOID DUPLICATE QUAD DURING OPERATION
    if(i > 0 && nums[i] == nums[i-1]) continue;

    for(int j = i+1; j < n; j++){

        //THIS CONDITION IS ALSO IMPORTANT TO AVOID j!=i+1 TO AVOID SAME QUADS AS nums[i],nums[j] is a 
        // FIRST PAIR AND HAS TO BE TAKEN IF THIS PAIR REPEAT THAN SKIP
        if(j != i+1 && nums[j] == nums[j-1]) continue;

        int k = j+1;
        int l = n-1;

        while(k < l){
            long long sum = nums[i];
            sum+=nums[j];
            sum+=nums[k];
            sum+=nums[l];

            if(sum > target){
                l--;

            }

            else if(sum < target){
                k++;
            }

            else{
                vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                ans.insert(temp);
                k++;
                l--;

                while(k < l && nums[k] == nums[k-1]) k++;                 
                while(k < l && nums[l] == nums[l+1]) l--;

            }
        }    
    }

   }
    vector<vector<int>> res (ans.begin() , ans.end());
    
   
}
 
int main(){   
    vector<int> arr = {1,0,-1,0,-2,2};
    _4sum(arr,0);
}