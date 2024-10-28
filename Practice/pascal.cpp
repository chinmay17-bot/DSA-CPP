#include <bits/stdc++.h>
using namespace std;
 
int fact(int n){
    if(n == 1 || n == 0) return 1;

    return n * fact(n-1);
}

int ncr(int n , int r){
    int num = fact(n);
    int dom = fact(r) * fact(n-r);

    return (num/dom);
}

void pascaltri(int n){
    vector<vector<int>> ans;
    int col;
    int row;
    for(int i = 1 ; i <= n; i++){
        vector<int> temp;
        col = 0;
        row = i;
        int num = ncr(row-1,col);
        for(int j = 1; j <= i; j++){
            temp.push_back(num);
            row-=1;
            col+=1;
            num = num* row/col;
        }

        ans.push_back(temp);
    }









    for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
    int n ;
    cin >> n;

    pascaltri(n);

}