#include <bits/stdc++.h>
using namespace std;
 
//Brute force way is to user 2 loops

//optimal way is by using 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp= head;
        stack<int > st; 

        vector<int > arr;

        while(temp){
            arr.push_back(temp->val);
            temp= temp->next;
        }
        int n= arr.size();

        vector<int> ans (n, 0);
        for(int i= 0;i <n  ;i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                ans[st.top()]= arr[i];
                st.pop();
            }

            st.push(i);
        }
        

        return ans;
    }

int main(){
    
}