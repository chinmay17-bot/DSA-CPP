#include <bits/stdc++.h>
using namespace std;


bool makeSides(vector<int> &m , int i, vector<int> &sideSum){

    if(i >= m.size() ){

        //It returns if we have used up all the matrix for current arrangement and we either made all sidesum 0 then it was possible to make a square
        return (!accumulate(sideSum.begin() , sideSum.end() , 0));
    }

    //to iterate through sides while trying combinations if sideSum is 0<= tha we try next side
    for(int side = 0 ; side < 4; side++){

        //if true means there is still space in side
        if(m[i] <= sideSum[side]){
            sideSum[side] -= m[i];

            //i+1 to try next matrix
            if(makeSides(m , i+1 , sideSum)) return true;

            //last arrangement didnt give result 
            //so we try another side for this matchstick
            sideSum[side] += m[i];
        }
    }

    return false;

}



bool makeSquare(vector<int> &m){
    if(m.size() < 4) return false;
 
    int sum = accumulate(m.begin() , m.end() , 0);
    if(sum % 4 != 0) return  false;
    vector<int> sideSum (4 , sum/4);
    sort(m.rbegin() , m.rend());


    return makeSides(m , 0 ,sideSum);
}

int main(){
   
}