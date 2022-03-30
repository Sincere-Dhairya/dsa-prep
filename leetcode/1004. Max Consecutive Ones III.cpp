/**
 * @file 1004. Max Consecutive Ones III
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * @link https://leetcode.com/problems/max-consecutive-ones-iii/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

//Brute Force Method TC - O(n^k)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k, int i = 0) {
        if(!k){
            int sum = 0, ones = 0;
            for(int k : nums){
                if(k){
                    sum += k;
                }
                else{
                    ones = max(ones, sum), sum=0;
                }
            }
            ones = max(ones, sum);
            return ones;
        }
        int ones = 0;
        for(i = i; i<nums.size(); ++i){
            if(!nums[i]){
                nums[i] = 1;
                ones = max(ones, longestOnes(nums, k-1, i+1));
                nums[i] = 0;
            }
        }
        return ones;
    }
};

// Sliding Window - TC - O(N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, max_len = 0, zeroes = 0;
        for(int i = 0; i<n; i++){
            if(!nums[i]){
                ++zeroes;
            }
            while(zeroes>k){
                if(nums[left]==0){
                    --zeroes;
                }
                ++left;
            }

            max_len = max(max_len, i-left+1);
        }
        return max_len;
    }
};