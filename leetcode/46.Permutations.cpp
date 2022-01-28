/**
 * @file 46. Permutations
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-27
 * @link https://leetcode.com/problems/permutations/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

//TC: N! SC-O(N)
class Solution {
public:
    void P_maker(vector<vector<int>> &perms, vector<int>&seq, vector<int> &nums, vector<int> &status){
        queue<int> s;
        for(int i=0; i<nums.size(); i++){
            if(status[i] == 0){
                s.push(i);
            }
        }
        if(s.empty()){
            perms.push_back(seq);
            return;
        }
        while(s.empty() == 0){
            int ind = s.front();
            s.pop();
            seq.push_back(nums[ind]);
            status[ind] = 1;
            P_maker(perms, seq, nums, status);
            status[ind] = 0;
            seq.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.end()-nums.begin();
        vector<int> status(n, 0), sequence;
        vector<vector<int>> perms;
        P_maker(perms, sequence, nums, status);
        return perms;
    }
};

//TC(O(N)) but SC- O(1). Great approach.
class Solution {
public:
    void P_maker(vector<vector<int>> &perms, vector<int> &nums, int begin, int n){
        if(begin>=n){
            perms.push_back(nums);
            return;
        }
        
        for(int i = begin; i<n; i++){
            swap(nums[i], nums[begin]);
            P_maker(perms, nums, begin+1, n);
            swap(nums[i], nums[begin]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.end()-nums.begin();
        vector<vector<int>> perms;
        P_maker(perms, nums, 0, n);
        return perms;
    }
};