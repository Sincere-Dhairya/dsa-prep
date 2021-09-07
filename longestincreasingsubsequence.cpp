//Longest Increasing SubSequence!
#include<bits/stdc++.h>

using namespace std;
/*
*/
int binsearch(vector<int> arr, int n, int high)
{
    int low = 0, mid;
    cout<<high<<endl;
    while(high>=low){
        mid = (high + low)/2;
        if(arr[mid] == n) return mid;
        else if (arr[mid] > n) high = mid-1;
        else low = mid+1;
    }
    return low;

}
//1 2 3 4 5 6 9 10
//
int main()
{
    vector<int> A ={14, 24, 18, 46, 55, 53, 82, 18, 101, 20, 78, 35, 68, 9, 16, 93, 101, 85, 81, 28, 78};// {10,9,2, 2,5,3,7, 7,101,7,18};
    //auto k = upper_bound(nums.begin(), nums.end(), 7)-nums.begin();
    
    //cout<<k<<" "<<nums[k]<<endl;
    int n = A.size();
    vector<int> dp(n,1);
    cout<<n;
    //lis.push_back(nums[0]);
    
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(A[j] < A[i] && dp[i] <= dp[j]) dp[i] = dp[j]+1;
        }
    }
    cout<<dp.size()<<" "<<endl;
    //auto itr = lis.begin();
    for(int i = 0; i < dp.size(); i++){
        cout<<dp[i]<<' ';
    }

}