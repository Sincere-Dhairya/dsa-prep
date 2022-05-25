/**
 * @file Number of Longest Increasing Subsequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-26
 * @link https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an integer array ‘ARR’ of length ‘N’, return the number of longest increasing 
subsequences in it.
The longest increasing subsequence(LIS) is the longest subsequence of the given 
sequence such that all elements of the subsequence are in increasing order.
Note :
The subsequence should be a strictly increasing sequence.
For Example :
Let ‘ARR’ = [50, 3, 90, 60, 80].
In this array the longest increasing subsequences are [50, 60, 80] and [3, 60, 80]. 
There are other increasing subsequences as well but we need the number of longest 
ones. Hence the answer is 2.
*/

// Tabulation. 
// TC: O(NxN), SC: O(N)

int findNumberOfLIS(vector<int> &arr){
    int n = arr.size(), maxlen = 0, num = 0;
    vector<int> arr1(n, 1), arr2(n, 1);
    for(int i = 1; i<n; ++i){
        for(int j = 0; j<i; ++j){
            if(arr[j]<arr[i]){
                if(arr1[j]+1 > arr1[i]){
                    arr1[i] = arr1[j]+1, arr2[i] = arr2[j];
                }
                else if(arr1[j]+1 == arr1[i]){
                    arr2[i] += arr2[j];
                }
            }
        }
        maxlen = max(maxlen, arr1[i]);
    }
    for(int i=0; i<n; ++i){
        if(arr1[i] == maxlen) 
            num += arr2[i];
    }
    return num;
}