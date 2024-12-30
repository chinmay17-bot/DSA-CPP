#include <bits/stdc++.h>
using namespace std;




//THIS IS BEST SOLUTION USING STACKS
//good question 
 
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> cars;
    int n= speed.size();
    for(int i= 0;i< n; i++){
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.begin(), cars.end());
    vector<float> time;
    for(auto it: cars){
        int dis= abs(target- it.first);
        time.push_back((float)dis/ it.second);
    }
    stack<float > stk;
    for(int i= 0;i < n; i++){
        while(!stk.empty() && stk.top()<= time[i]){
            stk.pop();
        }
        stk.push(time[i]);
    }
    return stk.size();
}
int main(){
    
}