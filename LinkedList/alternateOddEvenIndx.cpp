#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int val;
    Node *next;

    Node(){}

    Node(int data){
        this->val = data;
        this->next = NULL;
    }
};

Node *alterIndex(Node *head){ 

    //BRUTE FORCE USING EXTRA DATA ARRAY
    // vector<int> arr;
    //         if(head == NULL || head->next == NULL) return head;
    //         Node *temp = head;
    //         while(temp != NULL && temp->next != NULL){
    //             arr.push_back(temp->val);
    //             temp = temp->next->next;
    //         }

    //         if(temp){
    //             arr.push_back(temp->val);
    //         }

    //         temp = head->next;

    //         while(temp != NULL && temp->next != NULL){
    //             arr.push_back(temp->val);
    //             temp = temp->next->next;
    //         }


    //         if(temp){
    //             arr.push_back(temp->val);
    //         }

    //         temp = head;
    //         int i = 0;
    //         while(temp != NULL){
    //             temp->val = arr[i];
    //             i++;
    //             temp = temp->next;
    //         }

    //     return head;

        //OPTIMAL USING POINTERS 

        if(head == NULL || head->next == NULL) return head;
        Node *odd = head;
        Node *even = head->next;
        Node *evenhead = even;
        Node *temp = odd;
        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = evenhead;
        return temp;

}

int main(){
    
}