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


    Node* removeNthFromEnd(Node* head, int n) {
        //BRUTE FORCVE IS TO COUNT NUMBER OF ELEMENTS AND THE DELETE THE COUNT-NTH NODE


        

        //OPTIMAL WAY 
        // cout << head <<endl;
        Node *fast = head;
        while(n--){
            fast = fast->next;
        }

        if(fast == NULL) return head->next;

        Node *slow = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        Node *del = slow->next;
        slow->next = slow->next->next;
        // free(del);

        return head;
}

int main(){
    
}