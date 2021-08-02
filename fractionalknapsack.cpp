#include<bits/stdc++.h>

using namespace std;

struct weightgroup{
    float val;
    float weight;
    float ratio;
}; 

void calcratio(vector<weightgroup> & arr, int n){
    for(int i = 0 ; i<n; i++){
        arr[i].ratio = arr[i].val/arr[i].weight;
    }
}

bool cmp(weightgroup & a, weightgroup & b){
    if(a.ratio == b. ratio) return a.weight>b.weight;
    else return a.ratio>b.ratio;
}

double weightfinder(vector<weightgroup> values, int n, int cap){
    double totalval = 0.0;
    for(int i =0; i<n; i++){
        if(values[i].weight > cap) totalval+= (cap*values[i].ratio);
        else{
            totalval += values[i].val;
            cap -= values[i].weight;
        }
    }
    return totalval;
}

int main(){
    int n; cin>>n;
    vector<weightgroup> members(n);
    
    for(int i = 0; i<n; i++){
        cin>>members[i].val;
    }
    
    for(int i = 0; i<n; i++){
        cin>>members[i].weight;
    }
    
    calcratio(members, n);
    
    sort(members.begin(), members.end(), cmp);
    
    int capacity;
    cin>> capacity;
    
    double k = weightfinder(members, n, capacity);
    cout<<k;
    return 0;
}