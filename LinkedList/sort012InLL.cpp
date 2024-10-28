#include <bits/stdc++.h>
using namespace std;
  
  
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


Node *sort012(Node *head){
    //BRUTE FORCE IS TO COUNT ALL THE 012 AND MODIFY THE LL

    //OPTIMAL WAY

    // TO KEEP HEADS
    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);

    //FOR TRAVERSAL IN LL
    Node *zero = zerohead;
    Node *one = onehead;
    Node *two = twohead;

    Node *temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }

        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }

        else{
            two->next = temp;
            two = two->next; 
        }

        temp = temp->next;
    }

    zero->next = (onehead->next) ? onehead->next : twohead->next;
    one->next = twohead->next;
    two->next = NULL;

    return zerohead->next;

}

int main(){
    
}