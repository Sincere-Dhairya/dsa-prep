/**
 * @file 78. Subsets
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

// TC: O(N^2)
class Solution {
public:
    void create_subset(vector<vector<int>>& arr, int start, vector<int> nums, vector<int> smallset){
        for(int i = start+1; i<nums.size(); i++){
            smallset.push_back(nums[i]);
            arr.push_back(smallset);
            create_subset(arr, i, nums, smallset);
            smallset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>sbstarr;
        sbstarr.push_back({});

        for(int i = 0; i<nums.size(); i++){
            vector<int> smallset;
            smallset.push_back(nums[i]);
            sbstarr.push_back(smallset);
            create_subset(sbstarr, i, nums, smallset);
        }
        return sbstarr;
    }
};
// @lc code=end

