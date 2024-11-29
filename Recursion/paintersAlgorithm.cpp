#include <bits/stdc++.h>
using namespace std;

//A very interesting algo similar ans to countDearrg. do watch vods and notes
//Complex logic but very simple recursive code

int paintersAlgo(int n , int k){
    if(n == 1) return k;

    if(n == 2) return k + k*(k-1);

    return (k-1) * (paintersAlgo(n-1 , k) + paintersAlgo(n-2 , k));

} 


int main(){
    cout << paintersAlgo(3 , 3);
}