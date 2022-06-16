/**
 * @file Longest Sub-Array with Sum K 
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-16
 * @link https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1# @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function smallestSubsegment() that takes an array (A), sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1<=N<=10^5
-10^5<=A[i], K<=10^5
*/

// Brute Force Gave TLE
// TC: O(NxN), SC: O(1)
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K){ 
        int maxLen = 0;
        for(int i=0; i<N; ++i){
            int sum = A[i];
            if(A[i] == K) maxLen = max(maxLen, 1);
            for(int j = i+1; j<N; ++j){
                sum += A[j];
                if(sum == K){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    } 

};

// Prefix Sum Solution.
// TC: O(N), SC: O(N)
class Solution{
    public:
    
    int lenOfLongSubarr(int A[],  int N, int K){ 
        int maxLen = 0, sum = 0;
        unordered_map<int, int> prefix;
        prefix[0]=-1;
        for(int right = 0; right<N; ++right){
            sum += A[right];
            int diff = sum - K;
            if(prefix.count(diff)){
                maxLen = max(maxLen, right-prefix[diff]);
            }
            if(prefix.count(sum)==0)
                prefix[sum] = right;
        }
        return maxLen;
    }

};