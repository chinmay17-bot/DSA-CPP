#include <bits/stdc++.h>
using namespace std;

bool binSer(vector<int> &arr , int num){
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] > num){
            high = mid-1;
        }
        else if(arr[mid] < num){
            low = mid+1;
        }
        else {
            return true;
        }
    }
    return false;
}
 
int kthmissing(vector<int> &arr , int k){


    //SIMPLE SOLUTION USING BS AND LINEAR ITER
    // int num = 0;
    //     int cnt = 0;
    //     while(k){
    //         num++;
    //         if(!binSer(arr , num)){
               
    //             k--;
    //         }
    //     }

    //     return num;


    //MATHEMATICAL SOLUTION TRICKY BUT SIMPLE
    //BASED ON OBERVATION(DONE IN COPY IF CONFUSED)
    // for(int i = 0; i < arr.size(); i++){
    //     if(arr[i] < k) k++;
    //     else break;
    // }

    // return k


    //OPTIMAL WITH TRICK (written in copy for working)
    int low = 0;
    int high = arr.size()-1;

    while(low <= high){
        int mid = (low+high) / 2;
        int missing = arr[mid] - (mid+1);

        if(missing < k) low = mid+1;

        else high = mid-1;
    }


    return k+high+1;

}

int main(){
    
}