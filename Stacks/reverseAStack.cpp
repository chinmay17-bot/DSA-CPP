#include <bits/stdc++.h>
using namespace std;


//uses InsertAt bottom

void insertAtBottom(stack<int>&s, int&val){

    if(s.empty()){
        s.push(val);
        return;
    }

    int top= s.top();
    s.pop();
    insertAtBottom(s, val);

    s.push(top);
}


void reverseStack(stack<int>& s){
    if(s.empty()){
        return;
    }

    int top= s.top();
    s.pop();

    reverseStack(s);
    insertAtBottom(s, top);
    return;
    
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while(!s.empty()){
        cout<< s.top()<< " ";
        s.pop();
    }
}