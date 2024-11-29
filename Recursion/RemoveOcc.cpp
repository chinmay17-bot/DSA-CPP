#include <bits/stdc++.h>
using namespace std;


//BEST WAY TO DO IS BY ITERATIVELY
 
void removeSubstr(string&s , string&part){
    int found = s.find(part);

        if(found != string::npos){
            string left = s.substr(0 , found);
            string right = s.substr(found+part.size() , s.size());

            s = left+right;

            removeSubstr(s , part);
        }

        return;
}

int main(){
    
}