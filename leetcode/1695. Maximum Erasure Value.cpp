    /**
 * @file 1695. Maximum Erasure Value
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * @link https://leetcode.com/problems/maximum-erasure-value/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
*/

// Sliding Window with Hash Maps + Prefix Sum.
// TC: O(N^2), SC: O(N).
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), sum = 0, score = nums.front();
        vector<int> prefix(n+1, 0);
        
        for(int i = 0; i<n; ++i){
            sum += nums[i];
            prefix[i+1] = sum;
        }
        
        unordered_map<int, int> window;
        int leftInd = 0, rightInd = 0;
        for(int i = 0; i<n; ++i){
            while(window.count(nums[i]) == 0){
                window.insert({nums[i], i});
                rightInd = i+1;
                score = max(score, prefix[rightInd] - prefix[leftInd]);
                ++i;
            }
            if(window.count(nums[i])){
                i = window[nums[i]];
                leftInd = i+1;
                window.clear();
            }
            
        }
        return score;
    }
};


// Hashset + Window.
// TC: O(NxN), SC: O(N).
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), maxScore = 0;
        unordered_set<int> list;
        
        for(int i=0, j=0, window = 0; i<n; ++i){
            while(list.count(nums[i])){
                list.erase(nums[j]);
                window -= nums[j];
                ++j;
            }
            list.insert(nums[i]);
            window += nums[i];
            maxScore = max(maxScore, window);
        }
        return maxScore;
    }
};