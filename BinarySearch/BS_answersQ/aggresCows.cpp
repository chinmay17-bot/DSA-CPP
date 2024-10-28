#include <bits/stdc++.h>
using namespace std;


//TO RETURN IS COWS CAN BE PLACED IN X DISTANCE
 bool canPlace(vector<int> &arr , int cows , int dist){
    int cow = 1; int last = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if((arr[i] - last) >= dist) {
            cow++;
            last = arr[i];
        }
        
        
    }
    
    if(cow >= cows) return true;
    
    return false;
}

int minDisMustBeMax(vector<int> &stalls , int cows ){

    //BRUTE FORCE HERE WE TRY TO LINEARLY SEARCH IF COWS CANBE PLACED IN X DISTANCE 
    //AND TAKE THE MAXIMUM DISTANCE
    sort(stalls.begin() , stalls.end());

    int mn = 1;
    int mx = stalls[stalls.size()-1] - stalls[0];

    for(int i = 1; i < mx-mn+1; i++){
        if(canPlace) continue;

        else return i-1;
    }

    return -1;


    //OPTIMAL IN THIS WE CONVERT THE OOUTER LOOP TO LINEAR SINCE THE ANSWER LIES B/W 1 AND MAX DISTANCE BETWEEN STALLS

    sort(stalls.begin() , stalls.end());
    int n = stalls.size()-1;
    int mn = 1;
    int mx = stalls[n-1];
    
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    while(low <= high)
    {
        int mid = (low+high) / 2;
        if(canPlace(stalls, cows , mid)) low = mid+1;
        
        else high = mid-1;
    }
    
    return high;

}
 
int main(){
    
}