#include <bits/stdc++.h>
using namespace std;
 

int partitions(vector<int>&arr , int start , int end){

    int pivot = end;
    int i = start;
    int j = start;

    while(j < pivot){
        if(arr[j] < arr[pivot]){
            swap(arr[i] , arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i] , arr[pivot]);    
    return i;

}

void quickSort(vector<int>&arr , int i , int j){
    if(i < j){
        int part = partitions(arr , i , j);
        quickSort(arr , 0 ,part-1);
        quickSort(arr , part+1 , j);
    }
    return ;
}

int main(){
    vector<int> arr;
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }

    quickSort(arr, 0 , n-1);
    
    for(auto it: arr){
        cout << it << " ";
    }
}