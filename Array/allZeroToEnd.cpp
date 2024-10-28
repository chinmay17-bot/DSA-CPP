#include <bits/stdc++.h>
using namespace std;

void allZerosToEnd(vector<int> &arr){
    //MOST OPTIMAL CODE USING 2 POINTER
    int j = 0;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 0){
            j = i;
            break;
        }
    }

    if(j == 0) return;

    //IN THIS WE JUST FIND THE FIRST ELEMENT AND THEN KEEP SWAPPING WE WILL AUTOMATICALLY GET 0S AT END

    for (int i = j+1; i < n; i++)
    {
        if(arr[i] != 0){
            swap(arr[i] , arr[j]);
            j++;
        }
    }
    
    
}
 
int main(){
    vector<int> arr = {1,2,3,0,3,4,0,0,4,2};
    allZerosToEnd(arr);
    for(auto it : arr){
        cout << " " << it;
    }
}