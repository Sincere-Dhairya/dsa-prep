/**
 * @file 454. 4Sum II
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-03
 * @link https://leetcode.com/problems/4sum-ii/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
 

Constraints:

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28
*/

//O(N^3 LogN) Gave TLE
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        long sum = 0;
        map<int, int> list1;
        for(int i: nums1){
            ++list1[i];
        }
        
        int count = 0;
        for(int i: nums2){
            for(int j: nums3){
                for(int k: nums4){
                    int sum = -i-j-k;
                    if(list1.count(sum)){
                        count += list1[sum];
                    }
                }
            }
        }
        return count;
    }
};

//O(n^2 logn)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        long sum = 0;
        map<int, int> list1;
        for(int i: nums1){
            for(int j: nums2){
                ++list1[i+j];
            }
        }
        
        int count = 0;
        for(int j: nums3){
            for(int k: nums4){
                int sum = -j-k;
                if(list1.count(sum)){
                    count += list1[sum];
                }
            }
        }
        return count;
    }
};