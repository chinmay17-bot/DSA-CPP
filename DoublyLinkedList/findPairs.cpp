#include <bits/stdc++.h>
using namespace std;
 
 
//Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {


        // BRUTE FORCE BUT WILL NOT WORK FOR DUPLICATE ELEMENTS
        map<int,int> mp;
        Node *temp = head;
        while(temp != NULL){
            mp.insert({temp->data , 1});
            temp = temp->next;
        }
        
        vector<pair<int , int>> res;
        
        temp = head;
        while(temp != NULL){
            int diff = target - temp->data;
            if(mp.find(diff) != mp.end() && diff != temp->data){
                pair<int ,int> num = {temp->data , diff};
                res.push_back(num);
            }
            mp.erase(diff);
            mp.erase(temp->data);
            temp = temp->next;
        }
        
        return res;

        //BRUTE ANOTHER WAY
        //temp1 starts from head and we do double loop with temp2 (from next of temp1) to find the satifying temp1->data + temp2->data = target BREAK SECOND LOOP IF NULL OT IF SUM > TARGET



        //OPTIMAL SOLUTION

         Node *end = head;
        Node *strt = head;
        while(end->next != NULL){
            
            end = end->next;
        }
        
        vector<pair<int , int>> res;
        while(strt->data < end->data){
            int sum = strt->data + end->data;
            if(sum > target) {
                end = end->prev;
            }
            
            else if(sum <  target){
                strt = strt->next;
            }
            
            
            else{
                res.push_back({strt->data , end->data});
                strt = strt->next;
                end = end->prev;
            }
        }
        
        return res;
        
    }

int main(){
    
}