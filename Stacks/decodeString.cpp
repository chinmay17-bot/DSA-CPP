#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
        stack<string> st;
        int n= s.size();
        string ans= "";
        for(int i= 0; i < n; i++){
            if(s[i]== ']'){
                string temp= "";
                while(!st.empty() && !isdigit(st.top()[0]) && st.top()!= "["){
                    temp+= st.top();
                    st.pop();
                }
                st.pop();
                // cout << temp<<endl;
                string snum="";
                while(!st.empty() && isdigit(st.top()[0])){
                    snum+= st.top();
                    st.pop();
                }

                // while(st.top() == "[") st.pop();

                reverse(snum.begin(), snum.end());
                int num= stoi(snum);

                string ele= "";
                while(num-- ){
                    ele+= temp;
                }

                st.push(ele);
            }
            else{
                string str (1, s[i]);
                st.push(str);
            }
        }

        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){
    
}