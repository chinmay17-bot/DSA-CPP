#include <bits/stdc++.h>
using namespace std;
 
int cntRedundant(string s) 
    {
        stack<char> pr;
        int i=0;
        int pairs= 0;
        set<char> op;
        op.insert('+');
        op.insert('-');
        op.insert('*');
        op.insert('/');
        while(i<s.size())
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'|| op.find(s[i]) != op.end())
                pr.push(s[i]);
            else
            {
            
                if((s[i]==')' && pr.top()=='(') ||
                   (s[i]=='}' && pr.top()=='{') ||
                   (s[i]==']' && pr.top()=='[') )
                   {
                        pr.pop();
                        if(op.find(pr.top()) != op.end()){
                            pairs++;
                            pr.pop();
                        }
                   }
    
            }
            i++;
        }

        return pairs;
    }


int main(){
    string str= "((3)+(5))";
    
    cout << cntRedundant(str);
}