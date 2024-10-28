#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



//MOST OPTIMAL WAY 
ListNode *mergeLinkedList(ListNode *list1 ,ListNode* list2){
    //CREATE A DUMMY STARTING POINT FOR OUR LINKED LIST
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            temp->next = list1;
            list1 = list1->next;
        }

        else{
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if(list1) temp->next = list1;

    else temp->next = list2;
    


    return dummyNode->next;
}


ListNode *findMiddle(ListNode *head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}

ListNode *sortLinkedList(ListNode *head){
    
    //edge case / base case in recursive call
    if(head == NULL || head->next == NULL) return head;

    ListNode *middle = findMiddle(head);
    
    // ORDER OF ASSIGNING NEWRIGHT AND LEFT IS IMPORTANT AS WE DISCONNECT MIDDLE TO GET TWO SEPERATE
    // LINKED LIST
    ListNode *rightHead = middle->next;
    middle->next = NULL;

    ListNode *leftHead = head;

    leftHead = sortLinkedList(leftHead);
    rightHead = sortLinkedList(rightHead);

    return mergeLinkedList(leftHead , rightHead);

}


int main(){
    ListNode *head = new ListNode(3);
    //ListNode *newHead = sortLinkedList(head);

}