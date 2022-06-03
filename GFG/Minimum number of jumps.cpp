/**
 * @file Minimum number of jumps
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-31
 * @link https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1/?page=1&difficulty[]=1&difficulty[]=2&company[]=Amazon&company[]=Microsoft&company[]=Flipkart&company[]=Adobe&company[]=Google&company[]=Goldman%20Sachs&company[]=Facebook&company[]=Intuit%20&company[]=Linkedin&company[]=Salesforce&company[]=Twitter&company[]=Myntra&company[]=Atlassian&company[]=BrowserStack&company[]=Apple&company[]=Uber&sortBy=submissions# @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
Example 2:

Input :
N = 6
arr = {1, 4, 3, 2, 6, 7}
Output: 2 
Explanation: 
First we jump from the 1st to 2nd element 
and then jump to the last element.

Your task:
You don't need to read input or print anything. Your task is to complete function minJumps() which takes the array arr and it's size N as input parameters and returns the minimum number of jumps. If not possible returns -1.


Expected Time Complexity: O(N)
Expected Space Complexity: O(1)


Constraints:
1 ≤ N ≤ 10^7
0 ≤ arri ≤ 10^7
*/

// DP. Giving TLE coz of the constraints.
class Solution{
      public:
    int f(int dp[], int arr[], int &n ,int i){
        if(i==n-1) return 0;
        if(i >=n) return 1e9;
        if(arr[i]==0) return 1e9;
        if(dp[i]) return dp[i];
        int minjumps = 1e9;
        for(int j=1; j<=arr[i]; ++j){
            minjumps = min(minjumps, 1+f(dp, arr, n, i+j));
        }
        
        return dp[i] = minjumps;
    }  
    int minJumps(int arr[], int n){
        int dp[n];
        memset(dp, 0, sizeof(dp));
        int ans = f(dp, arr, n, 0);
        if(ans >= 1e9 || ans<0) return -1;
        return ans;
    }
};

// 