#include <bits/stdc++.h>
using namespace std;



//implemented  minstack

void minimize(stack<int>&st, int ele){
    if(st.empty() || st.top() >= ele){
        st.push(ele);
        return;
    }

    int num= st.top();
    st.pop();
    minimize(st, ele);
    st.push(num);

}
 
int main(){
    stack<int> st;
    
    minimize(st, 11);
    minimize(st, 4);
    minimize(st, 1);
    minimize(st, 2);
    minimize(st, 7);
    minimize(st, 22);
    minimize(st, 4);
    minimize(st, 5);

    while (!st.empty())
    {
        cout << st.top() <<" ";
        st.pop();
    }
    

}