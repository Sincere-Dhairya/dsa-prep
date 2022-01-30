/**
 * @file 2154. Keep Multiplying Found Values by Two
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-30
 * @link https://leetcode.com/contest/weekly-contest-278/problems/keep-multiplying-found-values-by-two/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:

If original is found in nums, multiply it by two (i.e., set original = 2 * original).
Otherwise, stop the process.
Repeat this process with the new number as long as you keep finding the number.
Return the final value of original.

 

Example 1:

Input: nums = [5,3,6,1,12], original = 3
Output: 24
Explanation: 
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
Example 2:

Input: nums = [2,7,9], original = 4
Output: 4
Explanation:
- 4 is not found in nums. Thus, 4 is returned.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i], original <= 1000
*/

//O(NlogN)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ind = lower_bound(nums.begin(), nums.end(), original) - nums.begin();
        
        while(ind<n and ind >= 0 and nums[ind] == original){
            original *= 2;
            ind = lower_bound(nums.begin(), nums.end(), original) - nums.begin();
        }
        return original;
    }
};

//O(n)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool seive[2001] ={0};
        for(int i: nums){
            seive[i] = 1;
        }
        while(seive[original]){
            original *= 2;
        }
        return original;
    }
};

//O(N) using set
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s;
        for(int i: nums){
            s.insert(i);
        }
        while(s.count(original)){
            original *=2;
        }
        return original;
    }
};

// Another O(N) approach
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.end()-nums.begin();
        for(int i = 0; i<n; i++){
            if(nums[i] == original){
                original*=2, i=-1;
            }
        }
        return original;
    }
};