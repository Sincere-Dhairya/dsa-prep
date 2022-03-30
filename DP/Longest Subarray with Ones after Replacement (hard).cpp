/**
 * @file Longest Subarray with Ones after Replacement (hard)
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * @link https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

// Brute Force method
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

// Sliding Window - O(N).
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