/**
 * @file 76. Minimum Window Substring
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * @link https://leetcode.com/problems/minimum-window-substring/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 10^5
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

// TC: O(NxN), SC: O(N).
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> list;
        for(auto c: t){
            ++list[c];
        }
        string ans = s;
        for(int i=0; i<s.size(); ++i){
            unordered_map<char, int> test;
            for(int j=i; j<s.size(); ++j){
                ++test[s[j]];
                bool flag = 1;
                for(auto p: list){
                    if(test.count(p.first) && test[p.first] >= p.second){
                        continue;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
                if(flag && ans.length() > j-i+1){
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans==s?"":ans;
    }
};

// Sliding Window
// TC: O(N), SC: O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int len = INT_MAX;
        unordered_map<int, int> tword;
        
        for(char &c: t){
            ++tword[c];
        }
        int count = t.length(), left = 0;
        
        for(int right =0; right<s.length(); ++right){
            if(tword[s[right]] > 0){
                --count;
            }
            --tword[s[right]];
            
            // reduce the window size.
            while(tword[s[left]] < 0){
                ++tword[s[left]];
                ++left;
            }
            
            // generaate ans string.
            int length = right-left+1;
            if(count == 0 && len > length){
                len = min(len, length);
                ans = s.substr(left, len);
            }
        }
        return ans;
    }
};