/**
 * @file Maximum Sum of two non-overlapping Subarrays of any length
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-13
 * @link https://www.geeksforgeeks.org/maximum-sum-of-two-non-overlapping-subarrays-of-any-length/ @endlink
 * @copyright Copyright (c) 2022
 * @tags prefix-sum kadanes-algorithm maximum-sum-subarray
 */
/*
Given an array A consisting of N integers, the task is to find the maximum sum of two non-overlapping subarrays of any length of the array.

Note: You can select empty subarrays also.

Examples: 

Input: N = 3, A[] = {-4, -5, -2}
Output: 0
Explanation: Two empty subarrays are optimal with maximum sum = 0.

Input:  N = 5, A[] = {5, -2, 3, -6, 5}
Output: 11
Explanation: Optimal subarrays are {5, -2, 3} and {5} with maximum sum = 11.
*/

#include<bits/stdc++.h>
using namespace std;

int maximumSum(int* arr, int n){
    int * fwdKadane = new int[n+1], * bwdKadane = new int[n+1];
    memset(fwdKadane, 0, (n+1)*sizeof(int));
    memset(bwdKadane, 0, (n+1)*sizeof(int));
    
    int k = 0, sum1 = 0, sum2 = 0;
    for(int i = 0; i<n; ++i){
        sum1 += arr[i];
        sum2 = max(sum1, sum2);
        fwdKadane[i+1] = sum2;
        sum1 = sum1<0?0: sum1;
    }
    
    sum1 = 0, sum2 = 0;
    
    for(int i = n-1; i>=0; --i){
        sum1 += arr[i];
        sum2 = max(sum2, sum1);
        sum1 = sum1<0?0:sum1;
        bwdKadane[i+1] = sum2;
    }
    
    int maxSum = 0;
    for(int i = 0; i<=n; ++i){
        maxSum = max(maxSum, fwdKadane[i]+bwdKadane[i]);
    }
    
    return maxSum;
    return 0;
}

int main(){
    int arr1[]= {5, -2, 3, -6, 5}, n1 = 5,
    arr2[] = {-4,-5,-2}, n2 = 3;
    cout <<maximumSum(arr1, n1) <<endl;
    cout << maximumSum(arr2, n2) <<endl;
}