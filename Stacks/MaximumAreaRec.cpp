#include <bits/stdc++.h>
using namespace std;
 


//brute force is to check for each element till where its width reaches 

//optimal way is using the nextSmallest and prevSmallest

    void nextSmallerEle(vector<int>& heights, vector<int> &npos){
        stack<int> st;

        st.push(-1);
        int n= heights.size();
        for(int i= n-1; i>= 0; i--){
        
                while(st.top()!= -1 && heights[st.top()] >= heights[i]){
                    st.pop();

                }
            

            npos.push_back(st.top());
            st.push(i);
        }
        
        reverse(npos.begin(), npos.end());

    }

    void prevSmallerEle(vector<int>& heights, vector<int> &ppos){
        stack<int> st;

        st.push(-1);
        int n= heights.size();
        for(int i= 0; i< n; i++){

        while(st.top()!= -1 && heights[st.top()] >= heights[i]){
            st.pop();
        }
        

            ppos.push_back(st.top());
            st.push(i);
        }

    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> npos;
        vector<int> ppos;

        nextSmallerEle(heights, npos);
        prevSmallerEle(heights, ppos);

        int area= INT_MIN;
        int n= heights.size();

        if(n == 1) return heights[0];
        for(int i= 0; i< n; i++){
            int leftWidth= ppos[i] == -1 ? 0 : ppos[i];
            int rightWidth= npos[i] == -1 ? n : npos[i];
            

            int tempAr= (rightWidth- leftWidth -1) * heights[i];

            area= max(area, tempAr);
        }

        return area;

    }


int main(){


}