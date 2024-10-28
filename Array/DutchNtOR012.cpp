#include <bits/stdc++.h>
using namespace std;

//brute and better solution are sorting algo and count number of each


//MOST OPTIMAL SOLUTION USING THREE POINTER
void dutchNatAlgo(int arr[] , int n ){
    int low,mid,high;
    low = 0; 
    mid = 0;
    high = n-1;

    while (mid <= high)
    {
        if(arr[mid] == 0){
            swap(arr[mid] , arr[low]);
            mid++;
            low++;
        }

        else if(arr[mid] == 1){
            mid++;
        }

        else{
            swap(arr[mid] , arr[high]);
            //WE DONT DO MID++ BECAUSE HIGH MIGHT HAVE 1 OR 0 SO WE CANT SAY IF 0 TO MID IS SORTED IN ABOVE CASE WE CAN
            high--;
        }
    }

    
    
}


int main(){



}