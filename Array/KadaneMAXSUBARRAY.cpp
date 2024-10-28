#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE IS --> FIND ALL SUBARRAY AND ANOTHER LOOP FOR SUM O(N3) 
//BETTER SOL (TLE)

/*
 int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int j = i;
            sum = 0;
            while(j < n){
                sum+=nums[j];
                mx = max(mx , sum);
                j++;
            }
        }

        return mx;
    }
*/


int maxSubArray(vector<int>& nums) {
    long long sum = 0;
        long long mx = LONG_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
            mx = max(mx , sum);

            if(sum < 0){
                sum = 0;
            }
        }
        return mx;  
}
 
int main(){
    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};
    cout <<  maxSubArray(arr);
}