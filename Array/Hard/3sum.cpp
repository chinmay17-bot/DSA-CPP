#include <bits/stdc++.h>
using namespace std;

void _3sum(vector<int> &arr){



    //BRUTE FORCE SOLUTION O(N3)

    /*


    set<vector<int>> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(arr[i] +arr[j] + arr[k] == 0){
                    vector<int> a;
                    a.push_back(arr[i]);
                    a.push_back(arr[j]);
                    a.push_back(arr[k]);

                    //TO MAKE SURE THAT WO DONT INPUT SAME NUMBERS 
                    sort(a.begin() , a.end());
                    ans.insert(a);
                }
            }
            
        }
        
    }


    //TO CONVERT SET OF VECTORS TO VECTOR OF VECTORS
    vector<vector<int>> ans(ans.begin() , ans.end());
    */



    //TO BETTER SOLTUION O(N2) USING SETS

    /*
    
    set<vector<int>> ans;
    int n = arr.size();
    
    for(int i = 0; i < n; i++){

        set<int> hashset;

        for(int j = i+1; j < n; j++){
            int diff = -(arr[i]+arr[j]);
            if(hashset.find(diff) != hashset.end()){
                vector<int> temp = {arr[i] , arr[j] , (diff)}; 
                sort(temp.begin() , temp.end());
                ans.insert(temp);
            }

            hashset.insert(arr[j]);

        }

    }

    vector<vector<int>> sol (ans.begin() , ans.end());

    */


    set<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin() , arr.end());
    
    for (int i = 0; i < n; i++)
    {

        //THIS CONDITION IS NECESSARY FOR AVOIDING SAME arr[i] SINCE IT will GENERATE SAME PAIR OF arr[j] arr[k]
        //WE CAN USE SETS TO AVOID SAME PAIRS INSERTION BUT THATS AN ADDED OPRATION INSTEAD JUST CHEK IF SAME 
        //ELEMENT THEN SKIP

        if(i > 0 && arr[i] != arr[i-1]) continue;

        int j = i+1;
        int k = n-1;

        while(j < k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }

            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                // sort(temp.begin() , temp.end()); ALREADY SORTED

                ans.insert(temp);

                k--;
                j++;


                //THESE CONIDITOINS ARE NECESSARY TO NOT INCLUDE SAME PAIRS WITH arr[i] AGAIN
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;


            }

        }
        vector<vector<int>> sol (ans.begin() , ans.end());
    }
    
}
 
int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    _3sum(arr);
}