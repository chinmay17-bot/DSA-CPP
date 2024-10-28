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


//DELETION OF HEAD
Node *deleteHead(Node *head){
    if(head == NULL || head->next ==NULL) return NULL;

    Node *prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete(prev);

    return head;
}

//DELETION OF TAIL
Node *deleteTail(Node *head){

    if(head == NULL || head->next == NULL) return NULL;

    Node *temp = head;
    Node *toReturn = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    Node *prev = temp->back;
    prev->next = NULL;
    temp->back = NULL;

    delete(temp);

    return toReturn;

}


//DELETE KTH ELEMENT
Node *deleteKTHelem(Node *head , int k){
    Node *temp = head;

    if(head == NULL) return NULL;

    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k ) break;
        
        temp = temp->next;
    }
    if(temp->next == NULL && temp->back == NULL) return NULL;

    if(temp == head){
        return deleteHead(head);
    }

    if(temp->next == NULL){
        return deleteTail(head);
    }

    if(temp == NULL) return head;

    Node *prev = temp->back;
    Node *next = temp->next;
    temp->next = NULL;
    temp->back = NULL;

    delete(temp);
    prev->next = next;
    next->back = prev;

    return head;

}


//INSERTION HEAD
Node *insertHead(Node *head, int a){
    Node *temp = new Node(a , NULL , head);
    head->back = temp;

    head = temp;


    return head;
}

//INSERT TAIL
Node *insertTail(Node *head , int a){
    Node *n = new Node(a , NULL , NULL);
    Node *temp = head;

    if(head == NULL || head->next == NULL) return NULL;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->back = temp;


    return head;

}

//INSERT KTH POS
Node *insertkth(Node *head , int a, int k){
    Node *temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    if(temp->back == NULL) return insertHead(head , a);

    if(temp->next == NULL) return insertTail(head , a);

    Node *prev = temp->back;

    Node *num = new Node(a , prev , temp);


    prev->next = num;
    temp->back = num;

    return head;
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

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    Node *head = convertArrToDLL(arr);

    //1 2 3 4 5 6 7 8 9 10 11 12 13
    printDLL(head);

    //DELETE HEAD
    head = deleteHead(head);

    //2 3 4 5 6 7 8 9 10 11 12 13
    printDLL(head);

    //DELETE TAIL
    head = deleteTail(head);

    //2 3 4 5 6 7 8 9 10 11 12 
    printDLL(head);

    //DELETE kth
    head = deleteKTHelem(head , 3);

    //2 3 5 6 7 8 9 10 11 12 
    printDLL(head);

    //INSERT HEAD
    head = insertHead(head , 3);

    //3 2 3 5 6 7 8 9 10 11 12 
    printDLL(head);

    //INSERT TAIL
    head = insertTail(head , 43);

    //3 2 3 5 6 7 8 9 10 11 12 43
    printDLL(head);

    //INSERT TAIL
    head = insertkth(head , 7 , 7);

    //3 2 3 5 6 7 7 8 9 10 11 12 43
    printDLL(head);
}