/**
 * @file 1081. Smallest Subsequence of Distinct Characters
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * @link https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        int alphas[26]={0}, n=s.length(), i=0;
        for(; i<n; ++i){
            alphas[s[i]-'a'] = i;
        }
        i=0;
        unordered_set<char> set;
        string ans = "";
        while(i<n){
            while(!ans.empty() and ans.back()>s[i] and alphas[ans.back()-'a']>i and !set.count(s[i])){
                set.erase(ans.back()),
                ans.pop_back();
            }
            if(!set.count(s[i])){
                set.insert(s[i]),
                ans.push_back(s[i]);
            }
            ++i;
        }
        return ans;
    }
};
