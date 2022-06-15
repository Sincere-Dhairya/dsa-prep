/**
 * @file First negative integer in every window of size k
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-15
 * @link https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1# @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 10^5
-105 <= A[i] <= 10^5
1 <= K <= N
*/

// Siding Window using Stacks
// TC: O(N), SC: O(N).
vector<long long> printFirstNegativeInteger(
        long long int A[],
        long long int N, long long int K
){
    queue<long long> q;
    for(long i=0; i<K; ++i){
        if(A[i] < 0) q.push(A[i]);
    }
    
    vector<long long> ans = {q.size()?q.front():0};
    
    for(long i= 0, j = K; j<N; ++i, ++j){
        if(q.front() == A[i]) q.pop();
        if(A[j] < 0) q.push(A[j]);
        
        long long val = 0;
        if(q.size()) val = q.front();
        else ans.emplace_back(val);
    }
    return ans;
}