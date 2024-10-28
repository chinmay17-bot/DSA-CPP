#include <bits/stdc++.h>
using namespace std;
 
double findMedian(vector<int> &a , vector<int> &b){
    //BRUTE ANS BETTER SOLUTIOUNS ARE EASY BY CREATING NEW ARRAY IN A SORTED FASHION OR BY TWO POINTER

    //IN OPTIMAL SOLUTION WE USE BINARY SEARCH
    
    
    int n1 = a.size();
    int n2 = b.size();

    if(n1 > n2) return findMedian(b , a);

    int n = n1+n2;

    //WE USE BIN SEARCH TO FINF POSTION FOR PARTITION IN FIRST ARRAY  AS SECOND ARRAY IS ADJUSTED ACCORDINGLY

    int low = 0; 
    int high = n1;

    //works for both even and odd number of lenght in combined array 
    int left = (n1 + n2 + 1)/2;

    while(low <= high){

        //ACTUALLY THE LENGTH OF FIRST PART OF FIRST ARRAY
        int mid1 = (low+high) / 2;

        //REMAINING LENGTH OF LEFT PART
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;

        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        if(mid1 > 0) l1 = a[mid1-1];
        if(mid2 > 0) l2 = b[mid2-1];


        if(l1 <= r2 && l2 <= r1) {
            if(n % 2 == 1) return max(l1 , l2);

            else {
                    double res =  ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
                    return res;
                };
        }

        if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }

    //dummy return
    return 0.0;
}


int main(){
    
}