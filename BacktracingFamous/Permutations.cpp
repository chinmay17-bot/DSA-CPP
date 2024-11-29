#include <bits/stdc++.h>
using namespace std;
 
// void printPermutaions(string str , int i){
//     if(i == str.size()){
//         cout << str << endl;
//     }

//     for(int j = i; j < str.size(); j++){
//         swap(str[i] , str[j]);

//         //Recursive call to generate for subproblem
//         printPermutaions(str , i+1);

//     }
// }


//for doing it by refernce we have to reswap the elements otherwise soltions will repeat
void printPermutaions(string &str , int i){
    if(i == str.size()){
        cout << str << endl;
    }

    for(int j = i; j < str.size(); j++){
        swap(str[i] , str[j]);

        //Recursive call to generate for subproblem
        printPermutaions(str , i+1);
        swap(str[i] , str[j]);


    }
}

int main(){
    string str = "abc";
    printPermutaions(str, 0);
}