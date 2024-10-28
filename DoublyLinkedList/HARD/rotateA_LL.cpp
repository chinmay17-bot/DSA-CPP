#include <bits/stdc++.h>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *kthNode(ListNode *head , int k){
    ListNode* temp = head;
    while(temp != NULL && --k){
        temp = temp->next;
    }
    return temp;
}

ListNode* rotateRight(ListNode* head, int k) {

    //OPTIMAL 
    if(head == NULL || head->next == NULL) return head;
    int cnt = 1;
    ListNode *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
        cnt++;
    }

    if(k % cnt == 0) return head;
    k = k%cnt;
    
    ListNode *temp = head;
    ListNode *kth = kthNode(temp , cnt-k);
    cout << kth->val;
    
    ListNode *newHead = kth->next;
    tail->next = head;
    kth->next = NULL;
    return newHead;
}


int main(){
    
}