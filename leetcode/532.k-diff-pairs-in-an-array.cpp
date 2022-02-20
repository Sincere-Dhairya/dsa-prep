/**
 * @file 532. K-diff Pairs in an Array
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-09
 * @link https://leetcode.com/problems/k-diff-pairs-in-an-array/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
 

Constraints:

1 <= nums.length <= 10^4
-10^7 <= nums[i] <= 10^7
0 <= k <= 10^7
*/

//O(N^2) approach gave TLE
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();

        int i =0, j = n-1;
        for(int i =0 ;i<n; i++){
            for(int j = n-1; j>i; j--){
                if(nums[j] - nums[i] == k) {
                    ++count;
                    while(j-1>i && nums[j] == nums[j-1]) --j;
                }
                if(nums[j] - nums[i] < k) break;
            }
            while(i<n-1 && nums[i] == nums[i+1]) ++i;
        }
        
        return count;
        
    }
};

// O(N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> list;
        for(int i: nums){
            ++list[i];
        }
        int count =0;
        for(int i: nums){
            if(k and list.count(i+k)){
                count+=1;
                list.erase(i+k);
            }
            else if(!k and list.count(i) and list[i]>1){
                count+=1;
                list.erase(i);
            }
        }
        return count;
    }
};
