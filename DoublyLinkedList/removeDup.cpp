#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
 


Node * removeDuplicates(struct Node *head)
    {
        // THIS WAY WILL DELETE DUPLICATE ELEMENTS ONE BY ONE WHICH CAN BE OPTIMISED TO REMOVE ALL DUPLICATE IN BETWEEN

        
        Node *temp = head->next;
        while(temp != NULL){
            if(temp->data == temp->prev->data){
                Node *prev = temp->prev;
                Node *next = temp->next;
                
                if(prev) prev->next = next;
                if(next) next->prev = prev;
                
                temp->next = NULL;
                temp->prev = NULL;
                
                delete(temp);
                
                temp = next;
            }
            
            else{
                temp = temp->next;
            }
        }
        
        return head;
    }

int main(){
    
}