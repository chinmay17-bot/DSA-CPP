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
    // Node (){}
    // Node(int data){
    //     this->data = data;
    //     this->next = NULL;
    // }

    // void setter(int data){
    //     this->data = data;
    //     this->next = NULL;
    // }

    // int getter(){
    //     return this->data;
    // }

};



//PRINT A LINKED LIST
void printList(Node **head){
    
    //head -> d1 -> d2 ... dn -> NULL
    //last one will be missed
    Node *temp = (*head);
    while (temp != NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next;
    }

    cout << "\n______________________________________\n";


}

//INSERT FUNCTIONS

//before HEAD
void insertAtStart(Node **head , int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = (*head);

    (*head) = temp;
}


//after TAIL

void insertAtEnd(Node **head , int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;

    Node *itr = (*head);

    while (itr->next != NULL)
    {
        itr = itr->next; 
    }
    itr->next = temp;
}



//Append data of a list to a linked list
void enterAList(Node **head , vector<int> &data){
    Node *temp = (*head);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    for (int i = 0; i < data.size(); i++)
    {
        temp->next = new Node(data[i]);
        temp = temp->next;
    }
    
    
}

//Reverse a linked list
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

Node *reverseListRecursive(Node *prev , Node **head , Node *next){
    if((*head) == NULL){
        return prev;
    }

    Node *temp = (*head);

    (next) = (temp)->next;
    (temp)->next = (prev);
    (prev) = (temp);
    (temp) = (next);
    reverseListRecursive(prev , &temp , next);
}


int main(){
    Node *d1 = new Node;
    d1->data = 4;
    d1->next = NULL;

    Node *head = new Node;
    head->data = 3;
    head->next = d1;


    //INITIAL LIST 3 -> 4
    printList(&head);


    //ENTER ELEMENT AT START
    insertAtStart(&head , 2);

    //NEW LIST 2 -> 3 -> 4
    printList(&head);


    //ENTER ELEMENT AT END
    insertAtEnd(&head , 5);

    //NEW LIST 2 -> 3 -> 4 -> 5
    printList(&head);


    //ENTER LIST OF ELEMENTS
    vector<int> data = {8,8,8};
    enterAList(&head , data);

    //NEW LIST 2 -> 3 -> 4 -> 5 -> 8 -> 8 -> 8
    printList(&head);

    //DELETION OF NODES


    //REVERSE A LL 2 <- 3 <- 4 <- 5 <- 8 <- 8 <- 8
    Node *Newhead = reverseList(&head);
    printList(&Newhead);


     //REVERSE AGAIN USING RECURSION
    Node *againbNewHead = reverseListRecursive(NULL , &Newhead , NULL);
    printList(&againbNewHead);
        

}