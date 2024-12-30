#include <bits/stdc++.h>
using namespace std;


class nStack{
    int *arr, *top, *next;
    int n;
    int size;
    int freeSpot;

    public:
        nStack(int m, int s){
            size= s;
            n= m;
            freeSpot= 0;
            arr= new int[size];
            top= new int[n];
            next= new int[size];


            for(int i= 0; i< n; i++){
                top[i]= -1;
            }

            for(int i= 0; i< size; i++){
                next[i]= i+1;
            }
            next[size-1]= -1;
        }


        bool push(int element, int m){

            //find index
            int index= freeSpot;

            //stack overflown
            if(index > n || index < 0) return false;

            //update freespot
            freeSpot= next[index];

            //insert element
            arr[index]= element;

            //update next or what was index stored 
            next[index]= top[m-1];

            //update top
            top[m-1]= index;

            return true;
        }

        bool pop(int m){

            //get top from mth stack
            int index= top[m-1];

            //stack underflown
            if(index== -1) return false;

            //update the top with index of the prev element inserted when insert top element of mth stack
            top[m-1]= next[index];

            //update the index as free spot
            next[index]= freeSpot;

            //the freespot for next insertion
            freeSpot= index;

            cout << arr[index]<< endl;

            return true;
        }


        ~nStack(){
            delete[] arr;
            delete[] top;
            delete[] next;
        }
};
 
int main(){
    nStack st(3, 6);
    cout << st.push(10,1) << endl; 
    cout << st.push(9,3) << endl; 
    cout << st.push(11,2) << endl; 
    cout << st.push(12,1) << endl; 
    // cout << st.push(10,3) << endl;

    cout << st.pop(1)<<endl; 
    cout << st.pop(2)<<endl; 
    cout << st.pop(3)<<endl; 
}