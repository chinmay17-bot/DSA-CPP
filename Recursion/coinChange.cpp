#include <bits/stdc++.h>
using namespace std;
 
int coinChange(vector<int> &arr , int amt){

    if(amt == 0){
        return 0;
    }

    int ans = INT_MAX;

    for(int i = 0; i < arr.size(); i++){
        int coin = arr[i];

        if(coin <= amt){
            int rec = coinChange(arr , amt - coin);
            if(rec != INT_MAX){
                int cnt = 1+rec;
                ans = min(cnt , ans);
            }
        }
    }

    return ans;
}


int main(){

    vector<int> arr = {1,2,5};

    int amt = 11;

    int ans = coinChange(arr , 11);
    if(ans == INT_MAX) cout <<  -1;

    cout <<  ans;
    
}