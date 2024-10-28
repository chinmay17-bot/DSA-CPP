#include <bits/stdc++.h>
using namespace std;

int ubound(vector<int> &arr, int k){
    int n = arr.size();
    int idx = n;

    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > k){
            high = mid-1;
            idx = mid;
        }

        else{
            low = mid+1;

        }
    } 

    return idx;
}

int main(){
    vector<int> arr = {1,2,5,6,7,8,9,13,17,24,55,57,59};
    int k = 17;
    int idx = ubound(arr , k);
    // int idx = lower_bound(arr.begin() , arr.end() , 14)-arr.begin();

    //THE SAME CAN BE IMPLEMENTED USING  STL lower_bound(arr.begin() , arr.end())-arr.begin()
    cout << idx;
}