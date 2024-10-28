#include <bits/stdc++.h>

using namespace std;


//MODIFIED VER OF LOWER BOUND FOR THIS QUES
int lbound(vector<int> &arr, int k){
    int n = arr.size();
    int idx = n;

    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(arr[mid] >= k){
            high = mid-1;
            idx = mid;
        }

        else{
            low = mid+1;

        }
    } 
    if( arr[mid] != k) return -1; // <-- EXTRA CHECK FOR THIS QUESTION
    return idx;
}


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

void firstAndLast(vector<int> &arr, int k){
    int lb = lbound(arr, k);
    if(lb == -1){
        cout << "-1 -1"; 
    }

    else{
        int ub = ubound(arr, k);
        cout << lb << " " << ub-1;
    }
}
 
int main(){
    vector<int> arr = {3 ,5 ,5 , 7 ,8 ,10};
    firstAndLast(arr, 4);
}