#include <bits/stdc++.h>
using namespace std;


//Brute force solution will give TLE

int sumSubarrayMins(vector<int>& arr) {
        int mini= INT_MAX;
        int n= arr.size();
        int sum= 0;
        int mod= 1e9+ 7;
        for(int i= 0; i< n; i++){
            mini= arr[i];
            sum= (sum+ mini)%mod;
            for(int j= i+ 1; j< n; j++){
                mini= mini > arr[j]? arr[j]: mini;

                sum= (sum+ mini)%mod;
            }
        }

        return sum;
    }
 
int main(){
    
}