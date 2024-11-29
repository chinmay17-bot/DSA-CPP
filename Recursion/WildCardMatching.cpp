#include <bits/stdc++.h>
using namespace std;
 
bool wildCardMatching(string s , string p , int si , int pi){
    
    if(s.size() == si && p.size() == pi){
        return true;
    }

    if(s.size() == si && p.size() > pi){
        
        while (pi <= p.size())
        {
            if(p[pi] != '*') return false;
            pi++;
        }

        return true;
        
    }

    if(s.size() > si && p.size() == pi){
       return false;
    }

    if(s[si] == p[pi] || p[pi] == '?')
        return wildCardMatching(s , p ,si+1 , pi+1);

    if(p[pi] == '*'){

        bool notInc = wildCardMatching(s , p ,si , pi+1);
        bool inc = wildCardMatching(s , p ,si+1 , pi);

        return notInc || inc;
    }

    return false;
    
}


int main(){
    cout << wildCardMatching("casasasSb" , "?b" , 0 , 0);
}