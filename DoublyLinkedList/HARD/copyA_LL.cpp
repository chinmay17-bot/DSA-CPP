#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


Node* copyRandomList(Node* head) {


    //WOULDVE BEEN EASY IF NOT FOR RANDOM POINTER AS WE DONT KNOW DURING COPYING THAT WHATS NUMBER IT IS POINTING TO

    //BRUTE FORCE (BY USING MAP TO KEEP NODES AS KEY AND VALUE)
    // Node* temp = head;
    //     Node* dummyNode = new Node(-1);
    //     Node* res = dummyNode;

    //     map<Node*,Node*> mp;
 
    //     while(temp){
    //         Node *nn = new Node(temp->val);
    //         mp[temp] = nn;
    //         temp = temp->next;
    //     }

    //     temp = head;
    //     // dummyNode = temp;
    //     while(temp){
    //         Node *copy = mp[temp];
    //         copy->next = mp[temp->next];
    //         copy->random = mp[temp->random];
    //         temp = temp->next;
    //     }

    // return mp[head];




    //OPTIMAL WAY ( 3 PASSES ARE DONE AS 3 STEPS ARE PERFORMED )
    Node *temp = head;

    //CREATING NEW NODES TO NOT LOOSE TRACK OF THEM 
    while(temp != NULL){
        Node *newNode = new Node(temp->val);
        Node *next = temp->next;
        temp->next = newNode;
        newNode->next = next;
        temp = temp->next->next;
    }


    //CONNECTING RANDOM POINTERS 

    temp = head;
    while(temp != NULL){
        Node *copy = temp->next;
        
        if(temp->random){
            copy->random = temp->random->next;
            
        }
        else{
            copy->random = NULL;
        }
        temp = temp->next->next;
    }
    //CONNECTING NEXT POINTERS
    //DURING RECONNECTION IT IS IMPORTANT TO MAKE SURE THAT TO RECONFIGURE THR PREVIOS LL

    temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while(temp != NULL){
        res->next = temp->next;
        res = temp->next;
        if(temp->next->next)
        temp->next = temp->next->next;
        else
        temp->next = NULL;
        temp = temp->next;
    }
    return dummyNode->next;
    }
 
int main(){
    
}