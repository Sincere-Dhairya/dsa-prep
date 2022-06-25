/**
 * @file 665. Non-decreasing Array
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-25
 * @link https://leetcode.com/problems/non-decreasing-array/ @endlink
 * @copyright Copyright (c) 2022
 * @tags arrays, dp, 
 */
/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
 

Constraints:

n == nums.length
1 <= n <= 10^4
-10^5 <= nums[i] <= 10^5
*/

// DP Solution, Gave TLE.
// TC: O(NxN), SC: O(NxN) + O(N)
class Solution {
public:
    int LIS(vector<vector<int>>& table, vector<int> & nums, int i, int j){
        if(i < 0)  return 0;
        if(table[i][j] > -1) return table[i][j];
        int pick = 0, unpick = 0;
        
        // pick
        if(nums[i] <= nums[j]){
            pick = 1+ LIS(table, nums, i-1, i);
        }
        // unpick
        unpick = LIS(table, nums, i-1, j);
        return table[i][j] = max(pick, unpick);
    }
    bool checkPossibility(vector<int>& nums) {
        nums.emplace_back(1e6);
        int n = nums.size();
        vector<vector<int>> table(n, vector<int>(n, -1));
        int lis = LIS(table, nums, n-2, n-1);
        return lis + 2 >= n;
    }
};

// Arrays.
// TC: O(N), SC: O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i<nums.size(); ++i){
            if(nums[i] < nums[i-1]){
                ++count;
                if(i-2 <0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        return count <=1;
    }
};