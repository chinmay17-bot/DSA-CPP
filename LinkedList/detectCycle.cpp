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

bool cycleDetection(Node *head){


    //BRUTE FORCE SOLUTION

    /*
    map<Node *, int> mp;
    Node *temp = head;
    while(temp != NULL){
        if(mp.find(temp) != mp.end()) return true;
        
        mp.insert({temp , 1});
        temp = temp->next;

    }

    return false;
    */

   //OPTIMAL SOLUTION USING TORTOISE AND HARE ALGO
   Node *fast = head;
   Node *slow = head;

   while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
    
    if(fast == slow) return true;
    
   }

   return false;
}

int main(){
   
}