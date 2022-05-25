/**
 * @file Longest Bitonic Sequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-26
 * @link https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array/list 'ARR' consisting of 'N' positive integers. A subsequence 
of 'ARR' is called bitonic if it is first increasing and then decreasing.
For Example:
An example of a bitonic sequence will be 1 < 2 < 3 < 4 > 2 > 1.
Your task is to return the length of the longest bitonic sequence of 'ARR'.
A subsequence of an array is an ordered subset of the array's elements having the 
same sequential ordering as the original array.
For Example:
Let ARR = [1, 2, 1, 2, 1]

One of the bitonic subsequences for this array will be [1, 2, 2, 1].
*/

// Tabulation.
// TC: O(NxN), SC: O(N)
int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> left(n, 1), right(n, 1);
    
    for(int i = 1; i<n; ++i){
        for(int j = 0; j<i; ++j){
            if(arr[i]>arr[j] && left[i] < left[j]+1){
                left[i] = left[j]+1;
            }
        }
    }
    
    for(int i = n-1; i>=0; --i){
        for(int j = n-1; j>i; --j){
            if(arr[i]>arr[j] && right[i] < right[j]+1){
                right[i] = right[j]+1;
            }
        }
    }
    
    int maxlen = 0;
    for(int i=0; i<n; ++i){
        maxlen = max(maxlen, left[i]+right[i]-1);
    }
    return maxlen;
} 
