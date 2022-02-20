/**
 * @file 1675. Minimize Deviation in Array
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-02-20
 * @link https://leetcode.com/problems/minimize-deviation-in-array/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
Example 3:

Input: nums = [2,10,8]
Output: 3
 

Constraints:

n == nums.length
2 <= n <= 10^5
1 <= nums[i] <= 10^9
*/

//N log N using heap.
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int mn = INT_MAX, mx = INT_MIN, diff = INT_MAX;
        
        for(int &i: nums){
            if(i%2){
                i*=2;
            }
            mn = min(mn, i),
            mx = max(mx, i);
            q.push(i);
        }
        
        while(1){
            int num = q.top();
            q.pop();
            diff = min(diff, num-mn);
            if(num%2){
                break;
            }
            num /= 2;
            q.push(num);
            mn = min(mn, num);
        }
        return diff;
    }
};