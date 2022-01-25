/**
 * @file 287. Find the Duplicate Number
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-25
 * @link https://leetcode.com/problems/find-the-duplicate-number/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 10^5
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/

//Using Unordered Set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> list;
        for(auto i: nums){
            if(list.count(i)){
                return i;
            }
            else{
                list.insert(i);
            }
        }
        return 0;
    }
};

//Using Binary Search - O(NLogN)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), high = n-1, low = 1;
        while(high >= low){
            int mid = (high + low)/2,
            count = 0;
            for(int i = 0; i<n; i++){
                if(nums[i] <= mid){
                    ++count;
                }
            }
            if(count > mid){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};

//O(N) : Fast Slow method
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), slow = nums[0], fast = nums[nums[0]];
        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while(fast != slow){
            fast = nums[fast],
            slow = nums[slow];
        }
        return slow;
    }
};
