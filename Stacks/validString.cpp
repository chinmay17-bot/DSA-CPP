#include <bits/stdc++.h>
using namespace std;
 
//by recursion but bad TC

bool isValid(string s) {
    // if(s.size()== 0) return true;
    // int idx= s.find("abc");
    // if(idx!= string::npos){
    //     string left= s.substr(0, idx);
    //     string right= s.substr(idx+3, s.size());
    //     return isValid(left+right);
    // }
    // return false;




    //OPTIMAL SOLUTION TC O(N) SC O(N)
     stack<char> st;

        if(s[0]!= 'a') return false;

        for(int i= 0; i< s.size(); i++){
            if(s[i]== 'a'){
                st.push('a');
            }
            else if(s[i]== 'b' && !st.empty()&& st.top()== 'a'){
                st.push('b');
            }

            else{
                if(!st.empty()&& st.top()== 'b'){
                    st.pop();
                    if(!st.empty()&& st.top()== 'a'){
                        st.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }

        return st.empty();


}

int main(){
    
}