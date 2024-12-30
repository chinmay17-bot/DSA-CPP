#include <bits/stdc++.h>
using namespace std;
 
int main(){
    vector<int> arr= {8,4,6,2,3};

    stack<int> st;
    int n= arr.size();
    st.push(-1);
    vector<int> ans;

    for(int i= n-1; i>= 0; i++){
        if(st.top() < arr[i]){
            ans.push_back(st.top());
        }
        else{
            while (st.top()>= arr[i])
            {
                st.pop();
            }
            
            ans.push_back(st.top());
        }

        st.push(arr[i]);


    }

    for(auto it: arr){
        cout << it <<" ";
    }
}