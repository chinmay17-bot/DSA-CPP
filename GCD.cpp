#include <bits/stdc++.h>
using namespace std;

void gcd(int n, int m){
    int gcd = 1;
    for (int i = 2; i <= n; i++)
    {
        if(n%i == 0 && m%i == 0){
            gcd = i;
        }
    }

    cout << gcd;
    
}
 
int main(){
    int n = 2;
    int m = 4;

    gcd(n , m);
}