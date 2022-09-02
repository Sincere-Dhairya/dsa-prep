/**
 * @file 28. Find the Index of the First Occurrence in a String
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * @link https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ @endlink
 * @copyright Copyright (c) 2022
 * @tags strings sliding-window
 */
/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.
*/

// TC: O(N), SC: O(N)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1, n = haystack.size(), m = needle.size();
        if(n <m)
            return ans;
        string window = haystack.substr(0, m);
        if(window == needle) return 0;
        for(int i = m; i<n; ++i){
            window.erase(0, 1);
            window.push_back(haystack[i]);
            if(window.compare(needle) == 0) return i-m+1;
        }
        return ans;
    }
};
