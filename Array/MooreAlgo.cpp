#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int cnt = 0;
    vector<int> nums = {2,2,1,1,1,2,2};
    int n = nums.size();

    //BRUTE FORCE



        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     cnt = 0;
        //     for(int j = 0; j < n; j++){
        //         if(nums[i] == nums[j]){
        //             cnt++;
        //             cout << cnt << "\n";
        //         }
        //     }
        //     if(cnt > (n/2)){
        //         ans = nums[i];
        //     }
        // }
        // cout << ans;


//MOST OPTIMAL SOLUTION MOORE VOTING ALGORITHM revise FOR WORKING IMP


        int cnt = 0;
        int el;
        for (int i = 0; i < n; i++)
        {
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }

            else if(nums[i] == el){
                cnt++;
            }

            else{
                cnt--;
            }
        }

        //COUNT THE MAJORITY ELEMENT

        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == el){
                cnt1++;
            }
        }

        if(cnt1 > (n/2)){
            cout << el;
        }
        
        
}