#include <bits/stdc++.h>
using namespace std;
 
string convert(string s, int numRows) {
        if(numRows== 1) return s;


        vector<string > pattern(numRows);

        //true to go down
        bool direction= true;

        int i= 0;
        int curRow= 0;
        while(true){
            if(i == s.size()) break;
            if(direction){
                while(curRow< numRows && i< s.size()){

                    pattern[curRow++].push_back(s[i++]);

                }
                //As next row is 1 above last row in opp direction
                curRow= numRows- 2;
                direction= false;
            }
            else{
                while(curRow> -1 && i< s.size()){

                    pattern[curRow--].push_back(s[i++]);
                }

                curRow= 1;
                direction = true;
            }
        } 

        string ans;
        for(auto it: pattern) ans+= it;

        return  ans;
    }


int main(){
    
}