#include <bits/stdc++.h>
using namespace std;
 

int findKRotation(vector<int> &arr) {

    //BRUTE FORCE CODE
    /*
    int i = 0;
        
        for(i = 0 ;i < arr.size()-1; i++){
            if(arr[i] > arr[i+1]){
                return i+1;
            }
        }
        
    return 0; 
    */


    //MOST OPTIMAL CODE
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int m = arr[0];
    int idx = 0;
    while(low <= high){
        int mid = (low+high)/2;


        //TO MAKE IT SLIGHTLY BETTER

        /*
        if(arr[low] <= arr[mid] && arr[mid] <= arr[high]){
            return arr[low];
        }
        */

        if(arr[low] <= arr[mid]){
            // m = min(m , arr[low]);

            if(m > arr[low]){
                m = arr[low];
                idx = low;
            }
            low = mid+1;
        }

        else{
            // m = min(m , arr[mid]);

            if(arr[mid] < m){
                m = arr[mid];
                idx = mid;
            }
            high = mid-1;
        }
    }

    return idx;
    }


int main(){
    
}