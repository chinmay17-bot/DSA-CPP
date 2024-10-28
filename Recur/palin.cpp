#include <bits/stdc++.h>
using namespace std;
 
bool chkPalin(string str , int i , int j){
    if(str[i] != str[j]){
        return false;    
    }

    return chkPalin(str , ++i , --j);
}

int main(){
    string str;
    cin >> str;
    int size = str.length();
    bool chk = chkPalin(str , 0 , size-1);
    if(chk){
        cout << "Palindrome";
    }

    else{
        cout << "Not Palindrome";
    }
}