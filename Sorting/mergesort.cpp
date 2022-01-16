#include <bits/stdc++.h>

using namespace std;


void merging(vector<int>& nums, int low, int mid, int high)
{
    cout<<"merging called."<<endl;
    
    vector<int> arr1, arr2;

    int n1 = mid - low +1, n2 = high - mid;
    cout<<n1<<"  "<<n2<<endl;

    for ( int i = 0; i<n1; i++){
        arr1.push_back(nums[i+low]);
    }

    for(int i = 0; i < n2; i++){
        arr2.push_back(nums[i+mid+1]);
    }

    int i = low, j = 0, k = 0;
    
    while(j< n1 && k < n2){
        if(arr1[j] < arr2[k]){
            nums[i] = arr1[j];
            ++j;
        }

        else{
            nums[i] = arr2[k];
            ++k;
        }
        ++i;
    }

    i = low;
    while(i <= high){
        cout<<nums[i]<<", ";
        if(i == high) cout<<endl;
        ++i;
    }

}

void mergesort(vector<int> &nums, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        cout<<"done with mid"<<endl;
        mergesort(nums, low, mid);
        cout<<"done with mergesort1"<<endl;
        mergesort(nums, mid+1, high);
        cout<<"done with mergesort2"<<endl;
        merging(nums, low, mid, high);
        cout<<"done with merging"<<endl;
    }
}

int main()
{
    printf("Hello World");
    vector<int> nums = {2, 7, 9, 1, 3, 5};
    
    int n = nums.size();
    mergesort(nums, 0, n-1);

    //nums = temp;
    
    cout<<endl<<'[';
    for(int i = 0; i<n; i++){
        cout<<nums[i];
        if( i != n-1) cout<<", ";
    }
    cout<<']'<<endl;

    return 0;
}
