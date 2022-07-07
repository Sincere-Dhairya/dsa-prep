/**
 * @file 97. Interleaving String
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * @link https://leetcode.com/problems/interleaving-string/ @endlink
 * @copyright Copyright (c) 2022
 * @tags recursion dp dynamic-programming
 */
/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
*/

// Recursion + Memoization.
class Solution {
public:
    bool checkStrings(vector<vector<vector<int>>>& table, string& a, string& b, string& c, int i, int j, int k){
        // base cases.
        if(a.size() == i){
            if(c.size() -k == b.size() - j){
                while(j<b.size()){
                    if(c[k] == b[j]) ++j, ++k;
                    else return 0;
                }
                return 1;
            }
            else return 0;
        }
        if(b.size() == j){
            if(a.size()-i == c.size()-k){
                while(k<c.size()){
                    if(c[k] == a[i]) ++i, ++k;
                    else return 0;
                }
                return 1;
            }
            else return 0;
        }
        if(k == c.size() && (i < a.size() || j<b.size())) return 0;
        
        if(table[i][j][k] > -1) return table[i][j][k];
        bool ans = false;
        if(a[i] == c[k]){
            ans = checkStrings(table, a, b, c, i+1, j, k+1);
        }
        if(b[j] == c[k]){
            ans |= checkStrings(table, a, b, c, i, j+1, k+1);
        }
        return table[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        
        vector<vector<vector<int>>> table(n1+1, vector<vector<int>> (n2+1, vector<int> (n3+1, -1)));
        
        return checkStrings(table, s1, s2, s3, 0, 0, 0);
    }
};

