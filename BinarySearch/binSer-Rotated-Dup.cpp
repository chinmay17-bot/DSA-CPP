#include <bits/stdc++.h>
using namespace std;



bool search(vector<int> &nums , int target){
    int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                return true;
            }

            //EXTRA CONDITION FOR IF ALL THREE ARE EQUAL

           
            if(nums[low] == nums[high] && nums[low] == nums[mid]){
                
                high--;
                low++;
                continue;
            
            }
            
            
            //LEFT IS SORTED
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && nums[mid] >= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            //RIGHT IS SORTED
            else{
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
}
 
int main(){
   vector<int> arr = {2,5,6,0,0,1,2};
   bool found = search(arr , 0);
   cout << found;
}