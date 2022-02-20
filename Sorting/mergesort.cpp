#include <bits/stdc++.h>

using namespace std;

void merging(vector<int> &arr, int high, int low, int mid){
    vector<int> temp1, temp2, temp;
    int n = high;
    for(int i = low; i<mid; i++){
        temp1.push_back(arr[i]);
    }
    for(int i =mid; i<n; i++){
        temp2.push_back(arr[i]);
    }
    int i=0,j=0;
    while(i<mid and j<high-mid+1){
        if(temp1[i] < temp2[j]){
            temp.push_back(temp1[i++]);
        }
        else{
            temp.push_back(temp2[j++]);
        }
    }
    while(i<mid){
        temp.push_back(temp1[i++]);
    }
    while(j<high-mid+1){
        temp.push_back(temp2[j++]);
    }
    for(int i = high-1; i>= low; i--){
        arr[i] = temp.back();
        temp.pop_back();
    }
}

void printing(vector<int> arr){
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void mergesort(vector<int> &arr, int high, int low){
    if(high > low){
        cout<<"Merge Sort called: high: "<<high<<" low: "<<low<<endl;
        int mid = (high+low)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid, high);

        merging(arr, low, mid, high);
        cout<<"Status after merging: ";
        printing(arr);
    }
}

int main()
{
    //printf("Hello World");
    vector<int> nums = {2, 7, 9, 1, 3, 5};
    
    int n = nums.size();
    mergesort(nums, 0, n);

    //nums = temp;
    
    cout<<endl<<'[';
    for(int i = 0; i<n; i++){
        cout<<nums[i];
        if( i != n-1) cout<<", ";
    }
    cout<<']'<<endl;

    return 0;
}
