/**
 * @file 128. Longest Consecutive Sequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * @link https://leetcode.com/problems/longest-consecutive-sequence/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sorting dp
 */
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/
// Sorting and DP.
// TC: O(NlogN), SC: O(N).
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        
        vector<int> arr(n, 1);
        
        for(int i=1; i<n; ++i){
            if(nums[i]-nums[i-1] == 1){
                arr[i] = 1+arr[i-1];
            }
            else if(nums[i] == nums[i-1]){
                arr[i] = arr[i-1];
            }
            maxLen = max(maxLen, arr[i]);
        }
        return maxLen;
    }
};

// Unordered_set.
// TC: O(N), SC: O(N).
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> list(nums.begin(), nums.end());
        int n=nums.size(), maxLen = 0;
        
        for(auto i: list){
            if(list.count(i+1)) continue;
            
            int local_count = 1, num = i;
            while(list.count(num-1)){
                ++local_count;
                --num;
            }
            
            maxLen = max(maxLen, local_count);
        }
        
        return maxLen;
    }
};