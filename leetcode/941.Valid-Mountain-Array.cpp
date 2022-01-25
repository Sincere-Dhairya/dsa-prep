/**
 * @file 941. Valid Mountain Array
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-25
 * @link https://leetcode.com/problems/valid-mountain-array/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
 

Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^4
*/

//O(N)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(), i=0;
        if(n < 3){
            return false;
        }
        for(; i<n-1 and arr[i]<arr[i+1]; i++);
        if(i == n-1 || i == 0 || arr[i] == arr[i+1]){
            return false;
        }
        for(; i<n-1 and arr[i]>arr[i+1]; i++);
        return i == (n-1);
    }
};
/*Test Cases
[2,1]
[3,5,5]
[0,3,2,1]
[1,2,3,2]
[1,2,3,4,4,3,2,1]
[5,4,3,2,1]
[1,2,3,4,5]
[5,5,4,3,2,1]
[5,4,3,6,7,3,2,1]
[1,2,3,2,1,3,4,7,5,3]
[4,4,3,2,3,4,4]
[1,2,3,4,5,5,4,3,2,1]
*/