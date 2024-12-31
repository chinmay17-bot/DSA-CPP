#include <bits/stdc++.h>
using namespace std;
 
vector<int> asteroidCollision(vector<int>& a) {
        stack<int > st;

        for(int i= 0; i< a.size(); i++){
            if(a[i]> 0){
                st.push(a[i]);
            }

            else{
                if(st.empty() || st.top()< 0){
                    st.push(a[i]);
                }
                else{

                    //to track if neg asteroid is destroyed or not
                    bool destr= false;
                    while(!st.empty() && st.top()> 0){

                        //asteroid is destroyed 
                        if(abs(a[i])== st.top()) {
                            destr= true;
                            st.pop();
                            break;
                        }
                        //asteroid is not destroyed 
                        else if(st.top()< abs(a[i])) {
                            
                            st.pop();
                        }
                        //asteroid is destroyed 
                        else{
                            destr= true;
                            break;
                        }
                    }

                    if(!neg){
                        st.push(a[i]);
                    }
                }
            }
        } 

        vector<int > arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }

        reverse(arr.begin(), arr.end());

        return arr;
    }

int main(){
    
}