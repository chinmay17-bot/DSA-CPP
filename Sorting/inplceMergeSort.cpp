#include <bits/stdc++.h>
using namespace std;

void mergeInPlace(vector<int > &arr , int low , int mid,int high){
    int len = high - low + 1;

    //a different way to find ceil 
    int gap = len / 2 + len % 2; 

    while(gap > 0){
        int i = 0;
        int j = i+gap;

        while(j <= high){
            if(arr[i] > arr[j]) swap(arr[i] , arr[j]);

            i++,j++;
        }

        
        if(gap <= 1){
            gap = 0;
        }
        else{
            gap = gap / 2 + gap % 2;
        }
    }
}


void mergeSort(vector<int> &arr , int low, int high){

    if(low == high){
        return;
    }
    int mid = (low+high) / 2;

    mergeSort(arr , low , mid);
    mergeSort(arr , mid+1 , high);
    mergeInPlace(arr, low, mid, high);

}

int main(){
   vector<int> arr;
   int n;
   int num;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
        cin >> num;
        arr.push_back(num);
   }

   mergeSort(arr , 0 , n-1);

   for(auto it : arr){
    cout << it << " ";
   }
   
}