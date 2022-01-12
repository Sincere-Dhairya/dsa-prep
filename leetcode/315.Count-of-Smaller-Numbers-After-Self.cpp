/**
 * @file 315. Count of Smaller Numbers After Self
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * @link https://leetcode.com/problems/count-of-smaller-numbers-after-self/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

//Brute Force O(n^2) approach Gave TLE
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int count = 0;
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j]<nums[i]){
                    ++count;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

//Using Sorting. TC-O(NlogN), SC (O(N))

