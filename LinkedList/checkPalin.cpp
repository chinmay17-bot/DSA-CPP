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

Node *reverse(Node *head ){
    Node *prev = NULL;
    Node *next;

    Node *temp = (head);
    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;

    }

    return prev; //WHY PREV AS TEMP WILL null AND PREV WILL STORE LAST ELEMENT
}
 
bool isPalindrome(Node* head) {

    //  BRUTE FORCE
        // vector<int> arr;
        // Node *temp = head;
        // while(temp != NULL){
        //     arr.push_back(temp->val);
        //     temp = temp->next;
        // }

        // int n = arr.size()-1;
        // int i = 0;
        // while(i < n){
        //     if(arr[i] != arr[n]) return false;
        //     i++,n--;
        // }
        // return true;



    //OPTIMAL SOLUTION USING TORTOISE AND HARE SOLUTION
        if(head == NULL || head->next == NULL) return true;
        Node *slow = head;
        Node *fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *newHead = reverse(slow->next);
        Node *first = head;
        Node *second = newHead;

        while(second != NULL){
            if(second->val != first->val){
                reverse(slow->next);
                return false;
            }

            second = second->next;
            first = first->next;
        }

        reverse(slow->next);
        return true;
}


int main(){
    
}