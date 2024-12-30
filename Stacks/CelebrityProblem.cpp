#include <bits/stdc++.h>
using namespace std;


//Fixed problem question

int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        
        //pushing all into stack
        int n= mat.size();
        for(int i= 0; i < n; i++) st.push(i);
        
        while(st.size()!= 1){
            int a= st.top();
            st.pop();
            int b= st.top();
            st.pop();
            
            if(mat[a][b]== 1){
                st.push(b);
            }
            
            else{
                st.push(a);
            }
        }
        
        //check if last person is a celebrity
        
        int celeb= st.top();
        
        for(int i= 0; i < n; i++){
            if(mat[celeb][i]!= 0) return -1;
        }
        
        for(int i= 0; i < n; i++){
            if(mat[i][celeb]== 0 && i!= celeb) return -1;
        }
        
        return celeb;
    }
 
int main(){
    
}