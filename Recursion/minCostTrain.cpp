#include <bits/stdc++.h>
using namespace std;

int costCalculator(vector<int>&days , vector<int>&cost ,int i){
    if(i >= days.size()) return 0;


    int cost1 = cost[0] + costCalculator(days , cost , i+1);

    int j = i;
    int nxtday = days[i] + 7 -1;
    while(days.size() > j && days[j] <= nxtday ) j++;

    int cost7 = cost[1] + costCalculator(days , cost , j);

    j = i;
    nxtday = days[i] + 30 -1;
    while(days.size() > j && days[j] <= nxtday) j++;

    int cost30 = cost[2] + costCalculator(days , cost , j);

    return min(cost1 , min(cost7 , cost30));
}

int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> cost = {2,7,15};
    cout << costCalculator(days, cost , 0);
}