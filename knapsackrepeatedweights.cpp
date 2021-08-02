#include<bits/stdc++.h>

using namespace std;

int weightfinder(vector<pair<int, int>> values, int n, int cap){
    vector<vector<int>> arr(n+1, vector<int> (cap+1, 0));
    
    for(int i = 0; i<n; i++){
        //cout<<"i = "<<i+1<<endl;
        for(int j = 0; j<cap+1; j++){
            if(j<values[i].first) arr[i+1][j] = arr[i][j];
            else arr[i+1][j] = max(
                arr[i][j], 
                values[i].second + arr[i+1][j-values[i].first]
            );
            //cout<<arr[i+1][j]<<" ";
        }
        //cout<<endl;
    }
    
    return arr[n][cap];
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