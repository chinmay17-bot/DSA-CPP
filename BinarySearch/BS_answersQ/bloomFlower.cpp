#include <bits/stdc++.h>
using namespace std;
 
int numberOfBouq(vector<int> &arr , int k , int m){
    if(arr.size() < m) return -1;
    
    //BRUTE FORCE SOLUTION
    int minn = arr[0];
    int maxn = arr[0];
    if(m*k > arr.size()) return -1;
    for(int i = 0; i < arr.size(); i++){
        if(minn > arr[i]){
            minn = arr[i];
        }
        if(maxn < arr[i]){
            maxn = arr[i];
        }
    }

    //TO COUNT NUNBER OF FLOWERS BLOOMED IN NTH DAY
    int cnt = 0;

    //TO COUNT NUMBER OF BOUQETS IN NTH DAT
    int boq = 0;
    for(int i = minn; i < maxn; i++){
        boq = 0;
        cnt = 0;
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] <= i){
                cnt++;
            }

            else{
                boq += (cnt/k);

                //SINCE ONLY TAKING ADJACENT FLOWERS
                cnt = 0;
            }

        }

        boq += (cnt/k);

        if(boq >= m) return i;
    }
    
    
    return -1;
}


int main(){
    
}