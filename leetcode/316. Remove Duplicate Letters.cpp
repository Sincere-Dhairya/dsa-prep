/**
 * @file 316. Remove Duplicate Letters
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * @link https://leetcode.com/problems/remove-duplicate-letters/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 10^4
s consists of lowercase English letters.
*/

// O(N) TC
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int alphabets[26]={0}, n = s.length(), i=0;
        for(; i<n; ++i){
            alphabets[s[i]-'a'] = i;
        }
        string ans = "";
        unordered_set<char> set;
        i=0;
        while(i<n){
            while(!ans.empty() && ans.back()>s[i] && alphabets[ans.back()-'a']>i && !set.count(s[i])){
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