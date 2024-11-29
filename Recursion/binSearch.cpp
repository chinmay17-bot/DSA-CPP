#include <bits/stdc++.h>
using namespace std;


//binsearch using recursion
bool binSearch(vector<int> &arr , int low, int high, int target){
    int mid = (low+high) / 2;

    if(arr[mid] == target) return true;

    if (low > high) return false;

    if(arr[mid] > target){
        binSearch(arr , low, mid-1 , target);
    }
    else{
        binSearch(arr ,mid+1, high , target);
    }
}


int main(){
 vector<int> arr = {1,3,5,6,7,9};
 cout << binSearch(arr , 0 ,arr.size() , 2);
}