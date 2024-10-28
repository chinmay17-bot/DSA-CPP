#include <bits/stdc++.h>
using namespace std;
 
void recurGCD(int n , int m){

    if(n == m){
        cout << n;
        return;
    }
    else{
        int mx = max(n , m);
        int mn = min(n , m);
        int res = mx - mn;
        int res1 = mn;
        recurGCD(res , res1);
    }

    
}

int main(){
    recurGCD(10 , 5);
}   