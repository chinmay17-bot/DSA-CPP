#include <bits/stdc++.h>
using namespace std;
 
class Node
{
    public:

    int data;
    Node *next;
    Node *back;

    Node(){}

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }

    Node(int data , Node *back , Node *next){
        this->data = data;
        this->next = next;
        this->back = back;
    }

};

void printDLL(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }

    cout << "\n";

}



Node *convertArrToDLL(vector<int> &arr ){
    Node *head = new Node(arr[0]);
    head->next = NULL;
    head->back = NULL;
    Node *prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node *temp = new Node(arr[i] , prev , NULL);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node *reverseAdll(Node *head){

    //BRUTE FORCE 
    //USE A STACK DS TO STORE DATA ANS IN SECOND ITERATION WE UPADATE DATA

    //OPTIMAL
    if(head == NULL || head->next == NULL) return head;

    Node *temp = head;
    Node *prev = NULL;
    Node *nde = head;
    while(temp != NULL){
        prev = temp->back;
        temp->back = temp->next;
        temp->next = prev;

        //NECESSARY TO STORE THE PREVIOUS TO RETURN HEAD
        nde = temp->next;
        temp = temp->back; 
    }
    return nde->back;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    Node *head = convertArrToDLL(arr);

    printDLL(head);

    head= reverseAdll(head);
    
    printDLL(head);
}