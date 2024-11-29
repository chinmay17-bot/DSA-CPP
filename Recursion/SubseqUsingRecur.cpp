#include <bits/stdc++.h>
using namespace std;
 
//NOT FULLY CORRECT AS SUBSEQENCE IN INCOMPLETE
void printSubSeq(string str , int i ,int n , string output ,vector<string> &ans){
    if(i == n) {
        ans.push_back(output);
        cout << output << endl;
        return ;
    }

    char ch = str[i];

    printSubSeq(str , i+1 , n  ,output + ch ,ans);
    printSubSeq(str , i+1 , n  ,output , ans);
}



int main(){
    string str = "abc";
    string out = "";

    vector<string> ans;
    printSubSeq(str , 0 , str.size() , out , ans);

    for(auto it : ans){
        cout << it << " ";
    }
}