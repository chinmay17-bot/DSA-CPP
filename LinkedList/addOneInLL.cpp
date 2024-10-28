#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *reverseList(Node **head ){
        Node *prev = NULL;
        Node *next;
    
        Node *temp = (*head);
        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;

        }

        return prev; //WHY PREV AS TEMP WILL null AND PREV WILL STORE LAST ELEMENT
}


int addition(Node *temp){

    //SINCE RECURSIVE CALL GOES TILL THE END WE DO NEED TO ADD 1 ATQ
    if(temp == NULL) return 1;
    
    //FROM END WE ADD THE RESULTING CARRY AFTER EACH OPERATION
    int carry = addition(temp->next);
    temp->data += carry;
    
    if(temp->data < 10) return 0;
    
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head) {
        

        //BRUTE FORCE METHOD USING REVERSE 2 TIMES 
        //TC O(3N)
        
        // head = reverseList(&head);
        // int carry = 1;
        // Node *temp = head;
        // while(temp != NULL){
            // temp->data += carry;
            // if(temp->data == 10){
                // temp->data = 0;
                // carry = 1;
            // }
            // 
            // else{
                // carry = 0;
            // }
            // 
            // temp = temp->next;
        // }
        // 
        // if(carry){
            // head = reverseList(&head);
            // Node *newHead = new Node(1);
            // newHead->next = head;
            // head = newHead;
        // }
        // 
        // else{
            // head = reverseList(&head);
        // }
        // 
        // return head;

        //OPTIMAL METHOD USING RECURSION
    
        
        Node *temp = head;

        //RECURSIVE CALL FOR CARRY ADDITION

        int carry = addition(temp);
        
        //IF NUMBER OF DIGITS INCREASES
        if(carry){
            Node *newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
        
        return head;
}


int main(){
    
}