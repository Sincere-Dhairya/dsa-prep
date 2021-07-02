#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 8, 7, 10, 11, 9};

    int n = arr.size() + 1;
    int sum = n*(n+1)/2;
    // Sum of n+1 integers method.
    //cout<<sum<<endl<<sum1;
    for(int i = 0; i<n-1; i++){
        sum -= arr[i];
    }

    cout<<sum<<endl;

    //marking the integers as negative method.
    int i = 0;
    while(i<n-1){
        if ( arr[abs(arr[i])]-1 >= (n-1));
        else arr[abs(arr[i])-1] = arr[abs(arr[i])-1] * (-1);

        ++i;
    }

    for ( i = 0; i<n-1; i++){
        if ( arr[i] > 0) break;
    }
    cout<<arr[i]-1<<endl;
}