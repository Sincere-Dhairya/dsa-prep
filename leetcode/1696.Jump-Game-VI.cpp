/**
 * @file 1696.Jump-Game-VI.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

 

Example 1:

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.
Example 2:

Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
Example 3:

Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
 

Constraints:

1 <= nums.length, k <= 105
-104 <= nums[i] <= 104
*/

//Brute force approach usign DP and Recursion
class Solution {
public:
    int calculator(vector<int> nums, int i, vector<int> & cache, int n, int k){
        if(i >= n) return 0;
        if(cache[i]) return cache[i];
        if (i == n-1) return cache[n-1] = nums[n-1];

        int sum = 0, maxsum = INT_MIN;
        for(int j = i+1; j<n and j <= i+k; j++){
            sum = nums[i] + calculator(nums, j, cache, n, k);
            maxsum = max(maxsum, sum);
        }
        return cache[i] = maxsum;
    }
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cache(n, 0);
        int ans = calculator(nums, 0, cache, n, k);
        return ans;
    }
};


//Optimized solution using Deque
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> seq{0};
        for(int i = 1; i<nums.size(); i++){
            nums[i] += nums[seq.front()];
            while(seq.size() and nums[i] >= nums[seq.back()])
                seq.pop_back();
            seq.push_back(i);
            while(seq.size() and i-seq.front()>=k)
                seq.pop_front();
        }
        return nums.back();
    }
};