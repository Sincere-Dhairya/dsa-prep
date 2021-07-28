#include<bits/stdc++.h>

using namespace std;

bool tester(vector<int> arr, int mid, int k, int N){
    k *= 2;
    int count = 0, diff = 0;

    for(int i = 0; i < N-1; i++){
        if(diff + arr[i+1] - arr[i] < k) diff += arr[i+1] - arr[i];
        else {
            if(diff + arr[i+1] -arr[i] == k) diff = 0;
            else diff = arr[i+1]-arr[i];
            ++count;
            diff = 0;
        }

        if(count>mid) return true;
    }
    return false;
}

int main(){
    int N= 5;

    int d = 2;

    vector<int> houses = {1, 3, 4, 6, 7};

    // for(int i =0; i<N; i++){
    //     int k;
    //     cin>>k;
    //     houses.push_back(k);
    // }

    int high = N, low = 0, mid;

    while(high >= low){
        mid = (high + low)/2;

        bool var = tester(houses, mid, d, N);
        if(var) low = mid+1;
        else high = mid-1;
    }
    cout<<low<<endl;
}