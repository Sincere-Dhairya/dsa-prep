#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    cout<<"Swap called"<<endl;
    int *temp = b;
    b = a;
    a = temp;
}

int partition(int * arr, int i, int j)
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

void quicksort(int * arr, int i, int j)
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
    int arr1[] = {1, 3, 5, 7}, arr2[] = {0, 2, 6, 8, 9};
    int n = 4, m = 5;
    int i =0, j= 0;
    while(i<n){
        if(arr1[i] > arr2[j]){
            cout<<arr1[i]<<" "<<arr2[j]<<endl;
            swap(arr1[i], arr2[j]);
            cout<<"Swapped"<<endl;
            quicksort(arr2, 0, m-1);
            cout<<"Sorted."<<endl;
        }
        ++i;
        
    }
    while(j < n){
        cout<<arr1[j]<<" ";
        ++j;
    }
    j = 0;
    while(j < m){
        cout<<arr2[j]<<" ";
        ++j;
    }
    return 0;
}
// void swap(long long int *a, long long int*b)
//         {
//             long long int * temp = new long long int;
//             *temp = *a;
//             *a = *b;
//             *b = *temp;
//         }
//         while(k<m && arr2[k] > arr2[k+1]){
//                         swap(&arr2[k], &arr2[k+1]);
//                         ++k;
//                     }