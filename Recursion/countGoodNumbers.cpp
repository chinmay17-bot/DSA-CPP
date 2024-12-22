#include <bits/stdc++.h>
using namespace std;


//O(logN) way to calculate power

//But more important function is that we are using mod 1e9+7 after ecery multiplication to keep result in range 
//NOTE This quees is not written in copy 
 
 int recursivePower(long long num , long long exp ,long long m){
        if(exp == 0) return 1;

        if(exp & 1){
            return (num * recursivePower((num * num)%m , exp/2, m)) %m;
        }

        else{
            return recursivePower((num * num)%m , exp /2, m);
        }
    }
    

    int countGoodNumbers(long long n) {
        int m = 1e9 + 7;

        long long four = recursivePower(4 , n/2, m) ;
        long long five = recursivePower(5 , n/2 + n%2 , m);

        return (four * five ) %m;

    }

int main(){
    
}