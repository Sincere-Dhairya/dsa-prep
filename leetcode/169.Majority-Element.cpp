/**
 * @file 169. Majority Element
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-21
 * @link https://leetcode.com/problems/majority-element/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

// TC - O(NlogN) SC - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=1;
        pair<int, int> ans={nums.front(), 1};
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                count=1;
            }
            else{
                ++count;
            }
            if(ans.second < count){
                ans.first = nums[i];
                ans.second = count;
            }
        }
        return ans.first;
    }
};

// TC - O(N) SC- O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.end()-nums.begin();
        unordered_map<int, int> list;
        int count_bound = n/2;
        
        for(int i=0; i<n; i++){
            ++list[nums[i]];
            if(list[nums[i]]> count_bound){
                return nums[i];
            }
        }
        return 0;
    }
};

// Best Solution Moore Voting Algorithm
// O(N) TC and O(1) SC
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, num=0;
        for(int i: nums){
            if(!count){
                num = i;
            }
            
            if(i == num){
                ++count;
            }
            else{
                --count;
            }
        }
        return num;
    }
};