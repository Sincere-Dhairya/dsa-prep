#include<bits/stdc++.h>

using namespace std;

void printing(vector<int> &arr){
    cout<<endl;
    for(auto n: arr){
        cout<<n<<" ";
    }
    return;
}

void merging(vector<int> &arr, int low, int mid, int high){
    vector<int> temparr;
    int i = low, j = mid;
    while(i<mid and j<high){
        if(arr[i]<arr[j]){
            temparr.push_back(arr[i++]);
        }
        else{
            temparr.push_back(arr[j++]);
        }
    }
    while(i<mid){
        temparr.push_back(arr[i++]);
    }
    while(j<high){
        temparr.push_back(arr[j++]);
    }
    int k=0;
    for(int i = low; i<mid; i++){
        arr[i] = temparr[k++];
    }
    for(int i = mid; i<high; i++){
        arr[i] = temparr[k++];
    }
    return;
}

void mergesort(vector<int> &arr, int low, int high){
    cout<<low<<" "<<high<<endl;
    if(low+1 == high){
        return ;
    }
    int mid = (high+low)/2;
    mergesort(arr, low, mid),
    mergesort(arr, mid, high);
    merging(arr, low, mid, high);

    return;
}

int main(){
    vector<int> arr = {1,6,23,4,12,56,7,2};
    mergesort(arr, 0, arr.size());
    printing(arr);
    return 0;
}