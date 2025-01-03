#include <bits/stdc++.h>
using namespace std;
 

int myAtoi(string s) {
        int num= 0;
        int sign= 1;
        bool strt= false;

        int i= 0;
        while(s[i]== ' '){
            i++;
        }

        if(i< s.size() && (s[i]== '-' || s[i]== '+')){
            sign= s[i]== '-'? -1: 1;
            i++;
        }
        

        while(i< s.size()){
            if(isdigit(s[i])){
                int digit= s[i]- '0';

                if(num > (INT_MAX/10) || (num == INT_MAX/10 && s[i]> '7')) {
                    return sign== -1 ? INT_MIN : INT_MAX;
                }

                num= num*10 + digit;
            }

            else break;
            i++;

        }

        return num*sign;
    }

int main(){
    
}