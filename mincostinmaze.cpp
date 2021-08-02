#include<bits/stdc++.h>

using namespace std;

void mincostfunc(vector<vector<int>> arr, int n, int m){
    vector<vector<int> > mincost(n, vector<int> (m, 0));
    mincost[n-1][m-1] = arr[n-1][m-1];
    
    int i = n-1, j = m-2;
    for(j; j>= 0; j--){
        mincost[i][j] = mincost[i][j+1] + arr[i][j];
    }
    
    i = n-2, j=m-1;
    
    for(i; i>=0 ; i--) mincost[i][j] = mincost[i+1][j] + arr[i][j];
    
    for(int i = n-2; i>=0; i--){
        for(int j = m-2; j>=0; j--){
            mincost[i][j] = arr[i][j] + min(mincost[i+1][j], mincost[i][j+1]);
        }
    }
    cout<< mincost[0][0];
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    
    for(int i = 0 ; i < n ;i++){
        for(int j = 0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    mincostfunc(arr,n, m);
}