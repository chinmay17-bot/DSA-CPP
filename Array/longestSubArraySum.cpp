#include <bits/stdc++.h>
using namespace std;
 
void subArraySum(int arr[] , int n , int k){



    // BRUTE FORCE SOLUTION WHICH GIVES TLE
    // Complete the function
        // int cnt1 = 1;
        // int cnt = 0;
        // int sum;
        // int j = 0;
        
        // for(int i = 0; i < N;i++){
        //     sum = A[i];
        //     if(sum == K){
        //         cnt = 1;
        //     }
        // }
        // for(int i = 0; i < N;i++){
        //     sum = A[i];
        //     cnt1 = 1;
        //     j = i+1;
        //     while(j < N){
        //             sum+=A[j];
        //             cnt1++;
        //             if(sum == K){
        //                 cnt = max(cnt , cnt1);
        //             }
        //             j++;
        //     }
        // }



//BETTER SOLUTION FOR ONLY POSITIVE ARRAY (MOST OPTIMAL SOLUTION FOR ARRAY WITH NEG AND POS)

map<long long, int> prefixSum;
int len = 0;
long long sum = 0;
for (int i = 0; i < n; i++)
{
    sum+=arr[i];
    if(sum == k){
        len = max(len , i+1);
    }

    long long rem = sum - k;
    if(prefixSum.find(rem) != prefixSum.end()){
        int l = i - prefixSum[rem];  
        len = max(len , l);
    }

    if(prefixSum.find(sum) == prefixSum.end()){  //WE DO THIS TO ENSURE IF 0 IS BEING ADDED IN SUM THEN IT DOES NOT 
                                                //GETS UPDATED ON THE LIST SINCE
        prefixSum[sum] = i;
    } 
}




//MOST OPTIMAL SOLUTION(ONLY FOR ARRAY WITH POSITIVE NUMBERS)

/*
    int i = 0;
    int j = 0;
    long long sum = arr[0];
    int l = 0;
    while(j < n){
        while (sum > k && i <= j)
        {
            sum-=arr[i];            //WE SUBTRACT TILL SUM IS GREATER AND i <= j AS SUB ARRAY 
            i++;
        }

        if(sum == k){
            l = max(l , (j-i)+1);
        }

        j++;
        if(j < n){
            sum+=arr[j];
        }


        
    }

    cout << l;
*/
    
}

int main(){
    int n = 6;
    int arr[6] = {1,4,3,3,5,5};
    int k = 16;
    subArraySum(arr , n , k);
}