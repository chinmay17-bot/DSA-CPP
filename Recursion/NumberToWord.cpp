#include <bits/stdc++.h>
using namespace std;

//BY recursion
string intergerToEnglish(int n ){
    vector<pair<int, string>> mp = {
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000, "Thousand"},
        {100, "Hundred"},
        {90, "Ninety"},
        {80, "Eighty"},
        {70, "Seventy"},
        {60, "Sixty"},
        {50, "Fifty"},
        {40, "Forty"},
        {30, "Thirty"},
        {20, "Twenty"},
        {19, "Nineteen"},
        {18, "Eighteen"},
        {17, "Seventeen"},
        {16, "Sixteen"},
        {15, "Fifteen"},
        {14, "Fourteen"},
        {13, "Thirteen"},
        {12, "Twelve"},
        {11, "Eleven"},
        {10, "Ten"},
        {9, "Nine"},
        {8, "Eight"},
        {7, "Seven"},
        {6, "Six"},
        {5, "Five"},
        {4, "Four"},
        {3, "Three"},
        {2, "Two"},
        {1, "One"}
    };  

    if(n == 0) return "Zero";

    int i = 0;
    
    for(int i = 0; i < mp.size(); i++){
        if(n >= mp[i].first){
            string mid = mp[i].second;
            string left = "";
            string right = "";

            if(n >= 100){
                left = intergerToEnglish(n/mp[i].first) + " ";
            }

            if(n % mp[i].first){
                right = " "+intergerToEnglish(n % mp[i].first);
            }

            return (left + mid + right);
        }
    }

    return "";

    

}


int main(){

int n;
cin >> n;
string number = intergerToEnglish(n );
cout << number;

}