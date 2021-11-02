/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();

        int i =0, j = n-1;
        for(int i =0 ;i<n; i++){
            for(int j = n-1; j>i; j--){
                if(nums[j] - nums[i] == k) {
                    ++count;
                    while(j-1>i && nums[j] == nums[j-1]) --j;
                }
                if(nums[j] - nums[i] < k) break;
            }
            while(i<n-1 && nums[i] == nums[i+1]) ++i;
        }
        
        return count;
        
    }
};
// @lc code=end

