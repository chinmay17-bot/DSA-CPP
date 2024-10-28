#include <bits/stdc++.h>
using namespace std;

int maxProdSubArray(vector<int> &arr ){

    //BRUTE FORCE
    // int n = arr.size();
    // int prod;
    // int maxi = INT_MIN;
    // for(int i = 0; i < n; i++){
    //     for(int j = i+1; j++){
    //         prod = arr[i];
    //         for(int k = i+1; k <= j; k++){
    //             prod *= arr[k];
    //         }
    //         maxi = max(maxi , prod);
    //     }
    // }

    // return maxi;

    //BETTER USE 2 LOOPS

    
    //OPTIMAL (USES AN OBSERVATION WRITTEN IN COPY)
    int prefix = 1;
    int suffix = 1;
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = 0; i < n ; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-i-1];

        maxi = max(maxi , max(prefix , suffix));
    }

    return maxi;

}

int main(){
    vector<int> r = {3, 2, -1, 4, -6, 3, -2, 6};
    cout << maxProdSubArray(r);
}