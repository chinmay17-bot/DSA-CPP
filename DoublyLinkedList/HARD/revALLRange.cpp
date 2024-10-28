#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



//FUNCTION TO REVERSE
void revInRange(ListNode *head){

    ListNode* strt = head;
    ListNode *n = NULL;
    ListNode *p = NULL;
    while(strt != NULL){
        ListNode *n = strt->next;
        strt->next = p;
        p = strt;
        strt = n; 
    }
    // return p;
}


//FUNCTION TO FIND KTH ELEMENT
ListNode* findK(ListNode* temp , int k){
    while(temp != NULL && --k){
        temp = temp->next;
    }
    if(temp == NULL && k) return NULL;
    // if(k == 0 && temp != NULL) return NULL;
    return temp;
}



ListNode* reverseKGroup(ListNode* head, int k) {


    //OPTIMAL SOLTUION 
    ListNode* temp = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    while(temp != NULL){
        ListNode* kth = findK(temp , k);


        //IF REMAINING LL DOES NOT CONTAIN K ELEMENTS
        if(kth == NULL) {
            

            //AN EDGE CASE IF LEN OF LL < K
            if(prev) prev->next = temp;
            break;
        }

        //PRESERVING NEXT NODE AFTER K SINCE WE ARE BREAKING IT OFF FOR REVERSAL
        next = kth->next;

        //REV
        kth->next = NULL;
        revInRange(temp);

        //FOR FIRST ITERATION SINCE WE NEED TO UPDATE HEAD
        if(temp == head) head = kth;

        //FOR ALL OTHER REVERSAL
        else{
            prev->next = kth; 
        }

        //STORING TEMP AS PREV AS ITS NEW LAST ELEM AND WILL BE POINTING TO NEW KTH AS IT WILL BE NEW FIRST ELEMENT IN NEXT REVERSAL
        prev = temp;
        temp = next;
    }
    return head;
}

int main(){
    
}