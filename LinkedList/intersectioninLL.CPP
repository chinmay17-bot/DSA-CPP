#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


    //BRUTE FORCE SOLUION USING HASHMAP
    // map<ListNode *, int>mp;
    // ListNode *temp = headA;
    // while(temp){
    //     mp.insert({temp , 1});
    //     temp = temp->next;
    // }
    // temp = headB;
    // while(temp != NULL){
    //     if(mp.find(temp) != mp.end()){
    //         return temp;
    //     }
    //     temp = temp->next;
    // }

    // return NULL;


    //OPTIMAL SOLUTION

    ListNode *temp = headA;
        int cnt1 = 0;
        int cnt2 = 0;

        while(temp != NULL){
            cnt1++;
            temp = temp->next;
        }

        temp = headB;
        while(temp != NULL){
            cnt2++;
            temp = temp->next;
        }

        int chk;
        if(cnt1 > cnt2) {

            chk = cnt1-cnt2;

            ListNode *l1 = headA;
            ListNode *l2 = headB;

            while(chk-- && l1 != NULL){
                l1 = l1->next;
            }

            while(l1 != NULL && l2 != NULL){
                if(l1 == l2){
                    return l1;
                }

                l1 = l1->next;
                l2 = l2->next;
            }
        }

        else{
            
            chk = cnt2 - cnt1;

            ListNode *l1 = headA;
            ListNode *l2 = headB;

            while(chk-- && l2 != NULL){
                l2 = l2->next;
            }

            while(l1 != NULL && l2 != NULL){
                if(l1 == l2){
                    return l1;
                }

                l1 = l1->next;
                l2 = l2->next;
            }
        }

        return NULL;

}

int main(){
    
}