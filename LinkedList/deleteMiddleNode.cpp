#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node *next;

    Node(){}

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
}; 

Node* deleteMiddle(Node* head) {


    //BRUTE FORCE SOLUTION
        // Node *temp = head;
        // int cnt = 0;

        // if(head == NULL || head->next == NULL){
    
        // return NULL;
        // } 
        // while(temp != NULL){
        //     cnt++;
        //     temp = temp->next;
        // }

        // cnt/=2;
        // temp = head;
        // while(temp != NULL){
        //     cnt--;
        //     if(cnt == 0){
        //         temp->next = temp->next->next;
        //         break;
        //     }

        //     temp = temp->next;
        // }

        
        
        
        //OPTIMAL SOLUTION
        //USIONG TORTOISE AND HARE ALGO TO FIND MIDDLE THEN IF NEXT NODE == SLOW 
        //THEN NODE->NEXT = NODE->NEXT->NEXT


        return head;
    }

int main(){
    
}