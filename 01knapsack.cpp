#include<bits/stdc++.h>

using namespace std;

int weightfinder(vector<pair<int, int>> values, int n, int cap){
    vector<vector<int>> arr(n, vector<int> (cap+1, 0));
    
    for(int i = 1; i<cap+1; i++){
        arr[0][i] = values[0].second;
    }
    
    for(int i = 1; i<n; i++){
        cout<<"i = "<<i<<endl;
        for(int j = 0; j<cap+1; j++){
            if(values[i].first <= j){
                arr[i][j] = max(arr[i-1][j], values[i].second + arr[i-1][j-values[i].first]);    
            }
            else{
                arr[i][j] = arr[i-1][j];
            }
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return arr[n-1][cap];
}
int main(){
    int n; cin>>n;
    vector<int> weights(n), values(n);
    
    for(int i = 0; i<n; i++){
        cin>>weights[i];
    }
    
    for(int i = 0; i<n; i++){
        cin>>values[i];
    }
    
    vector<pair<int, int>> arr(n);
    
    for(int i = 0; i< n; i++)
        arr[i] = make_pair(values[i], weights[i]);
    
    int capacity;
    cin>> capacity;
    
    int k = weightfinder(arr, n, capacity);
    cout<<k;
    return 0;
}