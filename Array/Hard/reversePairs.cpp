#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr , int low , int mid , int high){
        int left = low;
        int right = mid+1;
        
        vector<long long> temp;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low ; i <= high; i++){
            arr[i] = temp[i-low];
        }

        
        
    }


int countReverse(vector<int> &arr , int low , int mid , int high){
    int cnt = 0;
    int right = mid+1;
     for(int i = low; i <= mid; i++){
        while(right <= high && arr[i] > ((long long)(arr[right]) * 2)) right++;
        cnt += (right - (mid+1));
    }
        return cnt;
    }



int mergeSort(vector<int> &arr , int low , int high){
    int cnt = 0;
    
    if(low >= high) return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr , low , mid);
    cnt += mergeSort(arr , mid+1 , high);

    //WE DO A NEW FUNCTION AS TO AVOID MODIFYING MEGRE FUNCTION

    cnt += countReverse(arr , low , mid , high); 


    merge(arr , low , mid , high);

    return cnt;

}

int reversePairs(vector<int> &arr){
    return mergeSort(arr , 0 , arr.size() - 1);
}

int main(){
   
}