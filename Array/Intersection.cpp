#include <bits/stdc++.h>
using namespace std;
 
void Intesection(vector<int> a, vector<int> b){
    int n = b.size();
    int vis[n] = {0};
    vector<int> inter;
    

    //USING WHILE FOR BETTER APPROACH

    /*

    int i = 0,j = 0;
    while(i < a.size()){
        while (j < n)
        {
            if(a[i] < b[j]){
                i++;
                break;
            }
            else if(a[i] == b[j]){
                if(vis[j] == 0){
                    vis[j] = 1;
                    inter.push_back(b[j]);
                    i++,j++;
                    break;
                }
            }
            j++;
        }
        
    }

    */

    //USING FOR LOOP
    /*

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] < b[j]){
                break;
            }
            else if(a[i] == b[j]){
                if(vis[j] == 0){
                    vis[j] = 1;
                    inter.push_back(b[j]);
                    break;
                }
            }
        }
    }
    
    */


    //OPTIMAL SOLUTION(2 POINTER)

    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        if(a[i] < b[j]){
            i++;
        }

        else if(a[i] == b[j]){
            inter.push_back(a[i]);
            i++,j++;
        }
        else{
            j++;
        }
    }
    for(auto it: inter){
        cout << it << " ";
    }
    


}

int main(){
    vector<int> a = {1,2,2,3,3,4,5,6};
    vector<int> b = {2,3,3,5,6,7};

    Intesection(a , b);
}