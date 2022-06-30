/**
 * @file 462. Minimum Moves to Equal Array Elements II
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-30
 * @link https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/ @endlink
 * @copyright Copyright (c) 2022
 * @tags sorting maths
 */
/*
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16
 

Constraints:

n == nums.length
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

// Brute Force gives TLE
// TC: O(NxN), SC: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int minMoves = INT_MAX;
        for(int i=0; i<nums.size(); ++i){
            int alike = nums[i];
            int count = 0;
            for(int j = 0; j<nums.size(); ++j){
                if(i==j) continue;
                count += abs(nums[i]-nums[j]);
            }
            minMoves = min(minMoves, count);
        }
        return minMoves;
    }
};

// Optimized with sorting and median finding.
// TC:O(NlogN), SC: O(1)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = 0;
        if(n&1){
            median = nums[n/2];
        }
        else{
            median = (nums[n/2] + nums[(n/2)-1])/2;
        }
        int minMoves = 0;
        for(int i=0; i<n; ++i){
            minMoves += abs(nums[i]-median);
        }
        return minMoves;
    }
};