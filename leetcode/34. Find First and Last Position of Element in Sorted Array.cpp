/**
 * @file 34. Find First and Last Position of Element in Sorted Array
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * @link https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary-search.
 */
/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

// TC: O(LogN).
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> indices = {-1, -1};
        int high = nums.size()-1, low = 0;
        
        while(high >= low){
            int mid = low + (high-low)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                int i = mid, j = mid;
                while(i>=0 && nums[i] == target) --i;
                while(j<nums.size() && nums[j] == target) ++j;
                indices = {i+1, j-1};
                break;
            }
        }
        return indices;
    }
};