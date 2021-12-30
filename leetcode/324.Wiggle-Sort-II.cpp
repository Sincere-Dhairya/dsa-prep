/**
 * @file 324. Wiggle Sort II
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-30
 * @link https://leetcode.com/problems/wiggle-sort-ii/
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.
 

Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

//TC: nlogn approach SC - o(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int n = nums.size(), i = n-1, j = i/2, k = 0;
        while(k<n)
            if(k%2)
                nums[k++] = arr[i--];
            else
                nums[k++] = arr[j--];
    }
};

