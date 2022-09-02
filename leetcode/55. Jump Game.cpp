/**
 * @file 55. Jump Game
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * @link https://leetcode.com/problems/jump-game/ @endlink
 * @copyright Copyright (c) 2022
 * @tags recursion, dynamic-programming, greedy.
 */
/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/
// Dynamic Programming
// TC: O(NxN) 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n+1);
        cache[n-1] = 1;
        for(int i = n-2; i>=0; --i){
            for(int k = 1; k <= nums[i] && (i+k) < n; ++k){
                if(cache[i+k]){
                    cache[i] = 1;
                    break;
                }
            }
        }
        return cache[0];
    }
};

// Greedy Approach.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reachable = n-1;
        for(int i = n-2; i>=0; --i){
            if(nums[i]+i >= reachable){
                reachable = i;
            }
        }
        
        return !reachable; 
    }
};