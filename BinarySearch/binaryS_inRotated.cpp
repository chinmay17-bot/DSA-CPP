#include <bits/stdc++.h>
using namespace std;

void search(vector<int> &arr , int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == k){
            cout << mid;
            return;
        }


        //LEFT HALF IS SORTED
        else if(arr[low] < arr[mid]){
            if(arr[mid] >= k && arr[low] <= k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        //RIGHT HALF IS SORTED
        else{
            if(arr[mid] <= k && arr[high] >= k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    
}
 
int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int k = 8;
    search(arr , k);
}