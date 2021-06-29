#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {0, 1, 1, 0, 1, 0, 1, 1, 0, 1};

    int n = arr.size(), count=0;

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

    for(int i = 0, j = n-1; i<=j; i++, j--){
        
    }
}