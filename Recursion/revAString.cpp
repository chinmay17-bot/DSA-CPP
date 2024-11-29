#include <bits/stdc++.h>
using namespace std;
 
void reverseAString(string &str ,int i ,int j){
    if(i >= j){
        return;
    }


    swap(str[i] , str[str.size() - i - 1]);
    reverseAString(str , i+1 , j-1);
}

int main(){
    string str = "adasda";
    cout << str;
    cout << endl;
    reverseAString(str , 0 , str.size()-1);
    cout << str;
}