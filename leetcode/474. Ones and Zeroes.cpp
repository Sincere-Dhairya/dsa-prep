/**
 * @file 474. Ones and Zeroes
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-23
 * @link https://leetcode.com/problems/ones-and-zeroes/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/

// Recursion + Memoization. TC - O(N^2). SC - O(N^3)
class Solution {
public:
    int maxSubsetSize(vector<vector<vector<int>>>& cache, vector<int>& zeroes, vector<int>& ones, int i, int m, int n){
        if(i==0){
            if(m>= zeroes[0] && n>= ones[0]) return 1;
            return 0;
        }
        if(cache[i][m][n]) return cache[i][m][n];
        int unpick = maxSubsetSize(cache, zeroes, ones, i-1, m, n), pick = 0;
        if(zeroes[i]<= m && ones[i] <= n){
            pick = 1+ maxSubsetSize(cache, zeroes, ones, i-1, m-zeroes[i], n-ones[i]);
        }
        return cache[i][m][n] = max(pick, unpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.end()-strs.begin();
        vector<vector<vector<int>>> cache(len+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        vector<int> zeroes(len), ones(len);
        
        for(int i = 0; i<len; ++i){
            int z = 0, o = 0;
            for(auto c: strs[i]){
                if(c-'0') ++o;
                else ++z;
            }
            zeroes[i] = z, ones[i] = o;
        }
        return maxSubsetSize(cache, zeroes, ones, len-1, m, n);
        return 0;
    }
};

// Tabulation.
class Solution {
public:
    int maxSubsetSize(vector<vector<vector<int>>>& cache, vector<int>& zeroes, vector<int>& ones, int i, int m, int n){
        if(i==0){
            if(m>= zeroes[0] && n>= ones[0]) return 1;
            return 0;
        }
        if(cache[i][m][n]) return cache[i][m][n];
        int unpick = maxSubsetSize(cache, zeroes, ones, i-1, m, n), pick = 0;
        if(zeroes[i]<= m && ones[i] <= n){
            pick = 1+ maxSubsetSize(cache, zeroes, ones, i-1, m-zeroes[i], n-ones[i]);
        }
        return cache[i][m][n] = max(pick, unpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.end()-strs.begin();
        vector<vector<vector<int>>> cache(len+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        vector<int> zeroes(len), ones(len);
        
        for(int i = 0; i<len; ++i){
            int z = 0, o = 0;
            for(auto c: strs[i]){
                if(c-'0') ++o;
                else ++z;
            }
            zeroes[i] = z, ones[i] = o;
        }
        
        for(int j=0; j<=m; ++j){
            // zeroes
            for(int k=0; k<=n; ++k){
                // ones
                if(zeroes[0]<=j && ones[0]<=k) cache[0][j][k] =1;
            }
        }
        
        for(int i=1; i<len; ++i){
            for(int j=0; j<=m; ++j){
                for(int k=0; k<=n; ++k){
                    int unpick = cache[i-1][j][k], pick = 0;
                    if(zeroes[i]<=j && ones[i]<=k) pick = 1+cache[i-1][j-zeroes[i]][k-ones[i]];
                    cache[i][j][k] = max(pick, unpick);
                }
            }
        }
        return cache[len-1][m][n];
    }
};