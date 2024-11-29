#include <bits/stdc++.h>
using namespace std;

int perfectSquare(int num ){

    if(num<0) return 0;

    if(num == 0) return 1;

    int cnt =0;
    
    int ans = INT_MAX;
    for(int i = 1; i*i <= num ;i++){
        cnt = 1 + perfectSquare(num-(i*i) );
        ans = min(cnt , ans);
    }

    return ans;

} 

int main(){
    
    cout << perfectSquare(12);

}