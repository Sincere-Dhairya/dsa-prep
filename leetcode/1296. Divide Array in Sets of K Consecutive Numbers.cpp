/**
 * @file 1296. Divide Array in Sets of K Consecutive Numbers
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * @link https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ @endlink
 * @copyright Copyright (c) 2022
 * @tags maps sorting
 */
/*
Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
 

Constraints:

1 <= k <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> available, vacancy;
        sort(nums.begin(), nums.end());
        for(int &i: nums){
            ++available[i];
        }
        
        for(int i = 0; i<nums.size(); ++i){
            if(available[nums[i]] == 0) continue;
            bool flag = 0;
            for(int j=1; j<k; ++j){
                if((available[nums[i]+j] -= available[nums[i]]) < 0){
                    return 0;
                }
            }
            available[nums[i]] = 0;
        }
        return 1;
    }
};