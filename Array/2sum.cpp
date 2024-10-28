#include <bits/stdc++.h>
using namespace std;


vector<int> twoSum(int arr[] , int n , int target){

//BRUTE FORCE SOL


/*
vector<int> ans;
        int n = nums.size();
        int sum = 0;
        bool chk = false;
        for(int i = 0; i < n; i++){
            if(chk){
                break;
            }
            sum = 0;
            for(int j = 0; j < n; j++){
                if(i == j){
                    break;
                }
                sum = nums[i] + nums[j];

                if(sum == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    chk = true;
                    break;
                }
            }
        }

        return ans;

*/


//BETTER SOLUTION

/*


    map<int,int> mp;
    int rem = 0;
    for (int i = 0; i < n; i++)
    {
        rem = target - arr[i];
        if(mp.find(rem) != mp.end()){
            return{mp[rem] , i};
        }
        mp[arr[i]] = i;

        return {-1,-1};

    }
    
*/

    sort(arr , arr+n);
    int i = 0;
    int j = n-1;
    int sum = 0;
    while (i != j)
    {
        sum = arr[i]+arr[j];
        if(sum > target){
            sum-=arr[j];
            j--;
        }

        else if(sum < target){
            sum-=arr[i];
            i++;
        }

        else{
            return {i , j};
        }

        return {-1 , -1};
    }
    

}
 
int main(){
    int n = 4;
    int arr[n] = {2,7,11,15};
    int target = 9;
    vector<int> sol = twoSum(arr , n , target);
}