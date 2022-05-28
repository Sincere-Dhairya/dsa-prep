/**
 * @file Partition Array for Maximum Sum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-28
 * @link https://leetcode.com/problems/partition-array-for-maximum-sum/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.
Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 10^9
1 <= k <= arr.length
*/

// Recursion + Memoization.
// TC: Exponential reduced to O(N) + O(K), SC: O(N) 
class Solution {
public:
    int f(vector<int>& cache, vector<int>& arr, int& k, int& n, int i){
        if(i==n) return 0;
        if(cache[i]) return cache[i];
        int maxsum = 0, subsum = 0, maxnum = arr[i];
        for(int j=i; j<n && j<i+k; ++j){
            maxnum = max(maxnum, arr[j]);
            subsum = maxnum*(j-i+1);
            int cost = subsum + f(cache, arr, k, n, j+1);
            maxsum = max(maxsum, cost);
        }
        return cache[i]=maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> cache(n+1, 0);
        return f(cache, arr, k, n, 0);
    }
};

// Tabulation.
// TC: O(NxN), SC: O(N)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> cache(n+1, 0);
        for(int i=n-1; i>=0; --i){
            int maxsum = 0, subsum = 0, maxnum = arr[i];
            for(int j=i; j<n && j<i+k; ++j){
                maxnum = max(maxnum, arr[j]);
                subsum = maxnum*(j-i+1);
                int cost = subsum + cache[j+1];
                maxsum = max(maxsum, cost);
            }
            cache[i]=maxsum;
        }
        return cache[0];
    }
};