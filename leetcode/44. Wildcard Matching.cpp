/**
 * @file 44. Wildcard Matching
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * @link https://leetcode.com/problems/wildcard-matching/ @endlink
 * @copyright Copyright (c) 2022
 * @tags recursion, dynaic-programming
 */
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

// Tabulation.
#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.length();
        vvi table(n+1, vi(m+1, 0));
        table[n][m] = 1;
        
        for(int j = m-1; j>=0; --j){
            if(p[j] !='*'){
                break;
            }
            table[n][j] = 1;
        }
        
        for(int i = n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                if(s[i] == p[j] || p[j] == '?'){
                    table[i][j] = table[i+1][j+1];
                }
                else if(p[j] == '*'){
                    table[i][j] = table[i][j+1] ||
                        table[i+1][j];
                }
                else table[i][j] = 0;
            }
        }
        return table[0][0];
    }
};