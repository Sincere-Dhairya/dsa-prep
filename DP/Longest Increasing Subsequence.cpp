/**
 * @file Longest Increasing Subsequence
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-24
 * @link https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459 @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
For a given array with N elements, you need to find the length of the longest subsequence 
from the array such that all the elements of the subsequence are sorted in strictly 
increasing order.
Strictly Increasing Sequence is when each term in the sequence is larger than the preceding 
term.
For Example:
[1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3] is not.
*/

// Binary Search OP.
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> sequence;
    int len = 0;
    for(int i = 0; i<n; ++i){
        if(sequence.empty() || sequence.back() < arr[i]){
            sequence.push_back(arr[i]);
            ++len;
        }
        else{
            int ind = lower_bound(sequence.begin(), sequence.end(), arr[i]) - sequence.begin();
            sequence[ind] = arr[i];
        }
    }
    return len;
}

// Recursion + Memoization.
// TC: O(2^N), SC: O(N^2)
int Length(vector<vector<int>>& table, int arr[], int n, int i, int prev){
    if(i==n) return 0;
    if(table[i][prev+1]) return table[i][prev+1];
    int unpick = Length(table, arr, n, i+1, prev), pick =0;
    if(prev == -1 || arr[i]> arr[prev]){
        pick = 1+Length(table, arr, n, i+1, i);
    }
    return table[i][prev+1] = max(pick, unpick);
}

int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> table(n+1, vector<int>(n+1));
    return Length(table, arr, n, 0, -1);
}

// Tabulation.
// TC: O(NxN), SC: O(NxN).
int longestIncreasingSubsequence(int arr[], int n){
    vector<vector<int>> table(n+1, vector<int>(n+1));
    
    for(int i = n-1; i>=0; --i){
        for(int prev = i-1; prev >=-1; --prev){
            int unpick = table[i+1][prev+1], pick = 0;
            if(prev== -1 || arr[i]>arr[prev]) pick = 1+table[i+1][i+1];
            table[i][prev+1] = max(pick, unpick);
        }
    }
    return table[0][0];
}

// Space Optimized.
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> curr(n+1), next(n+1);
    for(int i = n-1; i>=0; --i){
        for(int prev = i-1; prev >=-1; --prev){
            int unpick = next[prev+1], pick = 0;
            if(prev== -1 || arr[i]>arr[prev]) pick = 1+next[i+1];
            curr[prev+1] = max(pick, unpick);
        }
        next = curr;
    }
    return next[0];
}

// Tabulation.
// TC: O(NxN), SC: O(N)
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> cache(n+1, 1);
    int len = 1;
    for(int i = 1; i<n; ++i){
        for(int j = 0; j<i; ++j){
            if(arr[i] > arr[j]){
                cache[i] = max(cache[i], cache[j]+1);
            }
        }
        len = max(len, cache[i]);
    }
    return len;
}