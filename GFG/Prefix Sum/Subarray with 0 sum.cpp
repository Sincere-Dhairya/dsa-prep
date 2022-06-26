/**
 * @file Subarray with 0 sum
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * @link https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621 @endlink
 * @copyright Copyright (c) 2022
 * @tag prefix-sum
 */
/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
Your Task:
You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the drivers code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 10^4
-10^5 <= a[i] <= 10^5
*/
// Prefix Sum
// TC: O(N), SC: O(N)

bool subArrayExists(int arr[], int n){
    int sum = 0;
    unordered_map<int, int> prefixSum;
    
    for(int i = 0; i<n; ++i){
        sum += arr[i];
        if(!arr[i] || !sum || prefixSum.count(sum)) return 1;
        else prefixSum[sum] = i;
    }
    
    return 0;
}