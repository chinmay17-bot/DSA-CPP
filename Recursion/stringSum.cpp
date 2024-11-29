#include <bits/stdc++.h>
using namespace std;


void SolveStringSum(string &num1 , string &num2, int i , int j , string &ans , int carry){
        //base case
        if(i < 0 && j < 0){
            if(carry) ans.push_back('1');
            return;
        }

        //
        int n1 = (i >= 0 ? num1[i] : '0') - '0';
        int n2 = (j >= 0 ? num2[j] : '0') - '0';

        int sum = n1 + n2 + carry;

        int digit = sum % 10;
        int carr = sum / 10;

        ans.push_back(digit + '0');
        if(carr) carry = 1;
        else carry = 0;

        SolveStringSum(num1 , num2 , i-1 , j-1 , ans , carry);


    }
 
int main(){
    
}