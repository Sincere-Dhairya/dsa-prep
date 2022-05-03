/**
 * @file 581. Shortest Unsorted Continuous Subarray
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-03
 * @link https://leetcode.com/problems/shortest-unsorted-continuous-subarray/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?
*/

// TC - O(NLogN) SC - O(N)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size()-1;
        while(i<j){
            if(i<j and arr[i]==nums[i]){
                ++i;
            }
            if(j>i and arr[j]==nums[j]){
                --j;
            }
            if(arr[i] != nums[i] && arr[j] != nums[j]){
                break;
            }
        }
        return j>i?j-i+1:0;
    }
};

// TC less than O(n^2) SC - O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1, maxnum = INT_MIN, n = nums.size();
        for(int i=0; i<n; ++i){
            if(maxnum > nums[i]){
                if(start < 0){
                    start = i-1;
                }
                while(start >= 1 && nums[start-1] > nums[i]){
                    --start;
                }
                end = i+1;
            }
            else{
                maxnum = nums[i];
            }
        }
        return end-start;
    }
};

// Best Solution.
// TC - O(N) SC- O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxnum  =INT_MIN, minnum = INT_MAX, left = -1, right = -1, n = nums.size();
        
        for(int i = 0; i<n;++i){
            if(maxnum > nums[i]){
                right = i;
                minnum = min(minnum, nums[i]);
            }
            else{
                maxnum = nums[i];
            }
        }
        
        if(right <0){
            return 0;
        }
        
        for(int i = 0; i<n; ++i){
            if(nums[i]>minnum){
                left = i;
                break;
            }
        }
        
        return right-left +1;
    }
};
/*
[1,2,5,10,8,5,4,11,12,13,15,20,19,21]
[2,6,4,8,10,9,15]
*/