/**
 * @file 792. Number of Matching Subsequences
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * @link https://leetcode.com/problems/number-of-matching-subsequences/ @endlink
 * @copyright Copyright (c) 2022
 * @tags unordered_maps, binary-search
 */
/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
*/

// Binary Search.


// Unordered Maps only.
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map< string, int> list;
        for(string& w: words){
            ++list[w];
        }
        
        for(auto& p: list){
            int si = s.size()-1, j = p.first.size()-1;
            while(si>=0 && j>=0){
                if(p.first[j] == s[si]){
                    --j;
                }
                --si;
            }
            count += (j==-1)? p.second: 0;
        }
        
        return count;
    }
};

