#include <bits/stdc++.h>
using namespace std;
 
int countDearr(int n){
    if(n == 1) return 0;

    if(n == 2) return 1;


    return (n-1) * (countDearr(n-1) + countDearr(n-2));
}

int main(){
    cout << countDearr(3);
}