
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {5,0,1,2,3,4};
    vector<int> ans(nums.size());

    for(int i =0; i<nums.size(); i++){
        ans[i] = nums[nums[i]];
    }

    for(int i =0; i<ans.size(); i++){
        cout<<ans[i];
        if(i != ans.size()-1) cout<<", ";
    }



}