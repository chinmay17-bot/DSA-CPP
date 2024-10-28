#include <bits/stdc++.h>
using namespace std;


//FORMULA OF NCR IS SIMPLIFIED TO THIS
int ncr(int n,int r){
    int res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

//THERE ARE 3 TYPES OF QUESTION

//RETURN THE ELEMENT AT POSITION 
void pascal1(int r,int c){
    cout << ncr(r-1,c-1);
}

//RETURN THE ROW AT A POSITION

void pascal2(int r){


    //BRUTE FORCE WITH O(N2) COMPLEXITY
    // for(int i= 1; i <= r; i++){
    //     cout << ncr(r-1, i-1) << " ";
    // }

    //OPTIMAL FOR ARRAY PRINTING OF NTH ROW BY AN OBSERVATION HOW AFTER 1 IN START OF AN ARRAY CONSEQ ELEMENTS ARE CALCULATED

    cout << 1 << " ";
    int res = 1;
    for(int i = 1; i <r ; i++){
        res = res*(r-i);
        res = res/i;
        cout << res << " ";
    }
}

void pascal3(int n){
    //BRUTE FORCE
    // for(int i = 1; i  <= n; i++){
        // for(int j = 1; j <= i; j++){
            // cout << ncr(i-1,j-1);;
        // }
        // cout << "\n";
    // }

    //OPTIMAL (USING THE ROW CONCEPT)
    int res = 1;

    for (int i = 1; i <= n; i++)
    {   
        cout << res;
        for(int j = 1; j < i; j++){
            res = res*(i-j);
            res = res/j;
            cout << res;
        }
        cout << "\n";
    }
    
}


 
int main(){
    int n = 5;

    // pascal1(3,2);
    // cout <<"\n";
    // pascal2(3);
    // cout << "\n";
    // pascal3(3);
}