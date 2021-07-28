#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    sort(nums.begin(), nums.end());  //nlogn
        
    vector<vector<int>> ans;
    
    int i = 0, j = 0, k = 0, n = nums.size();
    
    while(i<n){                        //n*
        int sum = -1*nums[i];
        j = i+1; 
        k = n-1;
        
        while(j<k){                     //n
            if(nums[k]+nums[j] == sum){
                vector<int> part = {nums[i], nums[j], nums[k]};
                ans.push_back(part);
                ++j;
                --k;
            }
            else if(nums[j] + nums[k] < sum){
                ++j;
                while(nums[j] == nums[j-1]) ++j;
            }
            else{
                --k;
                while(nums[k] == nums[k+1]) --k;
            }
        }
        ++i;
        while(nums[i] == nums[i-1]) ++i;
    }
    
    for(int i =0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}