#include <bits/stdc++.h>
using namespace std;

int subArrSum(vector<int> &arr){
    //BRUTE FORCE SOLUTION IS TO CHECK ALL SUBARRAYS
        


    //OPTIMAL SOLUTION
    map<int,int> prefixSum;
    int cnt = 0;
    int len = 0;
    int sum = 0;
    for(int i = 0;i < arr.size(); i++){
        // sum+=arr[i];
        if(sum == 0){
            len = max(len , i);
        }

        if(prefixSum.find(sum) != prefixSum.end()){
            len = max(i - prefixSum[sum] , len);
        }
        else{
            prefixSum.insert({sum , i});
        }
        sum+=arr[i];
    }

    return len;
}

int main(){
    vector<int> arr = {1, -1, 0, 0, 1};
    cout << subArrSum(arr);
}