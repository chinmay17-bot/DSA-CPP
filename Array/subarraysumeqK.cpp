#include <bits/stdc++.h>
using namespace std;





//VERY SIMILAR QUESTION IN HARD SECTION NUMBER OF SUBARRAYS WITH XOR X 
void subArraySumK(vector<int> &nums , int k){

    //BETTER/BRUTE FORCE SOLUTION

        /*
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = nums[i];
            for(int j = i+1; j < n; j++){
                sum+=nums[j];
                if(sum == k){
                    cnt++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] == k){
                cnt++;
            }
        }
        cout << cnt;
        */

    //OPTIMAL SOLTUION USING MAPS
    unordered_map<int ,int> mp;
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        int rem = 0;
        mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum+=nums[i];
        rem = sum-k;
        cnt+=mp[rem];
        mp[sum]++;
    }
    
    cout << cnt; 
    
}

int main(){
    vector<int> arr = {1,2,1,2,1};
    int k = 3;
    subArraySumK(arr , k);
}