#include <bits/stdc++.h>
using namespace std;
 
void simplify(string& str){


        //We simplify or normalise this way
        char strt= 'a';
        unordered_map<char, char> mp;

        for(int i= 0; i< str.size(); i++){
            if(mp.find(str[i])== mp.end()){
                mp[str[i]]= strt;
                strt++; 
            }
        }

        for(int i= 0; i< str.size(); i++){
            str[i]= mp[str[i]];
        }
    }


    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        simplify(pattern);

        vector<string > ans;

        for(int i= 0; i< words.size(); i++){
            string tempStr= words[i];
            simplify(tempStr);
            if(tempStr.compare(pattern)== 0) ans.push_back(words[i]);
        }

        return  ans;
    }

int main(){
    
}