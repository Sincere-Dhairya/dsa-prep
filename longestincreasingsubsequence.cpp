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
    vector<int> nums ={1,2,3,4,5,6,7,7,9};// {10,9,2, 2,5,3,7, 7,101,7,18};
    auto k = upper_bound(nums.begin(), nums.end(), 7)-nums.begin();
    
    cout<<k<<" "<<nums[k]<<endl;
    int n = nums.size();
    vector<int> lis;

    lis.push_back(nums[0]);
    
    for(int i =1; i<n; i++){
        if(lis.back() <= nums[i]) lis.push_back(nums[i]);
        else{
            int ind = upper_bound(lis.begin(), lis.end(), nums[i])-lis.begin();
            lis[ind] = nums[i];
        }
    }
    cout<<lis.size()<<" "<<endl;
    auto itr = lis.begin();
    for(int i = 0; i < lis.size(); i++){
        cout<<lis[i]<<' ';
    }

}