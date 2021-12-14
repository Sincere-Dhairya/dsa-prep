/**
 * @file 1446.Consecutive-Characters.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

// 2 pointer approach : TC O(N), SC O(1).
class Solution {
public:
    int maxPower(string s) {
        int n = s.size(), i = 0, j = 0, len = 0, maxlen = 0;
        while(j<n and i < n){
            if(s[i] == s[j]){
                len = j-i+1, ++j;
                maxlen = max(maxlen, len);
            }
            else{
                i = j, ++j;
            }
        }
        return maxlen;
    }
};
//  a   b   b   c   c   c   d   d   d   d   e   e   e   e   e   d   c   b   a   
// i,j  i       i           i               i                   i   i   i   i   j
//maxlen = 1|2