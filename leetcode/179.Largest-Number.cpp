/**
 * @file 179. Largest Number
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-17
 * @link https://leetcode.com/problems/largest-number/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 10^9
*/

// O(N logN))
class Solution {
public:
    class compare{
        public:
        bool operator()(int & i, int & j){
            string si = to_string(i), sj = to_string(j);
            return si+sj > sj+si;
        }
    };
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare());
        if(nums.front() == 0){
            return "0";
        }
        string total = "";
        
        for(auto i : nums){
            total+= to_string(i);
        }
        return total;
    }
};