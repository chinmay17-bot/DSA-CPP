#include <bits/stdc++.h>
using namespace std;

int jobCount(vector<int> &arr , int jobLimit){
    int cnt = 0;
    int grpCnt = 1;

    for(int i = 0; i < arr.size(); i++){
        if(cnt + arr[i] > jobLimit){
            grpCnt++;
            cnt = arr[i];
        }

        else{
            cnt += arr[i];
        }
    }

    return grpCnt;
}

int paintersProblem(vector<int> &nums , int k){
    //BRUTE FORCE 
    // int strt = *max_element(nums.begin() , nums.end());
    // int sum = accumulate(nums.begin() , nums.end() , 0);
    
    // for(int i = strt; i < sum; i++){
    //     if(jobCount(nums , i) <= k) return i;
    // }
    // return sum;

    //OPTIMAL 
    int strt = *max_element(nums.begin() , nums.end());
    int sum = accumulate(nums.begin() , nums.end() , 0);
    int low = strt;
    int high = sum;
    // for(int i = strt; i < sum; i++){
    while(low <= high){
        int mid = (low + high)/2;
        if(jobCount(nums , mid) <= k) high = mid-1;
        else low = mid+1;
    }
    return low;
}


 
int main(){
    
}