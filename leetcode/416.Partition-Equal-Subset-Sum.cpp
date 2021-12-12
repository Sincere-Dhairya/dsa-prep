/**
 * @file 416.Partition-Equal-Subset-Sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

//Recursion and backtracking gave TLE because of TC = O(2^N)
class Solution {
public:
    bool test_subsets(vector<int> & nums, int sum, int n, int i){
        if(sum == 0) return 1;
        else if(sum < 0) return false;
        //sum -= nums[i];
        for(; i<n ;i++)
            for(int j = i+1; j<n; j++)
                if(test_subsets(nums, sum-nums[i], n, j))
                    return true;
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 || n == 1) return false;
        return test_subsets(nums, sum/2, n, 0);
    }
};

//DP approach similar to 0-1 Knapsack problem
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 || n == 1) return false;
        sum /= 2;
        vector<vector<bool> > cache(n+1, vector<bool> (sum+1, 0));
        for(int i = 0; i<=n; i++)
            cache[i][0] = 1;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=sum; j++){
                if(nums[i]>j)
                    cache[i+1][j] = cache[i][j];
                else{
                    cache[i+1][j] = cache[i][j] || cache[i][j-nums[i]];
                }
            }
        }
        return cache[n][sum];
    }
};