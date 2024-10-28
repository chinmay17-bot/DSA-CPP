#include <bits/stdc++.h>
using namespace std;
 
void insertionSort(int arr[] , int i, int n){
    if(i == n-1){
        return;
    }

    int j = i;
    //To keep track of i which can be lost during the loop execution below
    while (arr[j] > arr[j+1] && j >= 0)
    {
        swap(arr[j] , arr[j+1]);
        j--;
    }

    insertionSort(arr , i+1 , n);
    


} 

int main(){
    int arr[7] = {9,12,14,15,6,8,13};
    insertionSort(arr , 0, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << " " << arr[i];
    }
    
}