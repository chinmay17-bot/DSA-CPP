#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals){
    int n = intervals.size();
    vector<vector<int>> res;


    //BRUTE FORCE SOLUTION
    // sort(intervals.begin() , intervals.end());


    // for(int i = 0 ; i < n; i++){
    //     if(!res.empty() && res.back()[1] >= intervals[i][1]) continue;

    //     int start = intervals[i][0]; 
    //     int end = intervals[i][1];

    //     for(int j = i+1; j < n ; j++) {
    //         if(end >= intervals[j][0]){
    //             end = max(end , intervals[j][1]);
    //         }

    //         else{
    //             break;
    //         }
    //     }

    //     vector<int> temp = {start , end};
    //     res.push_back(temp);
    // }



    //IN OPTIMAL SOLUTION WE JUST OPTIMISE THE FACT THAT WE ARE RECHECKING IN J = I+1
    //IN SINGLE ITERATION WE TRY TO JUMP TO NEXT PAIR WHICH IS  NOT IN CURRENT INTERVAL


    for(int i = 0; i < n; i++){
        if(res.empty() || res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
        

        else{
            int end = intervals[i][1];
            res.back()[1] = max(res.back()[1] , end);
        }
    }

    return res;
}

int main(){
    
}