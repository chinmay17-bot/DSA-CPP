#include <bits/stdc++.h>
using namespace std;


//Brute force solution 
// bool matchKchars(string& s, char &chr,  int &i, int k){
//         int j = s.size()- 1;

//         while(k > 0){
//             if(chr != s[j--]) return false;
//             k--;
//         }

//         return true;
//     }

//     string removeDuplicates(string s, int k) {

//         string ans="";

//         for(int i= 0; i< s.size(); i++){
//             char chr= s[i];
//             if(ans.size()< k-1) ans.push_back(chr);

//             else if(matchKchars(ans, chr, i, k-1)){
//                 for(int j= 0; j< k-1; j++){
//                     ans.pop_back();
//                 }
//             }

//             else
//                 ans.push_back(chr);
//         }

//         return ans;
//     }


//optimal solution using 2 pointers
string removeDuplicates(string s, int k) {
        int i= 0;
        int j= 0;

        vector<int > count(s.size());

        while(i< s.size() && j< s.size()){
            s[i]= s[j];
            count[i]= 1;
            if(i> 0&& s[i-1]== s[i]) {
                count[i]+= count[i-1];
            }

            if(count[i]== k){
                i-= k;
            }

            i++;j++;
        }

        string ans (s.substr(0, i));
        return ans;
    }


int main(){
    
}