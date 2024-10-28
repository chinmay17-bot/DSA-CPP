#include <bits/stdc++.h>
using namespace std;

int countStudent(vector<int> &arr , int pagelimit){
    int stdCnt = 1;
    int cap = 0;
    for(int i = 0; i < arr.size(); i++){
        if(cap+arr[i] > pagelimit) {
            stdCnt++;
            cap = arr[i];
        }

        else{
            cap += arr[i];
        }
    }

    return stdCnt;
}

int bookAllocation(vector<int> &arr , int m){
    
    // //BRUTE FORCE SOLUTION
    // //starting capacity

    // //ONLY IMPOSSIBLE SOLUTION
    // if(m > arr.size()) return -1;

    // int strt = *max_element(arr.begin(), arr.end());
    
    // //max capacity
    // int sum = accumulate(arr.begin() , arr.end() , 0);

    // for(int i = strt; i <= sum ; i++){
    //     if(countStudent(arr , i) == m) return i;
    // }

    // return sum;

    //OPTIMAL SOLUTION BY CHANGING FIRST LOOP TO BS
    //ONLY IMPOSSIBLE SOLUTION
    if(m > arr.size()) return -1;

    int strt = *max_element(arr.begin(), arr.end());
    
    //max capacity
    int sum = accumulate(arr.begin() , arr.end() , 0);

    int low = strt;
    int high = sum;

    while(low <= high){
        int mid = (low + high) /2;
        int cnt = countStudent(arr , mid);
        if(cnt <= m) high = mid-1;

        else low = mid+1;
    }

    return low;

}



int main(){
    
}
