#include <bits/stdc++.h>
using namespace std;
 

vector<int> maxSlidingWindow(vector<int>& nums, int k) {


    deque<int> que;
    vector<int> ans;
    //window creation
    for(int i= 0; i< k; i++){
        while(!que.empty() && nums[que.back()]< nums[i]){
            que.pop_back();
        }
        que.push_back(i);
    }
    //Initial entry

    ans.push_back(nums[que.front()]);
    for(int i= k; i< nums.size(); i++){
        //removal
        if(!que.empty() && (i- que.front()>= k)){
            que.pop_front();
        }
        //as new element just entered in the window remove the smaller elements as it can nevewr be an answer now 
        while(!que.empty() && nums[que.back()]< nums[i]){
            que.pop_back();
        }
        que.push_back(i);
        //Insert answer
        ans.push_back(nums[que.front()]);
    }

    
    return ans;
}



int main(){
    
}