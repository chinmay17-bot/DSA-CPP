#include <bits/stdc++.h>
using namespace std;


//uses InsertAt bottom

void insertTillSmall(stack<int>&s, int val){

    //THIS IS VERY IMPORTANT CONDITION
    if(s.empty()){
        s.push(val);
        return;
    }
    if(s.top() <= val){
        s.push(val);
        return;
    }

    int top= s.top();
    s.pop();
    insertTillSmall(s, val);

    s.push(top);
}



int main(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(5);

    insertTillSmall(s, 2);

    while(!s.empty()){
        cout<< s.top()<< " ";
        s.pop();
    }
}