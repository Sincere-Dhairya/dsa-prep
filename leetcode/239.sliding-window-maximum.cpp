/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printing_dque(deque<int> dq){
        while(!dq.empty()){
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i<k; i++){
            if(dq.empty()) dq.push_front(nums[i]);
            else if(dq.front() < nums[i]) {
                while(!dq.empty()) dq.pop_front();
                dq.push_front(nums[i]);
            } 
            else dq.push_back(nums[i]);
        }
        //cout<<dq.front()<<endl;
        ans.push_back(dq.front());
        //printing_dque(dq);
        cout<<endl;
        for(int i = 0, j = k; j<nums.size(); i++, j++){
            if(nums[i] == dq.front()) dq.pop_front();
            if(nums[j] > dq.front()){
                while(!dq.empty()) dq.pop_front();
                dq.push_front(nums[j]);
            }
            else{
                if(nums[j] <= dq.back()) dq.push_back(nums[j]);
                else {
                    while(!dq.empty() && dq.back() < nums[j])dq.pop_back();
                    dq.push_back(nums[j]);
                }
            }
            ans.push_back(dq.front());
            //printing_dque(dq);
            cout<<endl;
        }
        return ans;
    }
};
// @lc code=end

