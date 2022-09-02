/**
 * @file 10. Regular Expression Matching
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * @link https://leetcode.com/problems/regular-expression-matching/ @endlink
 * @copyright Copyright (c) 2022
 * @tags recursion dynamic-programming
 */
/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/
// Recursion + Memoization.
// TC: O(NxN), SC: O(NxN)
class Solution {
public:
    bool isMatch(vector<vector<int>>&table, string& s, string& p, int i, int j){
        if(j==p.size()){
            return i==s.size();
        }
        
        if(table[i][j] > -1){
            return table[i][j];
        }
        if(j+1 < p.length() && p[j+1] == '*'){
            if(isMatch(table, s, p, i, j+2)) return table[i][j] = 1;
            
            while(i<s.length() && (p[j] == '.' || s[i] == p[j])){
                ++i;
                if(isMatch(table, s, p, i, j+2)){
                    return table[i][j]=1;
                }
            }
        }
        else if(i<s.length() && (p[j] == '.' || s[i] == p[j])){
            return table[i][j] = isMatch(table, s, p, i+1, j+1);
        }
        return table[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> table(s.length()+1, vector<int> (p.length()+1, -1));
        return isMatch(table, s, p, 0, 0);
    }
};