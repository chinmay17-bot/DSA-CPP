#include <bits/stdc++.h>
using namespace std;
 
string removeKdigits(string num, int k) {
        string ans;

        stack<char> st;
        int n= num.size();
        for(int i= 0; i< n; i++){
            if(k> 0){
                while(!st.empty()&& st.top()> num[i]){
                    st.pop();
                    k--;
                    if(k== 0) break;
                }
            }

            st.push(num[i]);
        }

        while(!st.empty()&& k){
            st.pop();
            k--;
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i;
        for(i= 0; i< ans.size(); i++){
            if(ans[i]!= '0') break;
        }


        if(ans.substr(i, ans.size()).size()!= 0){
            return ans.substr(i, ans.size());

        }
        return "0";
    }

int main(){
    
}