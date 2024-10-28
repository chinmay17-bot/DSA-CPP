#include <bits/stdc++.h>
using namespace std;

void swap(int &n , int &m){
    int temp = n;
    n = m;
    m = temp;
}
 
void bubbleSort(int arr[] , int i , int j){
    if(i == j){
        return;
    }

    bubbleSort(arr , i , j-1);
    while (arr[j] < arr[j-1])
    {
        swap(arr[j-1] , arr[j]);
        j--;

    }
    return;
}

int main(){
    int arr[5] = {4,5,23,1,2};
    int n;
    cin >> n;
    int arr1[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    
    // bubbleSort(arr , 0 , 4);
    bubbleSort(arr1 , 0 , n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    

}