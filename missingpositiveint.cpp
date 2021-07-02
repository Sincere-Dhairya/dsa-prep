//first mising positive integer in unsorted array.

#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1, -2, 2, 9, 10, -3, -4};//{3,4,-1,1, -2, -5, -3, 5, 7};
    
    int i =0, j = 0, n = arr.size();

    while(j<n){
        if(arr[j] > 0){
            swap(arr[i], arr[j]);
            ++i;
            ++j;
        }
        else ++j;

    }
    cout<<i<<endl;

    int k = 0;
    while(k < i){
        if (arr[abs(arr[k])-1] >= i);
        else arr[abs(arr[k])-1] = arr[abs(arr[k])-1]*(-1);
        ++k;
    }

    for( k = 0; k < i; k++){
        if(arr[k] > 0) break;
    }
    cout<<"Number is :"<<k+1<<endl;

    for( i = 0; i<n; i++){
        cout<<arr[i];
        if(i != n-1) cout<<", ";
    }
}