#include <bits/stdc++.h>
using namespace std;
 
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

Node *mergeTwoLL(Node *l1 , Node *l2){
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            temp->bottom = l1;
            temp = l1;
            l1 = l1->bottom;
        }
        
        
        else{
            temp->bottom = l2;
            temp = l2;
            l2 = l2->bottom;
        }
        
        
    }
    
    if(l1) temp->bottom = l1;
    if(l2) temp->bottom = l2;
    
    return dummyNode->bottom;
}


Node *linkedList(vector<int> &arr){
        Node *head =  new Node(arr[0]);
        Node *temp =head ;
        int n = arr.size();
        for(int i = 1; i < n; i++){
            // cout << it;
            Node *data = new Node(arr[i]);
            temp->bottom = data;
            temp = temp->bottom;
        }
        
        return head;
    }

Node *flatten(Node *root) {


    // BRUTE FORCE USING EXTRA SPACE AND O(NLOGN) FOR SORTING
    // vector<int> arr ;
    // Node *temp = root;
    
    // while(temp != NULL){
    //     Node *top = temp;
    //     while(top != NULL){
    //         // cout << top->data <<" ";
    //         arr.push_back(top->data);
    //         top = top->bottom;
    //     }
        
    //     temp = temp->next;
    // }
    // sort(arr.begin() , arr.end());
    
    // return linkedList(arr);


    
    
    //OPTIMAL (TH IN  COPY EASY TO UNDERSTAND)
    if(root == NULL || root->next == NULL) return root;
        
        
        Node* newHead = flatten(root->next);
        Node* mergedHead = mergeTwoLL(root , newHead);
        
    return mergedHead;
}


int main(){
    
}