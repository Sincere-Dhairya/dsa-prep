/**
 * @file 131. Palindrome Partitioning
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-29
 * @link https://leetcode.com/problems/palindrome-partitioning/
 * @copyright Copyright (c) 2021
 * 
 */
/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

//using DP and Backtracking TC: O(N^3 ~ N^2) SC: O(N^2)
class Solution {
public:
    void substringsolver(vector<vector<string>> & ans, vector<string> help, vector<vector<int>> A, string s, int r, int n){
        for(auto i : A[r]){
            help.push_back(s.substr(r, i-r+1));
            if(i == n-1)
                ans.push_back(help);
            else
                substringsolver(ans, help, A, s, i+1, n);
            help.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<vector<bool> > cache(n, vector<bool>(n, 0));
        vector<vector<int>> A(n);
        
        for(int i = 0; i < n; i++)
            cache[i][i] = 1, A[i].push_back(i);
        for(int i = 0; i< n-1; i++)
            if(s[i] == s[i+1])
                cache[i][i+1] = 1, A[i].push_back(i+1);
        for(int i =2; i<n; i++){
            for(int r = 0; r < n and r+i < n; r++)
                if(s[r] == s[r+i] and cache[r+1][r+i-1])
                    cache[r][r+i] = 1, A[r].push_back(r+i);
        }
        substringsolver(ans, {}, A, s, 0, n);
        return ans;
    }
};