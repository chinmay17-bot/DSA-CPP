#include <bits/stdc++.h>
using namespace std;
     

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

    void nextSmallerEle(vector<int>& heights, vector<int> &npos){
        stack<int> st;

        st.push(-1);
        int n= heights.size();
        for(int i= n-1; i>= 0; i--){
        
                //we are not doing heights[st.top()] >= heights[i] as we can also include equal elements as long as its not smaller we dont change the prevsmaller as the solution will repeat
                while(st.top()!= -1 && heights[st.top()] > heights[i]){
                    st.pop();

                }
            

            npos.push_back(st.top());
            st.push(i);
        }
        
        reverse(npos.begin(), npos.end());

    }

    void prevBiggerEle(vector<int>& heights, vector<int> &ppos){
        stack<int> st;

        st.push(-1);
        int n= heights.size();
        for(int i= 0; i< n; i++){

        while(st.top()!= -1 && heights[st.top()] <= heights[i]){
            st.pop();
        }
        

            ppos.push_back(st.top());
            st.push(i);
        }

    }

    void nextBiggerEle(vector<int>& heights, vector<int> &npos){
        stack<int> st;

        st.push(-1);
        int n= heights.size();
        for(int i= n-1; i>= 0; i--){
        
                //we are not doing heights[st.top()] <= heights[i] as we can also include equal elements as long as its not smaller we dont change the prevsmaller as the solution will repeat
                while(st.top()!= -1 && heights[st.top()] < heights[i]){
                    st.pop();

                }
            

            npos.push_back(st.top());
            st.push(i);
        }
        
        reverse(npos.begin(), npos.end());

    }

    long long sumMin(vector<int>&arr, vector<int>&npos, vector<int>&ppos){
        long long sum= 0;
        int n= arr.size();
        for(int i= 0; i< n; i++){
            int right= npos[i]== -1 ? n: npos[i];
            int left= ppos[i];

            left= left- i;
            right= i- right;

            sum+= (left*right*arr[i]);
        }

        return sum;
    }

    long long sumMax(vector<int>&arr, vector<int>&npos, vector<int>&ppos){
        long long sum= 0;
        int n= arr.size();
        for(int i= 0; i< n; i++){
            int right= npos[i]== -1 ? n: npos[i];
            int left= ppos[i];

            left= left- i;
            right= i- right;

            sum+= (left*right*arr[i]);
        }

        return sum;
    }


    long long subArrayRanges(vector<int>& arr) {
        vector<int> npos;
        vector<int> ppos;
        vector<int> mnpos;
        vector<int> mppos;
        nextSmallerEle(arr, npos);
        prevSmallerEle(arr, ppos);
        nextBiggerEle(arr, mnpos);
        prevBiggerEle(arr, mppos);

        long long sum= 0;
        sum= sumMin(arr, npos, ppos);
        long long sum1= sumMax(arr, mnpos, mppos);
        return (sum1-sum);


    }


    int main(){
        
    }