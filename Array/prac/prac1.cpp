#include <bits/stdc++.h>
using namespace std;

//union

void un(vector<int> &arr1 , vector<int> &arr2){
    int i = 0;
    int j = 0;
    vector<int> ans;

    int n = arr1.size();
    int m = arr2.size();
    cout << ans.back();
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(ans.size() == 0 || ans.back() != arr1[i] ){

                ans.push_back(arr1[i]);
            }
            i++;
        }


        else{
            if(ans.size() == 0 || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    } 

    while (i < n)
    {
        if(ans.back() != arr1[i] || ans.size() == 0){
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if(ans.back() != arr2[j] || ans.size() == 0){
            ans.push_back(arr2[j]);
        }
        j++;
    }

    for(auto it: ans){
        cout << it << " ";
    }
    
    
}

void longestSub(){
    vector<int> arr = {2,3,5,1,9};
    int k = 10;
    int sum,rem;
    int len = 0;
    unordered_map<int , int> prefixSum;


    for(int i = 0; i < arr.size(); i++){
        sum+= arr[i];

        if(sum == k){
            len = max(len , i+1);
        }

        rem = sum - k;

        if(prefixSum.find(rem) != prefixSum.end()){
            len = max(len , (i - prefixSum[rem]+1));
        }
        if(prefixSum.find(sum) == prefixSum.end()){
            prefixSum[sum] = i;
        }
    }

    cout << len;

}


//2sum
vector<int> _2sum(vector<int> &arr , int k){
    int n = arr.size();
    map<int , int> mp;

    for(int i = 0; i < n; i++){
        int rem = k-arr[i];
        if(mp.find(rem) != mp.end()){
            return {mp[rem] , i};
        }
        mp[arr[i]] = i;
    }

    return {-1,-1};
}
 
int main(){
    // vector<int> arr1 = {1,1,2,3,4,5};
    // vector<int> arr2 = {2,3,4,4,5,6};

    // un(arr1 , arr2);
    // longestSub();
    vector<int> arr1 = {2,6,5,8,11};
    vector<int> ans = _2sum(arr1 , 14);

    cout << ans[0] << ans[1];
}