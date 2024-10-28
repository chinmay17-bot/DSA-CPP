#include <bits/stdc++.h>
using namespace std;

int secLar(vector<int> &arr){
    //BRUTE BY COMPARING ALL

    //BETTER BY SORTING


    //OPTIMAL WAY
    int lar = arr[0];
    int secLr = -1;
    
    for (int i = 1; i < arr.size(); i++)
    {   
        if(lar < arr[i]){
            secLr = lar;
            lar = arr[i];
        }
        else if(arr[i] > secLr && arr[i] < lar){
            secLr = arr[i];
        }

    }

    return secLr;
    

}

 
int main(){
    vector<int> arr = {1,2,3,0,3,4,0,0,4,2};
    int n = secLar(arr);
    cout << n;
}