#include <bits/stdc++.h>
using namespace std;
 
int longestSubArraySum0(vector<int> arr){
    map<int , int> prefixSum;
    int sum = 0;
    int len = 0;
    for(int i = 0; i < arr.size(); i++){
        if(sum == 0){
            len = max(len , i);
        } 
        else if(prefixSum.find(sum) != prefixSum.end()){
            len = max(len , (i-prefixSum[sum]));
        }

        else{
            prefixSum.insert({sum , i});
        }

        sum += arr[i];
    }

    return len;
}

int main(){
    
}