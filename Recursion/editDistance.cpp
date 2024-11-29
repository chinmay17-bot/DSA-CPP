#include <bits/stdc++.h>
using namespace std;
 

int opPerformed(string&w1 , string&w2 , int i, int j){
    if(i >= w1.size()) return w2.size() - j;
    if(j >= w2.size()) return w1.size() - i;

    int same = 0;

    if(w1[i] == w2[j]) {
        same = 0 + opPerformed(w1 , w2 , i+1 , j+1);
    }   
    else{

        int rep = 1 + opPerformed(w1 , w2 , i+1 , j+1);

        int ins = 1 + opPerformed(w1 , w2 , i+1 , j);

        int del = 1 + opPerformed(w1 , w2 , i , j+1);

        same = min(rep , min(ins , del));

    }

    return same;

}

int main(){
    string w1 = "horse";
    string w2 = "ros";
    cout << opPerformed(w1 , w2 , 0 , 0);
}