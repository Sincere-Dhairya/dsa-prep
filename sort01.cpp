#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {0, 1, 1, 0, 1, 0, 1, 1, 0, 1};

    int n = arr.size(), count=0;
/*
    //Brute force: O(2n)
    for(int i = 0 ; i<n; i++){
        if(arr[i] == 1) ++count;
    }
    
    int i = 0;

    while(i<n-count){
        arr[i] = 0;
        i++;
    }
    while(i < n){
        arr[i++] = 1;
    }

    for( i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    */
/* Wrong Approach
    for(int i = 0, j = n-1; i<=j; i++, j--){
        if (arr[i] >  arr[j]) swap(arr[i], arr[j]);       
    }
*/
//  two pointer approach. 
    int i=0, j=0;
    while(j<n){
        if(arr[j] == 0){
            swap(arr[i], arr[j]);
            ++i;
            ++j;

        }
        else{
            ++j;
        }
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i];
        if(i != n-1) cout<<", ";
    }
    cout<<endl;
}