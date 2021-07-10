#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> sums;

    for (int i = 0; i< arr.size(); i++){
        if(arr[i] >0) break;
        
    }

    sums.push_back(0);
    cout<<"JaiHo!"<<endl;
    int temp;
    for(int i = 0; i<arr.size(); i++){
        sums.push_back(max(arr[i], arr[i] + sums[i-1]));
        cout<<sums[i]<<endl;
        temp = max(sums[i-1], sums[i]);
    }
    int majorsum = -20, subarrsum = arr[0];

    for(int i =0; i< arr.size(); i++){
        subarrsum = max(arr[i], arr[i] + subarrsum);
        majorsum = max(majorsum, subarrsum);
    }
    int MAX = *max_element(sums.begin(), sums.end());
    cout<<endl<<MAX<<endl<<temp<<endl<<majorsum<<endl<<subarrsum;    
    return 0;

}