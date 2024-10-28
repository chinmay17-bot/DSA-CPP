#include <bits/stdc++.h>
using namespace std;
 

int stocks(vector<int> &arr, int n){

    //BRUTE FORCE GIVING TLE

    /*
    
    int j;
    int diff;
    int prof = INT_MIN;
    for (int i = 0; i < n-1; i++)
    {
        j = i+1;
        while (j < n)
        {
            diff = arr[j] - arr[i];
            prof = max(prof , diff);
            j++;
        }
        
    }
    if(prof < 0){
        return 0;
    }
    return prof;
    */



   //BETTER SOLUTION(USING 2 POINTERS)
    int i = 0;
    int mi = arr[i];
    int prof = INT_MIN;
    int cost;
    for (int i = 1; i < n; i++)
    {
        cost = arr[i] - mi;
        prof = max(prof , cost);

        if(mi > arr[i]){
            mi = arr[i];
        }
    }
    
    if(prof < 0){
        return 0;
    }
    return prof;
    

}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    int n = arr.size();
    cout << stocks(arr , n);
}