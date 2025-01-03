#include <bits/stdc++.h>
using namespace std;
 
void kmpAlgo(vector<int> &LPS ,string& str){
        for(int i= 1; i< LPS.size(); i++){
            int prevIndx= LPS[i- 1];

            while(prevIndx> 0 && str[i]!= str[prevIndx]) prevIndx= LPS[prevIndx-1];

            LPS[i]= prevIndx+ (str[i]== str[prevIndx]);
        }


    }


    int strStr(string haystack, string needle) {

        string kmpString (needle.begin(), needle.end());
        kmpString.push_back('#');
        kmpString+= haystack;
        vector<int > lps(kmpString.size(), 0);

        kmpAlgo(lps, kmpString);

        int cnt= 0;


        for(int i= 0; i< lps.size(); i++){
            if( lps[i]== needle.size()){
                return (i -needle.size()- lps[i]);
            }
        }

        return -1;
    }


int main(){
    
}