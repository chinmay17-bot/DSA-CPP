#include<bits/stdc++.h>
using namespace std;





//THIS NOT WRITTEN IN COPY SO SEE VOD IF CONFUSED IN OPTIMAL SOLUTION

vector<int> printLeaders(int arr[], int n) {

    //BRUTE FORCE

    /*
    vector<int> ans;
        int m = INT_MIN;
        for(int i = 0; i < n; i++){
            if(m < arr[i]){
                m = arr[i];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n;j++){
                if(arr[i] < arr[j]){
                    break;
                }
                else if(j == n-1 || arr[i] == m){
                    ans.push_back(arr[i]);
                    break;
                }
            }
        }
        ans.push_back(arr[n-1]);
        return ans;
    */


    //OPTIMAL SOLUTION
  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}

