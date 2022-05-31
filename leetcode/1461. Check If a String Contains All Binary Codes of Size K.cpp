/**
 * @file 1461. Check If a String Contains All Binary Codes of Size K
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-05-31
 * @link https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
Example 2:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
Example 3:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.
 

Constraints:

1 <= s.length <= 5 * 105
s[i] is either '0' or '1'.
1 <= k <= 20
*/

// Sliding Window.
// TC: O(N), SC: O(N).
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(n <= k) return 0;
        
        // creating the window.
        string str = "";
        for(int i=0; i<k; ++i){
            str.push_back(s[i]);
        }
        
        unordered_set<string> allnums;
        allnums.insert(str);
        
        for(int i = k; i<n; ++i){
            str.erase(0, 1);
            str.push_back(s[i]);
            allnums.insert(str);
        }
        
        return allnums.size()==pow(2,k);
    }
};