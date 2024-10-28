#include <bits/stdc++.h>
using namespace std;


void getFloorCeil(vector<int> &arr, int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int flr = -1;
    int cl = -1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] <= k){
            flr = arr[mid];
            low = mid+1;
        }

        else{
          high = mid-1;
        }
    }

    low = 0;
    high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] >= k){
            cl = arr[mid];
            high = mid-1;
        }

        else{
          low = mid+1;
        }
    }

    cout << flr << " " << cl;
    
}
 
int main(){
    vector<int> arr = {3 ,4 ,4 ,7 ,8 ,10};
    int k = 8;
    getFloorCeil(arr , k);
}