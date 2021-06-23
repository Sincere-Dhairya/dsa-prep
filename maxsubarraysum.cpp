#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> sums;

    for (int i = 0; i< arr.size(); i++){
        if(arr[i] >0) break;
        else return 0;
    }

    sums.push_back(0);

    int temp = arr[0];

    for(int i = 0; i<arr.size(); i++){
        sums.push_back(max(arr[i], arr[i] + sums[i-1]));
    }
    int MAX = *max_element(sums.begin(), sums.end());
    cout<<endl<<MAX;    
    return 0;

}