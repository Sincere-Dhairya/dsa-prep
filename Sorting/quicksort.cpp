#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int i, int j)
{
    int piv = i;
    cout<<"partition called"<<endl;

    while(i< j){
        while(arr[piv] >= arr[i]){
            ++i;
        }

        while(arr[piv] < arr[j]){
            --j;
        }

        if( i > j) {
            swap(arr[piv], arr[j]);
            break;
        }
        else swap(arr[i], arr[j]);
        cout<<"i is: "<<i<<", j is : "<<j<<endl;
    }
    return j;
}

void quicksort(vector<int>& arr, int i, int j)
{
    cout<<"quicksort called"<<endl;

    if(i < j){
        int piv = partition(arr, i, j);
        cout<<piv<<endl;

        quicksort(arr, i, piv-1);
        quicksort(arr, piv+1, j); 
    }
}

int main()
{
    vector<int> arr = {2, 7, 9, 1, 3, 5};
    int n = arr.size();
    cout<<"Main called"<<endl;
    quicksort(arr, 0, n-1);

    int i = 0;
    cout<<endl;
    while(i<n){
        cout<<arr[i];
        if(i != n-1) cout<<", ";
        ++i;
    }
}