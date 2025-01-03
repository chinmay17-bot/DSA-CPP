#include <bits/stdc++.h>
using namespace std;
 
string intToRoman(int num) {
        vector<pair<int , string>> romans;

        romans.push_back({1000, "M"});
        romans.push_back({900, "CM"});
        romans.push_back({500, "D"});
        romans.push_back({400, "CD"});
        romans.push_back({100, "C"});
        romans.push_back({90, "XC"});
        romans.push_back({50, "L"});
        romans.push_back({40, "XL"});
        romans.push_back({10, "X"});
        romans.push_back({9, "IX"});
        romans.push_back({5, "V"});
        romans.push_back({4, "IV"});
        romans.push_back({1, "I"});

        string ans= "";

        while(num){
            for(int i =0; i< romans.size(); i++){
                if(num>= romans[i].first){
                    ans+= romans[i].second;
                    num-= romans[i].first;
                    break;
                }


            }
        }

        return ans;


    }

int main(){
    
}