#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> arr = { 2, 3, 5, 1, 4, 9, 6, 8};
    int area = 0, n = arr.size();
    //O(n^2) approach.
    // for(int i = 0; i<n; i++){

    //     for(int j = i; j<n; j++){
    //         area = max(area, abs(j-i)*min(arr[i], arr[j]));
    //     }
    //     cout<<area<<endl;
    // }

    //2 pointer approach.
    int i = 0, j = n-1;
    while(i<j){
        area = max(area, abs(i-j)*min(arr[i],arr[j]));
        cout<<"length = "<<min(arr[i], arr[j])<<endl<<"width = "<<abs(i-j)<<endl<<"area = "<<abs(i-j)*min(arr[i],arr[j])<<endl<<endl;
        if(arr[i]<arr[j]) ++i;
        else --j;

    }
    cout<<area<<endl;
}