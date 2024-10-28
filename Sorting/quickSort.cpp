#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = low;
    int i = low;
    int j = high;
    
    while (i < j)
    {
        while (arr[pivot] >= arr[i] && i <= high-1)
        {
            i++;
        }

        while (arr[pivot] < arr[j] && j >= low+1)
        {
            j--;
        }
        
        if(i<j){
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[pivot] , arr[j]);
    
    return j;
}

void quickSort(vector<int> &arr, int i , int j){
    if(i < j){
        int part = partition(arr , i , j);
        quickSort(arr , i , part-1);
        quickSort(arr , part+1 , j);
    }
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