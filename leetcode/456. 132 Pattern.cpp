/**
 * @file 456. 132 Pattern
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-07
 * @link https://leetcode.com/problems/132-pattern/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 2 * 10^5
-10^9 <= nums[i] <= 10^9
*/

// TC - [O(N^2) - O(N)]. SC - O(N).

/* We will be considering the 3 numbers as a, c, b.  Here in the solution we will have a stack that will be storing the biggest number, that is, c in its top, an integer 'sec' will save the second largest num, that is, b; and every ith number is to be considered as the smallest that is a. */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.end()-nums.begin(), sec = INT_MIN;
        vector<int> s;
        for(int i = n-1; i>=0; --i){
            // hence, we will consider ith number as a and it should be smaller than the sec, that is b.
            if(nums[i]<sec){
                return true;
            }
            
            // Now the rest of the comound block will consider the ith number as c and for that the stack needs to have only those elements that are greater than nums[i], so that the smaller numbers can be popped out and saved in sec as b. for the next iteration, we will have b and c, and we will be comparing the ith element for a.
            while(!s.empty() && s.back() < nums[i]){
                sec=s.back(), s.pop_back();
            }
            s.push_back(nums[i]);
        }
        return false;
    }
};