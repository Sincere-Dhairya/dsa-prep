/**
 * @file Largest subarray of 0's and 1's
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-25
 * @link https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s @endlink
 * @copyright Copyright (c) 2022
 * @tags sliding-window queue
 */
/*
Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Example 1:

Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.
Example 2:

Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxLen() which takes the array arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^5
0 <= A[] <= 1
*/

// Sliding Window. Queue
// TC: O(N), SC: O(N)
class Solution{
  public:
  
    int tour(petrolPump p[],int n){
       queue<int> q;
       int balance = 0, ind = 0;
       
       for(int i = 0; i<n; ++i){
           balance += p[i].petrol -p[i].distance;
           if(balance <0){
               q.push(balance);
               balance = 0;
               ind = i+1;
           }
       }
       
       while(q.size()){
           balance += q.front(), q.pop();
       }
       if(balance >=0 ) return ind;
       return -1;
    }
};