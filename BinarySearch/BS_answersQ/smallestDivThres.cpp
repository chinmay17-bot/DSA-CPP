#include <bits/stdc++.h>
using namespace std;

int sumOfDiv(vector<int> &arr , int n){
    int sum = 0;
    for(auto it: arr){
        sum += ceil((double)it/ (double)n);
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {


    //BRUTE FORCE SOLUTION
    //TC O(N) + O(NLOGN) + O(N2) ~ O(N2)

    // vector<int> temp (nums.begin() , nums.end());

    // sort(temp.begin() , temp.end());
    // for(int i = 1 ; i <= temp[temp.size()-1]; i++){
    //     int sum = sumOfDiv(nums , i);
    //     if(sum <= threshold){
    //         return i;
    //     }
    // }
    // return 0;


    //OPTIMAL(JUST CONVERTING THE FIRST LOOP TOP BS)
        
}
 
int main(){
    
}