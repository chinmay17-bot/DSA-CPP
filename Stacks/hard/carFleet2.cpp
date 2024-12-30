#include <bits/stdc++.h>
using namespace std;

//Brute force is to check for each next car and their time 


//Hard problem bit complex understanding but good
//Optimal
 vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n =cars.size();

        vector<double > coltime(n, -1);
        stack<int > st;

        

        for(int i= n-1; i>= 0; i--){
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            while(!st.empty() ){
                double col= (double)(cars[st.top()][0]- cars[i][0])/ (cars[i][1]- cars[st.top()][1]);

                if(coltime[st.top()]== -1|| col<= coltime[st.top()]){
                    coltime[i]= col;
                    break;
                }

                st.pop();
            } 

            st.push(i); 
        }

        return coltime;
    }

int main(){
    
}