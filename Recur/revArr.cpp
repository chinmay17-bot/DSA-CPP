#include <bits/stdc++.h>
using namespace std;

void rev(int f , int r , int arr[]){
    if(f >= r){
        return;
    }

    else{
        int temp = arr[f];
        arr[f] = arr[r];
        arr[r] = temp;

        rev(++f , --r , arr);
    }
}
 
int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    rev(0, n-1, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    
}