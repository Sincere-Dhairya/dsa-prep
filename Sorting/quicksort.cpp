#include<bits/stdc++.h>

using namespace std;

void printing(vector<int> & arr){
    for(auto n : arr){
        cout<<n<<" ";
    }
    cout<<endl;
    return;
}

int partitioning(vector<int> & arr, int start, int end){
    int pivot = start;
    while(start<end){
        while(arr[start]<=arr[pivot]){
            ++start;
        }
        while(arr[end]>arr[pivot]){
            --end;
        }
        if(start<end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[pivot], arr[end]);
    return pivot;
}

void quicksort(vector<int>&arr, int start, int end){
    if(start<end){
        int piv = partitioning(arr, start, end);
        quicksort(arr, 0, piv-1),
        quicksort(arr, piv+1, end);
    }
    return;
}
//2, 7, 9, 1, 3, 5 

int main()
{
    vector<int> arr1 = {7,6,10,5,9,2,1,15,7}, arr2 = {1,6,23,4,12,56,7,2}, arr3 = {2, 7, 9, 1, 3, 5};
    quicksort(arr1, 0, arr1.size()-1);
    quicksort(arr2, 0, arr2.size()-1);
    quicksort(arr3, 0, arr3.size()-1);
    printing(arr1);
    printing(arr2);
    printing(arr3);
    return 0;
}