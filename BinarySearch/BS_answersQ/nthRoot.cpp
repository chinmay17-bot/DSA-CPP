#include <bits/stdc++.h>
using namespace std;
 
int NthRoot(int n, int m){


    //OPTIMAL WAY
	long long low = 1;
	long long high = m;
	
	while(low <= high){
	    long long mid = (low + high) / 2;
	    long long mm = mid;
	    
	    for(int i = 0; i < n-1; i++){
	        mm = mm * mid;
	        if(mm > m) break;
	    }
	    
	    
	    if(mm > m){
	        high = mid-1;
	    }
	    else if(mm < m){
	        low = mid+1;
	    }
	    else{
	        return mid;
	    }
	}
	
	return -1;
	}  

int main(){
    
}