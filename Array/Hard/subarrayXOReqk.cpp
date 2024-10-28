#include <bits/stdc++.h>
using namespace std;

void xork(vector<int> arr , int k){
    
    
    //OPTIMAL SOLUTION
    int xr = 0;
    int cnt = 0 ;

    map<int , int> mp;
    mp.insert({0,1});
    for(int i = 0; i < arr.size(); i++){
        xr = xr^arr[i];
        int x = xr^k;

        cnt+=mp[x];

        mp[xr]++;

    }

    cout << cnt;
}

int main(){
   vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    xork(a , k);
}