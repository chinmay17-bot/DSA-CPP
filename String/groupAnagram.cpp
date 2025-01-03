#include <bits/stdc++.h>
using namespace std;

//Optimal  but sort can be removed
 
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n= strs.size();

        map<string , vector<string >> mp;
         
        for(auto it: strs){
            string key= it;
            sort(key.begin(), key.end());
            mp[key].push_back(it);


        }

        vector<vector<string >> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }


//byr removing sort we have to do int hash[256] then compare each of the hash of strings

    std::array<int ,256> _hash(string s){
        std::array<int ,256> hash={0};

        
        for(int i= 0; i< s.size(); i++){
            hash[s[i]]++;
        }

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n= strs.size();

        map<std::array<int ,256> , vector<string >> mp;


         
        for(auto it: strs){
            string key= it;
            mp[_hash(key)].push_back(it);


        }

        vector<vector<string >> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
 
 
int main(){
    
}