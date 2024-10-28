#include <bits/stdc++.h>
using namespace std;
 
void longestConsecSubseq(vector<int> &nums){
    
    //BRUTE FORCE SOLUTION BY USING TWO LOOPS AND A LOT OF COUNTERS
        /*
        sort(nums.begin() , nums.end());

        int find;
        int n = nums.size();
        if(n == 0) return 0;
        int j;
        int inc;
        int cnt;
        int len = 1;
        for(int i = 0; i < n-1; i++){
            cnt = 1;
            j = i+1;
            find = nums[i]+1;
            while(j < n){
                if(nums[j] == find){
                    cnt++;
                    inc++;
                    find += 1;
                    j = i+1;
                }
                else{
                    j++;
                }
            }

            len = max(len , cnt);
        }

        return len;
        */


//BETTER WAY IS TO DO IT BY USING SORT SUCH TO ONLY CHK IF LAST ELEMENT IS SMALLER THAN PREVIOUS ONE NOT
    
    
    /*
    int n = nums.size();
        if(n == 0) {
            cout << 0;
            return;
        };
        
    sort(nums.begin() , nums.end());
    int cnt = 1;
    int len = 1;
    int lastSm = nums[0];
    int i = 1;
    while (i < n)
    {
        if(lastSm+1 == nums[i]){
            cnt++;
            lastSm = nums[i];
        }
        else if(lastSm+1 < nums[i]){    //THE MOMENT WE FIND THAT NEXT ELEMENT IS LARGER THE 
                                        //SAMLLER+1 THEN CHANGE COUNTER TO 0 SINCE ARRAY IS SORTED NO SMALLER+1
                                        //(CONSECUTIVE) ELEMENT CAN BE FOUND
            cnt = 1;
            lastSm = nums[i];
        }
        len = max(len , cnt);
        i++;

    }
    
        cout<< len;

    */


   //OPTIMAL SOLUTION USING SETS
   unordered_set<int> st;

   for(auto it : nums){
        st.insert(it);
   }
   int len = 0;

   for(auto it : st){
        if(st.find(it -1) == st.end()){
            int cnt = 1;
            int x = it;
            while (st.find(x+1) != st.end())
            {
                cnt++;
                x+=1;
            }

            len = max(len , cnt);
            
        }
   }
   cout << len;
}


int main(){
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    longestConsecSubseq(arr);
}