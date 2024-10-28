#include <bits/stdc++.h>
using namespace std;

//VERY IMP IN TERMS OF LOGICS
// BRUTE FOR IS TO COMPARE IT WITH EVERY OTHER PERMUTATION TO FIND THE NEXT PERMUTATION
// BETTER WAY IS TO USE STL next_permutation(nums.begin() , nums.end())

//WE JUST JUMP TO THE OPTIMAL IN INTERVIEW AFTER EXPLAINING THE OTHER TWO
//Concept of this question  is very good REMEMBER


void next_per(vector<int> &arr){
    int index = -1;
    int swpindex = -1;
    int n = arr.size();
    for (int i = n-2; i > -1; i--)
    {
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }

    }

    cout << index;

    if(index == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    for(int i = n-1; i > index; i--){
        if(arr[index] < arr[i]){
            swpindex = i;
            break;
        }
    }

    swap(arr[index] , arr[swpindex]);


    reverse(arr.begin()+index+1 , arr.end());

    
}



int main(){
    vector<int> arr = {3,2,1};
    
    for(auto it : arr){
        cout << it;
    }
    next_per(arr);
    cout << "\n";
    for(auto it : arr){
        cout << it;
    }
}