#include <bits/stdc++.h>
using namespace std;
 
void findN3major(vector<int> &arr){
    //BRUTE FORCE SOL IS COUNT EACH ELEMENT AND RETURN STORE THOSE WHOSE COUNT IS GREATER THAN N/3


    //BETTER WAY USING HASHMAPS


    /*
    int n = (arr.size()/3);
    vector<int> ans;

    map<int,int> mpp;
    for(auto it : arr){
        mpp[it]++;
    }

    for(auto it : mpp){
        if(it.second == n+1){
            ans.push_back(it.first);
        }
    }

    for(auto it:ans){
        cout << it <<" ";
    }

    */


   //OPTIMAL WAY
   //BY 2 POINTER

    /*
    sort(arr.begin(), arr.end());
    vector<int> ans;
    int i = 0;
    int j = 0;
    int cnt = 0;
    int n = (arr.size()/3);
    while(i < arr.size() && j < arr.size()){
        if(arr[i] == arr[j]){
            cnt++;
            j++;
        }
        else{
            if(cnt > n){
                ans.push_back(arr[i]);
            }
            i = j;
            cnt = 0;
        }
    }

    if(cnt > n){
        ans.push_back(arr[arr.size()-1]);
    }

        
    for(auto it:ans){
        cout << it <<" ";
    }
    */


    //BY MODIFIED MOORES ALGORITHM
    //WE CAN NOTICE FROM TEST CASES AND EXAMPLES THAT ATMOST
    //2 NUMBERS CAN BE IN THE ANSWER VECTOR
    vector<int> ans;

    int el1 = INT_MIN;
    int el2 = INT_MIN;

    int cnt1 = 0;
    int cnt2 = 0;
    int n = (arr.size()/3);

    for(int i = 0; i < arr.size(); i++){
        if(cnt1 == 0 && el2 != arr[i]){
            cnt1 = 1;
            el1 = arr[i];
        }

        else if(cnt2 == 0 && el1 != arr[i]){
            cnt2 = 1;
            el2 = arr[i];
        }

        else if(el1 == arr[i]) cnt1++;
        else if(el2 == arr[i]) cnt2++;

        else{
            cnt1--,cnt2--;
        } 
    }

    cnt1 = 0;
    cnt2 = 0;

    for(auto it : arr){
        if(it == el1){
            cnt1++;
        }
        if(it == el2){
            cnt2++;
        }
    }

    if(cnt1 > n){
        ans.push_back(el1);
    }

    if(cnt2 > n){
        ans.push_back(el2);
    }

    
    for(auto it:ans){
        cout << it <<" ";
    }


}


int main(){
    vector<int> arr = {3,2,3};
    findN3major(arr);
}