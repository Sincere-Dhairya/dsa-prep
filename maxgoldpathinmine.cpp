#include<bits/stdc++.h>

using namespace std;

void maxgold(vector<vector<int>> arr, int n, int m){
    vector<vector<int>> dpgold(n, vector<int> (m, 0));
    
    for(int i = 0; i<n; i++) dpgold[i][m-1] = arr[i][m-1];
    
    for(int j = m-2; j>=0; j--){
        for(int i = 0; i<n; i++){
            int k = j+1; 
            int maxg = 0;
            
            if(i == 0){
                dpgold[i][j] = arr[i][j] + max(dpgold[i][j+1], dpgold[i+1][j+1]);
            }
            else{
                for(int x = i-1; x<=i+1 && x>=0 && x<n; x++) maxg = max(maxg, dpgold[x][j+1]);
                dpgold[i][j] += arr[i][j] + maxg;
            }
        }
    }
    int ans = 0;
    
    for(int i = 0; i<n; i++) ans = max(dpgold[i][0], ans);
    cout<<ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> goldmine(n, vector<int> (m, 0));
    
    for(int i = 0; i<n; i++){
        for(int j =0 ;j <m; j++)
            cin >> goldmine[i][j];
    }
    
    maxgold(goldmine, n, m);
    return 0;
}