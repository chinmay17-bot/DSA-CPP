#include <bits/stdc++.h>
using namespace std;
 
void minimum(vector<int> &arr,int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int  m = INT_MAX;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[low] <= arr[mid]){
            m = min(m , arr[low]);
            low = mid+1;
        }

        else{
            m = min(m , arr[mid]);
            high = mid-1;
        }
    }

    cout << m;
}

int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int k = 8;
    minimum(arr , k);
}