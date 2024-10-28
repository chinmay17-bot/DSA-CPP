#include <bits/stdc++.h>
using namespace std;
 
float maxDisMin(vector<int> &arr, int k){



    //BRUTE FORCE 
    //THIS IS A BRUTE FORCE SOLUTION AS LINEAR SEACH FOR MAX CAN BE REMOVED
    //BY USING PRIORITY QUEUE AS WE REQUIRE MAX DISTANCE EVERYTIME


    // int n = arr.size();
    // vector<int> between (n-1 , 0);

    // for(int gasstation = 1; gasstation <= k; gasstation++){
    //     int maxIndx = -1;
    //     long double maxSection = -1;

    //     for(int i = 0; i < n-1; i++){
    //         long double diff = arr[i+1] - arr[i];
    //         long double sectionLen = diff / (long double)(between[i]+1);
    //         if(maxSection < sectionLen){
    //             maxSection = sectionLen;
    //             maxIndx = i;
    //         }
    //     }

    //     between[maxIndx]++;

    // }

    // long double ans = -1;
    // for(int i = 0; i < n-1; i++){
    //     long double diff = arr[i+1] - arr[i];
    //     long double sectionLen = diff / (long double)(between[i]+1);

    //     if(ans < sectionLen) ans = sectionLen;
    // }

    // return ans;


    //OPTIMAL USING EXTRA SPACE ENOUGH TO THIS 

    /* INDEXS ARE VERY IMPORTANT IN THIS QUESTIONS TO CALCULATE BETWEEN*/

        int n = arr.size();
        priority_queue<pair<long double ,int>> maxDis ;

        for(int i = 0; i < n-1; i++){
            long double diff =  (arr[i+1] - arr[i]);

            maxDis.push({diff , i});
        }

        vector<int> between (n-1 , 0);

        for(int i = 1; i <= k; i++){
            auto pt = maxDis.top();
            maxDis.pop();
            int indx = pt.second;
            between[indx]++;
            long double diff = (arr[indx+1] - arr[indx]);
            long double sectioLen = diff / (long double)(between[indx]+1);

            //WE REINSERT THE NEW UPDATED DISTANCE BECAUSE WE NEED THE INDEX
            maxDis.push({sectioLen , indx});
        }

        return maxDis.top().first;


        //MOST OPTIMAL SOLUTION IS ONLY BS BUT HARD
        //NOT DONE YET

}



int main(){

}