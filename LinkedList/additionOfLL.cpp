#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


    int carry = 0;
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    ListNode *res = new ListNode(-1);

    //FOR RETURNING HEAD OF RESULT
    ListNode *dummy = res;

    //ADDITION NODE BY NODE
    while(t1 != NULL && t2 != NULL){
        int sum = t1->val + t2->val + carry;
        ListNode *temp = new ListNode(sum%10);
        if(sum < 10){
            carry = 0;
        }
        else{
            carry = 1 ;
        }
        res->next = temp;
        res = temp;
        t1 = t1->next;
        t2 = t2->next;
    }

    //CHECKING WHICH ONE HAS REMAINING NODES SO WE CAN ADD THE CARRY IF EXIST
    ListNode *rem = (t1) ? t1 : t2;
    while(rem != NULL){
        int sum = rem->val + carry;
        ListNode *temp = new ListNode(sum%10);
        if(sum < 10){
            carry = 0;
        }
        else{
            carry = 1 ;
        }
        res->next = temp;
        res = temp;
        rem = rem->next;
    }


    //IF CARRY REMAINS AT LAST ADD ANOTHER NODE AT THE END
    if(carry){
        ListNode *end = new ListNode(1);
        res->next = end;
    }
    return dummy->next;
}

int main(){
    
}