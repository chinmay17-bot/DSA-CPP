#include <bits/stdc++.h>
using namespace std;
 
//Can be done by sets WHICH IS A BRUTE FORCE SOLUTION

void Union(int arr1[] , int arr2[] , int n , int m){
    //3 approaches
    //MAP-ENTER ALL ELEMENT ONLY IF FREQ IS ZERO
    //SET-INSERT BOTH ARRAY ELEMENTS IN SET
    int i = 0;
    int j = 0;
    vector<int> ans;

    //VECTOR functions are important in optimal solution for chking last element


    while (i < n && j < m)
    {
        if(arr1[i] <= arr2[j]){
            if(ans.size() == 0 || ans.back() != arr1[i]){ //<- this order of comparison is important since for an empty vector ans.back() gives undifined 
                ans.push_back(arr1[i]);
            }
            i++;
        }

        else {
            if(ans.size() == 0 || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }

    }

    while (i < n)
    {
        if(ans.size() == 0 || ans.back() != arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }

    
    while (j < m)
    {
        if(ans.size() == 0 || ans.back() != arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    }
    
    for(auto it : ans){
        cout << it << " ";
    }
    
}

int main(){
    int n,m;
    n = 6;
    m = 6;
    int a[n] = {1,1,2,3,4,5};
    int b[m] = {2,3,4,4,5,6};
    Union(a ,b , n , m);
    
}